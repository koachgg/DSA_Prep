class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size()){
            return "";
        }
        map<char,int> m;
        int n = s.size();

        int count =0;

        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }

        count = m.size();

        int i = 0;
        int j = 0;

        int mini =INT_MAX;
        int start =0;

        string temp;

        while(j != n){

            if(m.find(s[j]) != m.end()){
                m[s[j]]--;

                if(m[s[j]] ==  0){
                    count--;
                }
            }

            if(count == 0){

                while( count == 0){

                    if(j-i+1 < mini){
                        mini = j-i+1;
                        start =i;
                    }

                    if(m.find(s[i]) != m.end()){
                        m[s[i]]++;

                        if(m[s[i]] > 0){
                            count++;
                        }
                    }
                    i++;
                }
            }

            j++;
        }

        cout<<mini<<'\n';

        if(mini == INT_MAX){
            return "";
        }
        else{
            return s.substr(start,mini);
        }
    }
};