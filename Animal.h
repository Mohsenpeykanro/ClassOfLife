#ifndef CLASSOFLIFE_ANIMAL_H
#define CLASSOFLIFE_ANIMAL_H
#include <iostream>
#include <vector>
#include "cell.h"

class Animal : public Cell{
private:
friend class Virus;
public:
    int similarity(Cell, Cell);
    bool SimilarAnimal(Cell, Cell);
    void AsexualReproduction(Cell);
    void SexualReproduction(Cell, Cell);
};

class Virus : public Gene{
private:
    std::string RNA;
public:

};
#endif //CLASSOFLIFE_ANIMAL_H
