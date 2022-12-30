class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size(); 

        int closestSum = 10000000;

        for(int i=0; i<n; i++) {

            int j = i+1;
            int k = n-1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if(sum == target) {
                    return closestSum;
                } else if(sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return closestSum;
    }
};
