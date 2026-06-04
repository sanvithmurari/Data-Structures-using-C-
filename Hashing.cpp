#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};
class HashTable{
    int size;
    Node** table;
    public:
    HashTable(int s){
        size=s;
        table-new Node*[size];
        for(int i=0;i<size;i++){
            table[i]=NULL;
        }
    }

    int hashFunction(int key){
        return key%size;
    }

    void insert(int key){
        int index=hashFunction(key);
        Node* newnode=new Node(key);
        newnode->next=table[index];
        table[index]=newnode;
    }

    void search(int key){
        int index=hashFunction(key);
        Node* temp=table[index];
        while(temp){
            if(key==temp->data){
                cout<<"Found in table";
                return;
            }
            temp=temp->next;
        }
        cout<<"Not found";
    }

    void remove(int key){
        int index=hashFunction(key);
        Node* temp=table[index];
        Node* prev=NULL;
        while(temp && temp->data!=key){
            prev=temp;
            temp=temp->next;
        }
        if (temp == NULL) {
            cout << key << " not found, cannot delete." << endl;
            return;
        }
        if(prev==NULL){
            table[index]=temp->next;
        }
        else{
            prev->next=temp->next;
        }
        delete temp;
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    int size, choice, key;
    cout << "Enter size of hash table: ";
    cin >> size;
    HashTable ht(size);
    do {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;

            case 4:
                ht.display();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
}

