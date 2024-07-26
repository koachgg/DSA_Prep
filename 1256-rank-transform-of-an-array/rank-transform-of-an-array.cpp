class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());

        unordered_map<int,int>mp;
        int i=1;
        for(auto it:temp){
            if(mp.find(it) !=mp.end()){
                continue;
            }else{
                mp[it]=i++;
            }  
        }
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;

    }   
};