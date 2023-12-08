package Medium_Question;
//{ Driver Code Starts
//Initial Template for Java
/*
 * Problem name : Maximum Points From Top Left To Bottom Right
 * Difficulty : Medium
 * Problem Link : https://practice.geeksforgeeks.org/problems/maximum-points-from-top-left-to-bottom-right/0/
 * 
*/
import java.util.*;
import java.io.*;

class GFG{
    public static void main(String args[]) throws IOException{
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int N=sc.nextInt();
            int [][]points=new int[N][3];
            for(int i=0;i<N;i++){
                for(int j=0;j<3;j++){
                    points[i][j]=sc.nextInt();
                }
            }
            Solution obj=new Solution();
            int res=obj.maximumPoints(points,N);
            System.out.println(res);
            
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    public int recursion(int day,int prevTask,int[][] points,int N){
        if(day == 0){
            int maxi = Integer.MIN_VALUE;
            for(int task = 0 ; task < 3 ; task++){
                if(task != prevTask) maxi = Math.max(maxi,points[0][task]);
            }
            return maxi ;
        }   
        int maxi = Integer.MIN_VALUE;
        for(int task = 0 ; task < 3 ; task++){
            if(task != prevTask) {
                int point = points[day][task] + recursion(day-1,task,points,N);
                maxi = Math.max(maxi,point);
            }
        }
        return maxi ;
    }
    public int recursionPlusMemo(int day,int prevTask,int[][] points,int N,int[][] dp){
        if(day == 0){
            int maxi = Integer.MIN_VALUE;
            for(int task = 0 ; task < 3 ; task++){
                if(task != prevTask) maxi = Math.max(maxi,points[0][task]);
            }
            return maxi ;
        }  
        if(dp[day][prevTask] != -1) return dp[day][prevTask];
        int maxi = Integer.MIN_VALUE;
        for(int task = 0 ; task < 3 ; task++){
            if(task != prevTask) {
                int point = points[day][task] + recursionPlusMemo(day-1,task,points,N,dp);
                maxi = Math.max(maxi,point);
            }
        }
        dp[day][prevTask] = maxi;
        return dp[day][prevTask] ;
    }
    public int tabulation(int points[][], int N) {
        int[][] dp = new int[N][3];
        for (int task = 0; task < 3; task++) {
            dp[0][task] = (task == 0) ? points[0][1] : Math.max(points[0][0], points[0][2]);
        }
        for (int day = 1; day < N; day++) {
            for (int currentTask = 0; currentTask < 3; currentTask++) {
                int maxPoints = Integer.MIN_VALUE;
                for (int prevTask = 0; prevTask < 3; prevTask++) {
                    if (prevTask != currentTask) {
                        int currentPoints = points[day][currentTask] + dp[day - 1][prevTask];
                        maxPoints = Math.max(maxPoints, currentPoints);
                    }
                }
                dp[day][currentTask] = maxPoints;
            }
        }
        int result = Integer.MIN_VALUE;
        for (int task = 0; task < 3; task++) {
            result = Math.max(result, dp[N - 1][task]);
        }

        return result;
    }



    public int maximumPoints(int points[][],int N){
        // return recursion(N-1,3,points,N);
        // int[][] dp = new int[N+1][4];
        // for(int[] arr : dp)Arrays.fill(arr,-1);
        // return recursionPlusMemo(N-1,3,points,N,dp);
        return tabulation(points,N);
    }
}
