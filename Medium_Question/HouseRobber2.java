package Medium_Question;
/*
 * Problem name : House Robber 2
 * Problem Link : https://leetcode.com/problems/house-robber-ii/
 * Explanation : Created two temp arrays and solved the problem using the same approach as House Robber 1
 * Array 1 : Does not include the last element
 * Array 2 : Does not include the first element
 * 
 */
class Solution {
    public int solve(int arr[], int n) {
        int prev1 = arr[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = arr[i] + prev2;
            int notTake = prev1;
            int ans = Math.max(take, notTake);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

    public int rob(int[] arr) {
        int n = arr.length;
        if (n == 1) {
            return arr[0];
        }
        int[] temp1 = new int[n - 1];
        int[] temp2 = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            temp1[i] = arr[i];
        }
        for (int i = 1; i < n; i++) {
            temp2[i - 1] = arr[i];
        }
        int ans1 = solve(temp1, temp1.length);
        int ans2 = solve(temp2, temp2.length);
        return Math.max(ans1, ans2);
    }
}

public class HouseRobber2 {
    
}
