#include <iostream>
#include <string>
#include <sstream>
#include<fstream>
#include "number_map.hpp"
#include "name_map.hpp"

using namespace std;

int main(){
    long long int temp1;
    int temp2;
    Number_Map<long long int,int> B;
    ifstream file;
    file.open("numbers.txt");
    while (file >> temp1){
        file >> temp2;
        B.put(temp1,temp2);}
    file.close();
    ofstream myfile1;
    myfile1.open("EntryNumOutput.txt",ios_base::app);
    if (myfile1.is_open())
        {
    myfile1 << "\n \n";
    myfile1 << "NUMBER OF COLLISIONS FOR NUMBER MAP:- \n\n";
    myfile1 << "          DIV  MAD  MUL\n";
    myfile1 << "INT_CAST: ";
    for (int i=0;i<3;i++){
        myfile1 << B.col_num(i) << " ";
        }
    myfile1 << "\n";
    myfile1 << "COMP_SUM: ";
    for (int i=3;i<6;i++){
        myfile1 << B.col_num(i) << " ";
        }
    myfile1 << "\n";
    myfile1 << "POL_SUM:  ";
    for (int i=6;i<9;i++){
        myfile1 << B.col_num(i) << " ";
        }
    myfile1 << "\n";
    myfile1 << "CYCL_SUM: ";
    for (int i=9;i<12;i++){
        myfile1 << B.col_num(i) << " ";
        }
    myfile1 << "\n";
    myfile1.close();}
    else cout << "Unable to open file";

    string line;
    string t1, t2="";
    ifstream myfile;
    myfile.open("names.txt");
    Name_Map<string,string> C;
    int i=0;
    //int count=0;
    if (myfile.is_open()){
    while ( getline (myfile,line) )
    {
        istringstream iss(line);
        string word;
        iss >> word;
        t1 = word;
        word= "";
        while (iss){
            if (i!=0){
                t2+=word+" ";}
            iss >> word;
            i=1;
        }
        //t2=t2-word;
        /*for(string s; iss >> s; ){
        if (i==0){
            t1=s;
        }
        else {
            t2=t2+s;
        }
        }*/
        C.put(t1,t2);
        //count++;
        i=0;
        t2="";
    }
    myfile.close();
    }
    ofstream myfile2;
    myfile2.open("EntryNumOutput.txt",ios_base::app);
    if (myfile2.is_open())
        {
    myfile2 << "\n \n";
    myfile2 << "NUMBER OF COLLISIONS FOR NAME MAP:- \n\n";
    myfile2 << "           DIV  MAD  MUL\n";
    myfile2 << "INT_CAST: ";
    for (int i=0;i<3;i++){
        myfile2 << C.col_num(i) << " ";
        }
    myfile2 << "\n";
    myfile2 << "COMP_SUM: ";
    for (int i=3;i<6;i++){
        myfile2 << C.col_num(i) << " ";
        }
    myfile2 << "\n";
    myfile2 << "POL_SUM:  ";
    for (int i=6;i<9;i++){
        myfile2 << C.col_num(i) << " ";
        }
    myfile2 << "\n";
    myfile2 << "CYCL_SUM: ";
    for (int i=9;i<12;i++){
        myfile2 << C.col_num(i) << " ";
        }
    myfile2 << "\n";

    myfile2.close();}
    else cout << "Unable to open file";

    //cout <<B.find(9465586305);
    int input;
    long long input1;
    string input2;
    cout << "Please enter 1 to know balance of a phone number and 2 to know meaning of a name. Enter 0 to exit:\n";
    cin >> input;
    while (input!=0){
    if (input==1){
        cout << "Please enter number:\n";
        cin >> input1;
        cout << "Number= " << input1 << ", Balance= INR " << B.find(input1) << endl;
    }
    else if (input==2){
        cout << "Please enter name:\n";
        cin >> input2;
        cout << "Name= " << input2 << ", Meaning= " << C.find(input2) << endl;
    }
    cout << "Please enter 1 to know balance of a phone number and 2 to know meaning of a name. Enter 0 to exit:\n";
    cin >> input;
    }
};
