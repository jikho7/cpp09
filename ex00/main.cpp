# include "BitcoinExchange.hpp"

int main(int ac, char**av) // input.txt
{
    BitcoinExchange BitcoinExchange;
    (void)ac;
    (void)av;
    BitcoinExchange.process();
    return (0);
}

/*
    - getline(data.csv)
    - mettre res dans map (key: date, value: price BitcoinExchange)

*/