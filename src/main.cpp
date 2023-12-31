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

	while (true)
	{

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

		//std::vector<int>vec = { 226, 29, 904, 678, 565, 24, 712, 102, 347, 39, 594, 987, 738, 693, 392, 825, 996, 533, 817, 141, 151, 127, 666, 487, 708, 630, 918, 123, 1, 94, 684, 410, 477, 633, 0, 110, 517, 2, 614, 749, 130, 812, 991, 614, 1, 734, 420, 240, 80, 556 };
		//std::vector<int>vec = {  423, 876, 188, 845, 91, 42, 775, 5, 727, 469, 869, 4, 943, 507, 512, 207, 903, 678, 699, 671, 88, 530, 555, 51, 961, 539, 3, 276, 7, 231, 671, 748, 305, 833, 198, 991, 374, 364, 861, 159, 254, 458, 273, 468, 917, 666, 176, 978, 732, 365};
		//std::vector<int>vec = { 379, 207, 678, 651, 471, 4, 312, 529, 538, 975, 283, 879, 145, 584, 5, 412, 785, 999, 402, 4, 1, 153, 64, 676, 703, 854, 869, 374, 731, 368 };
		//std::vector<int>vec = { 770, 711, 271, 257, 0, 967, 5, 160, 669, 626, 631, 544, 613, 769, 41, 320, 542, 5, 20, 684, 13, 913, 308, 533, 618, 327, 979, 488, 682, 613 };

		//std::vector<int>vec = { 3, 924, 630, 337, 298, 651, 4, 0, 323, 696 };

		std::vector<int>vec = { 372, 793, 587, 689, 180, 5, 590, 474, 991, 174, 203, 512, 570, 554, 753, 137, 945, 251, 996, 805, 304, 119, 108, 3, 25, 337, 983, 274, 0, 341 };
		for (int i = 0; i < 10000; i++) {
			int val = distribution(gen);
			//tree.Put(vec[i]);
			tree.Put(val);
			//std::cout << val << ", ";
			//tree.Put(1);
		}
		//tree.LevelPrint();
		// 生成随机数
		/*int randomNum = distribution(gen);
		for (auto i : nums) {
			tree.Put(i);
		}*/
		tree.Put(5);
		tree.Put(5);
		tree.Put(5);

		//tree.LevelPrint();
		//tree.InorderPrint();
		//tree.PrintBinaryTree();

		if (tree.IsBanlanced()) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
		}
		tree.Delete(5);
		tree.Delete(5);
		//tree.LevelPrint();
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
		//tree.InorderPrint();
		//tree.PrintBinaryTree();
		if (tree.IsBanlanced()) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
			break;
		}
		std::cout << tree.GetSize() << std::endl;
	}
}