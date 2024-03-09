class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     int first = firstOccurrence(nums,target);
     if(first==-1) return {-1,-1};
     int last = lastOccurence(nums,target);
     if(last==-1) return {-1,-1};
     return {first,last};   
    }

private:    
    int firstOccurrence(vector<int>&nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
            else {
                high = mid -1;
            }
        }
        return ans;
    }
    int lastOccurence(vector<int> nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid]<target){
                low = mid +1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};