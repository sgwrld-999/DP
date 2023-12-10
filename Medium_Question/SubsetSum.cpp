//{ Driver Code Starts
//Initial template for C++
/*
Problem name : Subset Sum Problem
Problem link : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#
Problem link : https://leetcode.com/problems/partition-equal-subset-sum/
Explanation :
This is a problem based upon the subsequences of a array or string.
In this kind of problem we'll have to find the subsequences of the given array or string
and then we'll have to check if the given condition is satisfied or not.
Apprach : 
    pick or not pick
    pick : 
        if the element is less than or equal to the target then we'll pick it and 
        we'll check if the target - element is equal to 0 or not. If it is equal to 0
        then we'll return true else we'll call the recursion function again with the 
        target - element and the index - 1.
    Not pick :
        We'll not pick the element and we'll call the recursion function again with the 
        same target and the index - 1.
    Base cases :
        if the target is 0 then we'll return true.
        if the index is 0 then we'll check if the element is equal to the target or not.
        if it is equal to the target then we'll return true else we'll return false.
    Time Complexity : O(2^N)
    Space Complexity : O(N*N)
    where N is the size of the array.
Afterwards we'll optimize the above approach by using memoization and tabulation.

*/
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
private: 
    bool recursion(int idx,int target,vector<int>& arr){
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        
        bool notTake = recursion(idx-1,target,arr);
        bool take = false;
        if(target >= arr[idx]){
            take = recursion(idx-1,target-arr[idx],arr);
        }
        return (take || notTake);
    }
    bool recursionMemo(int idx,int target,vector<int>& arr,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        if(dp[idx][target] != -1) return dp[idx][target];
        bool notTake = recursionMemo(idx-1,target,arr,dp);
        bool take = false;
        if(target >= arr[idx]){
            take = recursionMemo(idx-1,target-arr[idx],arr,dp);
        }
        dp[idx][target] =  (take | notTake);
        return dp[idx][target];
        
    }
    bool tabulation(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    
        // Base cases
        for (int i = 0; i < n; i++) {
            dp[i][0] = true; // There is always an empty subset with sum 0
            if (arr[i] <= sum) {
                dp[i][arr[i]] = true; // Include the first element in the subset if it's not greater than the target sum
            }
        }
    
        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                dp[i][target] = dp[i - 1][target] || (target >= arr[i] ? dp[i - 1][target - arr[i]] : false);
            }
        }
    
        // The result is stored in the bottom-right corner of the DP table
        return dp[n - 1][sum];
    }
public:
    bool isSubsetSum(vector<int>&arr, int sum){
        // code here 
        // vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        // return recursionMemo(arr.size()-1,sum,arr,dp);
        return tabulation(arr,sum);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends

/*
CPP code for the problem : Partition Equal Subset Sum
Problem link : https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
    public boolean solve(int idx, int target, int[] nums, int[][] dp) {
        if (target == 0) return true;
        if (idx == 0) return (nums[idx] == target);
        if (dp[idx][target] != -1) return (dp[idx][target] == 1);

        boolean notTake = solve(idx - 1, target, nums, dp);
        boolean take = false;
        if (target >= nums[idx]) {
            take = solve(idx - 1, target - nums[idx], nums, dp);
        }

        dp[idx][target] = (take || notTake) ? 1 : 0;

        return dp[idx][target] == 1;
    }

    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int it : nums) sum += it;
        if (sum % 2 != 0) return false;

        int[][] dp = new int[nums.length][sum / 2 + 1];
        for (int[] row : dp) Arrays.fill(row, -1);

        return solve(nums.length - 1, sum / 2, nums, dp);
    }
}

*/