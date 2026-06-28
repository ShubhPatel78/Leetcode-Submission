class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mpp;
        for(int i=0;i<s1.size();i++){
            mpp[s1[i]]++;
        }
        if(s1.size()>s2.size()){
            return false;
        }
        int l=0;
        int r=0;
        map<char,int>curw;
        while(r<s1.size()){
            curw[s2[r]]++;
            r++;
        }
        if(mpp==curw){
            return true;
        }
        while(r<s2.size()){
            curw[s2[r]]++;
            curw[s2[l]]--;
            if(curw[s2[l]]==0){
                curw.erase(s2[l]);
            }
            l++;
            if(curw==mpp){
                return true;
            }
            r++;
        }
        return false;
    }
};