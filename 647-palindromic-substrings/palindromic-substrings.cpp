// class Solution {
// public:
//     int countSubstrings(string s) {
//        int res = 0;
//        for(int i=0;i<s.size();i++){
//         int l;
//         int r;
//         l=r=i;
//         // For ODD
//         while(l>=0 && r<s.size() && s[l]==s[r]){
//             res +=1;
//             l--;
//             r++;
//         }
//         // For Even
//         l = i;
//         r = i+1;

//         while(l>=0 && r<s.size() && s[l]==s[r]){
//             res +=1;
//             l--;
//             r++;
//         }

//        }
//        return res; 
//     }
// };

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += countPali(s, i, i);
            res += countPali(s, i, i + 1);
        }
        return res;
    }

private:
    int countPali(string s, int l, int r) {
        int res = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }
        return res;
    }
};
