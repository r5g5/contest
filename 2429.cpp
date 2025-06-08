class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int noOfSetBitsNum1 = __builtin_popcount(num1);
        int noOfSetBitsNum2 = __builtin_popcount(num2);
        if (noOfSetBitsNum1 == noOfSetBitsNum2)
            return num1;

        int ans = num1, i = 0;

        if (noOfSetBitsNum1 > noOfSetBitsNum2) {
            // remove extra ones from lsb
            while (noOfSetBitsNum1 - noOfSetBitsNum2 > 0) {
                // check if the bit is 0 or 1. If one, unset it.
                int bit = ans & (1 << i);
                if (bit) {
                    // set bit. unset it
                    ans = ans & ~(1 << i);
                    noOfSetBitsNum1--;
                }
                i++;
            }
        } else {
            // add extra ones from lsb
            while (noOfSetBitsNum2 - noOfSetBitsNum1 > 0) {
                // if bit is unset. Set it.
                int bit = ans & (1 << i);
                if (!bit) {
                    ans = ans | (1 << i);
                    noOfSetBitsNum1++;
                }
                i++;
            }
        }
        return ans;
    }
};