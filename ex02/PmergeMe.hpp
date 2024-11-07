#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <ostream>

class Pmerge
{
public:
    Pmerge();
    ~Pmerge();
    Pmerge(const Pmerge &other);
    Pmerge &operator=(const Pmerge &other);

    std::vector<int>& getVector(); 
    void displayVector(const std::vector<int>& vec) const;
    void    createPair(std::vector<int>& vec);
    void    displayDoubleVector(std::vector<std::pair<int, int> > doubleVec);

private:
    std::vector<int> _a;
    std::vector<std::pair<int, int> > _doubleVec;
};

std::ostream &operator<<(std::ostream& os, const std::pair<int, int>& pair);
std::ostream &operator<<(std::ostream& os, const std::vector<std::pair<int, int> > &doubleVec);

#endif

