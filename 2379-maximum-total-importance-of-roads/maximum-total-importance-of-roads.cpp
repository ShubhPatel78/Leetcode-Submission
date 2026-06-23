class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>v(n,0);
        for(int i=0;i<roads.size();i++){
            v[roads[i][0]]++;
            v[roads[i][1]]++;
        }
        double ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            ans=ans+((i+1)*v[i]);
        }
        return (long long)ans;
    }
};