class Solution {
public:
    bool canJump(vector<int>& nums){
        int n=nums.size();
        vector<bool>dp(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            bool ans=false;
            for(int j=1;j<=nums[i];j++){
                if(i+j>n-1){
                    ans=true;
                    break;
                }
                else{
                    ans=ans|dp[i+j];
                }
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};