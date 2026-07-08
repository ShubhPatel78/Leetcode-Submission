class Solution {
public:
    vector<int>f(int a){
        vector<int>temp;
        for(int i=1;i<=a;i++){
            if(a%i==0){
                temp.push_back(i);
            }
        }
        return temp;
    }
    int commonFactors(int a, int b) {
        vector<int>p;
        vector<int>q;
        p=f(a);
        q=f(b);
        int ans=0;
        for(int i=0;i<p.size();i++){
            for(int j=0;j<q.size();j++){
                if(p[i]==q[j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};