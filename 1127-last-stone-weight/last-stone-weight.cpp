class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(int &stone:stones){
            pq.push(stone);
        }

        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            pq.push(abs(a-b));
        }
        return pq.top();
    }
};


// Brute Force
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         while(stones.size()>1){
//             sort(begin(stones),end(stones));
//             int a = stones.back();
//             stones.pop_back();
//             int b = stones.back();
//             stones.pop_back();

//             stones.push_back(abs(a-b));
//         }
//         return stones[0];
//     }
// };