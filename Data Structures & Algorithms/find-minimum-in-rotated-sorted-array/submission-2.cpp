class Solution {
public:
    int findMin(vector<int> &nums) {
        int result = nums[0]; /* it is always the suspect */
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            /* this means they are in one section together */
            if (nums[l] < nums[r]) {
                result = min(result, nums[l]);
                break;
            }
            int m = (l + r) / 2;
            result = min(result, nums[m]); /* m can be together with l or r at this point */
            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return result;
    }
};
