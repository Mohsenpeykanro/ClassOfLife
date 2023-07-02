#include <iostream>
#include "cell.h"
#include "Animal.h"
using namespace std;

void GenomeMenu();
void CellMenu();
void AnimalMenu();

int main(){
    ::srand(::time(NULL));
    bool test = true;
    int n1;
    while(test != false){
        cout << "*********************\n";
        cout << "Chose your class: \n";
        cout << "1- Genome \n";
        cout << "2- Cell \n";
        cout << "3- Animal \n";
        cout << "4- Exit \n";
        cout << "Choose an Option: ";
        cin >> n1;
        switch (n1) {
            case 1:
                ::system("clear");
                GenomeMenu();
                break;
            case 2:
                ::system("clear");
                CellMenu();
                break;
            case 3:
                ::system("clear");
                AnimalMenu();
                break;
            case 4:
                ::system("clear");
                test = false;
                break;
        }
    }
    return 0;
}

vector<Cell> cell;
void GenomeMenu(){
    bool test = true;
    int n;
    vector<Gene> g;
    vector<Gene> rna;
    vector<Gene> dna;


    while (test != false){
        cout << "----- Genome Menu ----- \n";
        cout << "1- Create DNA \n";
        cout << "2- Create RNA \n";
        cout << "3- Create DNA From RNA \n";
        cout << "4- Small Mutation \n";
        cout << "5- Big Mutation \n";
        cout << "6- Reverse Mutation \n";
        cout << "7- Back To Main \n";
        cout << "Choose an Option: ";
        cin >> n;

        int a, b ,d, rn;
        string t1, t2 ,rbm1, rbm2, dbm1, dbm2;
        char tc1, tc2;
        switch (n) {

            case 1:
                ::system("clear");
                cout << "How Many DNA You Want to Create? ";
                cin >> a;
                for (int i = 0; i < a; ++i) {
                    Gene gt1;
                    cout << "First DNA Strand: \n";
                    cin >> t1;
                    cout << "Second DNA Strand: \n";
                    cin >> t2;
                    gt1.setDNA(t1, t2);
                    g.push_back(gt1);
                    cout << "-------------------------";
                }
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 2:
                ::system("clear");
                cout << "How Many RNA You Want to Create? ";
                cin >> a;
                cin.ignore();
                for (int i = 0; i < a; ++i) {
                    Gene gt2;
                    cout << "RNA Strand: \n";
                    getline(cin, t1);
                    gt2.setRNA(t1);
                    g.push_back(gt2);
                    cout << "-------------------------";
                }
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 3:
                ::system("clear");
                cout << "How Many DNA You Want to Create From RNA? ";
                cin >> a;
                cin.ignore();
                for (int i = 0; i < a; ++i) {
                    cout<<"which RNA?"<<endl;
                    cin>>d;
                    cin.ignore();
                    g[d-1].make_DNA();
                    cout << "-------------------------";
                }
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 4:
                NEXT1:
                cout << "Is it RNA or DNA? (RNA:1 , DNA:2): ";
                cin >> b;
                if (b == 1){
                    rna.clear();
                    for (int i = 0; i < g.size(); ++i) {
                        if (g[i].getRna().length() != 0){
                            cout << i+1 << "- " << g[i].getRna() << endl;
                            rna.push_back(g[i]);
                        }
                    }
                    cout << "-------------------------";
                    cout << "Which RNA? \n";
                    cin >> d;
                    cout << "Which Nucleobase You Want to Change? \n";
                    cin >> tc1;
                    cout << "Change to? \n";
                    cin >> tc2;
                    cout << "How Many of Them? \n";
                    cin >> rn;
                    rna[d-1].small_mutation_RNA(tc1, tc2, rn);

                }else if (b == 2){
                    dna.clear();
                    for (int i = 0; i < g.size(); ++i) {
                        if (g[i].getDna()[0].length() != 0){
                            cout << i+1 << "- " << g[i].getDna()[0] << endl;
                            cout << "   " << g[i].getDna()[1] << endl;
                            dna.push_back(g[i]);
                        }
                    }
                    cout << "-------------------------";
                    cout << "Which DNA? \n";
                    cin >> d;
                    cout << "Which Nucleobase You Want to Change? \n";
                    cin >> tc1;
                    cout << "Change to? \n";
                    cin >> tc2;
                    cout << "How Many of Them? \n";
                    cin >> rn;
                    dna[d-1].small_mutation_DNA(tc1, tc2, rn);
                }else{
                    cout << "Out of Range";
                    goto NEXT1;
                }
                break;
            case 5:
            NEXT2:
                cout << "Is it RNA or DNA? (RNA:1 , DNA:2): ";
                cin >> b;
                if (b == 1){
                    rna.clear();
                    for (int i = 0; i < g.size(); ++i) {
                        if (g[i].getRna().length() != 0){
                            cout << i+1 << "- " << g[i].getRna() << endl;
                            rna.push_back(g[i]);
                        }
                    }
                    cout << "-------------------------";
                    cout << "Which RNA? \n";
                    cin >> d;
                    cin.ignore();
                    cout << "Which Nucleobases You Want to Change? \n";
                    getline(cin, rbm1);
                    cout << "Change to? \n";
                    getline(cin, rbm2);
                    rna[d-1].big_mutation_RNA(rbm1, rbm2);

                }else if (b == 2){
                    dna.clear();
                    for (int i = 0; i < g.size(); ++i) {
                        if (g[i].getDna()[0].length() != 0){
                            cout << i+1 << "- " << g[i].getDna()[0] << endl;
                            cout << "   " << g[i].getDna()[1] << endl;
                            dna.push_back(g[i]);
                        }
                    }
                    cout << "-------------------------";
                    cout << "Which DNA? \n";
                    cin >> d;
                    cout << "Which Nucleobase You Want to Change? \n";
                    getline(cin, dbm1);
                    cout << "Change to? \n";
                    getline(cin, dbm2);
                    dna[d-1].big_mutation_DNA(dbm1, dbm2);
                }else{
                    cout << "Out of Range";
                    goto NEXT2;
                }
                break;
            case 6:
            NEXT:
                cout << "Is it RNA or DNA? (RNA:1 , DNA:2): ";
                cin >> b;
                if (b == 1){
                    rna.clear();
                    for (int i = 0; i < g.size(); ++i) {
                        if (g[i].getRna().length() != 0){
                            cout << i+1 << "- " << g[i].getRna() << endl;
                            rna.push_back(g[i]);
                        }
                    }
                    cout << "-------------------------";
                    cout << "Which RNA? \n";
                    cin >> d;
                    cin.ignore();
                    cout << "Which Nucleobases You Want to reverse? \n";
                    getline(cin, rbm1);
                    rna[d-1].reverse_mutation_RNA(rbm1);

                }else if (b == 2){
                    dna.clear();
                    for (int i = 0; i < g.size(); ++i) {
                        if (g[i].getDna()[0].length() != 0){
                            cout << i+1 << "- " << g[i].getDna()[0] << endl;
                            cout << "   " << g[i].getDna()[1] << endl;
                            dna.push_back(g[i]);
                        }
                    }
                    cout << "-------------------------";
                    cout << "Which DNA? \n";
                    cin >> d;
                    cin.ignore();
                    cout << "Which Nucleobase You Want to reverse? \n";
                    getline(cin, dbm1);
                    dna[d-1].reverse_mutation_DNA(dbm1);
                }else{
                    cout << "Out of Range";
                    goto NEXT;
                }
                break;
            case 7:
                ::system("clear");
                test = false;
                break;
        }
    }
}
void CellMenu(){
    int n;
    cout << "----- Cell Menu ----- \n";
    cout << "1- Receive Chromosome \n";
    cout << "2- Died Cell \n";
    cout << "3- Small Mutation \n";
    cout << "4- Big Mutation \n";
    cout << "5- Reverse Mutation \n";
    cout << "6- Palindrome Mutation \n";
    cout << "7- Back To Main \n";
    cout << "Choose an Option: ";
    cin >> n;

    bool test = true;
    int a, b, d;
    string t1, t2;
    char e1, e2;
    Cell c;
    while (test != false){
        switch (n) {
            case 1:
                ::system("clear");
                cout << "How Many Chromosome Your Cell Have? ";
                cin >> a;
                cin.ignore();
                c.receive_chro(a);
                cell.push_back(c);
                ::system("clear");
                break;
            case 2:
                ::system("clear");
                for (int i = 0; i < cell.size(); ++i) {
                    cell[i].die();
                }
                cout << "All Cells Checked" << endl;
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 3:
                ::system("clear");
                for (int i = 0; i < cell.size(); ++i) {
                    cout << i << "- ";
                    cell[i].show();
                    cout << "***" << endl;
                }
                cout << "Which Cell? ";
                cin >> a;
                cout << "First Char: ";
                cin >> e1;
                cout << "From? ";
                cin >> b;
                cout << "Second Char: ";
                cin >> e2;
                cout << "From? ";
                cin >> d;
                cell[a].small_mutation(e1, e2, b, d);
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 4:
                ::system("clear");
                for (int i = 0; i < cell.size(); ++i) {
                    cout << i << "- ";
                    cell[i].show();
                    cout << "***" << endl;
                }
                cout << "Which Cell? ";
                cin >> a;
                cout << "First Substring: ";
                cin >> t1;
                cout << "From? ";
                cin >> b;
                cout << "Second Substring: ";
                cin >> t2;
                cout << "From? ";
                cin >> d;
                cell[a].big_mutation(t1, b, t2, d);
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 5:
                ::system("clear");
                for (int i = 0; i < cell.size(); ++i) {
                    cout << i << "- ";
                    cell[i].show();
                    cout << "***" << endl;
                }
                cout << "Which Cell? ";
                cin >> a;
                cout << "Substring: ";
                cin >> t1;
                cout << "From? ";
                cin >> b;
                cell[a].reverse_mutation(t1, b);
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 6:
                ::system("clear");
                for (int i = 0; i < cell.size(); ++i) {
                    cout << i << "- ";
                    cell[i].show();
                    cout << "***" << endl;
                }
                cout << "Which Cell? ";
                cin >> a;
                cout << "***" << endl;
                for (int i = 0; i < cell[a].chro.size(); ++i) {
                    cout << i << "- ";
                    cout << cell[a].chro[i].getDNA();
                }
                cout << "Which Chromosome? ";
                cin >> b;
                cell[a].palindrome(b);
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 7:
                ::system("clear");
                test = false;
                break;
        }
    }
}
void AnimalMenu(){
    int n;
    bool test = true;
    while(test != false) {
        cout << "----- Animal Menu ----- \n";
        cout << "1- Similarity Between Chromosomes \n";
        cout << "2- Similarity Between Animal Species \n";
        cout << "3- Asexual Reproduction \n";
        cout << "4- Sexual Reproduction\n";
        cout << "5- Back To Main \n";
        cout << "Choose an Option: ";
        cin >> n;

        int a, b;
        Animal animal;
        switch (n) {
            case 1:
                ::system("clear");
                for (int i = 0; i < cell.size(); ++i) {
                    cout << i << "- ";
                    cell[i].show();
                 }
                cout << "First Cell:";
                cin >> a;
                cout << "Second Cell";
                cin >> b;
                cout << "Similarity Between These Two is:" << animal.similarity(cell[a], cell[b]) << "%" << endl;
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 2:
                ::system("clear");
                for (int i = 0; i < cell.size(); ++i) {
                    cout << i << "- ";
                    cell[i].show();
                }
                cout << "First Cell:";
                cin >> a;
                cout << "Second Cell";
                cin >> b;
                if (animal.SimilarAnimal(cell[a], cell[b]) == true){
                    cout << "They Are Over 70% Similar!" << endl;
                    cout << "Similarity Between These Two is:" << animal.similarity(cell[a], cell[b]) << "%";
                }else{
                    cout << "They Are Not So Similar :(" << endl;
                    cout << "Similarity Between These Two is:" << animal.similarity(cell[a], cell[b]) << "%" << endl;
                }
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 3:
                ::system("clear");
                for (int i = 0; i < cell.size(); ++i) {
                    cout << i << "- ";
                    cell[i].show();
                }
                cout << "Which Cell?";
                cin >> a;
                animal.AsexualReproduction(cell[a]);
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 4:
                ::system("clear");
                for (int i = 0; i < cell.size(); ++i) {
                    cout << i << "- ";
                    cell[i].show();
                }
                cout << "First Cell?";
                cin >> a;
                cout << "Second Cell?";
                cin >> b;
                animal.SexualReproduction(cell[a], cell[b]);
                cout << "Press Enter to Continue";
                cin.ignore();
                ::system("clear");
                break;
            case 5:
                ::system("clear");
                test = false;
                break;
        }
    }
}