#pragma once
#include<iostream>
#include<queue>
struct Node {
	int val;
	Node* next;
	Node(int value) :val(value), next(nullptr) {}
};

class LinkedList {

public:
	LinkedList() {}
	~LinkedList() {
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
		while (cur != nullptr)
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
	Node head = { 0 };		//空节点，便于后续节点的插入和删除操作。
	int size = 0;
};


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) :
		val(value),
		left(nullptr),
		right(nullptr) {}
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

	void InorderPrint() {
		InorderPrint(root);
		std::cout << std::endl;
	}

	void PostorderPrint() {
		PostorderPrint(root);
		std::cout << std::endl;
	}

	void DeletNode(int val) {
		root = DeleteNode(root, val);
	}

	int PrintMin() {
		return minTreeNode(root).val;
	}

private:
	void Put(TreeNode*& proot, int val) {
		/*if (proot->left == nullptr && val < proot->val) {
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
		}*/
		if (proot == nullptr) {
			proot = new TreeNode(val);
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
	void PreorderPrint(TreeNode*& proot) {
		if (proot == nullptr) {
			return;
		}
		std::cout << proot->val << " ";
		PreorderPrint(proot->left);
		PreorderPrint(proot->right);
	}
	void InorderPrint(TreeNode*& proot) {
		if (proot == nullptr) {
			return;
		}
		InorderPrint(proot->left);
		std::cout << proot->val << " ";
		InorderPrint(proot->right);
	}
	void PostorderPrint(TreeNode*& proot) {
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
		if (proot != nullptr) {
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
				//DeleteMinNode(proot->right);
				proot->right = DeleteNode(proot->right, v);
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
			TreeNode minNode = minTreeNode(proot->left);
			return minNode;
		}
		return *proot;
	}

	void DeleteMinNode(TreeNode*& proot) {
		if (proot == nullptr) {
			return;
		}
		if (proot->left != nullptr) {
			DeleteMinNode(proot->left);
		}
		else {
			delete proot;
			proot = nullptr;
			size--;
		}
	}
	TreeNode* root = nullptr;
	int size = 0;
};



struct AVLTreeNode {
	//typedef AVLTreeNode* pAVLTreeNode;
	int val;
	AVLTreeNode* left;
	AVLTreeNode* right;
	int height;
	AVLTreeNode(int value) :
		val(value),
		left(nullptr),
		right(nullptr),
		height(0) {}
};

//平衡因子：左子树的高度-右子树的高度
class AVLTree {
public:
	AVLTree() {}
	~AVLTree() {
		Destory(root);
	}

	void Put(int val) {
		Put(root, val);
	}
	void Delete(int val) {
		Delete(root, val);
	}

	void InorderPrint() {
		InorderPrint(root);
		std::cout << std::endl;
	}

	int GetSize() {
		return size;
	}

	bool IsBanlanced() {
		return IsBanlanced(root);
	}


	int GetBalance(AVLTreeNode*& proot) {
		return GetHeight(proot->left) - GetHeight(proot->right);
	}


	void SelfBalanced(AVLTreeNode*& proot) {
		if (proot == nullptr) {
			return;
		}
		if (GetBalance(proot) < -1) {
			if (GetBalance(proot->right) <=0) {
				proot=RR(proot);
			}
			else {
				proot=RL(proot);
			}
		}
		else if (GetBalance(proot) > 1) {
			if (GetBalance(proot->left) >=0) {
				proot=LL(proot);
			}
			else {
				proot=LR(proot);
			}
		}
	}

	void LevelPrint() {
		AVLTreeNode* tmp = root;
		std::queue<AVLTreeNode*> q;
		if (root == nullptr)
			return;
		q.push(tmp);

		// 计算树的高度
		int height = root->height;
		int nodesAtLevel = 1;
		int level = 1;

		while (!q.empty()) {
			/*int spaces = static_cast<int>(std::pow(2, height - level) - 1);
			int interval = static_cast<int>(std::pow(2, height - level + 1)-1);*/
			bool allNull = true; // 检查当前层级的节点是否都为空
			for (int i = 0; i < nodesAtLevel; i++) {
				AVLTreeNode* current = q.front();
				q.pop();

				//std::cout << std::string(spaces, ' ');

				if (current != nullptr) {
					allNull = false; // 当前层级存在非空节点
					std::cout << current->val<<" ";
					q.push(current->left);
					q.push(current->right);
				}
				else {
					std::cout << "n ";
					q.push(nullptr);
					q.push(nullptr);
				}

				//std::cout << std::string(interval, ' ');
			}
			if (allNull)
				break; // 如果当前层级的节点都为空，则退出循环
			std::cout << std::endl;

			nodesAtLevel *= 2;
			level++;
		}
	}

private:
	void Put(AVLTreeNode*& proot, int val) {
		if (proot == nullptr) {
			proot = new AVLTreeNode(val);
			size++;
		}
		else {
			if (val >= proot->val) {
				Put(proot->right, val);
			}
			else {
				Put(proot->left, val);
			}
		}
		proot->height = std::max(GetHeight(proot->left), GetHeight(proot->right)) + 1;
		SelfBalanced(proot);
	}


	AVLTreeNode* Delete(AVLTreeNode*& proot, int val) {
		if (proot == nullptr) {
			std::cout << "value is not in tree" << std::endl;
			return nullptr;
		}

		if (val > proot->val) {
			proot->right = Delete(proot->right, val);
		}
		else if (val < proot->val) {
			proot->left = Delete(proot->left, val);
		}
		else {
			if (proot->left == nullptr && proot->right == nullptr) {
				std::cout << "delete val：" << val << std::endl;
				delete proot;
				size--;
				proot = nullptr;
				return nullptr;
			}
			else if (proot->left == nullptr) {
				std::cout << "delete val: " << val << std::endl;
				AVLTreeNode* tmp = proot->right;
				delete proot;
				size--;
				return tmp;
			}
			else if (proot->right == nullptr) {
				std::cout << "delete val: " << val << std::endl;
				AVLTreeNode* tmp = proot->left;
				delete proot;
				size--;
				return tmp;
			}
			else {
				std::cout << "delete val：" << val << std::endl;
				proot->val = minTreeNode(proot->right).val;
				proot->right=Delete(proot->right, proot->val);
			}
		}
		proot->height = std::max(GetHeight(proot->left), GetHeight(proot->right)) + 1;
		SelfBalanced(proot);
		return proot;
	}

	int GetHeight(const AVLTreeNode* proot) {
		if (proot == nullptr) {
			return 0;
		}
		return proot->height;
	}


	//RR型，左旋一次
	AVLTreeNode* RR(AVLTreeNode*& proot) {
		AVLTreeNode* tmp = proot->right;
		proot->right = tmp->left;
		tmp->left = proot;

		proot->height = max(GetHeight(proot->left), GetHeight(proot->right)) + 1;
		tmp->height = max(GetHeight(tmp->left), GetHeight(tmp->right)) + 1;
		proot = tmp;
		return proot;
	}

	AVLTreeNode* RL(AVLTreeNode*& proot) {
		AVLTreeNode* tmp = proot->right;
		AVLTreeNode* tmp2 = tmp->left;
		proot->right = tmp2;
		tmp->left = tmp2->right;
		tmp2->right = tmp;
		tmp->height = max(GetHeight(tmp->left), GetHeight(tmp->right)) + 1;
		tmp2->height = max(GetHeight(tmp2->left), GetHeight(tmp2->right)) + 1;
		return RR(proot);
	}

	//LL型，右旋一次
	AVLTreeNode* LL(AVLTreeNode*& proot) {
		AVLTreeNode* tmp = proot->left;
		proot->left = tmp->right;
		tmp->right = proot;

		proot->height = max(GetHeight(proot->left), GetHeight(proot->right)) + 1;
		tmp->height = max(GetHeight(tmp->left), GetHeight(tmp->right)) + 1;
		proot = tmp;
		return proot;
	}

	AVLTreeNode* LR(AVLTreeNode*& proot) {
		/*return nullptr;*/
		AVLTreeNode* tmp = proot->left;
		AVLTreeNode* tmp2 = tmp->right;
		proot->left = tmp2;
		tmp->right = tmp2->left;
		tmp2->left = tmp;
		tmp->height = max(GetHeight(tmp->left), GetHeight(tmp->right)) + 1;
		tmp2->height = max(GetHeight(tmp2->left), GetHeight(tmp2->right)) + 1;
		return LL(proot);
	}



	void InorderPrint(AVLTreeNode*& proot) {
		if (proot == nullptr) {
			return;
		}
		InorderPrint(proot->left);
		std::cout << proot->val << " ";
		InorderPrint(proot->right);
	}

	void Destory(AVLTreeNode*& proot) {
		if (proot != nullptr) {
			Destory(proot->left);
			Destory(proot->right);
			//std::cout << "delete node, val:" << proot->val << std::endl;
			delete proot;
			size--;
			proot = nullptr;
		}
	}

	AVLTreeNode minTreeNode(AVLTreeNode* proot) {
		AVLTreeNode* current = proot;
		while (current->left != nullptr) {
			current = current->left;
		}
		return *current;
	}

	AVLTreeNode* DeleteMinNode(AVLTreeNode*& proot) {
		if (proot == nullptr) {
			return nullptr;
		}
		else if(proot->left) {
			proot->left=DeleteMinNode(proot->left);
		}
		else if(proot->right){
			AVLTreeNode* tmp = proot->right;
			delete proot;
			size--;
			return tmp;
		}
		else {
			delete proot;
			proot = nullptr;
			size--;
			return nullptr;
		}
		return proot;
	}

	bool IsBanlanced(AVLTreeNode*& proot) {
		if (proot == nullptr) {
			return true;
		}
		if (std::abs(GetHeight(proot->left) - GetHeight(proot->right)) > 1) {

			/*std::cout << proot->left->height << std::endl;
			std::cout << proot->right->height << std::endl;*/
			return false;
		}
		return IsBanlanced(proot->left) && IsBanlanced(proot->right);
	}


	AVLTreeNode* root = nullptr;
	int size = 0;
};
