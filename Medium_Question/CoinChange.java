package Medium_Question;

import java.util.Arrays;
/*
 * Problem name : Coin Change
 * Problem Link : https://leetcode.com/problems/coin-change/
 * Porblem link : https://practice.geeksforgeeks.org/problems/coin-change2448/1
 * explanation : 
 * The approch is to use is that while picking up the element we will check if the element is less than the sum or not
 * if it is less than the sum then we will check if the sum - element is present in the array or not
 * if it is present then we will pick the element and add 1 to the result
 * if it is not present then we will not pick the element and move to the next element
 * Basically can we pick the element or not again in that array.
 * And this will be done by not reducing the index of the array but by reducing the sum.
 * 
 */
class Solution1 {
    public int tabulation(int sum, int[] arr) {
        int[][] dp = new int[arr.length][sum + 1];

        for (int i = 1; i <= sum; i++) {
            dp[0][i] = (i % arr[0] == 0) ? (i / arr[0]) : 10000000;
        }

        for (int idx = 1; idx < arr.length; idx++) {
            for (int j = 0; j <= sum; j++) {
                int notPick = dp[idx - 1][j];
                int pick = 10000000;
                if (j >= arr[idx]) {
                    int pickValue = 1 + dp[idx][j - arr[idx]];
                    if (pickValue < 10000000) {
                        pick = pickValue;
                    }
                }
                dp[idx][j] = Math.min(pick, notPick);
            }
        }
        return dp[arr.length - 1][sum];
    }

    public int coinChange(int[] coins, int amount) {
        int result = tabulation(amount, coins);
        return (result == 10000000) ? -1 : result;
    }
}

class Solution2 {
    public int recursion(int idx, int sum, int[] arr, int[][] dp) {
        if (idx == 0) {
            if (sum % arr[idx] == 0) return (sum / arr[idx]);

            return 100000;
        }
        if (dp[idx][sum] != -1) return dp[idx][sum];
        int notPick = recursion(idx - 1, sum, arr, dp);
        int pick = 10000000; 
        if (arr[idx] <= sum) {
            int pickValue = 1 + recursion(idx, sum - arr[idx], arr, dp);
            if (pickValue < 100000000) {
                pick = pickValue;
            }
        }

        return (dp[idx][sum] = Math.min(pick, notPick));
    }

    public int coinChange(int[] coins, int amount) {
        int[][] dp = new int[coins.length + 1][amount + 1];
        for (int[] row : dp) Arrays.fill(row, -1);
        int result = recursion(coins.length - 1, amount, coins, dp);

        return (result == 100000) ? -1 : result;
    }
}
