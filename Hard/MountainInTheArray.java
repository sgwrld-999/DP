import java.util.Arrays;
/*
 * Problem name :  Minimum Number of Removals to Make Mountain Array
 * Problem URL  : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
 * Problem LInk : https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
 * Explanation  :
 *               Similar to LIS, we'll create two dp arrays, one for the increasing subsequence and one from decreasing subsequence
 *               or increasing subsequence from the end.
 *              Then we'll find the maximum length of the subsequence from both the arrays.
 *              And if we add the two lengths and subtract 1 from it, we'll get the minimum number of elements to be removed.
 *              The reason for subtracting 1 is that the element at the peak will be counted twice.
 * 
 * 
 */
public class MountainInTheArray {

class Solution {
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        if (n == 0)
            return 0;

        int[] dp1 = new int[n];
        Arrays.fill(dp1, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp1[j] + 1 > dp1[i]) {
                    dp1[i] = dp1[j] + 1;
                }
            }
        }

        int[] dp2 = new int[n];
        Arrays.fill(dp2, 1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                if (nums[i] > nums[j] && dp2[j] + 1 > dp2[i]) {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxi = Math.max(dp1[i] + dp2[i] - 1, maxi);
            }
        }

        return n - maxi;
    }
}

}
