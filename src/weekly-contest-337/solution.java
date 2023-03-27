

// 1
class Solution {
    public int[] evenOddBit(int n) {
        int[] array = new int[2];
        int i=0;
        while (n != 0) {
            array[i]+=n&1;
            n>>=1;
            i^=1;
        }
        return array;
    }
}

