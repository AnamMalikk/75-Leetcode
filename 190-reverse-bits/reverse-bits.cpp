class Solution {
public:
    int reverseBits(int n) {
        int bitSize = 32;
        vector<int> bits(bitSize, 0);

        for (int i = bits.size() - 1; i >= 0; i--) {
            if (pow(2, i) <= n) {
                bits[i] = 1;
                n -= pow(2, i);
            }
        }

        int ans = 0;

        for (int i = 0; i < bitSize; i++) {

            if (bits[i] == 1) {
                // with 10 in 4 bits, we will have 0 1 0 1,
                // we iterate from 0, so i is the first bit of n,
                // but it will be the last bit of reversedN.
                // That's why we use bitSize - i - 1.
                ans += pow(2, bitSize - i - 1);
            }
        }

        return ans;
    }
};