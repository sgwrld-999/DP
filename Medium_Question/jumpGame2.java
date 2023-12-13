package Medium_Question;
import java.util.Arrays;
/*
 * Problem name : Jump Game II
 * Problem Link : https://leetcode.com/problems/jump-game-ii/
 * Problem Link : https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
 * Explanation : 
 *          Whatever index we are from that index we can jump to any index in the range of 1 to nums[idx]
 *          for finding the minimum number of jumps we have to iterate over all the possible jumps and find the minimum
 *          number of jumps required to reach the end of the array.
 */

 class Solution1 {
    
    public int recursionMemo(int idx, int[] nums, int[] dp) {
        if (idx >= nums.length - 1) return 0;
        if (dp[idx] != -1) return dp[idx];

        int jump = nums[idx];
        int miniStep = 1000000007;

        for (int i = 1; i <= jump && idx + i < nums.length; i++) {
            int step = 1 + recursionMemo(idx + i, nums, dp);
            miniStep = Math.min(step, miniStep);
        }

        return (dp[idx] = miniStep);
    }

    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        return recursionMemo(0, nums, dp);
    }
}
class Solution2 {
    public int tabulation(int[] nums) {
    int n = nums.length;
    int[] dp = new int[n];
    Arrays.fill(dp, Integer.MAX_VALUE);

    dp[0] = 0;

    for (int idx = 0; idx < n; idx++) {
        int jump = nums[idx];
        for (int i = 1; i <= jump && idx + i < n; i++) {
            dp[idx + i] = Math.min(dp[idx + i], 1 + dp[idx]);
        }
    }

    return dp[n - 1] == Integer.MAX_VALUE ? -1 : dp[n - 1];
}

    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        return tabulation(nums);
    }
}
