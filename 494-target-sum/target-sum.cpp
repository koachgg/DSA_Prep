// class Solution {
// public:
//     int countSubsetSum(vector<int> &nums,int sum,int n){
//         vector<vector<int>> t(n+1,vector<int> (sum+1,0));
//         if (sum < 0) return 0;
//         for(int i=0;i<n+1;i++){
//             t[i][0] = 1;
//         }
//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<sum+1;j++){
//                 if(nums[i-1]<=j){
//                     t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
//                 }
//                 else {
//                     t[i][j] = t[i-1][j];
//                 }
//             }
//         }
//         return t[n][sum];
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();

//         int sum = 0;
//         for(int i=0;i<n;i++){
//             sum += nums[i];
//         }

//         if((sum+target)%2!=0 || (sum + target)<0){
//             return 0;
//         }

//         int newTarget = (sum+target)/2;
//         return countSubsetSum(nums,newTarget,n);
//     }
// };

class Solution {
public:
    int CountSubsetsWithSum(vector<int>& arr, int n, int sum) {
        if (sum < 0) return 0;  // Early return if sum is negative

        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;  // There's always one subset (the empty subset) that sums to 0
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j]; // Include or exclude the current item
                else
                    t[i][j] = t[i - 1][j]; // Exclude the current item
            }
        }

        return t[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sumofarray = accumulate(nums.begin(), nums.end(), 0);

        // Check if (sumofarray + target) is non-negative and even
        if ((sumofarray + target) % 2 != 0 || (sumofarray + target) < 0) {
            return 0;
        }

        int newTarget = (sumofarray + target) / 2;
        return CountSubsetsWithSum(nums, n, newTarget);
    }
};