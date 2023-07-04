#include"Solution.h"
/*****************************************************************//**
 * @file   main.cpp
 * @brief  
 * 
 * @author johnny
 * @date   July 2023
 *********************************************************************/


void main() {
	Solution s;
	vector<int> vec = { 10,3,8,9,4 };
	vector<string> res=s.findRelativeRanks(vec);
	for (auto i : res) {
		cout << i << endl;
	}
}