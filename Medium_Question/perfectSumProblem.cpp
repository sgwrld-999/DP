//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Problem name: Perfect Sum Problem
Ptoblem Link: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
Explanation : 
    The question is similar to the subsset problem but the difference is that
    we'll have to return the count of the subsets whose sum is equal to the given sum.

    SPECIAL CASE :
        If the lsit contains 0 then there will be 2 possibilities:
            1. We'll not take the 0.
            2. We'll take the 0.
        and will adding or leaving the 0 will not affect the sum.
        So, we have to update our base case accordingly.
        Case1 : 
            idx = 0 and arr[0] == 0 then return 2 -> Because we can either take the 0 or not take the 0.
            idx = 0 and arr[0] != 0 then return 1 -> Because we can only take the 0.
            idx != 0 and arr[0] == 0 then return 1 -> Because we can only not take the 0.
*/
// } Driver Code Ends
class Solution {
public:
    const int mod = 1000000007;
    int recursionMemo(int idx, int target, int arr[],vector<vector<int>>& dp) {
        if (idx < 0) {
            return (target == 0) ? 1 : 0;
        }

        if (idx == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || target == arr[0])  return 1;
            return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int notTake = recursionMemo(idx - 1, target, arr,dp)%mod;
        int take = 0;
        if (target >= arr[idx]) {
            take = recursionMemo(idx - 1, target - arr[idx], arr,dp)%mod;
        }
        return (dp[idx][target] = (take + notTake)%mod);
    }
    int tabulation(int n, int target, int arr[],vector<vector<int>>& dp) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                if (i == 0) {
                    if (j == arr[0]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                    continue;
                }
                int notTake = dp[i - 1][j];
                int take = 0;
                if (j >= arr[i]) {
                    take = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = (take + notTake)%mod;
            }
        }
        return dp[n][target];
    }

    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return recursionMemo(n - 1, sum, arr,dp);
    }
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends