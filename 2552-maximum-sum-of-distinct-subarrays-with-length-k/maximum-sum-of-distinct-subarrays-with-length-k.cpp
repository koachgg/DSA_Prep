class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        long long i=0,j=0;
        long long sum=0,mx=0;
        int count=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            sum+=nums[j];
            if(mp[nums[j]]==1) count++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(count==k){
                    mx=max(mx,sum);
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0) count--;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};