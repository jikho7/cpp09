#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <map>
#include <exception>
#include <ctime>
#include <algorithm>

class BitcoinExchange
{
    std::map<std::string, float>   _data;
    std::string                         _value;
    std::string                         _key;
    std::string                         _line;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        BitcoinExchange&operator=(BitcoinExchange &other);

        class CustomException : public std::exception {
            private:
                std::string _message;
            public:
                CustomException(const std::string& message) : _message(message) {}
                virtual ~CustomException() throw() {} // Bonne pratique pour gerer ressoucrces
                virtual const char* what() const throw() { // polymorphisme
                    return _message.c_str();
                }
        };

        int                             process();
        int                             extractDataFromFile();
        bool                            isInputValid();
        int                             calculate();

        bool                            isSeparator();
        bool                            isInputKeyValid();
        bool                            isInputValueValid();
        bool                            isDateTokenValid(std::string& token, int from, int to);
        bool                            isDateBissextile(std::string& year);

        std::string                     getString();
        void                            displayMap(std::map<std::string, float>& map);
        int                             insertToMap(std::map<std::string, float>& map, std::string& secondParam);

        float                           searchingPrice();
};

struct Compare {
    bool operator()(const std::pair<const std::string, float>& pair, const std::string& value) const {
        return pair.first < value; // pour lower_bound()
    }
    bool operator()(const std::string& value, const std::pair<const std::string, float>& pair) const {
        return value < pair.first;
    }
};

#endif