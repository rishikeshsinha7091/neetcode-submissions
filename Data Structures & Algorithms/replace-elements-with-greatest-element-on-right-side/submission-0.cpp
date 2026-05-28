class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int current_max= -1;
        int temp = 0;
        for (int i= arr.size()-1; i>=0; i--){
            temp = arr[i];
            arr[i]=current_max;
            current_max=max(current_max,temp);
        }
        return arr;
    }
};
