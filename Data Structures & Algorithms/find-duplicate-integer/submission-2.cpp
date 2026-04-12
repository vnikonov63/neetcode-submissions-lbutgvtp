class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for (int num : nums) {
            if (mySet.contains(num)) return num;
            mySet.insert(num);
        }
        return 0;
    }
};
