/*
 * Problem: Best Time to Buy and Sell Stock
 * Problem URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Explanation:
 *             - We have to find the maximum profit that we can make by buying and selling the stock
 *             - We can buy and sell the stock only once 
 *             - We can not sell the stock before buying it
 *             - We can not buy the stock after selling it
 *             - We have to buy the stock first and then sell it
 *             - We have to find the maximum profit that we can make by buying and selling the stock only once 
 *             - We have to find the maximum difference between the current price and the minimum price 
 *             - We have to find the minimum price in the array before the current price 
 *             - We have to find the maximum difference between the current price and the minimum price 
 *             - We have to find the minimum price in the array before the current price  
 *             - We have to find the maximum difference between the current price and the minimum price
 * 
 */

public class BTTBAS {
    class Solution {
        public int maxProfit(int[] prices) {
            int minPrice = prices[0];
            int maxProfit = 0;
            
            for (int currentPrice : prices) {
                int currentProfit = currentPrice - minPrice;
                maxProfit = Math.max(maxProfit, currentProfit);
                minPrice = Math.min(currentPrice, minPrice);
            }
    
            return maxProfit;
        }
    }
    
}
