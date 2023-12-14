package Medium_Question;

import java.util.Arrays;
/*
 * Problem naeme : Delete Operation for Two Strings
 * Problem Link : https://leetcode.com/problems/delete-operation-for-two-strings/
 * Explanation : 
 * Q1 -> Is posiible to convert one string to another string?
 * Ans-> Yes, removing the character from one string and adding the another string.
 * Q2 -> What can be deleted from the string?
 * Ans-> We can delete any character from the string but we'll delete which is not present in the another string.
 * Q3 -> What can we add to the string?
 * Ans-> We can add any character to the string but we'll add which is not present in the another string.
 * 
 * Example : abcde, ace
 * LCS -> ace 
 * deletion -> 2
 * insertion -> 0
 * Ans  -> 2 
 */
class Solution {
    int solveUsingMemoization(String a, String b, int i, int j, int[][] dp) {
        if (i == a.length() || j == b.length())
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];
        
        if (a.charAt(i) == b.charAt(j))
            return dp[i][j] = 1 + solveUsingMemoization(a, b, i + 1, j + 1, dp);
        else
            return dp[i][j] = Math.max(solveUsingMemoization(a, b, i, j + 1, dp), solveUsingMemoization(a, b, i + 1, j, dp));
    }
    
    public int minDistance(String word1, String word2) {
       int a = word1.length();
       int b = word2.length();
       int[][] dp = new int[a+1][b+1];

       for (int[] row : dp) Arrays.fill(row, -1);
       
       int common = solveUsingMemoization(word1, word2, 0, 0, dp);
       return (word1.length() - common + word2.length() - common);//(deletion + insertion)
    }
}
