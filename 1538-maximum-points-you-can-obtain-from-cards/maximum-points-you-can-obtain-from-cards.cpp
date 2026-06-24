class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ls=0;
        for(int i=0;i<=k-1;i++){
            ls=ls+cardPoints[i];
        }
        int maxi=ls;
        int rs=0;
        int ri=n-1;
        for(int i=k-1;i>=0;i--){
            ls=ls-cardPoints[i];
            rs=rs+cardPoints[ri];
            ri--;
            maxi=max(maxi,ls+rs);
        }
        return maxi;
    }
};