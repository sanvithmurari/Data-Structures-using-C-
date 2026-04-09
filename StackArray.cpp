//stack using array
#include<iostream>
using namespace std;
class Stack{
    int* arr;
    int top;
    int size;
    public:
    Stack(int s){
        arr=new int[s];
        size=s;
        top=-1;
    }

    void push(int x){
        if(top==size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++top]=x;
    }

    int pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top--];
    }

    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }
    
};

int main(){
    int choice, value,size;
    cout<<"Enter the size of stack: ";
    cin>>size;
    Stack s(size);
    do{
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Check if empty\n5. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to push: ";
                cin>>value;
                s.push(value);
                break;
            case 2:
                cout<<"Popped value: "<<s.pop()<<endl;
                break;
            case 3:
                cout<<"Top value: "<<s.peek()<<endl;
                break;
            case 4:
                if(s.isEmpty()){
                    cout<<"Stack is empty"<<endl;
                }else{
                    cout<<"Stack is not empty"<<endl;
                }
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
}while(choice!=5);
    return 0;
}