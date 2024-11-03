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
    //displayMap(this->_data);
    displayMap(this->_input);
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
        insertToMap(this->_data, this->_value);
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
        insertToMap(this->_input, this->_value);
    }
    return 0;
}

void BitcoinExchange::displayMap(std::map<std::string, float>& map)
{
    for (std::map<std::string, float>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << '\n';
    }
}

int BitcoinExchange::insertToMap(std::map<std::string, float>& map, std::string secondParam)
{
    std::stringstream ss(secondParam);
    float res;
    ss >> res;
    map.insert(std::pair<std::string, float>(this->_key, res));
    return 0;
}




