#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include "cStack.hpp"

template <typename E>
class Deque {

private:
    cStack<E> A,B;
public:
    Deque();				// constructor
    int size() const;				// number of items in the deque
    bool empty() const;				// is the deque empty?
    const E& front(); // the first element
    const E& back();	// the last element
    void insertFront(const E& e);		// insert new first element
    void insertBack(const E& e);		// insert new last element
    void removeFront();	// remove first element
    void removeBack();	// remove last element
  };

template <typename E>
Deque<E>::Deque(){

};


template <typename E>
int Deque<E>::size() const{
return A.redsize()+A.bluesize()+B.redsize();};


template <typename E>
bool Deque<E>::empty() const{
if (A.redempty() && A.blueempty() && B.redempty())
    return true;
else
    return false;
};

template <typename E>
const E& Deque<E>::front(){
    if (!A.redempty()){
        return A.redtop();
    }
    else if (!A.blueempty()){
        E temp;
        while (!A.blueempty()){
            temp= A.bluetop();
            A.redpush(temp);
            A.bluepop();
        }
        return A.redtop();
    }
    else if (!B.redempty()){
        while (!B.redempty()){
            A.bluepush(B.redtop());
            B.redpop();
        }
        return A.bluetop();
    }
    else{
        cout << "The Deque is empty. Error" << endl;
    }

};

template <typename E>
const E& Deque<E>::back(){
    if (!B.redempty()){
        return B.redtop();
    }
    else if (!A.blueempty()){
        //E temp;
        while (!A.blueempty()){
            B.redpush(A.bluetop());
            A.bluepop();
        }
        return B.redtop();
    }
    else if (!A.redempty()){
        while (!A.redempty()){
            A.bluepush(A.redtop());
            A.redpop();
        }
        return A.bluetop();
    }
    else{
        cout << "The Deque is empty. Error" << endl;
    }
};

template <typename E>
void Deque<E>::insertFront(const E& e){
A.redpush(e);};

template <typename E>
void Deque<E>::insertBack(const E& e){
B.redpush(e);};

template <typename E>
void Deque<E>::removeFront(){
    if (!A.redempty()){
        A.redpop();
    }
    else if (!A.blueempty()){
        //E temp;
        while (!A.blueempty()){
            A.redpush(A.bluetop());
            A.bluepop();
        }
        A.redpop();
    }
    else if (!B.redempty()){
        while (!B.redempty()){
            A.bluepush(B.redtop());
            B.redpop();
        }
        A.bluepop();
    }
    else{
        cout << "The Deque is empty. Error" << endl;
    }

};

template <typename E>
void Deque<E>::removeBack(){
    if (!B.redempty()){
        B.redpop();
    }
    else if (!A.blueempty()){
        //E temp;
        while (!A.blueempty()){
            B.redpush(A.bluetop());
            A.bluepop();
        }
        B.redpop();
    }
    else if (!A.redempty()){
        while (!A.redempty()){
            A.bluepush(A.redtop());
            A.redpop();
        }
        A.bluepop();
    }
    else{
        cout << "The Deque is empty. Error" << endl;
    }
};



#endif
