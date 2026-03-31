#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
    }
};

class SLL{
    Node* head;
    public:
    SLL(){
        head=NULL;
    }
    void InsertFront(int d){
        Node* newNode=new Node(d);
        if (head==NULL){
            head=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }

    void InsertEnd(int d){
        Node* newNode=new Node(d);
        if(head==NULL){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void InsertPosition(int d,int pos){
        Node* newNode=new Node(d);
        if(pos==1){
            InsertFront(d);
            return; 
        }
        Node* temp=head;
        for(int i=1;i<pos-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Invalid position"<<endl;
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void DeleteFront(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    void DeleteEnd(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }
        Node* temp=head;
        while(temp->next->next!=NULL){ 
        temp=temp->next;
    }
        delete temp->next;  
        temp->next=NULL;    
        }

    void DeletePosition(int pos){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(pos==1){
            DeleteFront();
            return;
        }
        Node* temp=head;
        for(int i=1;i<pos-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL||temp->next==NULL){
            cout<<"Invalid position"<<endl;
            return;
        }
        Node* nodeToDelete=temp->next;
        temp->next=temp->next->next;
        delete nodeToDelete;
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
};

int main(){
    int choice,val,pos;
    SLL list;
    do{
        cout<<"1. Insert at front"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Insert at position"<<endl;
        cout<<"4. Delete from front"<<endl;
        cout<<"5. Delete from end"<<endl;
        cout<<"6. Delete from position"<<endl;
        cout<<"7. Display"<<endl;
        cout<<"8. Search"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to insert: ";
                cin>>val;
                list.InsertFront(val);
                break;
            case 2:
                cout<<"Enter value to insert: ";
                cin>>val;
                list.InsertEnd(val);
                break;
            case 3:
                cout<<"Enter value to insert: ";
                cin>>val;
                cout<<"Enter position: ";
                cin>>pos;
                list.InsertPosition(val,pos);
                break;
            case 4:
                list.DeleteFront();
                break;
            case 5:
                list.DeleteEnd();
                break;
            case 6:
                cout<<"Enter position to delete: ";
                cin>>pos;
                list.DeletePosition(pos);
                break;
            case 7:
                list.Display();
                break;
            case 8:
                cout<<"Enter element to search: ";
                cin>>val;
                list.Search(val);
                break;
            case 9:
                choice=0;
        }
    }while(choice!=0);
}
