# include <iostream>
# include <vector>
using namespace std;

/*
================================================================================
                    DYNAMIC PROGRAMMING (1D DP MASTER GUIDE)
================================================================================

HOW TO IDENTIFY A 1D DP PROBLEM:
 1. Problem asks to "Count total number of ways" (e.g., Climbing Stairs).
 2. Problem asks for "Minimum or Maximum" cost/value.
 3. Brute force recursion evaluates identical function states multiple times
    (Overlapping Subproblems).

3-STEP RECURSION SHORTCUT:
 1. Express the problem state in terms of an index: f(ind).
 2. Explore all choices at that index according to the problem statement.
 3. Combine results:
    - Sum choices       -> If counting total ways.
    - min() or max()    -> If finding optimal solution.
================================================================================
*/

class DynamicProgrammingNotes {
public:

    // -------------------------------------------------------------------------
    // 1. NAIVE RECURSION (Brute Force)
    // -------------------------------------------------------------------------
    // Problem : Evaluates identical subproblems repeatedly (e.g., f(2) calculated
    //           multiple times in f(5) recursion tree).
    // Time    : O(2^N) - Exponential due to overlapping execution tree branch
    // Space   : O(N)   - Auxiliary recursion stack space
    int fibonacciRecursion(int n) {
        // Base Case
        if (n <= 1) return n;

        // Recursive tree splitting into left and right subproblems
        return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
    }


    // -------------------------------------------------------------------------
    // 2. TOP-DOWN DP (Memoization)
    // -------------------------------------------------------------------------
    // Strategy : Pass a lookup array initialized to -1. Store computed values.
    // Time     : O(N) - Computes each unique subproblem state exactly once
    // Space    : O(N) + O(N) - Stack space O(N) + Lookup Array O(N)
    int fibonacciMemoization(int n, vector<int>& dp) {
        // Step 1: Base Case
        if (n <= 1) return n;

        // Step 2: Look up previously computed result
        if (dp[n] != -1) return dp[n];

        // Step 3: Compute, store in DP array, and return
        return dp[n] = fibonacciMemoization(n - 1, dp) + fibonacciMemoization(n - 2, dp);
    }


    // -------------------------------------------------------------------------
    // 3. BOTTOM-UP DP (Tabulation)
    // -------------------------------------------------------------------------
    // Strategy : Replaces recursion with iterative loops filling table from base.
    // Time     : O(N) - Single linear loop execution
    // Space    : O(N) - Array space (Recursion stack space ELIMINATED)
    int fibonacciTabulation(int n) {
        if (n <= 1) return n;

        // Step 1: Declare DP table of size n + 1
        vector<int> dp(n + 1, 0);

        // Step 2: Initialize base cases
        dp[0] = 0;
        dp[1] = 1;

        // Step 3: Iteratively build solution from smallest subproblem to N
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }


    // -------------------------------------------------------------------------
    // 4. SPACE-OPTIMIZED TABULATION
    // -------------------------------------------------------------------------
    // Strategy : Notice dp[i] only depends on dp[i-1] (prev1) & dp[i-2] (prev2).
    // Time     : O(N)
    // Space    : O(1) - Constant auxiliary space (BEST APPROACH)
    int fibonacciSpaceOptimized(int n) {
        if (n <= 1) return n;

        // Base values mapped to track past state variables
        int prev2 = 0; // Represents dp[i-2]
        int prev1 = 1; // Represents dp[i-1]

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2; // Current calculated state
            prev2 = prev1;            // Shift window right
            prev1 = curr;
        }

        return prev1; // Holds value of dp[n]
    }


    // -------------------------------------------------------------------------
    // APPLICATION EXAMPLE: Count Ways To Reach Nth Stair
    // -------------------------------------------------------------------------
    // Problem : Can jump either 1 or 2 steps at a time.
    // Logic   : f(n) = f(n-1) + f(n-2) [Identical transition to Fibonacci]
    int climbStairs(int n) {
        if (n <= 1) return 1; // Base case: 1 way to stand at index 0 or 1 step

        int prev2 = 1, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2; // Sum of 1-step and 2-step choices
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};