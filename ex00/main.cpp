# include "BitcoinExchange.hpp"

int main(int ac, char**av)
{
    if (ac != 2)
    {
        std::cerr << "Missing argument" << std::endl;
        return (0);
    }
    BitcoinExchange BitcoinExchange;
    BitcoinExchange.process(av[1]);
    return (0);
}