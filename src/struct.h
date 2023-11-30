#pragma once
#include<iostream>
struct Node {
	int val;
	Node* next;
	Node(int value):val(value),next(nullptr){}
};

class LinkedList{

public:
	LinkedList(){}
	~LinkedList(){
		Node* cur = head.next;
		while (cur != nullptr) {
			Node* pnode = cur->next;
			delete cur;
			cur = pnode;
			std::cout << "delele node" << std::endl;
		}
		head.next = nullptr;
	}
	void AddNode(Node node) {
		Node* cur = head.next;
		if (cur == nullptr) {
			head.next = new Node(node.val);
			size++;
		}
		else {
			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			cur->next = new Node(node.val);
			size++;
		}
	}
	void InsertNode(Node node, int index) {
		if (index > size + 1||index==0) {
			std::cout << "insert failed, out of range" << std::endl;
			return;
		}
		int i = 1;
		Node* cur = head.next;
		Node* pre = &head;
		while (i < index) {
			cur = cur->next;
			pre = pre->next;
			i++;
		}
		pre->next = new Node(node.val);
		pre->next->next = cur;
		size++;
	}

	void InsertNodeAfter(Node node, int index) {
		if (index > size || index == 0) {
			std::cout << "insert failed, out of range" << std::endl;
			return;
		}
		int i = 1;
		Node* cur = head.next;
		while (i < index) {
			cur = cur->next;
			i++;
		}
		Node* tmp = cur->next;
		cur->next = new Node(node.val);
		cur->next->next = tmp;
		size++;
	}


	void DeleteNode(int index) {
		if (index > size + 1 || index == 0) {
			std::cout << "insert failed, out of range" << std::endl;
			return;
		}
		int i = 1;
		Node* cur = head.next;
		Node* pre = &head;
		while (i < index) {
			cur = cur->next;
			pre = pre->next;
			i++;
		}
		pre->next = cur->next;
		delete cur;
		size--;
	}


	void PrintLinkedList() {
		Node* cur = head.next;
		while (cur!=nullptr)
		{
			std::cout << cur->val << " ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}

	Node GetHeadNode() {
		return *head.next;
	}

private:
	Node head= { 0 };		//空节点，便于后续节点的插入和删除操作。
	int size = 0;
};


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value):
	val(value),
	left(nullptr),
	right(nullptr){}
};

class BinarySearchTree {
public:
	BinarySearchTree() {}
	~BinarySearchTree() {
		Destory(root);
	}
	void Put(int val) {
		if (root == nullptr) {
			root = new TreeNode(val);
			size++;
		}
		else {
			Put(root, val);
			size++;
		}
	}

	void PreorderPrint() {
		PreorderPrint(root);
		std::cout << std::endl;
	}

	void InorderPrint(){
		InorderPrint(root);
		std::cout << std::endl;
	}

	void PostorderPrint(){
		PostorderPrint(root);
		std::cout << std::endl;
	}

	void DeletNode(int val) {
		root=DeleteNode(root, val);
	}

	int PrintMin() {
		return minTreeNode(root).val;
	}

private:
	void Put(TreeNode*& proot,int val) {
		if (proot->left == nullptr && val < proot->val) {
			proot->left = new TreeNode(val);
		}
		else if (proot->right == nullptr && val > proot->val) {
			proot->right = new TreeNode(val);
		}
		else {
			if (val > proot->val) {
				Put(proot->right, val);
			}
			else {
				Put(proot->left, val);
			}
		}
	}
	void PreorderPrint(TreeNode*& proot){
		if (proot == nullptr) {
			return;
		}
		std::cout << proot->val << " ";
		PreorderPrint(proot->left);
		PreorderPrint(proot->right);
	}
	void InorderPrint(TreeNode*& proot){
		if (proot == nullptr) {
			return;
		}
		InorderPrint(proot->left);
		std::cout << proot->val << " ";
		InorderPrint(proot->right);
	}
	void PostorderPrint(TreeNode*& proot){
		if (proot == nullptr) {
			return;
		}
		PostorderPrint(proot->left);
		PostorderPrint(proot->right);
		std::cout << proot->val << " ";
	}

	void Destory(TreeNode*& proot) {
		/*if (proot == nullptr) {
			return;
		}
		if (proot->left!= nullptr) {
			Destory(proot->left);
		}
		if (proot->right != nullptr) {
			Destory(proot->right);
		}
		std::cout << "delete node, val:" << proot->val << std::endl;
		delete proot;
		size--;
		proot = nullptr;*/
		if (proot!=nullptr) {
			Destory(proot->left);
			Destory(proot->right);
			std::cout << "delete node, val:" << proot->val << std::endl;
			delete proot;
			size--;
			proot = nullptr;
		}
	}

	TreeNode* DeleteNode(TreeNode*& proot, int val) {
		if (proot == nullptr) {
			std::cout << "delete failed,not found" << std::endl;
			return nullptr;
		}
		if (val < proot->val) {
			proot->left = DeleteNode(proot->left, val);				//前驱节点
		}
		else if (val > proot->val) {
			proot->right = DeleteNode(proot->right, val);
		}
		else {
			if (proot->left == nullptr && proot->right == nullptr) {
				std::cout << "delete node, val:" << val << std::endl;
				delete proot;
				proot = nullptr;
				size--;
				return nullptr;
			}
			else if (proot->right == nullptr) {
				std::cout << "delete node, val:" << val << std::endl;
				TreeNode* left = proot->left;
				delete proot;
				proot = nullptr;
				size--;
				return left;
			}
			else if (proot->left == nullptr) {
				std::cout << "delete node, val:" << val << std::endl;
				TreeNode* right = proot->right;
				delete proot;
				proot = nullptr;
				size--;
				return right;
			}
			else {
				int v = minTreeNode(proot->right).val;
				proot->val = v;
				std::cout << "delete node, val:" << val << std::endl;
				DeleteMinNode(proot->right);
				return proot;
			}
		}
		return proot;
	}



	TreeNode minTreeNode(TreeNode* proot) {
		if (proot == nullptr) {
			return NULL;
		}
		if (proot->left != nullptr) {
			TreeNode minNode=minTreeNode(proot->left);
			return minNode;
		}
		return *proot;
	}

	void DeleteMinNode(TreeNode*& proot) {
		if (proot==nullptr) {
			return;
		}
		if (proot->left != nullptr) {
			DeleteMinNode(proot->left);
		}
		delete proot;
		proot = nullptr;
		size--;
	}
	TreeNode* root = nullptr;
	int size = 0;
};
