class Solution {
public:
    // vector<int> dp;
    int LCS(string s1, string s2, int n , int m)
    {
        int t[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // int del = word1.size() - LCS(word1,word2,n,m);
        // int insert = word2.size() - LCS(word1,word2,n,m);

        return n + m - 2*LCS(word1,word2,n,m);
    }
};