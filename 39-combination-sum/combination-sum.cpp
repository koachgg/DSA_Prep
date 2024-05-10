class Solution {
public:
    void combination(int index, int target, vector<int>& candidates, vector<int>&ds, vector<vector<int>>& ans){
        if(index==candidates.size()){
            if(target==0){
            ans.push_back(ds);
            }
            return;
        }

        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            combination(index,target-candidates[index],candidates,ds,ans);
            ds.pop_back();
        }

        combination(index+1,target,candidates,ds,ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        combination(0,target,candidates,ds,ans);
        return ans;
    }
};