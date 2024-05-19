class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 1e8;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i<n; i++) {
            int j = i+1;
            int k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum-target) < abs(ans-target)) {
                    ans = sum;
                }

                if (sum == target) {
                    return ans;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};
