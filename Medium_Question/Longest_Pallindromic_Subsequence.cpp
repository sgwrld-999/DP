#include<bits/stdc++.h>
using namespace std;   


class Solution{
  public :
  int solve(string s,int i,int j,vector<vector<int>>&dp){
      if(i>j)return 0;
      if(i==j)return 1;
      if(dp[i][j]!=-1)return dp[i][j];
      if(s[i]==s[j]){
          return dp[i][j]=2+solve(s,i+1,j-1,dp);
      }
      else{
          return dp[i][j]=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
      }
  }
};
int main(int argc, char const *argv[])
{
    Solution s;
    string str ;
    cout << "Enter the string : ";
    cin >> str ;
    int n = str.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int longestPalinSubseq = s.solve(str,0,str.size()-1,dp);
    //Printg the commoon substring 
    vector<char> ans(longestPalinSubseq);
    int i = 0 , j = str.size()-1;
    int indexFront = 0;
    int indexBack = longestPalinSubseq-1;
    while(i<=j){
        if(str[i]==str[j]){
            ans[indexFront++] = (str[i]);
            ans[indexBack--] = (str[j]);
            i++;
            j--;
        }else{
            if(dp[i+1][j]>dp[i][j-1]){
                i++;
            }else{
                j--;
            }
        }
    }
    //Only printing the half of the string of pallindrome
    for(auto x:ans){
        cout<<x;
    }
    
    cout<<endl;
    return 0;
}
