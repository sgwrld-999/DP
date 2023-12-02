#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Pascal Triangle 2
Problem link : https://leetcode.com/problems/pascals-triangle-ii/
Explanation :
Similar to the pascal triangle problem but this time we've to find the kth row of the pascal triangle.
But we have to return the kth row of the pascal triangle in O(k) space.
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prevRow(1,1);
        vector<int> curRow(2,1);
        if(rowIndex == 0)
            return prevRow;
        if(rowIndex == 1)
            return curRow;
        for(int i = 1 ; i <= rowIndex ; i++){
            vector<int> temp(i+1,1);
            for(int j = 1; j < i ; j++ ){
                temp[j] = curRow[j-1] + curRow[j];
            }
            prevRow = curRow;
            curRow = temp ;
        }
        return curRow;
    }
};

int main(){
    int numRows = 3;
    Solution obj;
    vector<int> ans = obj.getRow(numRows);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
//___________________________________________________________
/*
java code 
GFG link : https://practice.geeksforgeeks.org/problems/nth-row-of-pascals-triangle5008/1
class Solution {
    ArrayList<Long> nthRowOfPascalTriangle(int n) {
        ArrayList<Long> ans = new ArrayList<>();
        if (n == 1) {
            ans.add(1L);
            return ans;
        }
        if (n == 2) {
            ans.add(1L);
            ans.add(1L);
            return ans;
        }
        int mod = (int) (1e9 + 7);
        long[][] dp = new long[n + 1][n + 1];

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                }
            }
        }
        for (int i = 0; i < n ; i++) {
            ans.add(dp[n-1][i]);
        }
        return ans;
    }
}
*/