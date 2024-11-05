#include <iostream>
#include <map>
#include <exception>
#include <ctime>

class BitcoinExchange
{
    std::multimap<std::string, float> _data;
    std::multimap<std::string, float> _input;
    std::string _value;
    std::string _key;
    std::string _line;

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

        int     process();
        int     extractDataFromFile();
        int     isInputValid();
        int     calculate();

        bool    isSeparator();
        bool    isInputKeyValid();
        bool    isInputValueValid();

        bool    isYearValid(std::string year);
        bool    isMonthValid(std::string month);
        bool    isDayValid(std::string day);

        std::string getString();
        void    displaymultimap(std::multimap<std::string, float>& multimap);
        int     insertToMultiMap(std::multimap<std::string, float>& multimap, std::string secondParam);


        //int     extractFromInput();
        //int     madness();
};