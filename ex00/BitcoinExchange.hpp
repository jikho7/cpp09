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

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);
        BitcoinExchange&operator=(BitcoinExchange &other);

        class Parameter : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return("Parameter Error\n");
            }
        };

        class invalidDate : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return("Date is not valid\n");
            }
        };

        int     process();
        int     extractDataFromFile();
        int     extractFromInput();
        void    displaymultimap(std::multimap<std::string, float>& multimap);
        int     insertToMultiMap(std::multimap<std::string, float>& multimap, std::string secondParam);
        int     isDateValid();
        int     madness();
};