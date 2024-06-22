class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int s = 0, cs = 0;
        int n = customers.size();
        
        // Calculate total dissatisfied customers and total customers
        for (int i = 0; i < n; ++i) {
            s += customers[i] * grumpy[i]; // Total dissatisfied customers
            cs += customers[i]; // Total customers
        }
        
        int t = 0, ans = 0;
        
        // Sliding window to find the optimal period for the secret technique
        for (int i = 0; i < n; ++i) {
            t += customers[i] * grumpy[i]; // Add customers of current minute if grumpy
            
            int j = i - minutes + 1; // Start of the window
            if (j >= 0) {
                // Calculate max satisfied customers by considering the secret technique usage
                ans = max(ans, cs - (s - t));
                t -= customers[j] * grumpy[j]; // Remove the leftmost element as the window slides
            }
        }
        
        return ans;
    }
};
