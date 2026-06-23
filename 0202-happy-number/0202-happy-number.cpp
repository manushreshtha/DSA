class Solution {
public:
    int ssum(int n){
        int sum=0;
        while(n>0){
            int x= n%10;
            sum=sum+x*x;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n!=1 && st.find(n)==st.end()){
            st.insert(n);
            n=ssum(n);
        }
        if(n==1) return true;
        else return false;
    }
};