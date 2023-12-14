package Medium_Question;
import java.util.Arrays;
/*
 * Problem name : Minimum Deletions to Make String Palindrome
 * Problem Link : https://leetcode.com/problems/minimum-deletions-to-make-string-palindrome/
 * Explanation :
 *         How do we approach this problem?
 *         We need to genrate the longest palindromic sequence.
 *         In the given string there will be LPS which are already present now we need to find how we 
 *         can make the string pallindrome by adding the characters.
 *         So the remaining characters are the one which is not present in the LPS we need to add them 
 *         in such position such that the string becomes pallindrome.
 *         Means we have to find the length of LPS and then subtract it from the length of the string
 *         because the remaining characters are the one which we need to add to make the string pallindrome which 
 *         after adding will make the string pallindrome.
 * 
 */
class Solution {
    public int solveUsingMemoization(String a, String b, int i, int j, int[][] dp) {
        if (i == a.length() || j == b.length())
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        if (a.charAt(i) == b.charAt(j))
            return dp[i][j] = 1 + solveUsingMemoization(a, b, i + 1, j + 1, dp);
        else
            return dp[i][j] = Math.max(solveUsingMemoization(a, b, i, j + 1, dp), solveUsingMemoization(a, b, i + 1, j, dp));
    }
    public int minInsertions(String s) {
        int n = s.length();
        StringBuilder revStr = new StringBuilder();
        for (int i = 0; i < n; i++) {
            revStr.append(s.charAt(n - 1 - i));
        }

        int[][] dp = new int[n + 1][n + 1];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return (s.length()-solveUsingMemoization(s, revStr.toString(), 0, 0, dp)); 
    }
}