#include"Solution.h"
#include<boost\asio.hpp>
#include"struct.h"
#include <iostream>
#include <cstdlib>  // 包含rand()和srand()
#include <ctime>    // 包含time()
#include<random>
/*****************************************************************//**
 * @file   main.cpp
 * @brief  
 * 
 * @author johnny
 * @date   July 2023
 *********************************************************************/
void main() {
	/*Solution s;
	string str = "ngxlkthsjuoqcpavbfdermiywz";
	vector<string> vec = { "kuvp","q" };
	vector<int> t = { 0,1,2,3,4,5,6,7,8 };

	vector<vector<int>> t3 = { {0,0},{1,2},{0,2},{1,1} };

	vector<int> t1 = { 3,7,9 };
	vector<int>t2 = { 3,7,11 };
	s.findKthPositive(t, 5);*/
	//LinkedList L;
	//L.AddNode(Node(1));
	//L.AddNode(Node(2));
	//L.AddNode(Node(3));
	////L.InsertNodeAfter(Node(4), 3);
	//L.InsertNode(Node(4), 4);
	//L.InsertNode(Node(5), 5);
	//L.DeleteNode(5);
	//L.PrintLinkedList();
	//BinarySearchTree bst = BinarySearchTree();
	//bst.Put(3);
	//bst.Put(2);
	//bst.Put(4);
	///*bst.Put(2);
	//bst.Put(3);*/
	///*bst.PreorderPrint();
	//bst.InorderPrint();
	//bst.PostorderPrint();*/
	////bst.DeletNode(5);
	//bst.InorderPrint();
	//bst.PostorderPrint();
	//std::cout << bst.PrintMin() << std::endl;
	AVLTree tree;
	/*tree.Put(5);
	tree.Put(3);
	tree.Put(6);
	tree.Put(2);
	tree.Put(4);
	tree.Put(5);
	tree.Put(3);
	tree.Put(6);
	tree.Put(2);
	tree.Put(4);
	tree.Put(5);
	tree.Put(3);
	tree.Put(6);
	tree.Put(2);
	tree.Put(4);*/
	/*for (int i = 1; i <= 1000; i++) {
		tree.Put(i);
	}*/

	std::unordered_set<int> nums;
	// 创建随机数引擎
	std::random_device rd;
	std::mt19937 gen(rd());

	// 创建整数分布器，范围是[low, high]
	std::uniform_int_distribution<int> distribution(0, 1000);
	for (int i = 0; i <1000; i++) {
		tree.Put(distribution(gen));
	}

	// 生成随机数
	/*int randomNum = distribution(gen);
	for (auto i : nums) {
		tree.Put(i);
	}*/
	tree.Put(5);
	tree.InorderPrint();

	if (tree.IsBanlanced()) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
	tree.Delete(5);
	//tree.Put(3);
	//tree.Put(4);
	//tree.Put(2);
	//tree.Put(3);
	//tree.Put(7);
	//tree.Put(10);
	//tree.InorderPrint();
	//srand(static_cast<unsigned int>(time(0)));

	//// 生成并打印10个随机整数
	//for (int i = 0; i < 10000; ++i) {
	//	//int random_integer = rand();  // 生成随机整数
	//	//std::cout << random_integer << std::endl;
	//	tree.Put(rand());
	//}
	tree.InorderPrint();
	if (tree.IsBanlanced()) {
		std::cout << "true"<<std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
	std::cout<<tree.GetSize()<<std::endl;
}