//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
/*
Problem Name : Rod Cutting
Problem Link : https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#
Explanation : 
   - Pick and not pick approach but this time the rod lenght will be idx + 1 
   because we are starting from 0 and not 1.
   Base case : if idx == 0 then return sum * a[idx]
            reason : 
                - if we are at idx 0 then we have only one option to pick the rod
                of length 1 and we can pick it sum times so we will return sum * a[idx]
                ex : sum = 12 , price[0] = 6
                12 = {1,1,...1} 12 times
*/

// } Driver Code Ends
// User function Template for C++

class Solution{
  private:
  int recursion(int idx,int sum,int a[]){
      if(idx == 0) return (sum * a[idx]);
      
      int notPick = recursion(idx-1,sum,a);
      int pick = 0 ;
      int rodLen = idx + 1;
      if(rodLen <= sum) pick = a[idx] + recursion(idx,sum-rodLen,a);
      
      return max(pick,notPick);
  }
  int recursionMemo(int idx,int sum,int a[],vector<vector<int>>& dp){
      if(idx == 0) return (sum * a[idx]);
      if(dp[idx][sum] != -1) return dp[idx][sum];
      
      int notPick = recursionMemo(idx-1,sum,a,dp);
      int pick = 0 ;
      int rodLen = idx + 1;
      if(rodLen <= sum) pick = a[idx] + recursionMemo(idx,sum-rodLen,a,dp);
      
      return (dp[idx][sum] = max(pick,notPick));
  }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return recursionMemo(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends