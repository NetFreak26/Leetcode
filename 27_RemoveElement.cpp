class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        int j = n-1;
        while (i <= j) {
            if (nums[i] != val) {
                i++;
                continue;
            }
            while (j > i && nums[j] == val) {
                j--;
            }
            if (j > i) {
                swap(nums[i], nums[j]);
                i++;
            } else {
                j--;
            }
        }
        return i;
    }
};
