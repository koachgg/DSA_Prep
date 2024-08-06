// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = INT_MIN;
//         int prefix = 1;
//         int suffix = 1;
//         for(int i=0;i<n;i++){
//             if(prefix==0) prefix=1;
//             if(suffix==0) suffix = 1;

//             prefix *= nums[i];
//             suffix *=  nums[n-i-1];

//             maxi = max(maxi,max(prefix,suffix));
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 1, suff = 1;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(pref == 1000000000 || suff == 1000000000) break;
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;

            pref *= nums[i];
            suff *= nums[n-i-1];

            maxi = max(maxi, max(pref, suff));
        }
        return maxi;
    }
};