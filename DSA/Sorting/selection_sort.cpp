//selection sort algorithm
#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionsort(vector<int> arr){
    for(int i = 0;i<arr.size()-1;i++){
        int min_index = i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        if(min_index!=i){
        swap(arr[i],arr[min_index]);
        }
    }
    return arr;
}


int main(){
    vector<int> arr={5,3,8,2,6,9,0};
    vector<int> print = selectionsort(arr);
    for(int i = 0;i<print.size();i++){
        cout<<print[i]<<" ";
    }
    cout<<endl;
}