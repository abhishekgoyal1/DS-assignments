#include <iostream>
#include <fstream>
#include "trie.hpp"


using namespace std;

int main(){
    Trie A;
    string temp1;
    int temp2;
    ifstream file;
    file.open("name_number.txt");
    while (file >> temp1){
        file >> temp2;
        cout << temp1 << endl << temp2 << endl;
        //cout << temp1 << endl << temp2;
        A.insert(temp1,temp2);}
    file.close();
    A.search("Aachman");
    }
