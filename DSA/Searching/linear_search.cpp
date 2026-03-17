//linear search
#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> &arr,int tar){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==tar){
            return i+1;
        }
    }
    return -1;
}
int main(){
    vector <int> arr={5,1,9,2,3,7,4,8};
    cout<<binarysearch(arr,7)<<endl;
}