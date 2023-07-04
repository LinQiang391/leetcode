#include"Solution.h"

/**
 * .
 * @brief 506. 相对名次
 * @param score
 * @return 
 */

vector<string> Solution::findRelativeRanks(vector<int>& score) {
	vector<int> vec_b = score;
	sort(vec_b.begin(), vec_b.end(), [](int a, int b) {return a > b;});
	map<int, string> record;
	for (int i = 0; i < vec_b.size(); i++) {
		if (i == 0)
		{
			record[vec_b[i]] = "Gold Medal";
		}
		else if (i == 1)
		{
			record[vec_b[i]] = "Silver Medal";
		}
		else if (i == 2) {
			record[vec_b[i]] = "Bronze Medal";
		}
		else {
			record[vec_b[i]] = to_string(i+1);
		}
	}
	vector<string> res;
	for (int i = 0; i < score.size(); i++) {
		res.push_back(record[score[i]]);
	}
	return res;

}