class Solution {
public:
    int f(vector<int>&nums,int goal){
        if(goal<0){
            return 0;
        }
        int l=0;
        int r=0;
        int count=0;
        long long sum=0;
        int n=nums.size();
        while(r<n){
            sum=sum+nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            count=count+(r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }
        int a=f(nums,k);
        int b=f(nums,k-1);
        return a-b;
    }
};