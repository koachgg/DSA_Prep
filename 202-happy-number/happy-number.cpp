// class Solution {
// public:
//     bool isHappy(int n) {
//        unordered_set<int> visit;

//        while(visit.find(n)==visit.end()){
//         visit.insert(n);
//         n = getNextNumber(n);
//         if(n==1){
//             return true;
//         }
//        } 
//        return false;
//     }

//     int getNextNumber(int n){
//         int output = 0;

//         while(n>0){
//             int digit = n%10;
//             output += digit * digit;
//             n = n/10;
//         }
//         return output;
//     }
// };


class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = sumSquareDigits(n);

        while (slow != fast) {
            fast = sumSquareDigits(fast);
            fast = sumSquareDigits(fast);
            slow = sumSquareDigits(slow);
        }

        return fast == 1;
    }

private:
    int sumSquareDigits(int n) {
        int output = 0;
        while (n != 0) {
            output += (n % 10) * (n % 10);
            n /= 10;
        }
        return output;
    }
};
