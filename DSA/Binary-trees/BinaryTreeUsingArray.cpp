#include <iostream>
using namespace std;

void preorder(int* arr,int size,int n=0){
    if(n>=size){
        return;
    }
    if(arr[n]!=NULL){
    cout<<arr[n]<<" ";
}
    preorder(arr,size,2*n+1);
    preorder(arr,size,2*n+2);
};
void postorder(int* arr,int size,int n=0){
    if(n>=size){
        return;
    }
    postorder(arr,size,2*n+1);
    postorder(arr,size,2*n+2);
    if(arr[n]!=NULL){
    cout<<arr[n]<<" ";
}
};

void inorder(int* arr,int size,int n=0){
    if(n>=size){
        return;
    }
    inorder(arr,size,2*n+1);
    if(arr[n]!=NULL){
    cout<<arr[n]<<" ";
}
    inorder(arr,size,2*n+2);
};




int main(){
    int arr[]={
  10,                          // Level 0 (Index 0)
  20,30,                      // Level 1 (Indices 1-2)
  40,NULL,NULL,70,          // Level 2 (Indices 3-6)
  80,90,NULL,NULL,NULL,NULL,140,150 // Level 3 (Indices 7-14)
};
int size=sizeof(arr)/sizeof(int);
preorder(arr,size);
cout<<endl;
postorder(arr,size);
cout<<endl;
inorder(arr,size);
}