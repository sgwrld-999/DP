package Medium_Question;

import java.util.Arrays;
import java.util.Collections;

public class Printing_The_LIS {
    public int countStoringAlgo(int[] nums){
        int n = nums.length;
        int[] dp = new int[n];
        int[] hash = new int[1001];
        Arrays.fill(hash,0);
        Arrays.fill(dp,1);
        int last = 0;
        int max = 1;
        for(int i = 1 ; i < n ; i++){
            hash[i] = i;
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j] || dp[j]+1 < dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i] > max){
                max = dp[i];
                last = i;
            }
        }
        int ans[] = new int[max];
        ans[0] = nums[last];
        int idx = 1;
        while (last != hash[last]) {
            last = hash[last];
            ans[--idx] = nums[last];
            idx++;
        }
        Collections.reverse(Arrays.asList(ans));
        return max;
    }
}
