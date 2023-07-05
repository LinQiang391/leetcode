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
	vector<vector<int>> vec = { {1, 2},{3, 4} };
	/*vector<string> res=s.findRelativeRanks(vec);
	for (auto i : res) {
		cout << i << endl;
	}*/
	s.matrixReshape(vec,1,4);
}