class Solution {
public:
    
    void solve(vector<int> nums,vector<int> output,vector<vector<int>> &ans){
        if(nums.size()==0){
            ans.push_back(output);
            return;
        }

        vector<int> op1 = output;
        vector<int> op2 = output;
        op2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,op1,ans);
        solve(nums,op2,ans);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,output,ans);
        return ans;
    }
};