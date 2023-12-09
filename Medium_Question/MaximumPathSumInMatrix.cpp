//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Maximum path sum in matrix
Problem link : https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#
Problem link : https://leetcode.com/problems/minimum-falling-path-sum/
*/
// } Driver Code Ends
// User function Template for C++

#include <vector>
using namespace std;

class Solution {
private:
    //Time Complexity : O(N) + O(3^N)
    //Space complexity : O(N+1)
    int recursion(int N, vector<vector<int>> Matrix, int row, int col) {
        if(col < 0 || col > N ) return (-1000007);
        if(row == 0) return Matrix[row][col];
        
        int leftDiagonal =  Matrix[row][col] + recursion(N,Matrix,row-1,col-1);
        int up           =  Matrix[row][col] + recursion(N,Matrix,row-1,col);
        int rightDiagonal=  Matrix[row][col] + recursion(N,Matrix,row-1,col+1);
        
        return max(leftDiagonal,max(up,rightDiagonal));
    }
    int recursionMemo(int N, vector<vector<int>>& Matrix, int row, int col, vector<vector<int>>& dp) {
    // Base cases
        if (col < 0 || col >= N) return INT_MIN;
        if (row == 0) return Matrix[row][col];
        if (dp[row][col] != -1) return dp[row][col];
    
        // Recursive calls
        int leftDiagonal = Matrix[row][col] + recursionMemo(N, Matrix, row - 1, col - 1, dp);
        int up = Matrix[row][col] + recursionMemo(N, Matrix, row - 1, col, dp);
        int rightDiagonal = Matrix[row][col] + recursionMemo(N, Matrix, row - 1, col + 1, dp);
    
        // Update the memoization table
        dp[row][col] = max(leftDiagonal, max(up, rightDiagonal));
    
        return dp[row][col];
    }
    int tabulation(int N, vector<vector<int>> Matrix){
        vector<vector<int>>dp(N+1,vector<int>(N,-1));
        
        for(int i = 0 ; i < N ; i++) dp[0][i] = Matrix[0][i];
        
        for(int i = 1 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                int leftDiagonal = (j > 0) ? dp[i - 1][j - 1] : 0;
                int up = dp[i - 1][j];
                int rightDiagonal = (j < N - 1) ? dp[i - 1][j + 1] : 0;
    
                dp[i][j] = Matrix[i][j] + max(leftDiagonal, max(up, rightDiagonal));
                
            }
        }
        int maxi = INT_MIN;
        for(int i = 0 ; i < N ; i++)maxi = max(maxi,dp[N-1][i]);
        
        return maxi;
    }
public:
    int maximumPath(int N, vector<vector<int>> Matrix) {
        // int maxi = 0;
        // vector<vector<int>> dp(N,vector<int>(N,-1));
        // for (int i = N - 1; i >= 0; i--) {
        //     maxi = max(maxi, recursionMemo(N, Matrix, N-1 , i,dp));
        // }
        return tabulation(N,Matrix);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends