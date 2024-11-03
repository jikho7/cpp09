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
    //extractDataFromFile();
    extractFromInput();
    //displaymultimap(this->_data);
    displaymultimap(this->_input);
    isDateValid();
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

int BitcoinExchange::extractFromInput()
{
    std::string line;
    std::ifstream input("input.txt");

    while(std::getline(input, line))
    {
        size_t pos = line.find("|");
        if(pos == std::string::npos)
        {
            this->_value = "";
        }
        else if(pos > 0)
        {
            this->_key = line.substr(0, pos);
            line.erase(0, pos + 1);
            this->_value = line.substr(0, line.size());
        }
        std::cout << "date : " << this->_key << " amount : " << this->_value << std::endl;
        insertToMultiMap(this->_input, this->_value);
    }
    return 0;
}

void BitcoinExchange::displaymultimap(std::multimap<std::string, float>& multimap)
{
    for (std::multimap<std::string, float>::iterator it = multimap.begin(); it != multimap.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << '\n';
    }
}

int BitcoinExchange::insertToMultiMap(std::multimap<std::string, float>& multimap, std::string secondParam)
{
    std::stringstream ss(secondParam);
    float res;
    ss >> res;
    multimap.insert(std::pair<std::string, float>(this->_key, res));
    return 0;
}

int BitcoinExchange::isDateValid()
{
    // YYYY-MM-DD
    std::string year;
    std::string month;
    std::string day;

    std::string tmp = this->_key;
    //std::cout << "tmp : " << tmp << " tmp size : " << tmp.size() << " tmp[4] : " << tmp[4] << " tmp[7] : " << tmp[7] << std::endl;
    if (tmp.size() != 11 || tmp[4] != '-' || tmp[7] != '-')
        throw BitcoinExchange::invalidDate();
    
    size_t pos = tmp.find("-");
    year = tmp.substr(0, pos);
    tmp.erase(0, pos + 1);
    
    pos = tmp.find("-");
    month = tmp.substr(0, pos);
    tmp.erase(0, pos + 1);

    day = tmp.substr(0, tmp.size());

    std::cout << "year : " << year << " month : " << month << " day : " << day << std::endl;
    
    // from string to int
    std::stringstream ssYear (year);
    int res;
    ssYear >> res;
    if(res > 2022 || res < 2009)
    {
        std::cout << "Res : " << res << " Invalid year : " << this->_key << std::endl;
        throw BitcoinExchange::invalidDate();
    }

    std::stringstream ssMonth (month);
    ssMonth >> res;
    if(res > 12 || res < 1)
    {
        std::cout << "Res : " << res << " Invalid month: " << this->_key << std::endl;
        throw BitcoinExchange::invalidDate();
    }
    
    std::stringstream ssDay (day);
    ssDay >> res;
    if(res > 31 || res < 1)
    {
        std::cout << "Res : " << res << " Invalid day: " << this->_key << std::endl;
        throw BitcoinExchange::invalidDate();
    }
    return 0;
}

int BitcoinExchange::madness()
{
    /*
        - comparer date input avec date data
        - multiplier value input avec value data
        - gerer cas d erreur
    
    */
    return 0;
}
