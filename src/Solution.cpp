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
	return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);  //、最大乘积的结果只能最大三个数，或者最小两个数和最大的数的乘积
}

/**
 * @brief 题目：643. 子数组最大平均数 I
 * @url:https://leetcode.cn/problems/maximum-average-subarray-i/
 * @param nums
 * @param k
 * @return
 */
double Solution::findMaxAverage(vector<int>& nums, int k) {
	int n = nums.size();
	int res = 0;
	for (int i = 0; i < k; i++) {
		res += nums[i];
	}
	int total = res;
	for (int i = k; i < n; i++) {
		total = total - nums[i - k] + nums[i];			///滑动窗口
		res = max(res, total);
	}
	cout << res << endl;
	return res / (k * 1.0);
}


/**
 * @brief 题目：645. 错误的集合
 * @url:https://leetcode.cn/problems/set-mismatch/
 * @param nums
 * @return
 */
vector<int> Solution::findErrorNums(vector<int>& nums) {
	/*map<int, int>mp;
	vector<int>res;
	for (int i = 0; i < nums.size(); i++) {
		mp[nums[i]]++;
	}
	int lost;
	int overlap;
	for (int i = 1; i <= nums.size(); i++) {
		if (mp.find(i) == mp.end()) {
			lost = i;
		}
		if (mp[i] == 2) {
			overlap = i;
		}
	}
	res.push_back(overlap);
	res.push_back(lost);
	return res;*/
	int nums1 = 0, nums2 = 0;			//位运算优化
	int xorsum = 0;
	for (auto item : nums) {
		xorsum ^= item;
	}
	for (int i = 1; i <= nums.size(); i++) {
		xorsum ^= i;
	}

	int lowbit = xorsum & (~xorsum + 1);  //取一个数二进制最后一位为1，其余为0的值 等价于xorsum&(-xorsum)		此法可以快速解决一个数组中出现奇数次的两个数。
	for (auto item : nums) {
		if ((item & lowbit) == 0) {
			nums1 ^= item;
		}
		else {
			nums2 ^= item;
		}
	}
	for (int i = 1; i <= nums.size(); i++) {
		if ((i & lowbit) == 0) {
			nums1 ^= i;
		}
		else {
			nums2 ^= i;
		}
	}

	vector<int>res;
	for (auto item : nums) {
		if (item == nums1) {
			res.push_back(nums1);
			res.push_back(nums2);
			return res;
		}
	}
	res.push_back(nums2);
	res.push_back(nums1);
	return res;


}

/**
 * @brief 题目：661. 图片平滑器
 * @url:https://leetcode.cn/problems/image-smoother/
 * @param img
 * @return
 */
vector<vector<int>> Solution::imageSmoother(vector<vector<int>>& img) {

	int m = img.size();
	int n = img.front().size();
	vector<vector<int>>res(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int sum = 0;
			int total = 0;
			for (int x = i - 1; x <= i + 1; x++) {
				for (int y = j - 1; y <= j + 1; y++) {
					if (0 <= x && x <= m - 1 && 0 <= y && y <= n - 1) {
						sum += img[x][y];
						total++;
					}
				}
			}
			res[i][j] = sum / total;
		}
	}
	return res;

}

/**
 * @brief 题目：674. 最长连续递增序列
 * @url:https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
 * @param nums
 * @return
 */
int Solution::findLengthOfLCIS(vector<int>& nums) {
	vector<int> vec;
	int res = numeric_limits<int>::min();
	for (auto item : nums) {
		if (vec.empty() || vec.back() < item) {
			vec.push_back(item);
		}
		else {
			res = max(res, (int)vec.size());
			vec.clear();
			vec.push_back(item);
		}
	}
	return max(res, (int)vec.size());
}

/**
 * @brief 题目：682. 棒球比赛
 * @url:https://leetcode.cn/problems/baseball-game/
 * @param operations
 * @return
 */
int Solution::calPoints(vector<string>& operations) {
	vector<int> res;
	int total = 0;
	for (auto opt : operations) {
		if (opt == "+") {
			res.push_back(*(res.end() - 1) + *(res.end() - 2));
		}
		else if (opt == "C") {
			res.pop_back();
		}
		else if (opt == "D") {
			res.push_back(res.back() * 2);
		}
		else {
			res.push_back(stoi(opt));
		}
	}
	for (auto item : res) {
		total += item;
	}
	return total;
}

/**
 * @brief 题目：697. 数组的度
 * @url:https://leetcode.cn/problems/degree-of-an-array/
 * @param nums
 * @return
 */
int Solution::findShortestSubArray(vector<int>& nums) {
	map<int, int>mp;
	for (auto num : nums) {
		mp[num]++;
	}
	int degree = 0;
	for (auto item : mp) {
		degree = max(degree, item.second);
	}
	if (degree == 1) {
		return degree;
	}
	vector<int>target;
	for (auto item : mp) {
		if (item.second == degree) {
			target.push_back(item.first);
		}
	}
	int res = numeric_limits<int>::max();
	for (auto item : target) {
		for (auto iter = nums.end() - 1; iter != nums.begin(); iter--) {
			if (*iter == item) {
				int distance = iter - find(nums.begin(), nums.end(), item);
				res = min(res, distance + 1);
				break;
			}
		}
	}
	return res;


	/* 官方参考，写法优秀
	unordered_map<int, vector<int>> mp;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (mp.count(nums[i])) {
				mp[nums[i]][0]++;
				mp[nums[i]][2] = i;
			} else {
				mp[nums[i]] = {1, i, i};
			}
		}
		int maxNum = 0, minLen = 0;
		for (auto& [_, vec] : mp) {
			if (maxNum < vec[0]) {
				maxNum = vec[0];
				minLen = vec[2] - vec[1] + 1;
			} else if (maxNum == vec[0]) {
				if (minLen > vec[2] - vec[1] + 1) {
					minLen = vec[2] - vec[1] + 1;
				}
			}
		}
		return minLen;
	*/
}

/**704. 二分查找

 * @brief 题目：
 * @url:https://leetcode.cn/problems/binary-search/
 * @param nums
 * @param target
 * @return
 */
int Solution::search(vector<int>& nums, int target) {
	int left = 0, right = nums.size();
	while (left != right) {
		int mid = (left + right) / 2;
		if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid;
		}
		else {
			return mid;
		}
	}
	return -1;


	/*
	int left = 0, right = nums.size()-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid]<target) {
			left = mid + 1;
		}
		else if(nums[mid]>target) {
			right = mid-1;
		}
		else {
			return mid;
		}
	}
	return -1;
	*/
}
/**
 * @brief 题目：717. 1 比特与 2 比特字符
 * @url:https://leetcode.cn/problems/1-bit-and-2-bit-characters/
 * @param bits
 * @return
 */
bool Solution::isOneBitCharacter(vector<int>& bits) {
	int n = bits.size();
	int i = 0;
	while (i < n - 1) {
		/*if (bits[i] == 1) {
			i = i + 2;
		}
		else {
			i = i + 1;
		}*/
		i += bits[i] + 1;
	}
	return i == n - 1;
}

/**
 * @brief 题目：724. 寻找数组的中心下标
 * @url:https://leetcode.cn/problems/find-pivot-index/
 * @param nums
 * @return
 */
int Solution::pivotIndex(vector<int>& nums) {
	int left_sum = 0;
	int right_sum = 0;
	for (auto iter = nums.begin() + 1; iter != nums.end(); iter++) {
		right_sum += *iter;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (left_sum == right_sum) {
			return i;
		}
		if (i == nums.size() - 1) {
			return -1;
		}
		left_sum += nums[i];
		right_sum -= nums[i + 1];
	}
}

/**
 * @brief 题目：733. 图像渲染
 * @url:https://leetcode.cn/problems/flood-fill/
 * @param image
 * @param sr
 * @param sc
 * @param color
 * @return
 */
vector<vector<int>> Solution::floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	int n = image.size();
	int m = image.front().size();
	int target = image[sr][sc];
	vector<pair<int, int>>vec;
	//vector<vector<int>>flag(n, vector<int>(m, 0));
	vec.push_back({ sr,sc });
	if (target == color) {
		return image;
	}
	while (!vec.empty())										//广度优先搜索
	{
		int row = vec.front().first;
		int col = vec.front().second;
		if (row - 1 >= 0 && image[row - 1][col] == target) {
			vec.push_back({ row - 1,col });
			//flag[row - 1][col] = 1;
			image[row - 1][col] = color;
		}
		if (row + 1 < n && image[row + 1][col] == target) {
			vec.push_back({ row + 1,col });
			//flag[row + 1][col] = 1;
			image[row + 1][col] = color;
		}
		if (col - 1 >= 0 && image[row][col - 1] == target) {
			vec.push_back({ row ,col - 1 });
			//flag[row][col - 1] = 1;
			image[row][col - 1] = color;
		}
		if (col + 1 < m && image[row][col + 1] == target) {
			vec.push_back({ row,col + 1 });
			//flag[row][col + 1] = 1;
			image[row][col + 1] = color;
		}
		vec.erase(vec.begin());
	}
	image[sr][sc] = color;
	return image;



	//写法优化，取一个格子的上下左右方位：其中(x,y)为中心格子的坐标,一次对应下，右，左，上四个方位的格子。
	/*
	const int dx[4] = {1, 0, 0, -1};
	const int dy[4] = { 0, 1, -1, 0 };
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i], my = y + dy[i];
		if (mx >= 0 && mx < n && my >= 0 && my < m && image[mx][my] == currColor) {
			image[mx][my] = color;
		}
	}*/



}

/**
 * @brief 题目：744. 寻找比目标字母大的最小字母
 * @url:https://leetcode.cn/problems/find-smallest-letter-greater-than-target/
 * @param letters
 * @param target
 * @return
 */
char Solution::nextGreatestLetter(vector<char>& letters, char target) {
	for (auto c : letters) {			//线性查找
		if (target < c) {
			return c;
		}
	}
	return letters[0];

	/*
	二分查找
	return target < letters.back() ? *upper_bound(letters.begin(), letters.end() - 1, target) : letters[0];
	*/
}

/**
 * @brief 题目：746. 使用最小花费爬楼梯
 * @url:https://leetcode.cn/problems/min-cost-climbing-stairs/
 * @param cost
 * @return
 */
int Solution::minCostClimbingStairs(vector<int>& cost) {
	/*
	初次初拥动态规划：
	1.定义dp[]数组,其中dp[i]表示到达第i个阶梯需要的最小花费。
	2.求动态方程（递推表达式）：dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])由题目可知，第i个阶梯的最小花费由前一个阶梯或者前两个阶梯及其所需的花费可以推出。
	3.初始化dp数组。有递推表达式可知，需要初始化的值为dp[0]和dp[1]。由题目可知，可以从第一阶梯或者第二阶梯出发，即dp[0],dp[1]均为0;
	4.求目标值
	*/

	vector<int>dp(cost.size() + 1);
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i < dp.size(); i++) {
		dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
	}
	return dp[cost.size()];
}

/**
 * @brief 题目：747. 至少是其他数字两倍的最大数
 * @url:https://leetcode.cn/problems/largest-number-at-least-twice-of-others/
 * @param nums
 * @return
 */
int Solution::dominantIndex(vector<int>& nums) {
	/*int n = nums.size();
	if (n == 1) {
		return 0;
	}
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[nums[i]] = i;
	}
	sort(nums.begin(), nums.end());
	if (nums[n - 1] >= nums[n - 2] * 2) {
		return mp[nums[n - 1]];
	}
	return -1;*/

	//实际只要找到最大的值，以及第二大的值就可以，通过线性遍历
	int n = nums.size();
	pair<int, int> first_num = { 0,0 };
	pair<int, int> second_num = { 0,0 };
	for (int i = 0; i < n; i++) {
		if (nums[i] > first_num.first) {
			second_num = first_num;
			first_num.first = nums[i];
			first_num.second = i;
		}
		else {
			if (nums[i] > second_num.first) {
				second_num.first = nums[i];
				second_num.second = i;
			}
		}
	}
	if (first_num.first >= second_num.first * 2) {
		return first_num.second;
	}
	return -1;


}

/**
 * @brief 题目：748. 最短补全词
 * @url:https://leetcode.cn/problems/shortest-completing-word/
 * @param licensePlate
 * @param words
 * @return 
 */
string Solution::shortestCompletingWord(string licensePlate, vector<string>& words) {
	int n = words.size();
	map<char, int>mp;
	for (auto ch : licensePlate) {
		if (isalpha(ch)) {
			mp[tolower(ch)]++;
		}
	}
	int i = 0;
	string s(1001, 0);
	for (; i < n; i++) {
		map<char, int> mp2;
		for (auto ch : words[i]) {
			if (isalpha(ch)) {
				mp2[tolower(ch)]++;
			}
		}
		if (mp2.size() < mp.size()) {
			continue;
		}
		bool flag = true;
		for (auto entry : mp) {
			if (mp2.count(entry.first) == 0 || mp2[entry.first] < entry.second) {
				flag = false;
				break;
			}
		}
		if (flag) {
			s = s.length() <= words[i].length() ? s : words[i];
		}
	}
	return s;
}




