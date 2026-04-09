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

class Stack{
    public:
    Node* top;
    Stack(){
        top=NULL;
    }
    bool isEmpty(){
        return top==NULL;
    }
    void push(int val){
        Node* newnode=new Node(val);
        if(isEmpty()){
            top=newnode;
        }
        else{
            newnode->next=top;
            top=newnode;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Empty Stack\n";
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    void peek(){
        if(isEmpty()){
            cout<<"Empty\n";
            return;
        }
        cout<<"Top Element is "<<top->data<<endl;
    }
    
    void display(){
        if(isEmpty()){
            cout<<"Empty Stack\n";
            return;
        }
        Node* temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Stack s;
    int choice,value;
    cout<<"Enter your choice ";
    do{
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to push: ";
                cin>>value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice\n";
        }
    }while(choice!=5);
}
