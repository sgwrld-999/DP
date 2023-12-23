package Medium_Question;

import java.util.*;

/*
 * Problem name : Longest Divisible Subset
 * Problem URL  : https://leetcode.com/problems/largest-divisible-subset/
 * Problem LInk : https://www.geeksforgeeks.org/largest-divisible-subset-array/
 * Explanation  :
 *            In this we'll sort the array and then we'll apply the LIS approach with the slight modification.
 *            The modification is that we'll check if the current element is divisible by the previous element or not.
 *            The reason for sorting is that for being divisible the previous element should be smaller than the current element.
 *            Similar to LIS we'll create a dp array and a hash array to store the index of the previous element.
 * 
 *  
 * 
 * 
 */
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        if (n == 0) return new ArrayList<>();

        int[] dp = new int[n];
        int[] hash = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(hash, -1);

        int last = 0;
        int max = 1;

        Arrays.sort(nums);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > max) {
                max = dp[i];
                last = i;
            }
        }

        List<Integer> list = new ArrayList<>();
        int idx = 0;
        while (last != -1) {
            list.add(nums[last]);
            last = hash[last];
        }

        Collections.reverse(list);
        return list;
    }
}
