//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Number of Unique Paths
Problem link : https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1#
Problem link : https://leetcode.com/problems/unique-paths/
*/
// } Driver Code Ends
//User function template in C++

class Solution
{
    private:
    //TC : O(2^(a*b))
    //SC : O(a+1+b+1)
    int recursion(int i,int j){
        if(i == 0 && j == 0) return 1 ;
        if( i < 0 || j < 0) return 0 ;
        
        int up = recursion(i-1,j);
        int down = recursion(i,j-1);
        
        return (up + down) ;
    }
    //TC : O((a*b))
    //SC : O(a*b)
    int recursionMemo(int i,int j,vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1 ;
        if( i < 0 || j < 0) return 0 ;
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = recursionMemo(i-1,j,dp);
        int left = recursionMemo(i,j-1,dp);
        
        return (dp[i][j] = (up + left)) ;
    }

    int tabulation(int a, int b) {
    // Declare the dp table with dimensions (a+1) x (b+1)
        vector<vector<int>> dp(a, vector<int>(b , -1));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
    
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[a-1][b-1];
    }
    
    int spaceOptimization(int a, int b) {
        vector<int> prev(b, 0);
    
        for (int i = 0; i < a; i++) {
            vector<int> cur(b, 0);
    
            for (int j = 0; j < b; j++) {
                if (i == 0 && j == 0)
                    cur[j] = 1;
                else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? cur[j - 1] : 0;
    
                    cur[j] = up + left;
                }
            }
    
            prev = cur;
        }
    
        return prev[b - 1];
    }

    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        // return recursion(a-1,b-1);
        // vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
        // return recursionMemo(a-1,b-1,dp);
        return spaceOptimization(a,b);
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends