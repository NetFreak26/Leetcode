class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            for(int j=i+1; j<n; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int k = j + 1;
                int l = n - 1;

                while(k < l) {
                    if(k > j+1 && nums[k] == nums[k-1]) {
                        k++;
                        continue;
                    }

                    if(l < n-1 && nums[l] == nums[l+1]) {
                        l--;
                        continue;
                    }

                    long sum = (long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if(sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
