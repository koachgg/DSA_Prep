class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum, int n) {
        bool t[n+1][sum+1];
        
        // Initialize the DP table
        for(int i = 0; i <n+1; i++) {
            for(int j = 0; j <sum+1; j++) {
                if(i == 0) {
                    t[i][j] = false; // If there are no numbers, we cannot form any sum > 0
                }
                if(j == 0) {
                    t[i][j] = true; // We can always form sum 0 with an empty set
                }
            }
        }

        // Correct the initialization to avoid premature exit
        // t[0][0] = true;

        // Fill the DP table
        for(int i = 1; i <n+1; i++) {
            for(int j = 1; j <sum+1; j++) {
                if(nums[i-1] <= j) {
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum % 2 != 0) {
            return false;
        } else {
            return subsetSum(nums, sum / 2, n);
        }
    }
};