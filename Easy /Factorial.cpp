//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;
/*
Problem Name : Factorial
Problem Link : https://practice.geeksforgeeks.org/problems/factorial/0

*/
// } Driver Code Ends
class Solution {
public:
    long long recursionDp(int num, vector<long long> &dp) {
        if (num == 0 || num == 1)
            return 1;

        if (dp[num] != -1)
            return dp[num];

        return (dp[num] = num * recursionDp(num - 1, dp));
    }

    long long int factorial(int N) {
        vector<long long> dp(N + 1, -1);
        return recursionDp(N, dp);
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends