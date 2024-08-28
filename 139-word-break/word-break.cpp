class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
     vector<bool>dp(s.size()+1,false);
     int n = s.size();
     dp[n] = true;
    for(int i=n-1;i>=0;i--){
        for(const auto & w: wordDict){
            if((i+w.size())<=s.size() && s.substr(i,w.size())==w){
                dp[i] = dp[i+w.size()];
            }
            if(dp[i]) break;
        }
    }
    return dp[0];
    }
};