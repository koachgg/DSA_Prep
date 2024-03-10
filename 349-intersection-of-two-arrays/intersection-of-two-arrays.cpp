class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m =nums2.size();
        vector<int> result;
        unordered_map<int,int> mp;
        for(auto it:nums1){
            mp[it]++;
        }
        for(auto it:nums2){
            if(mp.find(it)!=mp.end()){
                result.push_back(it);
                mp.erase(it);
            }
        }
        return result;
    }
};