class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = numbers.size() - 1;
        while (p1 < p2) {
            if (numbers[p1] + numbers[p2] == target) return {p1 + 1, p2 + 1};
            else if (numbers[p1] + numbers[p2] > target) p2--;
            else p1++;
        }

        return {0, 0}; /* There is an answer, it does not matter */
    }
};
