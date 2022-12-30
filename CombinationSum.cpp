class Solution {
public:

    void findCombinations(vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &comb, int last) {

        if(target < 0) {
            return;
        }

        if(target == 0) {
            ans.push_back(comb);
            return;
        }

        for(int i=last; i<nums.size(); i++) {
            comb.push_back(nums[i]);
            findCombinations(nums, target-nums[i], ans, comb, i);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        findCombinations(candidates, target, ans, comb, 0);

        return ans;
    }
};
