#include "BitcoinExchange.hpp"
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream> // permet conversion de flux de chaine en type choisi

Btc::Btc() : _strPrice(""), _date("")
{
}

Btc::~Btc(){}

Btc::Btc(Btc &other)
{
    this->_data = other._data;
    this->_strPrice = other._strPrice;
    this->_date = other._date;
}

Btc &Btc::operator=(Btc &other)
{
    if(this != &other)
    {
        this->_data = other._data;
        this->_strPrice = other._strPrice;
        this->_date = other._date;
    }
    return *this;
}
int Btc::process()
{
    extractDataFromFile();
    displayMap();

    return 0;
}
int Btc::extractDataFromFile()
{
    std::string line;
    //std::string date;

    std::ifstream data("data.csv");
    //std::string price;

    while(std::getline(data, line))
    {
        size_t pos = line.find(",");
        this->_date = line.substr(0, pos); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)
        line.erase(0, pos + 1);
        this->_strPrice = line.substr(0, line.size()); // (Position of the first character to be copied as a substring, Number of characters to include in the substring)
        insertToMap();
    }
    return 0;
}

void Btc::displayMap()
{
    for (std::map<std::string, float>::iterator it = this->_data.begin(); it!=this->_data.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

int Btc::insertToMap()
{
    std::stringstream ss(this->_strPrice);
    float res;
    ss >> res;
    this->_data.insert(std::pair<std::string, float> (this->_date, res));
    return 0;
}

/* NOTE
    - Conversion avec stringstream <sstream>
    int num = 123;
    std::stringstream ss;
    ss << num;
    std::string str = ss.str(); // Convertit l'entier 123 en chaîne "123"

    std::string str = "123";
    std::stringstream ss(str);
    int num;
    ss >> num; // Convertit la chaîne "123" en entier 123
*/




