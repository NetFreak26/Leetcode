class Solution {
public:

    void findCombinations(vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &comb, int start, int lastIndex) {
        if(target < 0) {
            return ;
        }

        if(target == 0) {
            ans.push_back(comb);
            return;
        }

        for(int i=start; i<nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) {
                continue;
            }
            comb.push_back(nums[i]);
            findCombinations(nums, target-nums[i], ans, comb, i+1, i);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        findCombinations(candidates, target, ans, comb, 0, -1);

        sort(ans.begin(), ans.end());

        auto last = unique(ans.begin(), ans.end());
        ans.erase(last, ans.end());

        return ans;
    }
};
