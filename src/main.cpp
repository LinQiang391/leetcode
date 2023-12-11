#include"Solution.h"
#include<boost\asio.hpp>
#include"struct.h"
#include <iostream>
#include <cstdlib>  // 包含rand()和srand()
#include <ctime>    // 包含time()
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
	/*tree.Put(4);
	tree.Put(2);
	tree.Put(3);
	tree.Put(4);
	tree.Put(2);
	tree.Put(3);
	tree.Put(4);
	tree.Put(2);
	tree.Put(3);*/
	//tree.Put(7);
	//tree.Put(10);
	//tree.InorderPrint();
	//srand(static_cast<unsigned int>(time(0)));

	//// 生成并打印10个随机整数
	for (int i = 0; i < 10000; ++i) {
		//int random_integer = rand();  // 生成随机整数
		//std::cout << random_integer << std::endl;
		tree.Put(rand());
	}
	tree.InorderPrint();
	std::cout<<tree.GetSize()<<std::endl;
}