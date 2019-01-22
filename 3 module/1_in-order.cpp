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
    std::stack <binaryTreeNode*> s;
    binaryTreeNode* curr = root;
    while (curr && !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr -> left);
        }

        curr = s.top();
        s.pop();
        destination.push_back(curr -> data);
        curr = curr -> right);

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
