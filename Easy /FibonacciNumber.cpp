#include<bits/stdc++.h>
using namespace std;
/*
Problem Name : Fibonacci Number
Problem Link : https://leetcode.com/problems/fibonacci-number/
*/
class Solution{
    public:
    int fibseries(int n){
        if(n == 0 || n == 1) return n;
        return fibseries(n-1) + fibseries(n-2);
    }
    //Using DP : Recursion + Memoization
    int fibSeriesUsingDP(int n,vector<int>&DP){
        if(n == 0 || n == 1) return n;
        if(DP[n] != -1) return DP[n];
        return DP[n] = fibSeriesUsingDP(n-1,DP) + fibSeriesUsingDP(n-2,DP);
    }
    //Using DP : Bottom Up Approach + Tabulation 
    int fibSeriesUsingDPBottomUp(int n){
        vector<int>DP(n+1,-1);
        DP[0] = 0;
        DP[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            DP[i] = DP[i-1] + DP[i-2];
        }
        return DP[n];
    }
    //Using DP : Bottom Up Approach + Tabulation + Space Optimized
    int fibSeriesUsingDPBottomUpSpaceOptimized(int n){
        int prev1 = 0;
        int prev2 = 1;
        int sum = 0;
        for(int i = 2 ; i <= n ; i++){
            sum = prev1 + prev2;
            prev1 = prev2;
            prev2 = sum;
        }
        return sum;
    }
};

int main(){
    int n;
    cin >> n;
    Solution obj;
    cout << obj.fibseries(n) << endl;
    vector<int>DP(n+1,-1);
    cout << obj.fibSeriesUsingDP(n,DP) << endl;
    cout << obj.fibSeriesUsingDPBottomUp(n) << endl;
    cout << obj.fibSeriesUsingDPBottomUpSpaceOptimized(n) << endl;
    return 0;
}