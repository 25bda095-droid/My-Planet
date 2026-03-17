//merge sort
#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int> &arr,int start,int mid,int end){
    vector<int> temp;
    int left=start;
    int right=mid+1;

    while(left<=mid && right<=end){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=end){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=start;i<=end;i++){
        arr[i]=temp[i-start];
    }
}

void mergesort(vector<int> &arr,int start,int end){
    if(start>=end){
        return;
    }

    int mid=start+(end-start)/2;
    
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);

    merge(arr,start,mid,end);
}

int main(){
    vector<int> arr={3,2,8,4,5,1,7};
    mergesort(arr,0,arr.size()-1);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}