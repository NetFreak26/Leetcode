class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n-2;
        while (j >= 0 && nums[j] >= nums[j+1]) {
            j--;
        }

        if (j < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = j + 1;
        int r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        l = j + 1;
        while (nums[l] <= nums[j]) {
            l++;
        }
        swap(nums[l], nums[j]);
    }
};
