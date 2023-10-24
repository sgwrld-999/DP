#include<bits/stdc++.h>
using namespace std;

class Solution{
    public :
    int solve(string s1 , string s2 , int n , int m , vector<vector<int>>&dp){
        if(n==0 || m==0)
            return 0;
        if(dp[n-1][m-1]!=-1)
            return dp[n-1][m-1];
        if(s1[n-1]==s2[m-1]){
            return dp[n-1][m-1] = 1+solve(s1,s2,n-1,m-1,dp);
        }else{
            return dp[n-1][m-1] = max(solve(s1,s2,n-1,m,dp),solve(s1,s2,n,m-1,dp));
        }
    }
    string printLPS(string s1 , string s2 , int n , int m, int longestCommonSubsequence , vector<vector<int>>&dp){
    int i = n-1 , j = m-1;
    int indexFront = 0;
    int indexBack = longestCommonSubsequence-1;
    string ans(longestCommonSubsequence, ' ');
    while(i>=0 && j>=0){
        if(s1[i]==s2[j]){
            ans[indexFront++] = s1[i];
            ans[indexBack--] = s2[j];
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    for(auto x:ans){
        cout<<x;
    }
    cout<<endl;
    return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s1 , s2;
    cout << "Enter the first string : ";
    cin >> s1 ;
    for(int i = s1.size()-1 ; i >= 0 ; i--){
        s2.push_back(s1[i]);
    }
    int n = s1.size();
    int m = n ;
    vector<vector<int>> dp(n,vector<int>(m,-1)); // n+1 and m+1 for tabulation
    Solution s;
    int longestCommonSubsequence =  s.solve(s1,s2,n,m,dp);
    cout << "The length of the longest common subsequence is : " << longestCommonSubsequence << endl;
    string ans = s.printLPS(s1,s2,n,m,longestCommonSubsequence,dp);
    return 0;
}
