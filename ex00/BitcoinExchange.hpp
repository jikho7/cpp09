#include <iostream>
#include <map>

class Btc
{
    std::map<std::string, float> _data;
    std::string _strPrice;
    std::string _date;


    public:
        Btc();
        ~Btc();
        Btc(Btc &other);
        Btc&operator=(Btc &other);

        int     process();
        int     extractDataFromFile();
        void    displayMap();
        int     insertToMap();


};