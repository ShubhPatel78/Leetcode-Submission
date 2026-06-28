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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a=f(nums,goal);
        int b=f(nums,goal-1);
        return a-b;
    }
};