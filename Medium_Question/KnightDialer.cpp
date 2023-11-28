#include<bits/stdc++.h>
using namespace std;

/*
Problem Name : Knight Dialer
Problem Link : https://leetcode.com/problems/knight-dialer/
Explanation :
The question is saying us to find the total number of ways to reach the cell in n steps.
The knight can move only 2.5 step in move. So, noticeable thing is that what is the reachabilty dial of the knight
in the dialer. Also if n id given means we have to move n - 1 steps to reach the cell. So, we have to find the total
number of ways to reach the cell in n - 1 steps. So, we can use the recursion to solve this problem.
Also the reablablity is given below :
As :
0 -> 4 , 6 
1 -> 6 , 8
2 -> 7 , 9 
3 -> 4 , 8
4 -> 3 , 9 , 0
5 -> 
6 -> 1 , 7 , 0 
7 -> 2 , 6 
8 -> 1 , 3
9 -> 2 , 4

Also we've to check for each cell or number on the dialer
0,1,2,3,4,5,6,7,8,9 -> 10 numbers
Base case : n = 0 -> 1 as we can't move to next step than the only thing we can do is that we can stay at the same cell and
count it in our result. And from towards the next position.

*/
class Solution {
public:
    vector<int> adj[10] = {{4 , 6},{6 , 8},{7 , 9},{4 , 8},{3 , 9 , 0},{},{1 , 7 , 0 },{2 , 6},{1 , 3},{2 , 4}};
    int mod = 1e9 + 7;

    int solve(int n, int cell,vector<vector<int>>& dp) {
        if (n == 1) return 1;
        if (dp[n][cell] != -1) return dp[n][cell];

        int result = 0;
        for (auto node : adj[cell]) {
            result = (result + solve(n - 1, node,dp)) % mod;
        }

        dp[n][cell] = result;
        return dp[n][cell];
    }

    int knightDialer(int n) {
        int result = 0;
        vector<vector<int>> dp(5001, vector<int>(10, -1));
        for (int cell = 0; cell < 10; cell++) {
            result = (result + solve(n, cell,dp)) % mod;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.knightDialer(3131) << endl;
    return 0;
}