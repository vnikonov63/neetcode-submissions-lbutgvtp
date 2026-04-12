class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        for (const auto& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            hashMap[sorted].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& p : hashMap) {
            result.push_back(p.second);
        }

        return result;
    }
};
