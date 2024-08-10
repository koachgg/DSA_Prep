class Solution {
public:
    int countSubstrings(string s) {
       int res = 0;
       for(int i=0;i<s.size();i++){
        int l;
        int r;
        l=r=i;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            res +=1;
            l--;
            r++;
        }

        l = i;
        r = i+1;

        while(l>=0 && r<s.size() && s[l]==s[r]){
            res +=1;
            l--;
            r++;
        }

       }
       return res; 
    }
};