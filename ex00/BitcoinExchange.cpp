#include "BitcoinExchange.hpp"
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream> // permet conversion de flux de chaine en type choisi

BitcoinExchange::BitcoinExchange() : _value(""), _key(""), _line(""){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
    this->_data = other._data;
    this->_value = other._value;
    this->_key = other._key;
    this->_line = other._line;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
    if(this != &other)
    {
        this->_data = other._data;
        this->_value = other._value;
        this->_key = other._key;
        this->_line = other._line;
    }
    return *this;
}
int BitcoinExchange::process()
{
    std::ifstream input("input.txt");
    extractDataFromFile();
    while(std::getline(input, this->_line))
    {
        if(isInputValid())
        {
            //std::cout << "VALID INPUT : key input : " << this->_key << "\nValue valid : " << this->_value << std::endl;
            calculate();
        }

    }

    //extractFromInput();
    //displaymultimap(this->_data);
    return 0;
}
int BitcoinExchange::extractDataFromFile()
{
    std::string line;

    std::ifstream data("data.csv");

    while(std::getline(data, line))
    {
        size_t pos = line.find(",");
        this->_key = line.substr(0, pos); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)
        line.erase(0, pos + 1);
        this->_value = line.substr(0, line.size()); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)
        insertToMultiMap(this->_data, this->_value);
    }
    return 0;
}

bool BitcoinExchange::isInputValid()
{
    try
    {
        isSeparator(); // + recup _key input
        isInputKeyValid();
        isInputValueValid();
        return true;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return false;
}

int BitcoinExchange::calculate()
{
    std::stringstream ss (this->_value);

    float amount = 0;
    ss >> amount;

    float price = searchingPrice();
    std::cout << this->_key << " => " << this->_value << " = " << amount * price << std::endl;
    return 0;
}

void BitcoinExchange::displaymultimap(std::multimap<std::string, float>& multimap)
{
    for (std::multimap<std::string, float>::iterator it = multimap.begin(); it != multimap.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << '\n';
    }
}

bool BitcoinExchange::isSeparator()
{
        size_t pos = this->_line.find("|");
        if(pos)
        {
            this->_key = _line.substr(0, pos);
            _line.erase(0, pos + 1);
            return true;
        }
        throw CustomException("Error : Missing separator");
    return false;
}

int BitcoinExchange::insertToMultiMap(std::multimap<std::string, float>& multimap, std::string& secondParam)
{
    std::stringstream ss(secondParam);
    float res;
    ss >> res;
    multimap.insert(std::pair<std::string, float>(this->_key, res));
    return 0;
}

float BitcoinExchange::searchingPrice() // searchingKey for value
{
    std::map<std::string, float>::iterator it = this->_data.find(this->_key);
    if (it != this->_data.end()) {
        return it->second;
    }
    std::map<std::string, float>::iterator itt = std::lower_bound(this->_data.begin(), this->_data.end(), this->_key, Compare());
    // compare deux std::string, besoin de Compare pour gerer parametres custom de lower_bound
    if(itt != this->_data.end())
    {
        return itt->second;
    }
    else {
        throw std::runtime_error("Error: Key not found");
    }

    return 0;
}

bool BitcoinExchange::isInputKeyValid()
{
    std::string year;
    std::string month;
    std::string day;

    std::string tmp = this->_key;
    if (tmp.size() != 11 || tmp[4] != '-' || tmp[7] != '-')
        throw CustomException("Error : Wrong format");
    
    size_t pos = tmp.find("-");
    year = tmp.substr(0, pos);
    tmp.erase(0, pos + 1);
    pos = tmp.find("-");
    month = tmp.substr(0, pos);
    tmp.erase(0, pos + 1);
    day = tmp.substr(0, tmp.size());
    isDateTokenValid(year, 2009, 2022);
    isDateTokenValid(month, 1, 12);
    isDateTokenValid(day, 1, 31);

    return true;
}

bool BitcoinExchange::isInputValueValid()
{
    this->_value = this->_line.substr(0, this->_line.size()); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)
    std::stringstream ss (this->_value);
    int value;
    ss >> value;
    if (value < 0)
    {
        throw CustomException("Error : Not a positive number");
    }
    if(value > 1000)
    {
        throw CustomException("Error : Too large amount");
    }
    return true;
}

bool BitcoinExchange::isDateTokenValid(std::string &token, int from, int to)
{
    std::stringstream ssDay (token);
    int res;
    ssDay >> res;
    if(res >= from && res <= to)
    {
        return true;
    }
    throw CustomException("Error : Invalid date");
    return false;
}
