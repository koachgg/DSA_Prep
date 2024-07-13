class Solution {
public:
	    void permute(vector<int> &s,int start, vector<vector<int>> &v){
	        if(start == s.size()-1){
	            v.push_back(s);
	            return;
	        }
	        
	        set<char> mp;
	        
	        for(int i=start;i<s.size();i++){
	            if(mp.find(s[i])==mp.end()){
	                mp.insert(s[i]);
	                swap(s[start],s[i]);
	                permute(s,start+1,v);
	                swap(s[start],s[i]);
	            }
	        }
	    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        	vector<vector<int>>v;
		    permute(nums,0,v);
		    return v;
    }
};

