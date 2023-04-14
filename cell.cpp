#include "cell.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string complement(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='A')
            s[i]='T';
        else if(s[i]=='C')
            s[i]='G';
        else if(s[i]=='T')
            s[i]='A';
        else if(s[i]=='G')
            s[i]='C';
    }
    return s;
}
//string(1,s[s.size()-i-1] this is used to change a char to string and store in x.
bool is_palidrome(string s){
    for(int i=0;i<s.size()/2;i++){
        string x=complement(string(1,s[s.size()-i-1]));
        if(s[i]!=x[0])
            return false;
    }
    return true;
}
class Gene{
public:
    string RNA;
    string DNA[2];

    void make_DNA(string s);

    void small_mutation_RNA(char a,char b,int n);
    void small_mutation_DNA(char a,char b,int n);

    void big_mutation_RNA(string s1,string s2);
    void big_mutation_DNA(string s1,string s2);

    void reverse_mutation_RNA(string s);
    void reverse_mutation_DNA(string s);
};
void Gene::make_DNA(string s){
    DNA[0]=s;
    DNA[1]=complement(s);
}
//flag counts the number of mutation.
void Gene:: small_mutation_RNA(char a,char b,int n){
    int flag=0;
    for(int i=0;i<RNA.size();i++){
        if(RNA[i]==a && flag<n){
            RNA[i]=b;
            flag++;
        }
    }
}
void Gene::small_mutation_DNA(char a,char b,int n){
    int flag=0;
    for(int i=0;i<DNA[0].size();i++){
        if((DNA[0][i]==a || DNA[1][i]==a)&& flag<n){
            if(DNA[0][i]==a){
                DNA[0][i]=b;
                string x=complement(string(1,b));
                DNA[1][i]=x[0];
                flag++;
            }
            else{
                DNA[1][i]=b;
                string x=complement(string(1,b));
                DNA[0][i]=x[0];
                flag++;
            }
        }
    }
}
void Gene::big_mutation_RNA(string s1,string s2){
    int pos=RNA.find(s1);
    RNA.replace(pos,s1.size(),s2);
}
/*s2 is the string that we want to replace with it if s1 is found  in the DNA.
  beacuse priority,I set the position that founds s1 in DNA to maximum size of DNA instead of -1 and it means that 
  we can not found s1 in DNA.*/
void Gene::big_mutation_DNA(string s1,string s2){
    int pos1=DNA[0].size(),pos2=DNA[1].size();
    if(DNA[0].find(s1)!=string::npos)
        pos1=DNA[0].find(s1);
    if(DNA[1].find(s1)!=string::npos)
        pos2=DNA[1].find(s1);
    if(pos1<pos2){
        DNA[0].replace(pos1,s1.size(),s2);
        string temp=complement(s2);
        DNA[1].replace(pos1,s1.size(),temp);
    }
    else{
        DNA[1].replace(pos2,s1.size(),s2);
        string temp=complement(s2);
        DNA[0].replace(pos2,s1.size(),temp);
    }
}
void Gene::reverse_mutation_RNA(string s){
    if(RNA.find(s)!=string::npos){
        int pos=RNA.find(s);
        reverse(s.begin(),s.end());
        RNA.replace(pos,s.size(),s);
        cout<<RNA;
    }
    else
        cout<<"NOT FOUND!";
}
/* pos1 and pos2 are like what we have in big mutation.
   After finding s1 in DNA, we reverse s1 and put it in DNA.*/
void Gene::reverse_mutation_DNA(string s){
    int pos1=DNA[0].size(),pos2=DNA[1].size();
    if(DNA[0].find(s)!=string::npos)
        pos1=DNA[0].find(s);
    if(DNA[1].find(s)!=string::npos)
        pos2=DNA[1].find(s);

    reverse(s.begin(),s.end());
    string temp=complement(s);
    if(pos1<pos2){
        DNA[0].replace(pos1,s.size(),s);
        DNA[1].replace(pos1,s.size(),temp);
    }
    else{
        DNA[1].replace(pos2,s.size(),s);
        DNA[0].replace(pos2,s.size(),temp);
    }
}
class Cell{
public:
    vector<Gene>chro;

    void show();

    void receive_chro(int n);
    void die();
    void small_mutation(char a,char b,int n,int m);
    void big_mutation(string s1,int n,string s2,int m);
    void reverse_mutation(string s,int n);
    void palindrome(string s);
};
void Cell:: show(){
    for(int i=0;i<chro.size();i++){
        cout<<chro[i].DNA[0]<<endl
            <<chro[i].DNA[1]<<endl;

    }

}
void Cell::receive_chro(int n){
    Gene g;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        g.DNA[0]=s1;
        g.DNA[1]=s2;
        chro.push_back(g);
    }
}
/* count: counts the number of chars in DNA that do not form a bond (does not match their complement)
   count_AT: counts the number of A or T nucleotides.
   count_CG: counts the number of C or G nucleotides.
   count>5 or count_AT>3*count_CG: condition of death of a cell.
*/
void Cell::die(){
    int count=0,count_AT=0,count_CG=0;
    for(int i=0;i<chro.size();i++){
        for(int j=0;j<chro[i].DNA[0].size();j++){
            string x=complement(string(1,chro[i].DNA[1][j]));
            if(chro[i].DNA[0][j]!=x[0])
                count++;
            if(chro[i].DNA[0][j]=='A'||chro[i].DNA[0][j]=='T')
                count_AT++;
            else
                count_CG++;
        }
        if(count>5 || count_AT>3*count_CG)
            chro.erase(chro.begin()+i);
    }
    show();
}
// m=m-1: It is used only to convert the i-th chromosome to its index.
//flag: counts the number of mutation.
void Cell::small_mutation(char a,char b,int n,int m){
    m=m-1;
    int flag=0;
    string x=complement(string(1,b));
    for(int i=0;i<chro[m].DNA[0].size();i++){
        if((chro[m].DNA[0][i]==a || chro[m].DNA[1][i]==b)&& flag<n){
            if(chro[m].DNA[0][i]==a){
                chro[m].DNA[0][i]=b;
                chro[m].DNA[1][i]=x[0];
            }
            else{
                chro[m].DNA[1][i]=b;
                chro[m].DNA[0][i]=x[0];
            }
        }
    }
    show();
}
void Cell::big_mutation(string s1,int n,string s2,int m){
    n=n-1;
    m=m-1;
    int posn1=chro[n].DNA[0].size();
    int posn2=chro[n].DNA[1].size();
    int posm1=chro[m].DNA[0].size();
    int posm2=chro[m].DNA[1].size();
    if(chro[n].DNA[0].find(s1)!=string::npos)
        posn1=chro[n].DNA[0].find(s1);
    if(chro[n].DNA[1].find(s1)!=string::npos)
        posn2=chro[n].DNA[1].find(s1);
    if(chro[m].DNA[0].find(s2)!=string::npos)
        posm1=chro[m].DNA[0].find(s2);
    if(chro[m].DNA[1].find(s2)!=string::npos)
        posm2=chro[m].DNA[1].find(s2);
    if(posn1<posn2){
        chro[n].DNA[0].replace(posn1,s1.size(),s2);
        chro[n].DNA[1].replace(posn1,s1.size(),complement(s2));
    }
    else{
        chro[n].DNA[1].replace(posn2,s1.size(),s2);
        chro[n].DNA[0].replace(posn2,s1.size(),complement(s2));
    }
    if(posm1<posm2){
        chro[m].DNA[0].replace(posm1,s2.size(),s1);
        chro[m].DNA[1].replace(posm1,s2.size(),complement(s1));
    }
    else{
        chro[m].DNA[1].replace(posm2,s2.size(),s1);
        chro[m].DNA[0].replace(posm2,s2.size(),complement(s1));
    }
    show();
}
void Cell::reverse_mutation(string s,int n){
    int pos1=chro[n-1].DNA[0].size();
    int pos2=chro[n-1].DNA[1].size();
    if(chro[n-1].DNA[0].find(s)!=string::npos)
        pos1=chro[n-1].DNA[0].find(s);
    if(chro[n-1].DNA[1].find(s)!=string::npos)
        pos2=chro[n-1].DNA[1].find(s);
    reverse(s.begin(),s.end());
    string temp=complement(s);
    if(pos1<pos2){
        chro[n-1].DNA[0].replace(pos1,s.size(),s);
        chro[n-1].DNA[1].replace(pos1,s.size(),temp);
    }
    else{
        chro[n-1].DNA[1].replace(pos2,s.size(),s);
        chro[n-1].DNA[0].replace(pos2,s.size(),temp);
    }
    show();
}
// First, we find all the substrings and after making sure that they are palindromes, we print them.
void Cell::palindrome(string s){
    for(int i=0;i<s.size();i++){
        string temp="";
        temp+=s[i];
        for(int j=i;j<s.size()-1;j++){
            temp+=s[j+1];
            if(is_palidrome(temp) && temp.size()>2 && temp.size()%2==0)
                cout<<temp<<endl;
        }

    }
}
 