// Ninja Training

// A Ninja has to train for N days. Each day, the Ninja can perform one of 3 activities:

// Running
// Fighting Practice
// Learning New Moves

// Each activity gives the Ninja a certain number of points on each day. However, the Ninja cannot perform the same activity on two consecutive days.

// You are given a 2D array points, where:

// points[i][0] = points for Running on day i
// points[i][1] = points for Fighting Practice on day i
// points[i][2] = points for Learning New Moves on day i

// Your task is to determine the maximum total points the Ninja can earn over all N days.

#inlcude <iostream>
#include <vector>
using namespacestd;

class Solution {
public:

    int starting(vector<vector<int>>& matrix,int day,int last){
        int maxi = 0;
        if(day==0){
            for(int i=0;i<3;i++){
                if(i!=last){
                  maxi = max(maxi,matrix[0][i]);
                }
            }
            return maxi;
        }

        // for the days greater than zero(0)
        maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int points = matrix[day][i] + starting(matrix,day-1,i);
                maxi = max(maxi,points);
                }
        }
        return maxi;
    }
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        return starting(matrix,n-1,-1);
    }
};




// using memoization to store the best answer from maxi then when we get that same condition so intead of calculation again will use the saved onessssss.......
class Solution {
public:

    int starting(vector<vector<int>>& matrix,int day,int last,vector<vector<int>>& dp){
        int maxi = 0;
        if(day==0){
            for(int i=0;i<3;i++){
                if(i!=last){
                  maxi = max(maxi,matrix[0][i]);
                }
            }
            return maxi;
        }
        if(dp[day][last]!=-1){
            return dp[day][last];
        }

        // for the days greater than zero(0)
        maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int points = matrix[day][i] + starting(matrix,day-1,i,dp);
                maxi = max(maxi,points);
                }
        }
        return dp[day][last] = maxi;
    }
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return starting(matrix,n-1,3,dp);
    }
};

// Tabulation method

int ninjaRaining(int n,vector<vector<int>>& points){
    vector<vector<int>> dp(n,vector<int>(4,0));

    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max({points[0][0],points[0][1],points[0][2]});


    for(int day=1;day<n;day++){
        for(int last = 0;last<4;last++){
            dp[day][last] = 0;

            for(int task =0;task<3;task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}
