#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

class BST{
    public:
    Node* root;

    Node* insert(int val,Node* node){
        if(node==NULL){
            return new Node(val);
        }
        if(val<node->data){
            node->left=insert(val,node->left);
        }
        else{
            node->right=insert(val,node->right);
        }
        return node;
    }

    Node* search(int key,Node* rootnode){
        if(rootnode==NULL){
            return NULL;
        }
        if(key==rootnode->data){
            return rootnode;
        }
        if(key<rootnode->data){
            return search(key,rootnode->left);
        }
        if(key>rootnode->data){
            return search(key,rootnode->right);
        }
    }

    void Preorder(Node* root){
        if(root==NULL) return;
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Inorder(Node* root){
        if(root==NULL) return;
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

    void Postorder(Node* root){
        if(root==NULL) return;
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }

    Node* Min(Node* node){
        while(node->left){
            node=node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node,int key){
        if(node==NULL) return NULL;
        if(key<node->data){
            deleteNode(node->left,key);
        }
        else if(key>node->data){
            deleteNode(node->right,key);
        }
        else{
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                Node*temp=node->right;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                Node*temp=node->left;
                delete node;
                return temp;
            }
            else{
                Node* temp=Min(node->right);
                node->data=temp->data;
                node->right=deleteNode(node->right,temp->data);
            }
        }
    }
};

int main(){
    BST tree;
    int choice,val;
    do{
        cout<<"1. Insert\n2. Search\n3. Preorder\n4. Inorder\n5. Postorder\n6. Delete\n7. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to insert: ";
                cin>>val;
                tree.root=tree.insert(val,tree.root);
                break;
            case 2:
                cout<<"Enter value to search: ";
                cin>>val;
                if(tree.search(val,tree.root)){
                    cout<<"Value found in the tree.\n";
                }
                else{
                    cout<<"Value not found in the tree.\n";
                }
                break;
            case 3:
                cout<<"Preorder traversal: ";
                tree.Preorder(tree.root);
                cout<<endl;
                break;
            case 4:
                cout<<"Inorder traversal: ";
                tree.Inorder(tree.root);
                cout<<endl;
                break;
            case 5:
                cout<<"Postorder traversal: ";
                tree.Postorder(tree.root);
                cout<<endl;
                break;
            case 6:
                cout<<"Enter value to delete: ";
                cin>>val;
                tree.root=tree.deleteNode(tree.root,val);
                break;
            case 7:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    }while(choice!=7);
}