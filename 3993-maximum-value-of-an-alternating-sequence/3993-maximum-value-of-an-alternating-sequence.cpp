class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        long long add=n/2;
        return 1LL*s+1LL*add*m-(add-1);
    }
};