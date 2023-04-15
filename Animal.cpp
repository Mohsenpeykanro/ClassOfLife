#include <iostream>
#include <math.h>
#include <vector>
#include "Animal.h"
#include "cell.h"

// Similarity Between Chromosomes
int Animal::similarity(Cell a, Cell b) {
    double percentage;
    double TotalPercentage = 0;
    int TotalCount = 0;
    int count = 0;
// check which one is longer and do the calculation
// we check similarity char by char
    if (a.chro.size() >= b.chro.size()){
        for (int i = 0; i < a.chro.size(); ++i) {
            if (a.chro[i].getDNA().length() >= b.chro[i].getDNA().length()){
                for (int j = 0; j < b.chro[i].getDNA().length(); ++j) {
                    if (a.chro[i].getDNA()[j] == b.chro[j].getDNA()[j]){
                        count++;
                    }
                }
            }else{
                for (int j = 0; j < a.chro[i].getDNA().length(); ++j) {
                    if (a.chro[i].getDNA()[j] == b.chro[j].getDNA()[j]) {
                        count++;
                    }
                }
            }
            TotalCount++;
            percentage = ((double)count / a.chro[i].getDNA().length()) * 100;
            TotalPercentage += percentage;
        }
    }else{
        for (int i = 0; i < b.chro.size(); ++i) {
            if (a.chro[i].getDNA().length() >= b.chro[i].getDNA().length()) {
                for (int j = 0; j < b.chro[i].getDNA().length(); ++j) {
                    if (a.chro[i].getDNA()[j] == b.chro[j].getDNA()[j]) {
                        count++;
                    }
                }
            } else {
                for (int j = 0; j < a.chro[i].getDNA().length(); ++j) {
                    if (a.chro[i].getDNA()[j] == b.chro[j].getDNA()[j]) {
                        count++;
                    }
                }
            }
            TotalCount++;
            percentage = ((double) count / a.chro[i].getDNA().length()) * 100;
            TotalPercentage += percentage;
        }
    }

    return percentage;
}

// Similarity Between Animal Species
bool Animal::SimilarAnimal(Cell a, Cell b) {
    // we use the previous method and check it here and return bool
    if (similarity(a, b) >= 70){
        return true;
    }else{
        return false;
    }
}

//Asexual Reproduction
void Animal::AsexualReproduction(Cell a) {
    Cell b;
    // we double the chromosome here
    for (int i = 0; i < a.chro.size(); ++i) {
        a.chro.push_back(chro[i]);
    }
    bool test = true;
    int count = 0;
    // we randomly pick until we have more than 70%
    while (test == true || count == 100){
        b.chro.clear();
        for (int i = 0; i < (a.chro.size() / 2); ++i) {
            int n = ::rand() % a.chro.size();
            b.chro.push_back(a.chro[n]);
            count++;
        }
        if (similarity(a, b) >= 70){
            test = false;
            cout << "Baby Cell Created \n";
            for (int i = 0; i < b.chro.size(); ++i) {
                cout << b.chro[i].getDNA() << endl;
            }
        }
    }

}
// Sexual Reproduction
void Animal::SexualReproduction(Cell a1, Cell b1) {
    Cell a2, b2, c;
    bool test = true;
    int count = 0;
    // check if both are even
    if (a1.chro.size() % 2 != 0 || b1.chro.size() % 2 != 0){
        cout << "one of the cell have odd chromosome" << endl;
    }else{
        // we first do asexual reproduction and double the chromosome
        for (int i = 0; i < a1.chro.size(); ++i) {
            a1.chro.push_back(a1.chro[i]);
        }
        for (int i = 0; i < b1.chro.size(); ++i) {
            b1.chro.push_back(b1.chro[i]);
        }
        // then we randomly pick again until more than 70%
        while(test == true || count == 100){
            for (int i = 0; i < (a1.chro.size() / 2); ++i) {
                int n = ::rand() % a1.chro.size();
                a2.chro.push_back(a1.chro[n]);
            }
            for (int i = 0; i < (b1.chro.size() / 2); ++i) {
                int n = ::rand() % b1.chro.size();
                b2.chro.push_back(b1.chro[n]);
            }
            for (int i = 0; i < (a2.chro.size() / 2); ++i) {
                int n = ::rand() % a2.chro.size();
                c.chro.push_back(a2.chro[n]);
            }
            for (int i = 0; i < (b2.chro.size() / 2); ++i) {
                int n = ::rand() % b2.chro.size();
                c.chro.push_back(b2.chro[n]);
                count++;
            }
            if (similarity(a1, c) >= 70 || similarity(b1, c) >= 70){
                test = false;
                for (int i = 0; i < c.chro.size(); ++i) {
                    cout << c.chro[i].getDNA() << endl;
                }
            }
        }
    }
}
