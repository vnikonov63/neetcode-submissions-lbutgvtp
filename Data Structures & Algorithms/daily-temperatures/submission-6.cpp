class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> indexInWaiting;

        for (int i = 0; i < temperatures.size(); ++i) {
            int curr_temperature = temperatures[i];
            while (!indexInWaiting.empty() && curr_temperature > indexInWaiting.top().first) {
                auto pair = indexInWaiting.top();
                indexInWaiting.pop();
                result[pair.second] = i - pair.second;
            }
            indexInWaiting.push({curr_temperature, i});
        }
        return result;
    }
};
