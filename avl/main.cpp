#include <iostream>
#include <fstream>
#include "mavl.hpp"


using namespace std;

int main(){
    MAVLTree A;
    int temp1;
    string temp2;
    ifstream file;
    file.open("entries.txt");
    while (file >> temp1){
        file >> temp2;
        //cout << temp1 << endl << temp2;
        A.insert(temp1,temp2);}
    file.close();
    cout << A.size();

    /*A.insert(5,"abc");
    A.insert(3,"qwe");
    A.insert(2,"qaz");
    A.insert(7,"qwet");
    A.insert(9,"qaz");
    A.insert(4,"qwf");
    A.insert(1,"qazds");
    A.insert(42,"qasd");
    A.insert(52,"abc");
    A.insert(72,"qwes");
    A.insert(8,"qaz");
    A.insert(6,"qwe");
    A.insert(54,"qaz");
    A.insert(84,"qaer");
    A.insert(69,"qvds");
    //A.remove(5);
    //A.remove(1);
    //cout << A.get_place(5);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    A.delete_by_place(1);
    //A.remove(7);
    //A.remove(2);
    //A.remove(69);
    //A.remove(54);
    //A.remove(2);
    //A.remove(3);
    //A.remove(4);
    //A.remove(9);
    cout << A.size() << endl;
    //cout << A.size() << endl;
    //A.print();*/
};

