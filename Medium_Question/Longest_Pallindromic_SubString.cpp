#include<bits/stdc++.h>
using namespace std;
/*
problem statement: Given a string s, return the longest palindromic substring in s.
Explnation : A palindrome is a word, number, phrase, or other sequence of characters which reads the same backward as forward, such as madam, racecar.
Example 1:
Input: s = "babad"
Output: "bab"
*/
class Solution {
public:
    bool isPalindrome(string &s, int i, int j, vector<vector<bool>> &dp) {
        if (i >= j) return dp[i][j] = true;
        if (s[i] == s[j]) return dp[i][j] = isPalindrome(s, i + 1, j - 1,dp);
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int sizeOfS = s.size();
        int maxLength = INT_MIN;
        int startingPoint = 0;
        vector<vector<bool>> dp(sizeOfS, vector<bool>(sizeOfS, false));
        for (int i = 0; i < sizeOfS; i++) {
            for (int j = i; j < sizeOfS; j++) {
                if (isPalindrome(s, i, j,dp)) {
                    if (maxLength < j - i + 1) {
                        maxLength = j - i + 1;
                        startingPoint = i;
                    }
                }
            }
        }
        return s.substr(startingPoint, maxLength);
    }
};

int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.longestPalindrome(s);
    return 0;
}
