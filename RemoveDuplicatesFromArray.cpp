class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int pos = 1;
        int last = nums[0];

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != last) {
                nums[pos++] = nums[i];
                last = nums[i];
            }    
        }
        return pos;
    }
};
