class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> us;

        for (int i=0; i<nums.size(); i++) {
            int value = target - nums[i];
            if (us.find(value) != us.end()) {
                return {i, us[value]};
            } else {
                us[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};
