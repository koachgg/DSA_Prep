class Solution {
public:
    void solve(int index, string s, unordered_set<string> &st, vector<string>& ans, string str) {
        if (index == s.size()) {
            str.pop_back(); // Remove the last space
            ans.push_back(str);
            return;
        }

        string temp = "";
        for (int i = index; i < s.size(); i++) {
            temp += s[i];
            if (st.find(temp) != st.end()) {
                solve(i + 1, s, st, ans, str + temp + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string str = "";
        vector<string> ans;
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        solve(0, s, st, ans, str);
        return ans;
    }
};
