class Solution {
public:
    unordered_map<string,int> mp;
    bool solve(string a, string b){
        if (a.length() != b.length()) return false;
        if (a == b) return true;
        if (a.length() <= 1) return false;

        std::string key = a + ' ' + b;
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }

        int n = a.length();
        bool flag = false;

        for (int i = 1; i < n; ++i) {
            if ((solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i))) ||
                (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i)))) {
                flag = true;
                break;
            }
        }

        mp[key] = flag;
        return flag;
    }


    // bool solve(string a, string b){
    //     // Base conditions
    //     if(a.length()!=b.length()) return false;

    //     if(a.length()==0 && b.length()==0) return true;

    //     if(a.compare(b)==0) return true;

    //     if(a.length()|| b.length()<=1) return false;

    //     string key = a;
    //     key.push_back(' ');
    //     // key.append(b);
    //     key += b;
    //     if(mp.find(key)!=mp.end()){
    //         return mp[key];
    //     }

    //     int n = a.length();
    //     bool flag = false;
        
    //     for(int i=1;i<n;i++){
    //         if(solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true){
    //             flag = true;
    //             break;
    //         }
    //         if(solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true){
    //             flag = true;
    //             break;
    //     }
    // }
    //     return mp[key]= flag;
    // }

    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};