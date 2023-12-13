package Medium_Question;
import java.util.Arrays;
/*
 * Problem name : Jump Game III
 * Problem Link : https://leetcode.com/problems/jump-game-iii/
 * 
 * 
 */
class Solution1 {
    public boolean recursion(int[] arr,int start,boolean[] vis){
        if(arr[start] == 0) return true;

        vis[start] = true;
        boolean right = false;
        if(start+arr[start] < arr.length && !vis[start+arr[start]]) right = recursion(arr,start+arr[start],vis);

        boolean left = false;
        if(start-arr[start] >= 0 && !vis[start-arr[start]]) left = recursion(arr,start-arr[start],vis);

        return (right | left);
    }

    public boolean canReach(int[] arr, int start) {
        boolean[] vis = new boolean[arr.length+1];
        return recursion(arr,start,vis);
    }
}

class Solution2 {
    public int recursionMemo(int[] arr, int start, boolean[] vis, int[] dp) {
        if (arr[start] == 0) return 1;
        if (dp[start] != -1) return dp[start];
        vis[start] = true;

        int right = 0;
        if (start + arr[start] < arr.length && !vis[start + arr[start]])
            right = recursionMemo(arr, start + arr[start], vis, dp);

        int left = 0;
        if (start - arr[start] >= 0 && !vis[start - arr[start]])
            left = recursionMemo(arr, start - arr[start], vis, dp);

        dp[start] = (right | left);
        return dp[start];
    }

    public boolean canReach(int[] arr, int start) {
        boolean[] vis = new boolean[arr.length + 1];
        int[] dp = new int[arr.length + 1];
        Arrays.fill(dp, -1);
        return (recursionMemo(arr, start, vis, dp) == 1);
    }
}