#include "BitcoinExchange.hpp"
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream> // permet conversion de flux de chaine en type choisi

BitcoinExchange::BitcoinExchange() : _value(""), _key(""){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
    this->_data = other._data;
    this->_value = other._value;
    this->_key = other._key;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
    if(this != &other)
    {
        this->_data = other._data;
        this->_value = other._value;
        this->_key = other._key;
    }
    return *this;
}
int BitcoinExchange::process()
{
    extractDataFromFile();
    isInputValid();
    calculate();
    //extractFromInput();
    //displaymultimap(this->_data);
    return 0;
}
int BitcoinExchange::extractDataFromFile()
{
    std::string _line;

    std::ifstream data("data.csv");

    while(std::getline(data, _line))
    {
        size_t pos = _line.find(",");
        this->_key = _line.substr(0, pos); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)
        _line.erase(0, pos + 1);
        this->_value = _line.substr(0, _line.size()); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)
        insertToMultiMap(this->_data, this->_value);
    }
    return 0;
}

    // while(std::getline(data, line))
    // {
    //     size_t pos = line.find(",");
    //     this->_key = line.substr(0, pos); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)
    //     line.erase(0, pos + 1);
    //     this->_value = line.substr(0, line.size()); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)
    //     insertToMultiMap(this->_data, this->_value);
    // }

int BitcoinExchange::isInputValid()
{
    std::ifstream input("input.txt");

    while(std::getline(input, this->_line))
    {
        try
        {
            isSeparator(); // + recup _key input
            isInputKeyValid();
            isInputValueValid();
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "date : " << this->_key << " amount : " << this->_value << std::endl;
        insertToMultiMap(this->_input, this->_value);
    }
    return 0;
}

int BitcoinExchange::calculate()
{

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

int BitcoinExchange::insertToMultiMap(std::multimap<std::string, float>& multimap, std::string secondParam)
{
    std::stringstream ss(secondParam);
    float res;
    ss >> res;
    multimap.insert(std::pair<std::string, float>(this->_key, res));
    return 0;
}

bool BitcoinExchange::isInputKeyValid()
{
    // YYYY-MM-DD
    std::string year;
    std::string month;
    std::string day;

    std::string tmp = this->_key;
    //std::cout << "tmp : " << tmp << " tmp size : " << tmp.size() << " tmp[4] : " << tmp[4] << " tmp[7] : " << tmp[7] << std::endl;
    if (tmp.size() != 11 || tmp[4] != '-' || tmp[7] != '-')
        throw CustomException("Error : Wrong format");
    
    size_t pos = tmp.find("-");
    year = tmp.substr(0, pos);
    tmp.erase(0, pos + 1);
    pos = tmp.find("-");
    month = tmp.substr(0, pos);
    tmp.erase(0, pos + 1);
    day = tmp.substr(0, tmp.size());
    //std::cout << "year : " << year << " month : " << month << " day : " << day << std::endl;
    isYearValid(year);
    isMonthValid(month);
    isDayValid(day);

    return 0;
}

bool BitcoinExchange::isYearValid(std::string year)
{
    std::stringstream ssYear (year);
    int res;
    ssYear >> res;
    if(res <= 2022 || res >= 2009)
    {
        return true;
    }
    std::cout << "Res : " << res << " Invalid year : " << this->_key << std::endl;
    throw CustomException("Error : Invalid date (year)");
    return false;
}

bool BitcoinExchange::isMonthValid(std::string month)
{
    std::stringstream ssMonth (month);
    int res;
    ssMonth >> res;
    if(res <= 12 || res > 0)
    {
        return true;
    }
    std::cout << "Res : " << res << " Invalid month: " << this->_key << std::endl;
    throw CustomException("Error : Invalid date (month)");
    return false;
}

bool BitcoinExchange::isDayValid(std::string day)
{
    std::stringstream ssDay (day);
    int res;
    ssDay >> res;
    if(res <= 31 || res > 0)
    {
        return true;
    }
    std::cout << "Res : " << res << " Invalid day: " << this->_key << std::endl;
    throw CustomException("Error : Invalid date (day)");
    return false;
}

bool BitcoinExchange::isInputValueValid()
{
    this->_value = this->_line.substr(0, this->_line.size()); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)

    std::stringstream ss (this->_value);
    int value;
    ss >> value;
    //std::cout << "check amount  : " << it->second << std::endl;
    if (value < 0)
    {
        throw CustomException("Error : Not a positive number");
    }
    if(value > 1000)
    {
        //std::cout << "check amount it->second : " << it->second << std::endl;
        throw CustomException("Error : Too large amount");
    }
    return 0;
}

