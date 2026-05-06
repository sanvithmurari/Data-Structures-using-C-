#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    Node* front;
    Node* rear;
    public:
    Queue(){
        front=rear=NULL;
    }
    bool isEmpty(){
        return !front;
    }

    void enqueue(int val){
        Node* newnode= new Node(val);
        if(isEmpty()){
            front=newnode;
            rear=newnode;
            return;
        }
        rear->next=newnode;
        rear=newnode;
    }
    
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow: Queue is empty!\n";
            return;
        }
        Node* temp=front;
        front=front->next;
        delete temp;
    }

    void peak(){
        if(isEmpty()){
            cout<<"Queue is empty!\n";
            return;
        }
        cout<<"Front element= "<<front->data<<endl;
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty!\n";
            return;
        }
        Node* temp=front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    int choice, value;
    do{
        cout<<"1. Enqueue\n2. Dequeue\n3. Peak\n4. Display\n5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peak();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }    }while(choice!=5);
}