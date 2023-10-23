#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solvingUsingRecursion(string text1, string text2,int i , int j){
        if(i == text1.size())
            return 0;
        if(j == text2.size())
            return 0;
        if(text1[i] == text2[j])//If the character is matched then we have to find the next character
            return (1+solvingUsingRecursion(text1,text2,i+1,j+1)); //Adding 1 as the character is matched and we have to find the longest common subSequence 
        else //If the character is not matched then we have to find the next character and we have to iterate both the strings so onw will be incremented and other will be same similarly for other string
            return max(solvingUsingRecursion(text1,text2,i,j+1),solvingUsingRecursion(text1,text2,i+1,j)); // Max as we have to return the max string lenght 
    }
    int solveUsingMemoization(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        if (i == a.size() || j == b.size())
            return 0;

        if (dp[i][j] != -1) //If the value is already present in the dp array then we will return the value
            return dp[i][j];
        
        if (a[i] == b[j])
            return dp[i][j] = 1 + solveUsingMemoization(a, b, i + 1, j + 1, dp);
        else
            return dp[i][j] = max(solveUsingMemoization(a, b, i, j + 1, dp), solveUsingMemoization(a, b, i + 1, j, dp));
    }
    int solvingUsingTheBottomUp(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};
int main() {
    Solution s;
    string text1 = "abcde";
    string text2 = "ace";
    int i = 0;
    int j = 0;
    int result1 = s.solvingUsingRecursion(text1, text2, i, j);
    cout << "Result using recursion: " << result1 << endl;

    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
    int result2 = s.solveUsingMemoization(text1, text2, i, j, dp);
    cout << "Result using memoization: " << result2 << endl;

    int result3 = s.solvingUsingTheBottomUp(text1, text2);
    cout << "Result using bottom-up approach: " << result3 << endl;

    return 0;
}
