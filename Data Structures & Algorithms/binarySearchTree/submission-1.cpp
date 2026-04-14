/* Binary Search Tree Node */
class TreeNode {
public:
    int key;
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key, int val) {
        this->key = key;
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class TreeMap {
private:
    TreeNode* root;
public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        TreeNode* newNode = new TreeNode(key, val);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        insert_helper(root, key, val);
    }

    int get(int key) {
        TreeNode* curr = this->root;
        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->val;
            } else if (curr->key < key) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        return -1;
    }

    int getMin() {
        TreeNode* min_node = helper_min(this->root);
        return min_node == nullptr ? -1 : min_node->val;
    }

    int getMax() {
        TreeNode* max_node = helper_max(this->root);
        return max_node == nullptr ? -1 : max_node->val;
    }

    void remove(int key) {
        root = remove_helper(root, key);
    }

    std::vector<int> getInorderKeys() {
        vector<int> result;
        inorder_traversal(root, result);

        return result;
    }
private:
    TreeNode* helper_min(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr) return root;
        return helper_min(root->left);
    }

    TreeNode* helper_max(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->right == nullptr) return root;
        return helper_max(root->right);
    }

    void inorder_traversal(TreeNode* root, vector<int>& values) {
        if (root != nullptr) {
            inorder_traversal(root->left, values);
            values.push_back(root->key);
            inorder_traversal(root->right, values);
        }
    }

    TreeNode* insert_helper(TreeNode* root, int key, int val) {
        if (root == nullptr) return new TreeNode(key, val);
        if (root->key == key) root->val = val;
        else if (root->key < key) root->right = insert_helper(root->right, key, val);
        else root->left = insert_helper(root->left, key, val);

        return root;
    }

    // if we found the node with this key
    // if it has no children, just remove it
    // if it only has a left child -> replace it with a left child;
    // if it only has a right child -> replace it with a right child
    // if it has 2 children -> replace it with the minimum node from the right subtree
    // or alternatively with the max node from the left subtree

    // we search for the node, until we find it.
    // then check the children
    // then do the necessary replacement.
    // for the two children case we can just call the same helper for that "next in line node"
    // But how do we just delete a node, that is a leaf? 
    // We make the helper return the new root that is a nullptr and in
    // that case just return the TreeNode further up the unwinding recursion chain
    TreeNode* remove_helper(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->key == key) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) return root->right;
              else if (root->right == nullptr) return root->left; 
              else {
                TreeNode* nextInLine = helper_min(root->right);
                root->key = nextInLine->key;
                root->val = nextInLine->val;
                root->right = remove_helper(root->right, nextInLine->key);

                return root;
            }
            // work with the children
        } else if (root->key < key) {
            root->right = remove_helper(root->right, key);
        } else {
            root->left = remove_helper(root->left, key);
        }

        return root;
    }
};







