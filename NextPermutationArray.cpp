class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int k = n - 1;

        while(k > 0 && nums[k-1] >= nums[k]) {
            k--;
        }

        if(k == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int j = n - 1;

            while(nums[j] <= nums[k-1]) {
                j--;
            }

            swap(nums[k-1], nums[j]);

            j = n - 1;
            while(k < j) {
                swap(nums[k], nums[j]);
                k++;
                j--;
            }
        }
    }
};
