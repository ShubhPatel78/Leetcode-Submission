class Solution {
public:
    int f(vector<int>&nums,int k){
        int l=0;
        int r=0;
        int c=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]>k){
                l=r+1;
            }
            c=c+(r-l+1);
            r++;
        }
        return c;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return f(nums,right)-f(nums,left-1);
    }
};