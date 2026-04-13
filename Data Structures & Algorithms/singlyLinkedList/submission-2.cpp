class Node {
public:
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int v) : val(v), next(nullptr) {}
    Node(int v, Node* n): val(v), next(n) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList(): head(nullptr){}

    int get(int index) {
        Node* curr = head;

        for (int i = 0; curr != nullptr; ++i, curr = curr->next)
            if (i == index)
                return curr->val;

        return -1;
    }

    void insertHead(int val) {
        if (head == nullptr) {
            head = new Node(val);
            return;
        }
        Node* newHead = new Node(val, head);
        head = newHead;
    }
    
    void insertTail(int val) {
        if (head == nullptr) {
            head = new Node(val);
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = new Node(val);
    }

    bool remove(int index) {
        if (head == nullptr) return false;
        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return true;
        }

        Node* curr = head;
        for (int i = 0; i < index - 1 && curr != nullptr; ++i, curr = curr->next){}

        if (curr == nullptr || curr->next == nullptr)
            return false;

        Node* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        return true;
    }

    vector<int> getValues() {
        vector<int> result;
        Node* curr = head;
        while (curr != nullptr) {
            result.push_back(curr->val);
            curr = curr->next;
        }
        return result;
    }
};










