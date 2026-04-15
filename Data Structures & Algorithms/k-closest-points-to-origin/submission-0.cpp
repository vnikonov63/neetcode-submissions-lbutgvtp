struct Compare {
    bool operator()(const vector<int>& l, const vector<int>& r) const {
        return l[0] * l[0] + l[1] * l[1] > r[0] * r[0] + r[1] * r[1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> minHeap;

        for (const auto& point: points) {
            minHeap.push({point[0], point[1]});
        }

        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }
};
