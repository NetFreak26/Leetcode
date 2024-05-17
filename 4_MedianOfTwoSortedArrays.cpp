class Solution {
private:
    int findLowers(vector<int> &nums, int val) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= val) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int half = (n + m + 1) / 2;
        int l = -1e6;
        int r = 1e6;
        int partition1;
        int partition2;
        while (l <= r) {
            int mid = (l + r) / 2;
            partition1 = findLowers(nums1, mid);
            partition2 = findLowers(nums2, mid);
            if (partition1 + partition2 == half) {
                break;
            } else if (partition1 + partition2 < half) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // cout << partition1 << " " << partition2 << endl;
        int left;
        if (partition1 == 0 && partition2 == 0) {
            left = nums1[0];
        } else if (partition1 == 0) {
            left = partition1 + partition2 < half ? nums2[partition2] : nums2[partition2-1];
        } else if (partition2 == 0) {
            left = partition1 + partition2 < half ? nums1[partition1] : nums1[partition1-1];
        } else {
            left = max(nums1[partition1-1], nums2[partition2-1]);
        }
        if ((n + m ) % 2 == 1) {
            return left;
        }
        int right;
        if (partition1 == n && partition2 == m) {
            right = nums1[n-1];
        } else if (partition1 == n) {
            right = partition1 + partition2 > half ? nums2[partition2-1] : nums2[partition2];
        } else if (partition2 == m) {
            right = partition1 + partition2 > half ? nums1[partition1-1] : nums1[partition1];
        } else {
            right = min(nums1[partition1], nums2[partition2]);
        }
        return (double)(left + right) / 2;
    }
};
