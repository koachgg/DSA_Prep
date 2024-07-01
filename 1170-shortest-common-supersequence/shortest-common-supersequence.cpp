// class Solution {
// public:
//        vector<vector<int>> dp;
//     string shortestCommonSupersequence(string str1, string str2) {
//      dp.resize(str1.size()+1,vector<int>(str2.size()+1));

//     }
// };



class Solution {
public:
    vector<vector<int>> dp;
    string lcsstr(string &str1 , string &str2){

        int i = str1.size();
        int j = str2.size();
        string lcs = "";
        while(i != 0 && j != 0){

            if(str1[i-1] == str2[j-1]){

                lcs += str1[i-1];
                i--;
                j--;
            }
            else  if(dp[i-1][j] > dp[i][j-1]){

                i--;
                
            }
            else{

                j--;
            }

        }
        reverse(lcs.begin() , lcs.end());
        return lcs;
    }
    string shortestCommonSupersequence(string str1, string str2) {

        dp.resize(str1.size()+ 1 , vector<int>(str2.size()+1 , 0));

        for(int i = 1; i <= str1.size(); i++){

            for(int j = 1; j <= str2.size(); j++){

                if(str1[i-1] == str2[j-1]){

                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{

                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        string lcs = lcsstr(str1,str2);

        string ans = "";
        int i = 0;
        int p1 = 0,p2 = 0;
        while(i < lcs.size()){

            while(p1 < str1.size() && str1[p1] != lcs[i]){

                ans += str1[p1];
                p1++;
            }
            while(p2 < str2.size() && str2[p2] != lcs[i]){

                ans += str2[p2];
                p2++;
            }

            ans += lcs[i];
            i++;
            p1++;
            p2++;
        
        }
        while(p1 < str1.size() ){

            ans += str1[p1];
            p1++;
        }
        while(p2 < str2.size() ){

            ans += str2[p2];
            p2++;
        }
        

        return ans;


        
    }
};