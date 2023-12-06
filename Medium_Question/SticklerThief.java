package Medium_Question;

//{ Driver Code Starts
import java.util.*;
/*
 * Problem name : Stickler Thief or House Robber
 * Problem Link : https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#
 * Problem Link : https://leetcode.com/problems/house-robber/
 * Explanation : Pick or not pick recursion appraoch
 */
class GFG
 {
	public static void main (String[] args)
	 {
	  
	  //taking input using Scanner class
	  Scanner sc = new Scanner(System.in);
	  
	  //taking count of testcases
	  int t = sc.nextInt();
	  while(t-- > 0){
	      
	      //taking count of houses
	      int n = sc.nextInt();
	      int arr[] = new int[n];
	      
	      //inserting money present in 
	      //each house in the array
	      for(int i = 0; i<n; ++i)
	           arr[i] = sc.nextInt();
  	      
  	      //calling method FindMaxSum() of class solve
  	      System.out.println(new Solution().FindMaxSum(arr, n));
	 }
   }
}
// } Driver Code Ends


class Solution
{
    //Function to find the maximum money the thief can get.
    public int solve(int idx,int[] arr,int n,int[] dp){
        if(idx < 0) return 0;
        if(idx == 0) return arr[idx];
        if(dp[idx] != -1) return dp[idx];
        int pick = arr[idx] + solve(idx-2,arr,n,dp);
        int notPick = 0 + solve(idx-1,arr,n,dp);
        
        dp[idx] = Math.max(pick,notPick);
        return dp[idx];
    }
    public int solve1(int arr[],int n){
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        dp[0] = arr[0];
        int neg = 0 ;
        for(int i = 1 ; i < n ; i++){
            int take = arr[i];
            if(i > 1) take += dp[i-2];
            int notTake = 0 + dp[i-1];
            dp[i] = Math.max(take,notTake);
        }
        return dp[n-1];
    }
    public int solve3(int arr[],int n){
        int prev1 = arr[0];
        int prev2 = 0 ;
        for(int i = 1 ; i < n ; i++){
            int take = arr[i];
            if(i > 1) take += prev2;
            int notTake = 0 + prev1;
            int ans = Math.max(take,notTake);
            prev2 = prev1 ;
            prev1 = ans;
        }
        return prev1;
    }
    public int FindMaxSum(int arr[], int n)
    {
        // Your code here
        
        return solve3(arr,n);
    }
}