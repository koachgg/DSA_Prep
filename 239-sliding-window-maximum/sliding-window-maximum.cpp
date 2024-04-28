class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     int n = nums.size();
     vector<int> ans;
    //  vector<int> list;
     deque<int> list;
     int mx = INT_MIN;
     int i=0,j=0;
     while(j<n){
        // this is where the max comparison happens
        while(list.size()>0 && list.back()<nums[j]){
            list.pop_back();
        }
        list.push_back(nums[j]);

        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            ans.push_back(list.front());
            if(!list.empty()&&list.front()==nums[i]){
                list.pop_front();
            }
            i++;
            j++;
        }
     }  
     return ans;
    }
};