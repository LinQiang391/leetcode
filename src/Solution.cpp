#include"Solution.h"
/**
 * .
 * @brief 题目：https://leetcode.cn/problems/relative-ranks/
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

/**
 * @brief 题目：https://leetcode.cn/problems/array-partition/
 * 思路：数组排序后，可以连续两两组合，取其中小的那个值相加。
 * @param nums
 * @return 
 */
int Solution::arrayPairSum(vector<int>& nums){
	sort(nums.begin(), nums.end());
	int res = 0;
	for (int i = 0; i < nums.size(); i = i + 2) {
		res = res + nums[i];
	}
	return res;
}

/**
 * @brief 题目：https://leetcode.cn/problems/reshape-the-matrix/
 * @param mat
 * @param r
 * @param c
 * @return 
 */
vector<vector<int>> Solution::matrixReshape(vector<vector<int>>& mat, int r, int c) {
	if (mat.size() * mat.front().size() != r * c) {
		return mat;
	}
	std::vector<std::vector<int>> res(r, std::vector<int>(c, 0));
	int row = 0, col = 0;
	for (auto rows : mat) {
		for (auto item : rows) {
			res[row][col++] = item;
			if (col == c ) {
				col = 0;
				row++;
			}
		}
	}
	/* better method
	* m=mat.size();
	* n=mat[0].size();
	 vector<vector<int>> ans(r, vector<int>(c));
        for (int x = 0; x < m * n; ++x) {
            ans[x / c][x % c] = nums[x / n][x % n];
        }
	*/
	return res;
}


/**
 * @brief 题目：https://leetcode.cn/problems/distribute-candies/
 * @param candyType
 * @return 
 */
int Solution::distributeCandies(vector<int>& candyType) {
	map<int, int> mp;
	for (auto item : candyType) {
		if (mp.find(item) == mp.end()) {
			mp[item]++;
		}
		else {
			mp[item] = 1;
		}
	}
	return min(mp.size(), candyType.size() / 2);

	/*可以使用用set去重优化
	* return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);	
	*/
}


/**
 * @brief 题目：https://leetcode.cn/problems/longest-harmonious-subsequence/
 * @param nums
 * @return 
 */
int Solution::findLHS(vector<int>& nums) {
	unordered_set<int> set(nums.begin(), nums.end());
	map<int, int> mp;
	for (auto item : set) {
		mp[item] = 0;
	}
	for (auto iter : nums) {
		mp[iter]++;
	}
	int res = 0;
	for (auto item : set) {
		if (mp.find(item + 1) != mp.end()) {
			res = max(res, mp[item] + mp[item + 1]);
		}
		else if (mp.find(item - 1) != mp.end()) {
			res = max(res, mp[item] + mp[item - 1]);
		}
	}
	return res;


	/*
	* 
	* 优化写法 c++17引入结构化绑定键值方式遍历map表
	unordered_map<int, int> cnt;
        int res = 0;
        for (int num : nums) {
            cnt[num]++;
        }
        for (auto [key, val] : cnt) {
            if (cnt.count(key + 1)) {
                res = max(res, val + cnt[key + 1]);
            }
        }
        return res;
	*/
}
