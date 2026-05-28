class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int front = 0;
        int back = nums.size()-1;

        while (front<=back){
            if (nums[back]==val){
                back--;
            }
            else if (nums[front]!=val){
                front++;
            }
            else if (nums[front]==val && nums[back]!=val){
                nums[front]=nums[back];
                front++;
                back--;
            } 
        }

        return front;
    }
};