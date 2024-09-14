class Solution {
public:
    int hammingWeight(int n) {
        // int res = 0;
        // int bit =0;

        // while(n!=0){
        //     bit = n &1;
        //     if(bit==1){
        //         res++;
        //     }
        //     n=n>>1;
        // }
        // return res;

        int res = 0;
        while(n!=0){
            n = n & (n-1);
            res++;
        }
        return res;
    }
};