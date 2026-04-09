#include<iostream>
using namespace std;
class Queue{
    private:
        int front;
        int rear;
        int size;
        int *queue;
    public:
        Queue(int c){
            front = rear = 0;
            size = c;
            queue = new int[size];
        }

        void enqueue(int data){
            if(rear == size){
                cout<<"Queue is full"<<endl;
                return;
            }
            queue[rear] = data;
            rear++;
        }

        void dequeue(){
            if(front == rear){
                cout<<"Queue is empty"<<endl;
                return;
            }
            for(int i=0; i<rear-1; i++){
                queue[i] = queue[i+1];
            }
            rear--;
        }

        void display(){
            if(front == rear){
                cout<<"Queue is empty"<<endl;
                return;
            }
            for(int i=front; i<rear; i++){
                cout<<queue[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    int choice, data,size;
    cout<<"Enter the size of the queue: ";
    cin>>size;
    Queue q(size);
    do{
        cout<<"1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter data to enqueue: ";
                cin>>data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice!=4);
    return 0;
}