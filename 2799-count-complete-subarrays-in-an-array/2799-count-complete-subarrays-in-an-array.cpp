class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        set<int>temp;
        for(int i=0;i<n;i++){
            temp.insert(nums[i]);
        }
        int k=temp.size();
        for(int i=0;i<n;i++){
            set<int>s;
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                if(s.size()==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};