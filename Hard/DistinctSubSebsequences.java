
import java.util.Arrays;
/*
 *Problem name : Distinct Subsequences
 *Problem URL : https://leetcode.com/problems/distinct-subsequences/
 */

 /*
  * Explanation : 
  WHy we are using the recursion?
  Because there are multiple string in s which can be equal to t. And if we shrink the size of t 
  then we might miss some cases where the string in s is equal to t. So we have to check for all the
  cases. So we are using recursion.

COUNT THE NUMBER OF DISTINCT SUBSEQUENCES OF A STRING -> HINT -> RECURSION
F(i-1,j-1) -> Representing NUm of distinct subsequences of s[0...i-1] and t[0...j-1]
When return 1 -> When j == 0 -> Because we have found the subsequence
When return 0 -> When i == 0 -> Because we have reached the end of s but not t
When s[i] == t[j] -> We have two choices -> Either we can include the character or we can exclude the character
                    -> If we include the character then we have to find the number of distinct subsequences of s[0...i-1] and t[0...j-1]
                    -> If we exclude the character then we have to find the number of distinct subsequences of s[0...i-1] and t[0...j]
                    -> So we have to add both the choices
When s[i] != t[j] -> We have only one choice -> We have to exclude the character
                    -> So we have to find the number of distinct subsequences of s[0...i-1] and t[0...j]

  */

  /*
  * Approach : 
  * 1. Recursion
  * 2. Recursion + Memoization
  * 3. Tabulation
  * 4. Space Optimized Tabulation
*/

class Solution {
    public int recursion(int i,int j,String s, String t) {
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(s.charAt(i) == t.charAt(j)) {
            return recursion(i-1,j-1,s,t) + recursion(i-1,j,s,t);
        }
        else{
           return recursion(i-1,j,s,t); 
        } 
    }
    public int recursionMemo(int i, int j, String s, String t, int[][] dp) {
        if (j < 0) return 1;
        if (i < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s.charAt(i) == t.charAt(j)) {
            return dp[i][j] = recursionMemo(i - 1, j - 1, s, t, dp) + recursionMemo(i - 1, j, s, t, dp);
        } else {
            return dp[i][j] = recursionMemo(i - 1, j, s, t, dp);
        }
    }

    public int tabulation(String s, String t) {
        int n = s.length();
        int m = t.length();
        int[][] dp = new int[n + 1][m + 1];
        for (int[] rows : dp) Arrays.fill(rows, -1);
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int i = 1; i <= m; i++) dp[0][i] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
    public int spaceOpt(String s, String t) {
        int n = s.length();
        int m = t.length();
        int[] prev = new int[m + 1];
        int[] curr = new int[m + 1];
        Arrays.fill(prev, -1);
        Arrays.fill(curr, -1);
        prev[0] = 1;
        curr[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            System.arraycopy(curr, 0, prev, 0, m + 1);
        }
        return prev[m];
    }

    public int numDistinct(String s, String t) {
        return spaceOpt(s, t);
    }
}
