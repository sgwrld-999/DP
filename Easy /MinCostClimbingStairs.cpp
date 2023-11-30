#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Min Cost Climbing Stairs
Problem link : https://leetcode.com/problems/min-cost-climbing-stairs/
Explanation : 
The question is similar to the climbing stairs problem but this time we've given the 
cost of each step and we have to find the minimum cost to reach the top of the stairs.
So this time we have to take care of the cost of each step and we have to find the minimum
cost to reach the top of the stairs.

Example :
Input : cost = [10,15,20]
If we are stading at -1 there are two ways to proceed either we can take 0th step or 1st step
if we take 0th step then the cost will be 10 and if we take 1st step then the cost will be 15
so we will take the minimum cost which is 10 and we will move to the 0th step and then we will
there are 2 options either we can take 1st step or 2nd step if we take 1st step then the cost will
So'll we take the second step and we will reach the top of the stairs and the cost will be 30.
But if we take the 1st step then the cost will be 15 and then we will reach the top of the stairs
and the cost will be 15.
So the minimum cost to reach the top of the stairs is 15.

So we've to go through all the steps and check if it's the minimum cost to reach the top of the stairs
or not.

Recursion -> As we've to go through all the steps and check if it's the minimum cost to reach the top of the stairs
or not so we can use recursion to solve this problem.
Memoization -> As we've repating subproblems so we can use memoization to solve this problem.

*/
class Solution1 {
public:
    int bottomUpApproach(vector<int>& cost, int n) {
        vector<int> dp(n + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        return bottomUpApproach(cost, size - 1);
    }
};

class Solution2 {
public:
    int topDownApproach(vector<int>& cost,int size , vector<int>& dp){
        if(size == 1)
            return cost[1];
        if(size == 0)
            return cost[0];

        if(dp[size] != -1)
            return dp[size];
        
        dp[size] = cost[size] + min(topDownApproach(cost , size -1,dp) ,topDownApproach(cost , size - 2,dp));
        return dp[size];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> memoizationTable(size+1,-1);
        return min(topDownApproach(cost, size-1,memoizationTable),topDownApproach(cost, size-2,memoizationTable));
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> cost(n);
        for(int i = 0 ; i < n ; i++)
            cin>>cost[i];
        Solution1 ob1;
        Solution2 ob2;
        cout<<ob1.minCostClimbingStairs(cost)<<endl;
        cout<<ob2.minCostClimbingStairs(cost)<<endl;
    }
    return 0;
}