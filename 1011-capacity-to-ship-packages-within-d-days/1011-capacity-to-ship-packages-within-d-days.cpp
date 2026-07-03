class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(), weights.end(),0);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=1;
            int caps=0;
            for(int i:weights){
                caps=caps+i;
                if(caps>mid){
                    cnt++;
                    caps=i;
                }
            }
            if(cnt<=days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }   
        return ans; 
    }
};