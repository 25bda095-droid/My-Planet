// Dynamic Programming: Frog Jump with k Distances (DP 4)

// Problem Statement:

// A frog wants to climb a staircase with n steps. 
// Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k. 
// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference.
//  The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. 
// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

# include <climits>
# include <iostream>
using namespace std;

int f(int idx,int k){
    int min_step = INT_MAX;
    int mini = INT_MAX;

    if(idx==0) return 0;

    for(int i=1;i<k;i++){
        if(idx-i>=0){
        int fs = f(idx-i,k) + abs(a[idx]-a[idx-i]);
        mini = min(min_step,fs);
        }
    }

    return mini;

}

int main(){

}


// can we space optimize it - No we cant but we can just make it to O(k) instead of O(n) but what if we put k = n then no use of space optimization so just keep it normal...
