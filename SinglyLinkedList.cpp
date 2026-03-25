#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node* next;
};
template <class T>
class SLL{
    Node* head;
    public:
    SLL(){
        head=NULL;
    }
    void InsertFront(T d);
    void InsertEnd(T d);
    void InsertPosition(T d,int pos);
    void DeleteFront();
    void DeleteEnd();
    void DeletePosition(int pos);
    void Display();
    void Search(T key);
};

template<class T>
void SLL<T>::InsertFront(T d){
    Node* newNode=new Node();
    newNode->data=d;
    newNode->next=head;
    head=newNode;
}