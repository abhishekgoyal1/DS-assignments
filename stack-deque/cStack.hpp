#ifndef CSTACK_H
#define CSTACK_H

#include <iostream>

using namespace std;

template <typename E>
class cStack {		// an interface for a stack

private:
    int *arr;
    int top_red;
    int top_blue;
    int capacity;
public:
    cStack(int cap = 100);		// constructor from capacity
    int redsize() const;		// number of items in stack
    bool redempty() const;		// is the stack empty?
    const E& redtop() const;	      		// the top element
    void redpush(const E& e); 		// push x onto the stack
    void redpop();		      	// remove the top element
    int bluesize() const;               // number of items in stack
    bool blueempty() const;             // is the stack empty?
    const E& bluetop() const;           // the top element
    void bluepush(const E& e);          // push x onto the stack
    void bluepop();                     // remove the top element
 };

template <typename E>
cStack<E>::cStack(int cap){
    arr= new E[cap];
    capacity=cap;
    top_red=-1;
    top_blue=capacity;};

template <typename E>
int cStack<E>::redsize() const{
    return top_red +1;
};

template <typename E>
bool cStack<E>::redempty() const{
    if (top_red==-1)
        return true;
    else
        return false;
};

template <typename E>
const E& cStack<E>::redtop() const{
    if (redempty()){
        cout << "No element found" << endl;
        //return;
        }
    else
        return arr[top_red];
};

template <typename E>
void cStack<E>::redpush(const E& e){
    top_red++;
    arr[top_red]= e;
};

template <typename E>
void cStack<E>::redpop(){
    if (redempty())
        cout << "The red stack is empty" << endl;
    else{
        top_red--;}
};

template <typename E>
int cStack<E>::bluesize() const{
    return 100-top_blue;
};

template <typename E>
bool cStack<E>::blueempty() const{
    if (top_blue==100)
        return true;
    else
        return false;
};

template <typename E>
const E& cStack<E>::bluetop() const{
    if (blueempty()){
        cout << "No element found" << endl;}
    else
        return arr[top_blue];
};

template <typename E>
void cStack<E>::bluepush(const E& e){
    top_blue--;
    arr[top_blue]= e;
};

template <typename E>
void cStack<E>::bluepop(){
    if (blueempty())
        cout << "The blue stack is empty" << endl;
    else{
        top_blue++;}
};



#endif
