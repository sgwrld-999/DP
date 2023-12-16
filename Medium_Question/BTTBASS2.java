package Medium_Question;

import java.util.Arrays;
/*
 * Problem name : Best Time to Buy and Sell Stock II
 * Problem URL  : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Explanation  :
 *              - Approach 1 : Recursion Since we've to find the maximum profit sum for that we can use recursion
 *                             because we have check all the possible cases and then find the maximum profit sum.
 *                             Things to keep in mind while using recursion:
 *                             1. When can we but the stock? When we hven't bought any stock yet.
 *                             2. When can we sell the stock? When we have bought the stock.
 *                             3. If we've already bought the stock then we have two choices: 
 *                                   i. Either we can sell the stock
 *                                   ii. Or we can skip the current day and move forward holding the stock 
 *                            4. If we haven't bought the stock then we have two choices:       
 *                                  i. Either we can buy the stock
 *                                  ii. Or we can skip the current day and move forward without buying the stock
 *                           5. We have to return the maximum profit sum
 *             - Approach 2 : Recursion + Memoization
 *                          - We can see that there are many overlapping subproblems in the recursion tree
 *                          - So we can use memoization to store the results of the subproblems
 *                          - We can use a 2D array to store the results of the subproblems
 *                          - We can use the dayIndex and holdingStock as the parameters for the memoization table
 *                          - We can use -1 as the base case for the memoization table
 *              - Approach 3 : Tabulation
 *                          - We can see that the recursion is following a top-down approach
 *                          - So we can use tabulation to store the results of the subproblems
 *                          - We can use a 2D array to store the results of the subproblems
 *                          - We can use the dayIndex and holdingStock as the parameters for the tabulation table
 *            - Approach 4 : Space Optimized Tabulation
 *                          - We can see that we are only using the results of the previous day
 *                          - So we can use two variables to store the results of the previous day
 *                          - We can use the dayIndex and holdingStock as the parameters for the tabulation table
 *  
 * 
 */

 // 0 -> No buy or sell
 // 1 -> Buy 
public class BTTBASS2 {
    class Solution {
    public int calculateMaxProfit(int dayIndex, int holdingStock, int[] stockPrices, int[][] memo) {
        if (dayIndex == stockPrices.length) return 0;
        if (memo[dayIndex][holdingStock] != -1) return memo[dayIndex][holdingStock];
        
        int maxProfit = 0;
        if (holdingStock == 1) {
            maxProfit = Math.max(-stockPrices[dayIndex] + calculateMaxProfit(dayIndex + 1, 0, stockPrices, memo), 
                                 0 + calculateMaxProfit(dayIndex + 1, 1, stockPrices, memo));
        } else {
            maxProfit = Math.max(stockPrices[dayIndex] + calculateMaxProfit(dayIndex + 1, 1, stockPrices, memo), 
                                 0 + calculateMaxProfit(dayIndex + 1, 0, stockPrices, memo));
        }

        return memo[dayIndex][holdingStock] = maxProfit;
    }
    int calculateMaxProfitUsingTabulation(int[] stockPrices) {
        int numberOfDays = stockPrices.length;
        int[][] dp = new int[numberOfDays + 1][2];
        for (int[] row : dp) Arrays.fill(row, -1);
        dp[numberOfDays][0] = 0;
        dp[numberOfDays][1] = 0;

        for (int i = numberOfDays - 1; i >= 0; i--) {
            for (int holdingStock = 0; holdingStock <= 1; holdingStock++) {
                int maxProfit = 0;
                if (holdingStock == 1) {
                    maxProfit = Math.max(-stockPrices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                } else {
                    maxProfit = Math.max(stockPrices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                }
                dp[i][holdingStock] = maxProfit;
            }
        }
        return dp[0][1];
    }
    int spaceOptUsing2Arrays(int[] stockPrices) {
        int numberOfDays = stockPrices.length;
        int[] dp1 = new int[2];
        int[] dp2 = new int[2];
        dp1[0] = 0;
        dp1[1] = 0;

        for (int i = numberOfDays - 1; i >= 0; i--) {
            for (int holdingStock = 0; holdingStock <= 1; holdingStock++) {
                int maxProfit = 0;
                if (holdingStock == 1) {
                    maxProfit = Math.max(-stockPrices[i] + dp2[0], 0 + dp2[1]);
                } else {
                    maxProfit = Math.max(stockPrices[i] + dp2[1], 0 + dp2[0]);
                }
                dp1[holdingStock] = maxProfit;
            }
            dp2[0] = dp1[0];
            dp2[1] = dp1[1];
        }
        return dp1[1];
    }
    public int maxProfit(int[] stockPrices) {
        int numberOfDays = stockPrices.length;
        int[][] memoTable = new int[numberOfDays + 1][2];
        for (int[] row : memoTable) Arrays.fill(row, -1);

        return calculateMaxProfit(0, 1, stockPrices, memoTable);
    }
}

}
