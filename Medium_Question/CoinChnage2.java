package Medium_Question;
/*
 * Problem name : Coin Change 2
 * Problem Link : https://leetcode.com/problems/coin-change-2/
 * Explanation : 
 *      - Pick and not pick with duplicates allowed
 * 
 */
class Solution {
    public int recursion(int idx, int sum, int[] arr) {
        if (idx == 0) return (sum % arr[idx] == 0) ? 1 : 0;

        int notTake = recursion(idx - 1, sum, arr);
        int take = 0;
        if (sum >= arr[idx]) take = recursion(idx , sum - arr[idx], arr);

        return (take + notTake);
    }
    public int recursionMemo(int idx, int sum, int[] arr,int[][] dp) {
        if (idx == 0) return (sum % arr[idx] == 0) ? 1 : 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int notTake = recursionMemo(idx - 1, sum, arr,dp);
        int take = 0;
        if (sum >= arr[idx]) take = recursionMemo(idx , sum - arr[idx], arr,dp);

        return (dp[idx][sum] = take + notTake);
    }
    public int tabulation(int sum, int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][sum + 1];
        
        for (int i = 0; i <= sum; i++) {
            dp[0][i] = (i % arr[0] == 0) ? 1 : 0;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int j = 0; j <= sum; j++) {
                int notTake = dp[idx - 1][j];
                int take = (j >= arr[idx]) ? dp[idx][j - arr[idx]] : 0;

                dp[idx][j] = take + notTake;
            }
        }

        return dp[n - 1][sum];
    }
    public int change(int sum, int[] a) {
        
        return  tabulation(sum, a);
    }
}
