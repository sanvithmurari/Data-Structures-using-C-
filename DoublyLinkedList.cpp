#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

class DLL{
    Node* head;
    public:
    DLL(){
        head=NULL;
    }

    void InsertFront(int val){
        Node* newnode= new Node(val);
        if(head==NULL){
                head=newnode;
                return;
        }
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }

    void InsertEnd(int val){
        Node* newnode= new Node(val);
        if(head==NULL){
                head=newnode;
                return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }

    void InsertPos(int val, int pos){
        Node* newnode= new Node(val);
        Node* temp= head;
        for(int i=1;i<pos-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(!temp){
            cout<<"Position out of range";
        }
        newnode->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
        }
    }

    void DeleteFront(){
        if(head==NULL){
            cout<<"List is Empty!\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head){
            head->prev=NULL;
        }
        delete temp;
    }

    void DeleteEnd(){
        if(head==NULL){
            cout<<"List is Empty!\n";
            return;
        }
        Node* temp=head;
        if(temp->next==NULL){
            head=NULL;
            delete temp;
            return;
        }
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        delete temp;
    }

    void DeletePos(int pos){
        if(head==NULL){
            cout<<"List is Empty!\n";
            return;
        }
        if(pos==1){
            DeleteFront();
        }
        Node* temp=head;
        for(int i=1;i<pos&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(!temp){
            cout<<"Position out of range";
        }
        if(temp->next){
            temp->next->prev=temp->prev;
        }
        if(temp->prev){
            temp->prev->next=temp->next;
        }
        delete temp;
    }

    void Display(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }

    void Search(int key){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        int i=1;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                cout<<"Element found at position "<<i<<endl;
                return;
            }
            temp=temp->next;
            i++;
        }
        cout<<"Element not found"<<endl;
    }

    void reverse(){
        Node* temp= NULL;
        Node* current=head;
        while(current){
            temp=current->prev;
            current->prev=current->next;
            current->next=temp;
            current=current->prev;
        }
        if(temp!=NULL){
            head=temp->prev;
        }
    }
};

int main(){
    int choice, val, pos;
    DLL dll;
    do{
        cout<<"1. Insert at Front\n2. Insert at End\n3. Insert at Position\n4. Delete from Front\n5. Delete from End\n6. Delete from Position\n7. Display\n8. Search\n9. Reverse\n0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to insert: ";
                cin>>val;
                dll.InsertFront(val);
                break;
            case 2:
                cout<<"Enter value to insert: ";
                cin>>val;
                dll.InsertEnd(val);
                break;
            case 3:
                cout<<"Enter value to insert: ";
                cin>>val;
                cout<<"Enter position: ";
                cin>>pos;
                dll.InsertPos(val, pos);
                break;
            case 4:
                dll.DeleteFront();
                break;
            case 5:
                dll.DeleteEnd();
                break;
            case 6:
                cout<<"Enter position: ";
                cin>>pos;
                dll.DeletePos(pos);
                break;
            case 7:
                dll.Display();
                break;
            case 8:
                cout<<"Enter value to search: ";
                cin>>val;
                dll.Search(val);
                break;
            case 9:
                dll.reverse();
                break;
            case 0:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
}while(choice!=0);
    return 0;
}