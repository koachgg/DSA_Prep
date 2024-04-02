class Solution {
public:
    vector<int>NSL(vector<int>&arr){
        vector<int>v;
        stack<pair<int,int>>s;
        for(int i=0;i<arr.size();i++){
            if(s.size()==0){
                v.push_back(-1);
            }
            else if(s.size()>0 && s.top().first<arr[i]){
                v.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        return v;
    }

    vector<int>NSR(vector<int>&arr){
        vector<int>v;
        stack<pair<int,int>>s;
        int pcode=arr.size();
        for(int i=arr.size()-1;i>=0;i--){
            if(s.size()==0){
                v.push_back(pcode);
            }
            else if(s.size()>0 && s.top().first<arr[i]){
                v.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(pcode);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int>left(n),right(n),width(n),area(n);
        left=NSL(heights);
        right=NSR(heights);
        int ans = heights[0];
        for(int i=0;i<n;i++){
            width[i]=right[i]-left[i]-1;
        }

        for(int i=0;i<n;i++){
            area[i]=heights[i]*width[i];
            ans=max(ans,area[i]);
        }
        return ans;
    }
};