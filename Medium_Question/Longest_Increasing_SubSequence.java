package Medium_Question;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
/*
 * Problem name : Longest Increasing Subsequence
 * Problem URL  : https://leetcode.com/problems/longest-increasing-subsequence/
 * Problem LInk : https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
 * Explanation  :
 *             - Approach 1 : Recursion simmilar to the pick and don't pick approach
 *             - Approach 2 : Recursion + Memoization
*              - Approach 3 : Tabulation
*              - Approach 4 : Space Optimized Tabulation
               - Approach 5 : Binary Search
    Approach 5 : 
    THe thought process behind this approach is that we will create a list which will be equal to the length of the array.
    Example : 
    nums = [10,9,2,5,3,7,101,18]
    Iterating over array
    i = 0 -> list1 = [10]
    i = 1 -> list2 = [9]
    i = 2 -> list3 = [2]
    i = 3 -> list3 = [2,5]
    i = 4 -> list3 = [2,5,3]
    i = 5 -> list3 = [2,5,3,7]
    i = 6 -> list3 = [2,5,3,7,101] & list1 = [10,101] & list2 = [9,101]
    i = 7 -> list3 = [2,5,3,7,18] & list1 = [10,101] & list2 = [9,101] & list4 = [18]
    Now we can see that the length of the list is the length of the longest increasing subsequence. 
    Using the similar idea instead of creating a list we can create a single and whenever we encourter the small element than the 
    last element of the list we will replace the last element of the list with the current element.
    Example :
    nums = [10,9,2,5,3,7,101,18]
    Iterating over array
    i = 0 -> list1 = [10]
    i = 1 -> list1 = [9]
    i = 2 -> list1 = [2]
    i = 3 -> list1 = [2,5]
    i = 4 -> list1 = [3,5]
    i = 5 -> list1 = [3,5,7]
    i = 6 -> list1 = [3,5,7,101]
    i = 7 -> list1 = [3,5,7,18]
    Now we can see that the length of the list is the length of the longest increasing subsequence.
    NOTE : the list we've stored is not the answer but the length of the list is the answer.

 *                         
 * 
 */
public class Longest_Increasing_SubSequence {
    class Solution {
    public int recursion(int idx,int prevIdx,int n,int[] nums) {
        if(idx == n)return 0;

        int notTake = 0 + recursion(idx+1,prevIdx,n,nums);
        int take = 0 ;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = recursion(idx+1,idx,n,nums) + 1 ;
        } 

        return Math.max(notTake,take);
    }
    public int recursionMemo(int idx,int prevIdx,int n,int[] nums,int[][] dp) {
        if(idx == n)return 0;
        if(dp[idx][prevIdx+1]  != -1) return dp[idx][prevIdx+1];
        int notTake = 0 + recursionMemo(idx+1,prevIdx,n,nums,dp);
        int take = 0 ;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = recursionMemo(idx+1,idx,n,nums,dp) + 1 ;
        } 

        return dp[idx][prevIdx+1] = Math.max(notTake,take);
    }
    public int tabulation(int n, int[] nums, int[][] dp) {
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--) {
                int notTake = dp[idx + 1][prevIdx + 1];
                int take = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    take = dp[idx + 1][idx + 1] + 1;
                }

                dp[idx][prevIdx + 1] = Math.max(notTake, take);
            }
        }
        return dp[0][0];
    }
    int spaceOpt(int n, int[] nums) {
        int[] dp1 = new int[n + 1];
        int[] dp2 = new int[n + 1];
        Arrays.fill(dp1, 0);
        Arrays.fill(dp2, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--) {
                int notTake = dp2[prevIdx + 1];
                int take = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    take = dp2[idx + 1] + 1;
                }

                dp1[prevIdx + 1] = Math.max(notTake, take);
            }
            int[] temp = dp1;
            dp1 = dp2;
            dp2 = temp;
        }
        return dp2[0];
    } 
    public int binarySearch(int[] a){
        int n = a.length;
        if (n == 0)
            return 0;

        List<Integer> ans = new ArrayList<>();
        ans.add(a[0]);

        for (int i = 1; i < n; i++) {
            if (a[i] > ans.get(ans.size() - 1)) {
                ans.add(a[i]);
            } else {
                int index = Arrays.binarySearch(ans.toArray(new Integer[0]), a[i]);
                if (index < 0) {
                    index = -index - 1;
                }
                ans.set(index, a[i]);
            }
        }

        return ans.size();
    }
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n + 1][n + 1];
        for (int[] row : dp)
            Arrays.fill(row, 0);
        return tabulation(n, nums, dp);
    }
}
}
