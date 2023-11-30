//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Count ways to N'th Stair(Order does not matter)
Problem link : https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1
Explanation :
The question is saying us to find the total number of ways to reach the Nth stair
using either 1 or 2 steps at a time also in min steps. 
The question is similar to the climbing stairs problem. But the only difference is that
we can take either 1 or 2 steps at a time. So, we can use the recursion to solve this problem.
Also the base case is that if n == 0 or n == 1 then we can reach the cell in 1 way.
*/
// } Driver Code Ends
class Solution{
	public:
	    int solve(int n,vector<int>& dp){
	        if( n == 1 || n == 0) return 1;
	        if(dp[n] != -1) return dp[n];
	        return (dp[n] = 1 + min(solve(n-1,dp), solve(n-2,dp)));
	    }
		int nthStair(int n){
		    //  Code here
		    vector<int>dp(n+1,-1);
		    return solve(n,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends