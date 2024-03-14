class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;
        int ans=0;
        int hi= *max_element(nums.begin(),nums.end());
        while(lo<=hi){
            int mid=(lo+hi)/2;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]/mid)+((nums[i]%mid)!=0);
        }
        long long time=sum;
        if(time<=threshold){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
        }
        return ans;
    }
};



// class Solution {
// public:
//     long long sumOfD(vector<int> &nums,int div){
//         long long sum = 0;
//         for(int i =0;i<nums.size();i++){
//             sum += ceil((double)(nums[i])/(double)(div));
//         }
//         return sum;
//     }
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int low = 1;
//         int high = *max_element(nums.begin(),nums.end());

//         while(low<=high){
//             int mid = (low+high)/2;
//             if(sumOfD(nums,mid)<=threshold){
//                 high = mid+1;
//             }
//             else {
//                 low = mid-1;
//             }
//         }
//         return low;
//     }
// };