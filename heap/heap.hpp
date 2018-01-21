#ifndef HEAP_H
#define HEAP_H

#include <iostream>

using namespace std;

template <typename E, typename C>
class Heap;

template <typename E>
class node{
public:
    E value;
    node<E>* parent;
    node<E>* left;
    node<E>* right;
    node(){
    parent=NULL;
    left=NULL;
    right=NULL;}
    node(E& e){
    value=e;
    parent=NULL;
    left=NULL;
    right=NULL;}
};

template <typename E, typename C>			// element and comparator
class Heap {         // priority-queue interface

private:
    node<E>* root;
    node<E>* last;
    int size1;
    C comparator;

public:
    Heap(); //Constructor
    int size() const;					// number of elements
    bool isEmpty() const;				// is the queue empty?
    void insert(const E& e);				// insert element
    const E& min() const;		// minimum element
    void removeMin();
    //void val();			// remove minimum
    void mergeHeaps(Heap H); //MODIFIED
    void heapify(E A[], int size2, int root_index);
    node<E>* getRoot();
    void buildHeap(E A[], int size2);
    void deleteHeap(node<E>* head);
    void inorder(E* A,int index, node<E>* head);
    void print_inorder();
    //One function to do the traversal
};

template <typename E, typename C>
Heap<E,C>::Heap(){
root=NULL;
last=NULL;
/*last->parent=NULL;
last->left=NULL;
last->right=NULL;*/
size1=0;};

template <typename E, typename C>
void Heap<E,C> :: deleteHeap(node<E>* head) {
    if (head == NULL) return;
    deleteHeap(head->left);
    deleteHeap(head->right);
    head->left=NULL;
    head->right=NULL;
    head->parent=NULL;
    delete (head);
};

template <typename E, typename C>
int Heap<E,C>::size() const{
    return size1;
};
template <typename E, typename C>
bool Heap<E,C>::isEmpty() const{
if (size1==0)
    return true;
else
    return false;
};

template <typename E,typename C>
node<E>* Heap<E,C>::getRoot(){
return root;};

template <typename E, typename C>
void Heap<E,C>::insert(const E& e){
    node<E>* node1= new node<E>;
    node1->value=e;
    node1->left=NULL;
    node1->right=NULL;
    node1->parent=NULL;
    size1++;
    if (root==NULL)
    {
        root=node1;
        last=node1;
    }
    else{
        node<E>* current= last;
        node<E>* temp= last->parent;
        while (temp!= NULL && temp->left!=current){
            current=current->parent;
            temp=current->parent;
        }
        if (temp==NULL){
            while (current->left!= NULL || current->right!=NULL){
                current=current->left;
            }
        }
        else{
            if (temp->right==NULL){
                current=temp;
            }
            else{
                current=temp->right;
                while (current->left!=NULL || current->right!=NULL){
                    current=current->left;
                }
            }

        }
        if (current->left==NULL){
            current->left=node1;
            node1->parent=current;}
        else{
            current->right=node1;
            node1->parent=current;}
        E tempval;
        node<E>* temp2= node1;
        last=node1;
        while (comparator(temp2->value,current->value) && current!=root){
            tempval=current->value;
            current->value=temp2->value;
            temp2->value=tempval;
            current=current->parent;
            temp2=temp2->parent;
        }
        if (current==root){
            if (comparator(temp2->value,current->value)){
                tempval=current->value;
                current->value=temp2->value;
                temp2->value=tempval;
            }
        }
    }
};

template <typename E,typename C>
const E& Heap<E,C>::min() const{
    if (!isEmpty())
        return root->value;
    else
        cout << "The given heap is empty. Error" << endl;
};

template <typename E,typename C>
void Heap<E,C>::removeMin(){
    if (isEmpty()){
        cout << "The given Heap is empty. Error" << endl;
        return;}
    else if (root==last){
        root=NULL;
        size1=0;
    }
    else{
    E tempval=last->value;
    size1--;
    node<E> *temp= last->parent;
    if (temp->left==last)
        temp->left=NULL;
    else
        temp->right=NULL;
    root->value= tempval;
    node<E>* current= root;
    node<E>* current2= root->left;
    node<E>* current3= root->right;
    while (current2!=NULL){
        if (current3==NULL){
            if (comparator(current2->value,current->value)){
                tempval=current->value;
                current->value=current2->value;
                current2->value=tempval;
            }
            break;
        }
        else{
            if (comparator(current->value,current2->value) && comparator(current->value,current3->value)){
                break;
            }
            else if (!comparator(current->value,current2->value) && !comparator(current->value,current3->value) && comparator(current2->value,current3->value)){
                tempval=current->value;
                current->value=current2->value;
                current2->value=tempval;
                current=current2;
                current2=current->left;
                current3=current->right;
            }
            else if (!comparator(current->value,current2->value) && !comparator(current->value,current3->value) && comparator(current3->value,current2->value)){
                tempval=current->value;
                current->value=current3->value;
                current3->value=tempval;
                current=current3;
                current2=current->left;
                current3=current->right;
            }
            else if (!comparator(current->value,current2->value)){
                tempval=current->value;
                current->value=current2->value;
                current2->value=tempval;
                current=current2;
                current2=current->left;
                current3=current->right;
            }
            else if (!comparator(current->value,current3->value)){
                tempval=current->value;
                current->value=current3->value;
                current3->value=tempval;
                current=current3;
                current2=current->left;
                current3=current->right;
            }
        }
    }
    if (temp->left!=NULL)
        last=temp->left;
    else{
    current=temp;
    temp=temp->parent;
    while (temp!= NULL && temp->right!=current){
        current=current->parent;
        temp=current->parent;
    }
    if (temp==NULL){
        while (current->left!= NULL || current->right!=NULL){
            current=current->right;
        }
    }
    else{
            current=temp->left;
    while (current->left!=NULL || current->right!=NULL){
                current=current->right;
            }
    }
    last=current;}}
};

template <typename E,typename C>
void Heap<E,C>::heapify(E A[], int size2, int root_index){
    int smallest= root_index;
    int lchild= 2*root_index+1;
    int rchild= 2*root_index+2;
    if (lchild < size2 && comparator(A[lchild],A[smallest])){
        smallest=lchild;}
    if (rchild < size2 && comparator(A[rchild],A[smallest])){
        smallest= rchild;}
    if (smallest!=root_index){
        E temp=A[root_index];
        A[root_index]=A[smallest];
        A[smallest]=temp;
        heapify(A,size2,smallest);
    }
};

template <typename E,typename C>
void Heap<E,C>::inorder(E A[],int index, node<E>* head){
    if (head==NULL)
        return;
    inorder(A,index*2+1,head->left);
    A[index]=head->value;
    //cout << head->value << endl;
    inorder(A,index*2+2,head->right);
};


template <typename E,typename C>
void Heap<E,C>::print_inorder(){
    E A[size1];
    /*for (int i=0;i<size1;i++)
        A[i]=0;*/
    inorder(A,0,root);
    for (int i=0;i<size1;i++)
        cout << A[i] << endl;
};

template <typename E,typename C>
void Heap<E,C>::mergeHeaps(Heap H){
    int size2=H.size();
    int total=size1+size2;
    node<E>* head= H.getRoot();
    E A[size1];
    E B[size2];
    E arr[total];
    inorder(A,0,root);
    inorder(B,0,head);
    for (int i=0;i<size1;i++){
        arr[i]=A[i];
    }
    for (int i=size1;i<total;i++){
        arr[i]=B[i-size1];
    }
    buildHeap(arr,total);
};


template <typename E,typename C>
void Heap<E,C>::buildHeap(E A[], int size2){
    for (int i= size2/2-1;i>=0;i--){
        heapify(A,size2,i);
    }
    node<E>** heap1;
    //deleteHeap(root);
    heap1=new node<E>*[size2];
    for (int i=0;i<size2;i++){
    heap1[i]=new node<E>;}
    heap1[0]->value=A[0];
    root=heap1[0];
    for (int i=1;i<size2;i++){
	heap1[i]->value=A[i];
	if (i%2==1){
		heap1[(i-1)/2]->left=heap1[i];
		heap1[i]->parent=heap1[(i-1)/2];
		}
	else{
		heap1[(i-2)/2]->right=heap1[i];
		heap1[i]->parent=heap1[(i-2)/2];}
	}
   last=heap1[size2-1];
   size1=size2;

return;
};

#endif
