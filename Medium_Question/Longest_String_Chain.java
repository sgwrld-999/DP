package Medium_Question;

import java.util.Arrays;
import java.util.Comparator;
/*
 * Problem name : Longest String Chain
 * Problem URL  : https://leetcode.com/problems/longest-increasing-subsequence/
 * Problem LInk : https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
 * Explanation  :
 *              Since we've to find the Longest string chain, And since it's the
 *             longest increasing subsequence problem, we'll sort the array and then we'll apply the LIS approach.    
 *             Why sorting is required?
 *             Because we can pick from anywhere in the array. So, we'll sort the array and then we'll apply the LIS approach.
 *             We just need an additional check that the current element is one character longer than the previous element or not.
 * 
 */
public class Longest_String_Chain {
    class SortByLen implements Comparator<String> {
        @Override
        public int compare(String a, String b) {
            return Integer.compare(a.length(), b.length());
        }
    }

class Solution {
        private int max = 1;

        public boolean isPossible(String a, String b) {
            if (a.length() != b.length() + 1)
                return false;

            int i = 0;
            int j = 0;
            int n = a.length();
            int m = b.length();
            
            while (i < n ) {
                if (j < m && a.charAt(i) == b.charAt(j) ) {
                    i++;
                    j++;
                } else {
                    i++;
                }
            }

            return i == n && j == m;
        }

        public int longestStrChain(String[] nums) {
            int n = nums.length;
            if (n == 0)
                return 0;

            int[] dp = new int[n];
            Arrays.fill(dp, 1);

            Arrays.sort(nums, new SortByLen());

            System.out.println(Arrays.toString(nums));
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (isPossible(nums[i], nums[j]) && dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                    }
                }
                if (dp[i] > max) {
                    max = dp[i];
                }
            }
            return max;
        }
    }
}
