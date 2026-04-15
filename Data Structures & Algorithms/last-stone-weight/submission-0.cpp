class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while (maxHeap.size() > 1) {
            int largest = maxHeap.top();
            maxHeap.pop();
            int secondLargest = maxHeap.top();
            maxHeap.pop();

            if (largest == secondLargest) {
                continue;
            }

            maxHeap.push(largest - secondLargest);
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
        
    }
};
