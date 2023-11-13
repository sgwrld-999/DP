//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

/*
Problem Name : Shortest Common Supersequence
Problem Link : https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#
Concepts Used : Longest Common Subsequence

Time Complexity : O(m*n)
Space Complexity : O(m*n)

Explanation :
1. Find the length of longest common subsequence of both the strings.
2. The length of shortest common supersequence will be sum of length of both the strings minus length of longest common subsequence.
3. Now, we have to find the shortest common supersequence.
4. We will use the same approach as we used in printing the longest common subsequence.
5. We will start from the last index of both the strings and check if the characters are equal or not.
6. If the characters are equal, then we will add that character to the supersequence and move to the previous index of both the strings.
7. If the characters are not equal, then we will check which of the two strings has the longest common subsequence at the previous index.
8. We will add the character of that string to the supersequence and move to the previous index of that string.
9. We will repeat the above steps until we reach the first index of both the strings.
10. Now, we will reverse the supersequence and return it.


*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int match = 0;
                int nm = 0;
                if (str1[i - 1] == str2[j - 1])
                    match = 1 + dp[i - 1][j - 1];
                else
                    nm = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(match, nm);
            }
        }

        int val = dp[m][n];
        int superseqLen = m + n - val;

        
        string superseq;
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                superseq.push_back(str1[i - 1]);
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    superseq.push_back(str1[i - 1]);
                    i--;
                } else {
                    superseq.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        while (i > 0) {
            superseq.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            superseq.push_back(str2[j - 1]);
            j--;
        }

        reverse(superseq.begin(), superseq.end());

        return superseq;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string A, B;
        cin>>A>>B;
        
        Solution ob;
        cout<<ob.shortestCommonSupersequence(A, B)<<endl;
    }
    return 0;
}


// } Driver Code Ends