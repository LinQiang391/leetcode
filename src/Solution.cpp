#include"Solution.h"
/**
 * .
 * @brief 题目：506. 相对名次
 * url:https://leetcode.cn/problems/relative-ranks/
 * @param score
 * @return
 */
vector<string> Solution::findRelativeRanks(vector<int>& score) {
	vector<int> vec_b = score;
	sort(vec_b.begin(), vec_b.end(), [](int a, int b) {return a > b; });
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
			record[vec_b[i]] = to_string(i + 1);
		}
	}
	vector<string> res;
	for (int i = 0; i < score.size(); i++) {
		res.push_back(record[score[i]]);
	}
	return res;

}

/**
 * @brief 题目：561. 数组拆分
 * url:https://leetcode.cn/problems/array-partition/
 * 思路：数组排序后，可以连续两两组合，取其中小的那个值相加。
 * @param nums
 * @return
 */
int Solution::arrayPairSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int res = 0;
	for (int i = 0; i < nums.size(); i = i + 2) {
		res = res + nums[i];
	}
	return res;
}

/**
 * @brief 题目：566.重塑矩阵
 * url:https://leetcode.cn/problems/reshape-the-matrix/
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
			if (col == c) {
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
 * @brief 题目：575. 分糖果
 * url:https://leetcode.cn/problems/distribute-candies/
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
 * @brief 题目：594.最长和谐子序列
 * url:https://leetcode.cn/problems/longest-harmonious-subsequence/
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

/**
 * @brief 题目：598. 范围求和 II
 * url:https://leetcode.cn/problems/range-addition-ii/
 * 寻找最小边界
 * @param m
 * @param n
 * @param ops
 * @return
 */
int Solution::maxCount(int m, int n, vector<vector<int>>& ops) {
	if (ops.size() == 0) {
		return m * n;
	}
	else {
		int left = numeric_limits<int>::max(), right = numeric_limits<int>::max();
		for (auto item : ops) {
			left = min(left, item[0]);
			right = min(right, item[1]);
		}
		return left * right;
	}
}

/**
 * @brief 题目：599. 两个列表的最小索引总和
 * url: https://leetcode.cn/problems/minimum-index-sum-of-two-lists/
 * @param list1
 * @param list2
 * @return
 */
vector<string> Solution::findRestaurant(vector<string>& list1, vector<string>& list2) {
	map<string, int> mp;
	map<int, vector<string>> res;
	int m = list1.size();
	int n = list2.size();
	for (int i = 0; i < m; i++) {
		mp[list1[i]] = i;
	}
	int min_index = numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		if (mp.find(list2[i]) != mp.end()) {
			min_index = min(min_index, mp[list2[i]] + i);
			res[mp[list2[i]] + i].push_back(list2[i]);
		}
	}
	return res[min_index];
}



/**
 * @brief 题目：605. 种花问题
 * @url:https://leetcode.cn/problems/can-place-flowers/
 * @param flowerbed
 * @param n
 * @return
 */
bool Solution::canPlaceFlowers(vector<int>& flowerbed, int n) {
	int m = flowerbed.size();
	int res = 0;
	int zero_count = 0;   //两朵花之间空的格子数
	bool flag = true;
	for (int i = 0; i < m; i++) {
		if (flowerbed[i] == 1) {
			if (flag) {
				res = res + zero_count / 2;			//考虑左边界，没有花，右边界有花,只种一端，最多可种 格子数/2
				flag = false;					//标志左边出现花
			}
			else {
				res = res + (zero_count - 1) / 2;		//一般情况，两朵花之间可以种的花的数量为（格子数-1）/2
			}
			zero_count = 0;
		}
		else {
			zero_count++;
		}
	}
	if (zero_count == m) {
		res = res + (zero_count + 1) / 2;		//两端都不种，（格子数+1)/2
	}
	else {
		res = res + zero_count / 2;				//考虑左边界有花，右边界无花，只种一段。
	}
	return res >= n;
}


/**
 * @brief 题目：628. 三个数的最大乘积
 * @url:https://leetcode.cn/problems/maximum-product-of-three-numbers/
 * @param nums
 * @return 
 */
int Solution::maximumProduct(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);  //最大乘积的结果只能最大三个数，或者最小两个数和最大的数的乘积
}


