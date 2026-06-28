class Solution {
public:
    int numRescueBoats(vector<int>&nums,int limit) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<=r){
            if(nums[l]+nums[r]<=limit){
                 l++;
                 r--;
            }
            else{
                r--;
            }
            ans++;
        }
        return ans;
    }
};