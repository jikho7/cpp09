#include <iostream>
#include <map>
#include <exception>

class BitcoinExchange
{
    std::map<std::string, float> _data;
    std::map<std::string, float> _input;
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

        int     process();
        int     extractDataFromFile();
        int     extractFromInput();
        void    displayMap(std::map<std::string, float>& map);
        int     insertToMap(std::map<std::string, float>& map, std::string secondParam);
};