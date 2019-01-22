/*Дано число N ≤ 104 и последовательность целых чисел из [-231..231] длиной N.
Требуется построить бинарное дерево, заданное наивным порядком вставки.
Т.е., при добавлении очередного числа K в дерево с корнем root,
если root→Key ≤ K, то узел K добавляется в правое поддерево root; иначе в левое поддерево root.
Выведите элементы в порядке post-order (снизу вверх).*/
#include <iostream>
#include <vector>


template <typename T>
class binaryTree {
private:
	struct binaryTreeNode {
		T data;
		binaryTreeNode* left;
		binaryTreeNode* right;
		binaryTreeNode();
		binaryTreeNode(T& value);
		~binaryTreeNode();
	};
	binaryTreeNode* root;

	void add(T& value, binaryTreeNode*& current);
	void copyTree(std::vector<T>& destination, binaryTreeNode* current);

public:
	binaryTree();
	~binaryTree();

	void add(T& value);
	void copyTree(std::vector<T>& destination);
};


template <typename T>
binaryTree<T>::binaryTreeNode::binaryTreeNode() {
	data = T();
	left = nullptr;
	right = nullptr;
}


template <typename T>
binaryTree<T>::binaryTreeNode::binaryTreeNode(T& value) {
	data = value;
	left = nullptr;
	right = nullptr;
}


template <typename T>
binaryTree<T>::binaryTreeNode::~binaryTreeNode() {
	delete left;
	delete right;
}


template <typename T>
binaryTree<T>::binaryTree() {
	root = nullptr;
}


template <typename T>
binaryTree<T>::~binaryTree() {
	delete root;
}


template <typename T>
void binaryTree<T>::add(T& value) {
	add(value, root);
}


template <typename T>
void binaryTree<T>::add(T& value, binaryTreeNode*& current) {
	if(current) {
		if(current->data <= value) {
			add(value, current->right);
		} else {
			add(value, current->left);
		}
	} else {
		current = new binaryTreeNode(value);
	} 

}


template <typename T>
void binaryTree<T>::copyTree(std::vector<T>& destination) {
	copyTree(destination, root);
}


template <typename T>
void binaryTree<T>::copyTree(std::vector<T>& destination, binaryTreeNode* current) {
	if(current->left) {
		copyTree(destination, current->left);
	}
	if(current->right) {
		copyTree(destination, current->right);
	}
	destination.push_back(current->data);
}


int main() {
	int n;
	std::cin >> n;

	binaryTree<int> Tree;
	for(int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		Tree.add(temp);
	}

	std::vector<int> out;
	Tree.copyTree(out);

	for(int i = 0; i < n; i++) {
		std:: cout << out[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
