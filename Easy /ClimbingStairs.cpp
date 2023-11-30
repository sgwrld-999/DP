#include<bits/stdc++.h>
using namespace std;

/*
Problem Name : Climbing Stairs
Problem Link : https://leetcode.com/problems/climbing-stairs/
Explanation :
The question is saying us to find the total number of ways to reach the Nth stair and we've 
to find the number of ways we can reach that stair.

So it's given that we can take either 1 or 2 steps at a time. So, we can use the recursion to solve this problem.
Also the base case is that if n == 0 or n == 1 then we can reach the cell in 1 way.
AND WE HAVE TO FIND THE NUMBER OF WAYS TO REACH THE Nth STAIR. MEANS TOTAL NUMBER OF WAYS TO REACH THE Nth STAIR.

*/

//top-down approach 
class Solution1 {
public:
    int solution(int n,vector<int>& dp){
        if(dp[n] != -1)
            return dp[n];

        if( n == 1 || n == 2)
            return n;
        dp[n] = solution(n-1,dp)+solution(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return solution(n,dp);
    }
};
//Bottom-up Approach 
class Solution2 {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};

//The bottom up with constant space complexity 
class Solution3 {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int prev1 = 1;
        int prev2 = 2;
        int sum = 0 ;
        for (int i = 3; i <= n; i++) {
            sum = prev1 + prev2 ;
            prev1 = prev2;
            prev2 = sum ;
        }
        
        return sum;
    }
};

int main(){
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    cout << s1.climbStairs(4) << endl;
    cout << s2.climbStairs(5) << endl;
    cout << s3.climbStairs(5) << endl;
    return 0;
}