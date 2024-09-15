class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0;i<32;i++){
            uint32_t lsb =  n & 1;
            uint32_t rev_lsb = lsb << (31-i);
            result = result | rev_lsb;
            n=n>>1;
        }
        return result; 
    }
};