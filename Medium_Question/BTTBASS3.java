package Medium_Question;
import java.util.Arrays;

/*
 * Problem name : Best Time to Buy and Sell Stock III
 * Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * Problem link : https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/
 * Explanation : 
 *            Similar ot BTTBASS2, but here we can do at most 2 transactions in total.
 *            We have to introduce one more parameter in the memo table, which is the count of transition.
 *            and we'll decrease the count of transition by 1 only when we sell the stock.
 *            So, the base case will be when count of transition = 0, then we can't do any transaction.
 *            Everything else is same as BTTBASS2.  
 * 
 * FOR BTBASS4 : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/ instead of 2 transactions, we can do at most k transactions.
 * FOR BTBASS4 GFG : https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/
 */
public class BTTBASS3 
{
    class Solution {
        public int calculateMaxProfit(int dayIndex, int holdingStock, int countOfTransition, int[] stockPrices, int[][][] memo) {
            if (countOfTransition == 0) return 0;
            if (dayIndex == stockPrices.length) return 0;
            if (memo[dayIndex][holdingStock][countOfTransition] != -1)
                return memo[dayIndex][holdingStock][countOfTransition];

            int maxProfit = 0;
            if (holdingStock == 1) {
                maxProfit = Math.max(-stockPrices[dayIndex] + calculateMaxProfit(dayIndex + 1, 0, countOfTransition, stockPrices, memo),
                        0 + calculateMaxProfit(dayIndex + 1, 1, countOfTransition, stockPrices, memo));
            } else {
                maxProfit = Math.max(stockPrices[dayIndex] + calculateMaxProfit(dayIndex + 1, 1, countOfTransition - 1, stockPrices, memo),
                        0 + calculateMaxProfit(dayIndex + 1, 0, countOfTransition, stockPrices, memo));
            }

            return memo[dayIndex][holdingStock][countOfTransition] = maxProfit;
        }
        public int tabulationMethod(int[] stockPrices) {
            int numberOfDays = stockPrices.length;
            int[][][] memoTable = new int[numberOfDays + 1][2][3];
            for (int[][] row : memoTable) {
                for (int[] row2 : row) {
                    Arrays.fill(row2, -1);
                }
            }
    
            // Fix: Adjust the loop bounds for the base case initialization
            // Base case 1: count of transition = 0 for any day and holding stock
            for (int i = 0; i <= numberOfDays; i++) { // Fix: Use <= instead of <
                for (int j = 0; j < 2; j++) {
                    memoTable[i][j][0] = 0;
                }
            }
    
            // Base case 2: dayIndex = numberOfDays for any count of transition and holding stock
            for (int i = 0; i < 2; i++) {
                for (int j = 1; j < 3; j++) {
                    memoTable[numberOfDays][i][j] = 0; // Fix: Use numberOfDays instead of numberOfDays - 1
                }
            }
    
            for (int idx = numberOfDays - 1; idx >= 0; idx--) {
                for (int buy = 0; buy < 2; buy++) {
                    for (int numberOfTransition = 1; numberOfTransition < 3; numberOfTransition++) {
                        int maxProfit = 0;
                        if (buy == 1) {
                            maxProfit = Math.max(-stockPrices[idx] + memoTable[idx + 1][0][numberOfTransition],
                                    0 + memoTable[idx + 1][1][numberOfTransition]);
                        } else {
                            maxProfit = Math.max(stockPrices[idx] + memoTable[idx + 1][1][numberOfTransition - 1],
                                    0 + memoTable[idx + 1][0][numberOfTransition]);
                        }
                        memoTable[idx][buy][numberOfTransition] = maxProfit;
                    }
                }
            }
            return memoTable[0][1][2];
        } 

        int spaceOptimisedCode(int[] stockPrices){
            int numberOfDays = stockPrices.length;
            int[][] afterArray = new int[2][3];
            int[][] currArray = new int[2][3];
            for(int i = 0 ; i < 2 ; i++){
                for(int j = 0 ; j < 3 ; j++){
                    afterArray[i][j] = 0;
                    currArray[i][j] = 0;
                }
            }
    
            for (int idx = numberOfDays - 1; idx >= 0; idx--) {
                for (int buy = 0; buy < 2; buy++) {
                    for (int numberOfTransition = 1; numberOfTransition < 3; numberOfTransition++) {
                        int maxProfit = 0;
                        if (buy == 1) {
                            maxProfit = Math.max(-stockPrices[idx] + afterArray[0][numberOfTransition],
                                    0 + afterArray[1][numberOfTransition]);
                        } else {
                            maxProfit = Math.max(stockPrices[idx] + afterArray[1][numberOfTransition - 1],
                                    0 + afterArray[0][numberOfTransition]);
                        }
                        currArray[buy][numberOfTransition] = maxProfit;
                    }
                }
                afterArray = Arrays.copyOf(currArray, currArray.length);
            }
            return currArray[1][2];
        }
        public int maxProfit(int[] stockPrices) {
            // int numberOfDays = stockPrices.length;
            // int[][][] memoTable = new int[numberOfDays][2][3];
            // for (int[][] row : memoTable) {
            //     for (int[] row2 : row) {
            //         Arrays.fill(row2, -1);
            //     }
            // }

            // return calculateMaxProfit(0, 1, 2, stockPrices, memoTable); // 1 means holding stock
            // return tabulationMethod(stockPrices);
            return spaceOptimisedCode(stockPrices);
        }
    }

}
