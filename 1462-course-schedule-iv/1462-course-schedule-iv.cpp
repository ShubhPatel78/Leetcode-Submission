class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<bool>>r(n,vector<bool>(n,false));
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            r[u][v]=true;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    r[i][j]=(r[i][j])||(r[i][k] && r[k][j]);
                }
            }
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(r[queries[i][0]][queries[i][1]]);
        }
        return ans;
    }
};