class Solution {
public:
    bool checkValidString(string s) {
        int m = s.length();
        int min = 0,max = 0;
        for(int i=0;i<m;i++)
        {
            if(s[i]=='(')
            {
                min = min + 1;
                max = max + 1;
            }
            else if(s[i]==')')
            {
                min = min - 1;
                max =  max - 1;
            }
            else
            {
                min = min - 1;
                max = max + 1;
            }
            if(min<0)
            min=0;
            if(max < 0)
            return false;
        }
        return min==0;
    }
};