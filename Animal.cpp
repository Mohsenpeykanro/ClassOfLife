#include <iostream>
#include <math.h>
#include <vector>
#include "Animal.h"
#include "cell.h"

int Animal::similarity(Cell a, Cell b) {
    double percentage;
    double TotalPercentage = 0;
    int TotalCount = 0;
    int count = 0;

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

bool Animal::SimilarAnimal(Cell a, Cell b) {
    if (similarity(a, b) >= 70){
        return true;
    }else{
        return false;
    }
}

void Animal::AsexualReproduction(Cell a) {
    Cell b;
    for (int i = 0; i < a.chro.size(); ++i) {
        a.chro.push_back(chro[i]);
    }
    bool test = true;
    while (test == true){
        for (int i = 0; i < (a.chro.size() / 2); ++i) {
            int n = ::rand() % a.chro.size();
            b.chro.push_back(a.chro[n]);
        }
        if (similarity(a, b) >= 70){
            test = false;
        }
    }
}

void Animal::SexualReproduction(Cell a1, Cell b1) {
    Cell a2, b2, c;
    bool test = true;
    if (a1.chro.size() % 2 != 0 || b1.chro.size() % 2 != 0){

    }else{
        for (int i = 0; i < a1.chro.size(); ++i) {
            a1.chro.push_back(a1.chro[i]);
        }
        for (int i = 0; i < b1.chro.size(); ++i) {
            b1.chro.push_back(b1.chro[i]);
        }
        while(test == true){
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
            }
            if (similarity(a1, c) >= 70 || similarity(b1, c) >= 70){
                test = false;
            }
        }
    }
}
