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
	vector<int>vec = { 1,2,2,3,1,4,2 };
	/*vector<string> res=s.findRelativeRanks(vec);
	for (auto i : res) {
		cout << i << endl;
	}*/
	//s.findErrorNums(vec);
	//cout << s.findMaxAverage(vec, 1) << endl;
	cout << s.findShortestSubArray(vec);
}