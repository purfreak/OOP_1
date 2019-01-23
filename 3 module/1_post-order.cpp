#include <iostream>
#include <vector>
#include <stack>


class binaryTree {
private:
    struct binaryTreeNode {
        int data;
        binaryTreeNode* left;
        binaryTreeNode* right;
        binaryTreeNode();
        explicit binaryTreeNode(int& value);
        ~binaryTreeNode();
    };
    binaryTreeNode* root;

    void add(int& value, binaryTreeNode*& current);
    void copyTree(std::vector<int> &destination, std::stack<binaryTreeNode*> &s);

public:
    binaryTree();
    ~binaryTree();

    void add(int& value);
    void copyTree(std::vector<int>& destination);
};


binaryTree::binaryTreeNode::binaryTreeNode() {
    data = int();
    left = nullptr;
    right = nullptr;
}


binaryTree::binaryTreeNode::binaryTreeNode(int& value) {
    data = value;
    left = nullptr;
    right = nullptr;
}


binaryTree::binaryTreeNode::~binaryTreeNode() {
    delete left;
    delete right;
}


binaryTree::binaryTree() {
    root = nullptr;
}


binaryTree::~binaryTree() {
    delete root;
}


void binaryTree::add(int& value) {
    add(value, root);
}


void binaryTree::add(int& value, binaryTreeNode*& current) {
    if (current) {
        if (current->data <= value) {
            add(value, current->right);
        } else {
            add(value, current->left);
        }
    } else {
        current = new binaryTreeNode(value);
    }

}


void binaryTree::copyTree(std::vector<int>& destination) {
    if (!root)
        return;
    
    std::stack<binaryTreeNode*> s1;
    std::stack<binaryTreeNode*> s2;
    
    s1.push(root);
    binaryTreeNode* node;

    // Run while first stack is not empty 
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2 
        node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children of removed item to s1 
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    // Print all elements of second stack 
    while (!s2.empty()) {
        destination.push_back(s2.top() -> data);
        s2.pop();
    }
}



int main() {
    int n;
    std::cin >> n;

    binaryTree Tree;

    int temp;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        Tree.add(temp);
    }

    std::vector<int> out;
    Tree.copyTree(out);

    for (int i = 0; i < n; i++) {
        std:: cout << out[i] << " ";
    }
    std::cout << std::endl;
}
