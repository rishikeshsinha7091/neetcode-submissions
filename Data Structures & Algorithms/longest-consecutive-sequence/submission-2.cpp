class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> ipSet;
        int maxCount=1;
        int count=1;

        for (int num:nums){
            ipSet.insert(num);
        }

        for (int num:ipSet){
            if (!ipSet.count(num-1)){
                int x = num;
                while (ipSet.count(x+1)){
                    count++;
                    maxCount=max(count,maxCount);
                    x++;
                }
                count = 1;
            }
        }

        return maxCount;
    }
};