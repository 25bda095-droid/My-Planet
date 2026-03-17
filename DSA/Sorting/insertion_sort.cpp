//insertion sort
#include <iostream>
#include <vector>
using namespace std;


vector<int> insertionsort(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    return arr;
}


int main(){
    vector<int> arr={3,2,8,4,5,1,7};
    vector<int> print=insertionsort(arr);
    for(int i=0;i<print.size();i++){
        cout<<print[i]<<" ";
    }
    cout<<endl;
}