class Solution {
public:
    int findMax(vector<int> &piles){
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi = max(piles[i],maxi);
        }
        return maxi;
    }

    long long totalhours(vector<int> &piles,int h){
        long long totalH=0;
        for(int i=0;i<piles.size();i++){
            totalH += ceil((double)piles[i]/(double)h);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles); 
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            long long totalHr = totalhours(piles,mid);
            if(totalHr<=h){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }       
        return ans;
    }
};