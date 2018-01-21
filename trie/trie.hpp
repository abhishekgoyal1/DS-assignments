#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <queue>

using namespace std;


class node {
    public:
    bool fullstop;
    int number;
    node* children[26];
    node(){
        fullstop=false;
        number=0;
        for (int i=0;i<26;i++){
            children[i]= NULL;
        }
    }
};

class Trie{
private:
    node* root;
public:
    Trie();
    void insert(string s,int no);
    void search(string s);
    int count_match(node* head);

};

Trie::Trie(){
    root= new node();
}

void Trie::insert(string s,int no){
    node* temp=root;
    int index;
    for (int i=0;i<s.length();i++){
        index= s[i]-'a';
        temp->children[index]=new node;
        temp= temp->children[index];
    }
    temp->fullstop=true;
    temp->number=no;
}
int Trie::count_match(node* head){
    int count1=0;
    node* temp= head;

};
void Trie::search(string s){
    node* temp=root;
    node* temp2;
    int check=0;
    int index;
    index= s[0]-'a';
    int i=0;
    temp2= temp->children[index];
    while (temp2!= NULL){
        cout << i << endl;
        i++;
        temp=temp2;
        if (i==s.length()){
            check=1;
            break;
        }
        index= s[i]- 'a';
        temp2= temp->children[index];
    }
    if (check==0){
        cout << "Contact not found" << endl;
        return;
    }
    else{
        if (temp->fullstop){
            cout << "Found contact with the specified name: " << endl;
            cout << s << " " << temp->number << endl;
        }
        else{
            queue<node*> A;
            int count1=0;
            for (int i=0;i<26;i++){
                if (temp->children[i]!=NULL){
                    A.push(temp->children[i]);}
                    }
            while (!A.empty()){
                temp2=A.front();
                if (temp2->fullstop){
                    count1++;
                }
                A.pop();
                for (int i=0;i<26;i++){
                if (temp2->children[i]!=NULL){
                    A.push(temp2->children[i]);
                }}
            }
            cout << endl << count1 << endl;
        }
    }
}


#endif
