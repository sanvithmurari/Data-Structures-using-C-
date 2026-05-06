#include<iostream>
using namespace std;
class Queue{
    int front,rear,size;
    int *queue;
    public: 
    Queue(){
        size=100;
        queue=new int(size);
        front=rear=-1;
    }

    bool isEmpty(){
        return front==-1 || front>rear;
    }

    void enqueue(int val){
        if(rear==size-1){
            cout<<"Queue Overflow: Queue is full!\n";
            return;
        }
        if(isEmpty()){
            front=0;
        }
        rear++;
        queue[rear]=val;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow: Queue is empty!\n";
            return;
        }
        front++;
        if(front>rear){
            front=rear=-1;
        }
    }

    int peak(){
        return queue[front];
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty!\n";
            return;
        }
        cout<<"QUEUE ELEMENTS: ";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){ 
    Queue q;
    int choice,value;
    cout<<"1. Enqueue\n2. Dequeue\n3. Peak\n4. Display\n5. Exit\n";
    do{
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
                if(!q.isEmpty()){
                    cout<<"Front element: "<<q.peak()<<endl;
                } else {
                    cout<<"Queue is empty!\n";
                }
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    } while(choice!=5); 
}