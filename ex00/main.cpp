# include "BitcoinExchange.hpp"

int main(int ac, char**av) // input.txt
{
    Btc btc;
    (void)ac;
    (void)av;
    btc.process();
    return (0);
}

/*
    - getline(data.csv)
    - mettre res dans map (key: date, value: price btc)

*/