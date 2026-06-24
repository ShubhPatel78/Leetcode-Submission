class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxi=0;
        vector<int>hash(256,-1);
        while(r<n){
            if(hash[s[r]]!=-1){
                //we have seen this character
                //let us check if it is in our current window
                if(hash[s[r]]>=l){
                    //it is our window
                    l=hash[s[r]]+1;
                }
            }
            maxi=max(maxi,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxi;
    }
};