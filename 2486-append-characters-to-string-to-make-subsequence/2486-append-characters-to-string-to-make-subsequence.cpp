class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        while(i<t.size() && j<s.size()){
            if(t[i]==s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==t.size()){
            return 0;
        }
        return t.size()-i;
    }
};