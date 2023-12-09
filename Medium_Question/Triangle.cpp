//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Minimum Sum Path in Triangle
Problem link : https://practice.geeksforgeeks.org/problems/minimum-sum-path-in-a-triangle/0/#
Problem link : https://leetcode.com/problems/triangle/
Explanation  : This time will we start from the start as there is no fixed number of 
                col in each row. So we will start from the top and go to the bottom.
                We will use the same approach as we used in MaximumPathSumInMatrix.cpp
                and UniquePathsInAGrid.cpp. We will use recursion, recursion with memoization
                and tabulation.
                Time Complexity : O(N^2)
                Space Complexity : O(N^2)
                where N is the number of rows in the triangle.
                We can optimize the space complexity to O(N) by using a single array of size N.
                We will start from the bottom and go to the top.
                Time Complexity : O(N^2)
                Space Complexity : O(N)
                where N is the number of rows in the triangle.
                We can optimize the space complexity to O(1) by using the same array of size N.
                We will start from the bottom and go to the top.
                
*/
// } Driver Code Ends
class Solution {
  private:
  int recursion(int row,int col,int n,vector<vector<int>>& triangle ){
      if(row == n - 1) return triangle[row][col];
      
      int down = triangle[row][col] + recursion(row+1,col,n,triangle);
      int diagonal = triangle[row][col] + recursion(row+1,col+1,n,triangle);
      
      return min(down,diagonal);
  }
  int recursionMemo(int row,int col,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
      if(row == n - 1) return triangle[row][col];
      if(dp[row][col] != -1) return dp[row][col];
      
      int down = triangle[row][col] + recursionMemo(row+1,col,n,triangle,dp);
      int diagonal = triangle[row][col] + recursionMemo(row+1,col+1,n,triangle,dp);
      dp[row][col] = min(down,diagonal);
      return dp[row][col];
  }
  int tabulation(int n, vector<vector<int>>& triangle) {
       
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                } else if (j == triangle[i].size() - 1) {
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                }
            }
        }
    
        int minPathSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minPathSum = min(minPathSum, dp[n - 1][j]);
        }
    
        return minPathSum;
    }

  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return tabulation(n,triangle);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends