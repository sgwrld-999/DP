#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Pascal Triangle
Problem link : https://leetcode.com/problems/pascals-triangle/
Explanation :
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

For example :
Input : numRows = 5
1 //base Case 
1 1 //base Case
1 2 1 // 2 = 1 + 1 => 1st row 1st column + 1st row 2nd column
1 3 3 1 // 3 = 1 + 2 => 2nd row 1st column + 2nd row 2nd column and 3 = 2 + 1 => 2nd row 2nd column + 2nd row 3rd column
1 4 6 4 1 // 4 = 1 + 3 => 3rd row 1st column + 3rd row 2nd column and 6 = 3 + 3 => 3rd row 2nd column + 3rd row 3rd column and 4 = 3 + 1 => 3rd row 3rd column + 3rd row 4th column

From the above observation we can see that the current row is the sum of the previous row and the previous row shifted by one column.
Or the formula is : currentRow[i] = previousRow[i] + previousRow[i - 1]
*/
class Solution {
    public:
    vector<vector<int>> pascalTriangle(int numRows){
        vector<vector<int>> dp(numRows);
        for(int i = 0 ; i < numRows ; i++){
            dp[i].resize(i + 1);
            dp[i][0] = dp[i][i] = 1;
            for(int j = 1 ; j < i ; j++){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        return dp;
    }
};

int main(){
    int numRows = 5;
    Solution obj;
    vector<vector<int>> ans = obj.pascalTriangle(numRows);
    for(int i = 0 ; i < numRows ; i++){
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}