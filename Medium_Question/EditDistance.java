package Medium_Question;

import java.util.Arrays;
class Solution {
    int recursionMemo(int i,int j,String s, String t,int[][] dp){
        if(i < 0) return j+1 ;
        if(j < 0) return i+1 ;
        if (dp[i][j] != -1) return dp[i][j];
        if(s.charAt(i) == t.charAt(j)) {
            return dp[i][j]= 0 + recursionMemo(i-1,j-1,s,t,dp);
        }
        else{
            return dp[i][j]=1 + Math.min(recursionMemo(i-1,j,s,t,dp),Math.min(recursionMemo(i,j-1,s,t,dp),recursionMemo(i-1,j-1,s,t,dp)));
        }
    }
    public int tabulation(String s, String t) {
        int n = s.length();
        int m = t.length();
        int[][] dp = new int[n + 1][m + 1];

        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {//Using 1 based indexing
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();int[][] dp = new int[n + 1][m + 1];
        for (int[] rows : dp) Arrays.fill(rows, -1);
        return recursionMemo(n-1,m-1,word1,word2,dp);
    }
}