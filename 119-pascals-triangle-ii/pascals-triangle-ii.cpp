class Solution {
public:
    vector<int> getRow(int rowIndex) {
     long long ans = 1;
     vector<int> ansRow;
     ansRow.push_back(1);
     for(int col=1;col<=rowIndex;col++){ // 0 based indexing is used here if it was 1- indexed
        ans = ans * (rowIndex-col+1); // then no need of adding +1
        ans = ans /col;
        ansRow.push_back(ans);
     }   
     return ansRow;
    }
};