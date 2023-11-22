#include"Solution.h"
#include<boost\asio.hpp>
#include"struct.h"
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
	LinkedList L;
	L.AddNode(Node(1));
	L.AddNode(Node(2));
	L.AddNode(Node(3));
	//L.InsertNodeAfter(Node(4), 3);
	L.InsertNode(Node(4), 4);
	L.InsertNode(Node(5), 5);
	L.DeleteNode(5);
	L.PrintLinkedList();
}