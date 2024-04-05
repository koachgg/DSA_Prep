class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int mxL[size];
        int mxR[size];
        mxL[0] = height[0];
        for(int i =1;i<size;i++){
            mxL[i] = max(mxL[i-1],height[i]);
        }
        mxR[size-1] = height[size-1];
        for(int i=size-2;i>=0;i--){
            mxR[i] = max(mxR[i+1],height[i]);
        }
        int water[size];
        for(int i=0;i<size;i++){
            water[i] = min(mxL[i],mxR[i])-height[i];
        }
        int sum = 0;
        for(int i=0;i<size;i++){
            sum = sum + water[i];
        }
        return sum;
    }
};