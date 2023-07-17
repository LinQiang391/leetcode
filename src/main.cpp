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
	string str = "1s3 PSt";
	vector<string> vec = { "step", "steps", "stripe", "stepple" };
	/*vector<string> res=s.findRelativeRanks(vec);
	for (auto i : res) {
		cout << i << endl;
	}*/
	//s.findErrorNums(vec);
	//cout << s.findMaxAverage(vec, 1) << endl;
	s.shortestCompletingWord(str, vec);
}