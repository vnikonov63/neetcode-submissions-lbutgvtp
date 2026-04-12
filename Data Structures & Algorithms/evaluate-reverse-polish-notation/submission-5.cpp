class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> storage;
        for (int i = 0; i < tokens.size(); ++i) {
            string curr = tokens[i];
            if (curr == "+") {
                int a = storage.top();
                storage.pop();
                int b = storage.top();
                storage.pop();
                storage.push(a + b);
            }  else if (curr == "-") {
                int a = storage.top();
                storage.pop();
                int b = storage.top();
                storage.pop();
                storage.push(b - a);
            } else if (curr == "*") {
                int a = storage.top();
                storage.pop();
                int b = storage.top();
                storage.pop();
                storage.push(a * b);
            } else if (curr == "/") {
                int a = storage.top();
                storage.pop();
                int b = storage.top();
                storage.pop();
                storage.push(floor(b / a));
            } else {
                storage.push(stoi(curr));
            }
        }
        return storage.top();
    }
};
