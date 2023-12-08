//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Number of Unique Paths
Problem link : https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1#
Problem link : https://leetcode.com/problems/unique-paths-II/

*/

// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    const int mod = 1000000007;
    int recursion(int i,int j, vector<vector<int>> &grid){
        if(i == 0 && j == 0) return 1 ;
        if( i < 0 || j < 0) return 0 ;
        int up = (grid[i][j] != 0) ? recursion(i-1,j,grid) : 0 ;
        int left = (grid[i][j] != 0) ? recursion(i,j-1,grid) : 0;
        
        return (up + left) ;
    }
    int recursionMemo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i >= 0 && j >= 0 && grid[i][j] == 0)
            return 0;
            
        if (i == 0 && j == 0)
            return 1;
    
        if (i < 0 || j < 0 )
            return 0;
    
        if (dp[i][j] != -1)
            return dp[i][j];
    
        int up = recursionMemo(i - 1, j, grid, dp);
        int left = recursionMemo(i, j - 1, grid, dp);
    
        // Apply modulo after calculating the sum
        return dp[i][j] = (up + left) % mod;
    }
    int tabulation(int n, int m, vector<vector<int>> &grid){
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0) 
                    dp[i][j] = 0;
                else if(i == 0 && j == 0) 
                    dp[i][j] = 1;
                else{
                    int up = 0 ;
                    int left = 0;
                    if(i > 0 && grid[i][j] == 1) 
                        up = dp[i-1][j];
                    if(j > 0 && grid[i][j] == 1) 
                        left = dp[i][j-1];
                        
                        
                    dp[i][j] = (up + left) % mod;
                }
            }
        }
        return dp[n-1][m-1];
    }
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return tabulation(n,m,grid);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends