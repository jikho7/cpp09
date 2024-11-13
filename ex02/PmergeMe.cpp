#include "PmergeMe.hpp"

Pmerge::Pmerge(): _even(true), _nbOfElements(0){}

Pmerge::~Pmerge(){}

Pmerge::Pmerge(const Pmerge &other)
{
    this->_doubleVec = other._doubleVec;
    this->_doubleList = other._doubleList;
    this->_bigNumberVector = other._bigNumberVector;
    this->_smallNumberVector = other._smallNumberVector;
    this->_bigNumberList = other._bigNumberList;
    this->_smallNumberList = other._smallNumberList;

    this->_even = other._even;
    this->_vecTemplate = other._vecTemplate;
    this->_listTemplate = other._listTemplate;
    this->_nbOfElements = other._nbOfElements;
}

Pmerge &Pmerge::operator=(const Pmerge &other)
{
    if(this != &other)
    {
        this->_doubleVec = other._doubleVec;
        this->_doubleList = other._doubleList;
        this->_bigNumberVector = other._bigNumberVector;
        this->_smallNumberVector = other._smallNumberVector;
        this->_bigNumberList = other._bigNumberList;
        this->_smallNumberList = other._smallNumberList;

        this->_even = other._even;
        this->_vecTemplate = other._vecTemplate;
        this->_listTemplate = other._listTemplate;
        this->_nbOfElements = other._nbOfElements;
    }
    return *this;
}

// GETTER

// METHODS
void Pmerge::process(char * input)
{
    // Time to process a range of 5 elements with std::[..] : 0.00031 us
    clock_t startV = clock(); // base sur les ticks CPU : Les ticks CPU mesurent le temps de calcul utilisé par le programme, et non le temps total écoulé.
    std::cout << "----------  VECTOR  ----------" << std::endl;
    std::cout << ORANGE << "Before : " << RESET << input << std::endl;
    init(input, this->_vecTemplate);
    orderPair(this->_vecTemplate);
    createDoubleContainer(this->_vecTemplate, this->_doubleVec);
    orderDoubleContainer<std::vector<int> >(this->_doubleVec);
    separateNumbers(this->_bigNumberVector, this->_smallNumberVector, this->_doubleVec);
    insertSmallNumbersToMainChain(this->_bigNumberVector, this->_smallNumberVector);
    std::cout << ORANGE << "After : " << RESET;
    displayContainer(this->_bigNumberVector);
    clock_t endV = clock();
    double timeSpentVector = (double)(endV - startV) / CLOCKS_PER_SEC;
    std::cout << ORANGE << "Time to process a range of " << this->_nbOfElements  << " for vector container : " << timeSpentVector << RESET << std::endl;

    clock_t startL = clock();
    std::cout << "----------  LIST  ----------" << std::endl;
    std::cout << ORANGE << "Before : " << RESET << input << std::endl;
    init(input, this->_listTemplate);
    orderPair(this->_listTemplate);
    createDoubleContainer(this->_listTemplate, this->_doubleList);
    orderDoubleContainer<std::list<int> >(this->_doubleList);
    separateNumbers(this->_bigNumberList, this->_smallNumberList, this->_doubleList);
    insertSmallNumbersToMainChain(this->_bigNumberList, this->_smallNumberList);
    std::cout << ORANGE << "After : " << RESET;
    displayContainer(this->_bigNumberList);
    clock_t endL = clock();
    double timeSpentList = (double)(endL - startL) / CLOCKS_PER_SEC; // CLOCK_PER_SEC : converti les ticks en secondes, représente le nombre de ticks par seconde.
    std::cout << ORANGE << "Time to process a range of " << this->_nbOfElements  << " for list container : " << timeSpentList << RESET << std::endl;

    clock_t startD = clock();
    std::cout << "----------  DEQUE  ----------" << std::endl;
    std::cout << ORANGE << "Before : " << RESET << input << std::endl;
    init(input, this->_dequeTemplate);
    orderPair(this->_dequeTemplate);
    createDoubleContainer(this->_dequeTemplate, this->_doubleDeque);
    orderDoubleContainer<std::deque<int> >(this->_doubleDeque);
    separateNumbers(this->_bigNumberDeque, this->_smallNumberDeque, this->_doubleDeque);
    insertSmallNumbersToMainChain(this->_bigNumberDeque, this->_smallNumberDeque);
    std::cout << ORANGE << "After : " << RESET;
    displayContainer(this->_bigNumberDeque);
    clock_t endD = clock();
    double timeSpentdeque = (double)(endD - startD) / CLOCKS_PER_SEC; // CLOCK_PER_SEC : converti les ticks en secondes, représente le nombre de ticks par seconde.
    std::cout << ORANGE << "Time to process a range of " << this->_nbOfElements  << " for deque container : " << timeSpentdeque << RESET << std::endl;
}




// DISPLAY

// OPERATOR
std::ostream &operator<<(std::ostream &os, const std::pair<int, int> &pair)
{
    os << pair.first << " " << pair.second << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::pair<int, int> > &doubleVec)
{
    for (std::vector<std::pair<int, int>  >::const_iterator it = doubleVec.begin(); it != doubleVec.end(); ++it) {
        os << *it << " ";
    }
    return os;
}