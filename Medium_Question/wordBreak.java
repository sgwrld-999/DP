package Medium_Question;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

/*
 * Problem name : Word Break
 * Problem Link : https://leetcode.com/problems/word-break/
 * Explanation  : https://youtu.be/oBUpyPZ08zU?si=jTYeKOOaGPiuJBRy
 *                 We have to break the string into substring and check if all the breaked components 
 *                 are present in the dictionary or not.
 *                 Breaking the string into substring means we've to use a loop to break the string
 *                 into substring and then we've to check if the substring is present in the dictionary
 *                 or not.
 * 
 */
class Solution1 {
    HashSet<String> st = new HashSet<String>();

    public boolean recursion(int idx, int n, String s) {
        if (idx >= n) return true;

        if (st.contains(s)) return true;
        for (int i = 1; idx + i <= n; i++) { 
            String str = s.substring(idx, idx + i);
            if (st.contains(str) && recursion(idx + i, n, s)) return true;
        }

        return false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();

        for (String str : wordDict) st.add(str);

        return recursion(0, n, s);
    }
}

class Solution2 {
    HashSet<String> st = new HashSet<String>();
    int dp[] = new int[301];
    public boolean recursion(int idx, int n, String s) {
        if (idx >= n) return true;
        if(dp[idx] != -1) return (dp[idx]==1);
        if (st.contains(s)) return true;
        for (int i = 1; idx + i <= n; i++) { 
            String str = s.substring(idx, idx + i);
            if (st.contains(str) && recursion(idx + i, n, s)){
                dp[idx] = 1;
                return true;
            } 
        }
        dp[idx] = 0 ;
        return false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        Arrays.fill(dp,-1);
        for (String str : wordDict) st.add(str);

        return recursion(0, n, s);
    }
}