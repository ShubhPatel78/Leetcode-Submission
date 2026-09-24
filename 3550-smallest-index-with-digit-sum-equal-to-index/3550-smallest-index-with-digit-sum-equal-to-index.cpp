class Solution {
public:
    int f(int n){
        int ans=0;
        while(n>0){
            int r=n%10;
            ans=ans+r;
            n=n/10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==f(nums[i])){
                return i;
            }
        }
        return -1;
    }
};