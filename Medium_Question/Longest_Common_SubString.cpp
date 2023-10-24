#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestCommonSubStringRecursive(string S1, string S2, int n, int m){
        //The code is similar to the longest sub sequence but the difference is that we'll return 0 if 
        //it don't match.
        if(n == 0 || m == 0)return 0;

        if(S1[n-1] == S2[m-1]){
            return 1+longestCommonSubStringRecursive(S1,S2,n-1,m-1);
        }

        return 0;
    }

   int longestCommonSubStringRecursiveMemo(string S1, string S2, int n, int m, vector<vector<int> >& dp) {
    // The code is similar to finding the longest common substring
    // between S1 and S2 using recursion and memoization.

    if (n == 0 || m == 0)
        return 0;

    if (dp[n - 1][m - 1] != -1)
        return dp[n - 1][m - 1];

    if (S1[n - 1] == S2[m - 1]) {
        dp[n - 1][m - 1] = 1 + longestCommonSubStringRecursiveMemo(S1, S2, n - 1, m - 1, dp);
        return dp[n - 1][m - 1];
    } else {
        dp[n - 1][m - 1] = 0;
        return 0;
    }
    }


    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int maxAns = 0 ; 
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1 ;
                    maxAns = max(maxAns,dp[i][j]);
                }else 
                    dp[i][j] = 0;   
            }
        }
        return maxAns;
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; 
        string s1, s2;
        cout << "Enter the string : ";
        cin >> s1 ;
        n = s1.size();
        for(int i = s1.size()-1 ; i >= 0 ; i--){
            s2.push_back(s1[i]);
        }
        m = n ;
        vector<vector<int> > dp(n+1,vector<int>(m+1 , -1));
        Solution ob;
        cout << "The lenght of the longest substring is : " << ob.longestCommonSubStringRecursiveMemo (s1, s2, n, m, dp ) << endl;
        vector<char> ans;
        int i = n - 1 ; int j = m - 1 ;
        while(i > 0 && j > 0){
            if(s1[i] == s2[2]){
                ans.push_back(s1[i]);
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
        for (auto &i : ans)
        {
            cout << i << " ";
        }
        
    }
}