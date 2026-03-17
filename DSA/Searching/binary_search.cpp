//Binary Search
#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &arr,int low,int high,int tar){
    int mid=low+(high-low)/2;
    if(arr[mid]==tar){
        return mid;
    }
    if(arr[mid]>=tar){
        return binary_search(arr,0,mid-1,tar);
    }
    else{
        return binary_search(arr,mid+1,high,tar);
    }
}

int main(){
    vector <int> arr={2,3,6,8,9,11,13};
    cout<<binary_search(arr,0,arr.size(),9)+1<<endl;
}
