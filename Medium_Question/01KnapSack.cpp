//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*
Problem Name : 0 - 1 Knapsack
Problem Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
Explanation :
This is a problem based upon the subsequences of a array or string.
In this kind of problem we'll have to find the subsequences of the given array or string
and then we'll have to check if the given condition is satisfied or not.
Apprach : 
    pick or not pick
    pick : 
        if the element is less than or equal to the target then we'll pick it and 
        we'll check if the target - element is equal to 0 or not. If it is equal to 0
        then we'll return true else we'll call the recursion function again with the 
        target - element and the index - 1.
    Not pick :
        We'll not pick the element and we'll call the recursion function again with the 
        same target and the index - 1.
    Base cases :
        if the target is 0 then we'll return true.
        if the index is 0 then we'll check if the element is equal to the target or not.
        if it is equal to the target then we'll return true else we'll return false.
    Time Complexity : O(2^N)
    Space Complexity : O(N*N)
    where N is the size of the array.
Afterwards we'll optimize the above approach by using memoization and tabulation.
Sample imput : 
    arr = {1,2,3,4,5}
    target = 10
*/
// } Driver Code Ends
class Solution
{
    public:
    int recursion(int idx,int w, int wt[],int val[]){
        if(idx == 0){
            if(wt[idx] <= w) return val[idx];
            return 0;
        }
        int notPick = recursion(idx-1,w,wt,val);
        int pick = INT_MIN;
        if(wt[idx] <= w){
            pick = val[idx] + recursion(idx-1,w-wt[idx],wt,val);
        }
        
        return max(pick,notPick);
        
    }
    int recursionMemo(int idx,int w, int wt[],int val[],vector<vector<int>>& dp){
        if(idx == 0){
            if(wt[idx] <= w) return val[idx];
            return 0;
        }
        if(dp[idx][w] != -1) return dp[idx][w];
        
        int notPick = recursionMemo(idx-1,w,wt,val,dp);
        int pick = INT_MIN;
        if(wt[idx] <= w){
            pick = val[idx] + recursionMemo(idx-1,w-wt[idx],wt,val,dp);
        }
        
        return (dp[idx][w] = max(pick,notPick));
        
    }
    int tabulation(int w, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    
        for (int i = 0; i <= w; i++) dp[0][i] = (i >= wt[0]) ? val[0] : 0;
    
        for (int idx = 1; idx < n; idx++) {
            for (int wgt = 0; wgt <= w; wgt++) {
                int notPick = dp[idx - 1][wgt];
                int pick = (wgt >= wt[idx]) ? val[idx] + dp[idx - 1][wgt - wt[idx]] : INT_MIN;
    
                dp[idx][wgt] = max(pick, notPick);
            }
        }
        return dp[n - 1][w];
    }
    int spaceOpt(int w, int wt[], int val[], int n) {
        vector<int> prev(w+1,-1);vector<int> curr(w+1,-1);
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    
        for (int i = 0; i <= w; i++) prev[i] = (i >= wt[0]) ? val[0] : 0;
    
        for (int idx = 1; idx < n; idx++) {
            for (int wgt = 0; wgt <= w; wgt++) {
                int notPick = prev[wgt];
                int pick = (wgt >= wt[idx]) ? val[idx] + prev[wgt - wt[idx]] : INT_MIN;
    
                curr[wgt] = max(pick, notPick);
            }
            prev = curr;
        }
        return prev[w];
    }
    int spaceOpt2(int w, int wt[], int val[], int n) {
        vector<int> prev(w+1,-1);
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    
        for (int i = 0; i <= w; i++) prev[i] = (i >= wt[0]) ? val[0] : 0;
    
        for (int idx = 1; idx < n; idx++) {
            for (int wgt = w; wgt >= 0; wgt--) {
                int notPick = prev[wgt];
                int pick = (wgt >= wt[idx]) ? val[idx] + prev[wgt - wt[idx]] : INT_MIN;
    
                prev[wgt] = max(pick, notPick);
            }
        }
        return prev[w];
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
    //   return recursion(n-1,W,wt,val);
    //   vector<vector<int>> dp(n,vector<int>(w+1,-1));
    //   return recursionMemo(n-1,w,wt,val,dp);
    // return tabulation(w,wt,val,n);
    return spaceOpt(w,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends