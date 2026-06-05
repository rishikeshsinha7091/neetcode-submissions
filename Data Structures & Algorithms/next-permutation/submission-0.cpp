class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int pivot=-10;
        int min1=-10;
        for(int i=len-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                pivot=i-1;
                break;
            }
        }
        if (pivot==-10){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=len-1; i>pivot; i--){
            if (nums[i]>nums[pivot]){
                min1=i;
                break;
            }
        }

        swap(nums[min1],nums[pivot]);
        reverse(nums.begin()+pivot+1,nums.end());
    }
};