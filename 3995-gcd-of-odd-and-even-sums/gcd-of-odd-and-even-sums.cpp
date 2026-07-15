class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd((n*(2+(n-1)*2))/2,(n*(4+(n-1)*2))/2);
    }
};