#include<iostream>
using namespace std;

void selectionSort(int a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    cout<<"Selection Sorted array: ";
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int a[],int n){
    int i,j;
    for(i=1;i<n;i++){
        int key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    cout<<"Insertion Sorted array: ";
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}

int main(){
    int a[100],n,i;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }   
    selectionSort(a,n);
    insertionSort(a,n);
    return 0;
}