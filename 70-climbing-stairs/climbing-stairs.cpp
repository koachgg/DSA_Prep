// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==1) return 1;
//         if(n==0) return 1;

//         int left = climbStairs(n-1);
//         int right = climbStairs(n-2);

//         return left + right;
//     }
// };


// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n + 1, 0);

//         dp[0] = 1;
//         dp[1] = 1;

//         for(int i = 2; i <= n; i++){
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int climbStairs(int n) 
    {
        if(n<=2)
            return n;

      int n1=1;
      int n2=2;
      int n3=0;
     
        for(int i=2;i<n;i++)
        {
            n3=n1+n2;  //solved using fibonacci approch
            n1=n2;
            n2=n3;
        }
        return n3;

    }
};