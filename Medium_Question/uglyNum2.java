package Medium_Question;
/*
 * Problem name : Ugly Number II
 * Problem Link : https://leetcode.com/problems/ugly-number-ii/
 * Explanatiion : https://www.geeksforgeeks.org/ugly-numbers/
 * 
 */

class Solution1 {
    boolean check(int n){
        while(n > 1){
            if(n % 2 == 0) n /= 2; 
            else if(n % 3 == 0) n /= 3; 
            else if(n % 5 == 0) n /= 5;
            else return false ;
        }

        return (n == 1);
    }
    public int nthUglyNumber(int n) {
        int ctr = 0 ;
        int i   = 0 ;
        while(ctr < n){
            if(check(i)){
                ctr++;
            }
            i++;
        }
        return (i - 1);
    }
}

class Solution2 {
    public int nthUglyNumber(int n) {
        int[] uglyNum = new int[1691];
        uglyNum[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int fac2 = 2;
        int fac3 = 3;
        int fac5 = 5;
        for (int i = 1; i < 1691; i++) {
            int mini = Math.min(fac2, Math.min(fac3, fac5));
            uglyNum[i] = mini;
            if (fac2 == mini) fac2 = 2 * uglyNum[++i2];
            if (fac3 == mini) fac3 = 3 * uglyNum[++i3];
            if (fac5 == mini) fac5 = 5 * uglyNum[++i5];
        }
        return uglyNum[n - 1];
    }
}
