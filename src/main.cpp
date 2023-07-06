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
	vector<int>vec = { 1 };
	/*vector<string> res=s.findRelativeRanks(vec);
	for (auto i : res) {
		cout << i << endl;
	}*/
	s.canPlaceFlowers(vec, 1);
}