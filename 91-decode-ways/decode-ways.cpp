// class Solution {
// public:
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> dp(n+1);
//         dp[0] = 1;
//         dp[1] = s.charAt(0) =='0' ? 0:1;


//         for(int i=2;i<=n;i++){
//             int oneDigit = s[i-1] - '0';
//             int twoDigit = (s[i-2]-'0')*10
//         }
//     }
// };

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        
        for (int i = 2; i <= n; ++i) {
            int oneDigit = stoi(s.substr(i - 1, 1));
            int twoDigits = stoi(s.substr(i - 2, 2));
            
            if (oneDigit >= 1 && oneDigit <= 9)
                dp[i] += dp[i - 1];
            
            if (twoDigits >= 10 && twoDigits <= 26)
                dp[i] += dp[i - 2];
        }
        
        return dp[n];
    }
};
