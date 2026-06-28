class Solution {
public:
    int MOD=1000000007;
    int rev(int num){
        int ans=0;
        while(num>0){
            int r=num%10;
            ans=ans*10+r;
            num=num/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int k=rev(nums[i]);
            nums[i]=nums[i]-k;
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int c=1;
        int curr=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==curr){
                ans=ans+c;
                c++;
            }
            else{
                c=1;
                curr=nums[i];
            }
        }
        ans=ans%MOD;
        return ans;
    }
};