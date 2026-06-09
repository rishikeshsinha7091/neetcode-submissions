class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            // Duplicate Skip #1: Skip duplicate elements for the fixed pointer 'i'
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Step 2: Standard Two Pointers technique
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    // We found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move pointers to search for other combinations
                    left++;
                    right--;
                    
                    // Duplicate Skip #2: Skip duplicates for the 'left' pointer
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    
                    // Duplicate Skip #3: Skip duplicates for the 'right' pointer
                    // Notice we check nums[right] == nums[right + 1] because we already moved right down
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};