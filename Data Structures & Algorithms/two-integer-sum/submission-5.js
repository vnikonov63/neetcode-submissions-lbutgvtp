class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        let hashMap = new Map();

        for (let i = 0; i < nums.length; ++i) {
            const complement = target - nums[i];
            if (hashMap.has(complement)) {
                return [hashMap.get(complement), i];
            }
            hashMap.set(nums[i], i);
        }

        return [-1, -1];
    }
}
