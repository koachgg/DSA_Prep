// class Solution {
// public:
//     // int t[2001][2001]; //Cache memory for fast response
    
//     // Just a normal function for checking palindrome
//     bool isPalin(string &s, int i, int j){
//         while(i <= j){
//             if(s[i++] != s[j--]) return false;
//         }
//         return true;
//     }

//     int helper(string &s, int i, int j,vector<int> &t){
//         if(i >= j) return 0; // If there are no elements, then no partition needed.
        
//         // If subproblem is already calculated, then that from there
        
//         if(isPalin(s, i, j)) return 0; // If already is a palindrome, then no need to partitioning.
        
//         if(t[i][j] != -1) return t[i][j];

//         int mini = 1e9; // Mini variable for calculating, the minimum value
        
//         // Checking for all possibilities of partitioning, like - MCM
//         for(int k=i;k<=j-1;k++){
//           int left = 0;
//           int right =0;

//           if(t[i][k]!=-1){
//             left = t[i][k];
//           }
//           else{
//             left = helper(s,i,k);
//             t[i][k] = left;
//           }

//           if(t[k+1][j]!=-1){
//             right = t[k+1][j];
//           }
//           else {
//             right = helper(s,k+1,j);
//             t[k+1][j] = right;
//           }

//           int ans = left + right + 1;
//             // Update Minimum Variable
//             mini =min(mini, ans);
//         }
//         return t[i][j] = mini; // Store and return our answer
//     }    

//     int minCut(string s) {
//         //memset(t, -1, sizeof(t)); //Initialize cache memory with all '-1'
//          int n = s.size();
//         vector<int> t(n,-1);
//         return helper(s, 0, s.size()-1,t),;            
//     }
// };


class Solution {
public:
    bool check(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int f(int i, string&s, vector<int>&dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        for(int j=i; j<s.size(); j++){
            if(check(i, j, s)){
                int cnt=1+f(j+1, s, dp);
                ans=min(ans, cnt);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        vector<int>dp(s.size(), -1);
        return f(0, s, dp)-1;
    }
};