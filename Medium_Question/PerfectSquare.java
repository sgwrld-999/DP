package Medium_Question;
import java.util.Arrays;
// Problem name : Perfect Squares
// Problem Link : https://leetcode.com/problems/perfect-squares/
/*
 * Explanation :
 *         We have explore all the possible ways to make the number n.
 *         To do that we can use recursion and check for all the possible ways
 *         to make the number n.
 *         If the number if given n so we have to find the perfect square numbers which
 *         are less than or equal to n and then we can subtract the perfect square number
 *         from n and then we can again check for the perfect square numbers which are less
 *         than or equal to n and then we can subtract the perfect square number from n and
 *         then we can again check for the perfect square numbers which are less than or equal
 *         to n and then we can subtract the perfect square number from n and so on.
 *         We can use recursion to do that.  
 */
class Solutio1 {
    int recursion(int n ){
        if(n == 0) return 0;

        int minCtr = Integer.MAX_VALUE;

        for(int i = 1 ; i * i <=  n ; i++){
            int res = 1 + recursion(n-(i*i));

            minCtr = Math.min(minCtr,res);
        }

        return minCtr ;
    }
    public int numSquares(int n) {
        return recursion(n);
    }
}

class Solution2 {
    int recursionMemo(int n , int[] dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int minCtr = Integer.MAX_VALUE;

        for(int i = 1 ; i * i <=  n ; i++){
            int res = 1 + recursionMemo(n-(i*i),dp);

            minCtr = Math.min(minCtr,res);
        }

        return (dp[n] = minCtr) ;
    }
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        return recursionMemo(n,dp);
    }
}


class Solution3 {
    int tabulation(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);

        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            int minCtr = Integer.MAX_VALUE;

            for (int i = 1; i * i <= j; i++) { 
                int res = 1 + dp[j - (i * i)]; 

                minCtr = Math.min(minCtr, res);
            }

            dp[j] = minCtr;
        }

        return dp[n];
    }

    public int numSquares(int n) {
        return tabulation(n);
    }
}
