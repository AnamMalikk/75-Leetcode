class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n),suff(n);
        // calculating prefix product
        pre[0]=1;
        int p=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=p;
            p*=nums[i];
        }
        // calculating suffix product
        suff[n-1]=1;
        p=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=p;
            p*=nums[i];
        }
        // Finding answer
        for(int i=0;i<n;i++) pre[i]*=suff[i];

        return pre;
    }
};