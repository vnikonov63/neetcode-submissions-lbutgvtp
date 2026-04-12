class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end())
                return {hash[complement], i}; /* any index in hash is smaller */
            hash[nums[i]] = i;
        }
        return {0, 0}; /* unreachable - guaranteed solution */
    }
};
