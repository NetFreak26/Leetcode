class Solution {
public:

    int findStart(vector<int> &nums, int target, int l, int r) {
        if(l > r) {
            return - 1;
        }

        int mid = (l + r) / 2;

        if(nums[mid] == target) {
            int s = findStart(nums, target, l, mid - 1);
            return s == -1 ? mid : s;
        } else {
            return findStart(nums, target, mid+1, r);
        }
    }

    int findEnd(vector<int> &nums, int target, int l, int r) {
        if(l > r) {
            return - 1;
        }

        int mid = (l + r) / 2;

        if(nums[mid] == target) {
            int e = findEnd(nums, target, mid+1, r);
            return e == -1 ? mid : e;
        } else {
            return findEnd(nums, target, l, mid-1);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int s = -1;
        int e = -1;

        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(nums[mid] == target) {
                s = findStart(nums, target, l, mid);
                e = findEnd(nums, target, mid, r);
                return {s, e};
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return {-1, -1};
    }
};
