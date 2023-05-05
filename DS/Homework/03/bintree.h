#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>

template <typename T>
struct BinNode {
	T data;
	BinNode<T>* left;
	BinNode<T>* right;
	BinNode(T d) : data(d), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinTree {
public:
	BinTree() : root(nullptr) {}
	~BinTree() { clear(root); }
	void clear() { clear(root); root = nullptr; }
	bool empty() const { return root == nullptr; }
	void insert(const T& data) { insert(root, data); }
	void preOrder(void (*visit)(const T&)) const { preOrder(root, visit); }
	void inOrder(void (*visit)(const T&)) const { inOrder(root, visit); }
	void postOrder(void (*visit)(const T&)) const { postOrder(root, visit); }
protected:
	BinNode<T>* root;
	void clear(BinNode<T>* node) {
		if (node == nullptr) {
			return;
		}
		clear(node->left);
		clear(node->right);
		delete node;
	}
	void insert(BinNode<T>*& node, const T& data) {
		if (node == nullptr) {
			node = new BinNode<T>(data);
			return;
		}
		if (data < node->data) {
			insert(node->left, data);
		}
		else {
			insert(node->right, data);
		}
	}
	void preOrder(BinNode<T>* node, void (*visit)(const T&)) const {
		if (node == nullptr) {
			return;
		}
		visit(node->data);
		preOrder(node->left, visit);
		preOrder(node->right, visit);
	}
	void inOrder(BinNode<T>* node, void (*visit)(const T&)) const {
		if (node == nullptr) {
			return;
		}
		inOrder(node->left, visit);
		visit(node->data);
		inOrder(node->right, visit);
	}
	void postOrder(BinNode<T>* node, void (*visit)(const T&)) const {
		if (node == nullptr) {
			return;
		}
		postOrder(node->left, visit);
		postOrder(node->right, visit);
		visit(node->data);
	}
};
class HuffmanNode {
public:
	char ch; 
	int freq; // 出现频率
	HuffmanNode* left; // 左子节点
	HuffmanNode* right; // 右子节点
	
	// 构造函数
	HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
	bool operator()(const HuffmanNode* a, const HuffmanNode* b) const {
		return a->freq > b->freq;
	}
};

HuffmanNode* buildHuffTree(const string& str) {
	
	unordered_map<char, int> freqMap;
	for (char c : str) {
		freqMap[c]++;
	}
	
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
	for (auto& [c, freq] : freqMap) {
		pq.push(new HuffmanNode(c, freq));
	}
	
	while (pq.size() > 1) {
		HuffmanNode* left = pq.top();
		pq.pop();
		HuffmanNode* right = pq.top();
		pq.pop();
		HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq);
		parent->left = left;
		parent->right = right;
		pq.push(parent);
	}
	
	return pq.top();
}



#endif
