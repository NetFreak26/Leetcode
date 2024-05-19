class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        while (j < n) {
            while (j < n-1 && nums[j] == nums[j+1]) {
                j++;
            }
            nums[i] = nums[j];
            i++;
            j++;
        }
        return i;
    }
};
