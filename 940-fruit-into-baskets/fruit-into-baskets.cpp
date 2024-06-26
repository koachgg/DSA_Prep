class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i=0,j=0;
        int mx = 0;
        unordered_map<int,int> mpp;

        while(j<n){
            mpp[fruits[j]]++;
            if(mpp.size()<=2){
                mx = max(mx,j-i+1);
                j++;
            }
            else if(mpp.size()>2){
                while(mpp.size()>2){
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]]==0){
                        mpp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};