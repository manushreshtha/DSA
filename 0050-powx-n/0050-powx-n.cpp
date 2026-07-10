class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        return solve(x, N);
    }
    double solve(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2==0) return solve(x*x, n/2);
        return x*solve(x*x, n/2);
    }
};