package Medium_Question;


//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String line1[] = in.readLine().trim().split("\\s+");
            int N = Integer.parseInt(line1[0]);
            int W = Integer.parseInt(line1[1]);
            String line2[] = in.readLine().trim().split("\\s+");
            int val[] = new int[N];
            for(int i = 0;i < N;i++)
                val[i] = Integer.parseInt(line2[i]);
            String line3[] = in.readLine().trim().split("\\s+");
            int wt[] = new int[N];
            for(int i = 0;i < N;i++)
                wt[i] = Integer.parseInt(line3[i]);
                
            Solution ob = new Solution();
            System.out.println(ob.knapSack(N, W, val, wt));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    public static int recursion(int idx,int wgt,int val[],int wt[]){
        if(idx == 0) return (int)((wgt / wt[idx])*val[idx]);
        
        int notPick = recursion(idx-1,wgt,val,wt);
        int pick = 0;
        if(wt[idx] <= wgt) pick = val[idx] + recursion(idx,wgt-wt[idx],val,wt);
        
        return Math.max(pick,notPick);
    }
    public static int recursionMemo(int idx,int wgt,int val[],int wt[],int[][] dp){
        if(idx == 0) return (int)((wgt / wt[idx])*val[idx]);
        if(dp[idx][wgt] != -1) return dp[idx][wgt];
        int notPick = recursionMemo(idx-1,wgt,val,wt,dp);
        int pick = 0;
        if(wt[idx] <= wgt) pick = val[idx] + recursionMemo(idx,wgt-wt[idx],val,wt,dp);
        
        return (dp[idx][wgt] = Math.max(pick,notPick));
    }
    static int knapSack(int N, int W, int val[], int wt[])
    {
        int[][] dp = new int[N+1][W+1];
        for(int[] row : dp)Arrays.fill(row,-1);
        return recursionMemo(N-1,W,val,wt,dp);
    }
}