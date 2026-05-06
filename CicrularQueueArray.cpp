#include<iostream>
using namespace std;
#define size 5
class Queue{
    public:
    int front,rear;
    int* queue;
    Queue(){
        queue=new int[size];
        front=rear=-1;
    }

    bool isempty(){
        return front==-1;
    }
    void enqueue(int val){
        if((rear+1)%size==front){
            cout<<"Queue is Full!\n";
            return;
        }
        if(isempty()){
            front=rear=0;
        }
        else{
            rear=(rear+1)%size;
        }
        queue[rear]=val;
    }

    void dequeue(){
        if(isempty()){
            cout<<"Queue is Empty\n";
            return;
        }
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }

    void display(){
        if(isempty()){
            cout<<"Queue is Empty\n";
            return;
        }
        for(int i = front; ; i = (i + 1) % size){
            cout << queue[i] << " ";
            if(i == rear)
                break;
        }
        cout << endl;
}
};
int main(){
    Queue q;
    int choice,val;
    do{
        cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice!\n";
        }    }while(choice!=4);
    return 0;
}