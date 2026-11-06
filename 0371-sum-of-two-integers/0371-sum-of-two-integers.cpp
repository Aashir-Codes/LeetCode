class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
        int sum_without_carry = a ^ b;       // Add without carry
        int carry = (a & b) << 1;            // Calculate carry
        a = sum_without_carry;
        b = carry;
        }
    
       return a;
    }
};