#include <iostream>
#include <vector>
using namespace std;

vector <int> bubblesort(vector<int> arr){
    int n=sizeof(arr)/sizeof(int);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}

int main(){
    vector<int> arr={3,2,8,4,5,1,7};
    vector<int> print=bubblesort(arr);
    for(int i=0;i<print.size();i++){
        cout<<print[i]<<" ";
    }
    cout<<endl;
}