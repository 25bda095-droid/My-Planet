#include <algorithm>
#include <climits>
# include <iostream>
using namespace std;

/*
================================================================================
           STRIVER DP-03: FROG JUMP (MINIMUM ENERGY TO REACH STAIR N-1)
================================================================================
Problem Statement:
- A frog stands at index 0 and wants to reach index N-1.
- The frog can jump either 1 step or 2 steps forward at a time.
- Energy consumed in jumping from step i to step j is |heights[i] - heights[j]|.
- Goal: Find the MINIMUM total energy required to reach index N-1.

Recurrence Relation:
  f(ind) = min(
      f(ind - 1) + |heights[ind] - heights[ind - 1]|,   // Option 1: 1-step jump
      f(ind - 2) + |heights[ind] - heights[ind - 2]|    // Option 2: 2-step jump
  )

Base Case:
  f(0) = 0  (Frog is already at index 0, so 0 energy is consumed)
================================================================================
*/

// rough code idea only how we implement this
// Memoization approach
int fun(int idx,int<arr>dp,int <arr> a){
    int right = INT_MAX;
    if(idx==0) return 0;

    if(dp[idx]!=-1) return dp[idx];

    int left = fun(idx-1) + abs(a[idx]-a[idx-1]);
    if(idx>1){
        right = fun(idx-2) + abs(a[idx]-a[idx-2]);
    }

    return min(left,right);

}

// Time Complexity: O(n), since each state (index) is computed once and stored in the DP array.

// Space Complexity: O(n) for the DP array + O(n) recursion stack, leading to O(n) overall.



//Tabulation Approach

int<arr> dp[n];
dp[0]=0;
for(i=1;i<n;i++){
    int fs = dp(idx-1) + abs(a[idx]-a[idx-1]);
    int ss = INT_MAX;
    if(i>1){
        ss = dp(idx-2) + abs(a[idx]-a[idx-2]);
    }

    dp[i] = min(fs,ss);

    return dp(n-1);
}



// Easy way no need of the array here

int prev = 0;
int prev2 = 0
for(i=1;i<n;i++){
    int fs = prev + abs(a[idx]-a[idx-1]);
    int ss = INT_MAX;
    if(i>1){
        ss = prev2 + abs(a[idx]-a[idx-2]);
    }

    curr = min(fs,ss);
    prev2 = prev;
    prev = curr;

    return prev;
}