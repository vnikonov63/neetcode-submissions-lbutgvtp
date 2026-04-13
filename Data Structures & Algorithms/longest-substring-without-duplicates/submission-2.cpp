class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int result = 0;
        unordered_set<char> data;
        for (int r = 0; r < s.size(); ++r) {
            while (data.find(s[r]) != data.end()) {
                data.erase(s[l]);
                ++l;
            }
            data.insert(s[r]);
            result = max(result, r - l + 1);
        }

        return result;
    }
};
