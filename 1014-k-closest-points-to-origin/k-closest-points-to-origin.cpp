class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh;
        for(int i=0;i<points.size();i++){
            int distance = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            maxh.push({distance,{points[i][0],points[i][1]}});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<vector<int>> ans;
        while(!maxh.empty()){
            ans.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return ans;
    }
};