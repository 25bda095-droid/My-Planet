//quick sort
#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &arr,int low,int high){
    
    int pivot = arr[low+(high-low)/2];
    int i=low;
    int j=high;

    while(i<=j){
        while(arr[i]<pivot){
            i++;
    }
        while(arr[j]>pivot){
            j--;
    }
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
    }
}
    if(low<j) quick_sort(arr,low,j);
    if(i<high) quick_sort(arr,i,high);
}

int main(){
    vector<int> arr={3,9,1,6,2,4,7};
    quick_sort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}