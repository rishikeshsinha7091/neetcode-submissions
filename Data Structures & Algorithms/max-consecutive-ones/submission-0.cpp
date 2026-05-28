class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;     // This is your 'ones_counter_prev'
        int current_count = 0; // This is your 'ones_counter'
        
        for (int num : nums) {
            if (num == 1) {
                current_count++;
            } else {
                // We hit a zero. Check if our current streak is the best one yet.
                max_count = max(max_count, current_count);
                // CRITICAL: Reset the current count for the next potential streak.
                current_count = 0;
            }
        }
        
        // CRITICAL: One final check in case the array ended with a streak of 1s.
        return max(max_count, current_count);
    }
};