#include<bits/stdc++.h>
using namespace std;

/*
Problem name : Count Vowels Permutation
Problem link : https://leetcode.com/problems/count-vowels-permutation/
Problem link : https://practice.geeksforgeeks.org/problems/count-vowels-in-string/1
Explanation :
Approach : 
    - We'll have to find the number of strings of length n that can be formed using the vowels
      'a','e','i','o','u' under the given constraints.
    - We'll use recursion to solve this problem.
    - We'll have 2 choices at each index of the string eeither we can take the vowel or we can
      not take the vowel.
    - If we take the vowel then we'll call the recursion function again with the same index and
        the length of the string - 1.
    - If we don't take the vowel then we'll call the recursion function again with the same index
        and the length of the string.
    - Base cases :
        - If the length of the string is 0 then we'll return 1.
        - If the index is greater than or equal to 5 then we'll return 0.
    - Time Complexity : O(2^N)
    - Space Complexity : O(N)
    where N is the length of the string.
    - We can optimize the above approach by using memoization and tabulation.

*/

class Solution {
private:
    int solve(string s,int n,int idx){
       
        if( n == 0)  return 1 ;
        if(idx >= 5) return 0 ;

        int take = solve(s,n-1,idx);
        int notTake = solve(s,n,idx+1);

        return take + notTake ;
    }
    int recursionMemo(string s,int n,int idx,vector<vector<int>>& dp){
       
        if( n == 0)  return 1 ;
        if(idx >= 5) return 0 ;
        if(dp[idx][n] != -1) return dp[idx][n];
        int take = solve(s,n-1,idx);
        int notTake = solve(s,n,idx+1);

        return (dp[idx][n] = take + notTake) ;
    }
    int tabulation(string s, int n) {
    vector<vector<int>> dp(5, vector<int>(n + 1, -1)); 

    for (int i = 0; i < 5; i++) dp[i][0] = 1;

    for (int i = 4; i >= 0; i--) {
        for (int j = 1; j <= n; j++) { 
            int pick = dp[i][j - 1];
            int notPick = 0;
            if (i < 4) notPick = dp[i + 1][j];

            dp[i][j] = pick + notPick;
        }
    }

    return dp[0][n];
}
public:
    int countVowelStrings(int n) {
        string s = "aeiou";
        vector<vector<int>> dp(6,vector<int>(n+1,-1));
        return tabulation(s,n);
    }
};
