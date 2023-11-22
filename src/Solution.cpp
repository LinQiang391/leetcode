#include"Solution.h"
#include <set>
#include <queue>
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



/**
 * @brief 题目：766. 托普利茨矩阵
 * @url:https://leetcode.cn/problems/toeplitz-matrix/
 * @param matrix
 * @return
 */
bool Solution::isToeplitzMatrix(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix.front().size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 >= 0 && i + 1 < n && j + 1 >= 0 && j + 1 < m && matrix[i][j] != matrix[i + 1][j + 1]) {
				return false;
			}
		}
	}
	return true;
}

/**
 * @brief 题目：804. 唯一摩尔斯密码词
 * @url:https://leetcode.cn/problems/unique-morse-code-words/
 * @param words
 * @return
 */
int Solution::uniqueMorseRepresentations(vector<string>& words) {
	map<char, string>mp;
	set<string>res;
	vector<string>decode = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	string str = "abcdefghijklmnopqrstuvwxyz";
	int i = 0;
	for (auto ch : str) {
		mp[ch] = decode[i++];
	}
	for (auto s : words) {
		string s1;
		for (auto c : s) {
			s1 += mp[c];
		}
		res.emplace(s1);
	}
	return res.size();

}

/**
 * @brief 题目：806. 写字符串需要的行数
 * @url:https://leetcode.cn/problems/number-of-lines-to-write-string/
 * @param widths
 * @param s
 * @return
 */
vector<int> numberOfLines(vector<int>& widths, string s) {
	int total = 0;
	vector<int> res;
	int row = 1;
	for (auto ch : s) {
		/*total += widths[ch - 'a'];*/
		if (total + widths[ch - 'a'] > 100) {
			row++;
			total = widths[ch - 'a'];
		}
		else {
			total += widths[ch - 'a'];
		}
	}
	res = { row,total };
	return res;
}


/**
 * @brief 题目：812. 最大三角形面积
 * @url:https://leetcode.cn/problems/largest-triangle-area/
 * 还有一种利用凸包的运算
 * @param points
 * @return
 */
double Solution::largestTriangleArea(vector<vector<int>>& points) {
	int n = points.size();
	auto aera = [](int x1, int y1, int x2, int y2, int x3, int y3) {				//三角形的面积公式，由S=1/2|PA||PB|sinθ
		return abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)) * 1.0 / 2;
	};
	double res = 0.;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				res = max(res, aera(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
			}
		}
	}
	return res;
}


/**
 * @brief 题目：821            . 字符的最短距离
 * @url:https://leetcode.cn/problems/shortest-distance-to-a-character/
 * @param s
 * @param c
 * @return
 */
vector<int> Solution::shortestToChar(string s, char c) {
	int n = s.length();
	vector<int> answer;
	vector<int> index;
	for (int i = 0; i < n; i++) {
		if (s[i] == c) {
			index.push_back(i);
		}
	}

	for (int i = 0; i < n; i++) {
		if (i <= index[0]) {
			answer.push_back(index.front() - i);
		}
		else if (index.size() > 1 && i >= index[0] && i <= index[1]) {
			if (index[1] - i <= i - index[0]) {
				answer.push_back(index[1] - i);
				index.erase(index.begin());
			}
			else {
				answer.push_back(i - index[0]);
			}

		}
		else {
			answer.push_back(i - index[0]);
		}
	}
	return answer;

	/*先从左往右遍历，计算就算当前点与最近左目标点的距离，然后从右往左遍历，计算当前点与最近右目标点的距离，取最小值。
	int n = s.length();
		vector<int> ans(n);

		for (int i = 0, idx = -n; i < n; ++i) {
			if (s[i] == c) {
				idx = i;
			}
			ans[i] = i - idx;
		}

		for (int i = n - 1, idx = 2 * n; i >= 0; --i) {
			if (s[i] == c) {
				idx = i;
			}
			ans[i] = min(ans[i], idx - i);
		}
		return ans;
	*/
}

/**
 * @brief 题目：832. 翻转图像
 * @url:https://leetcode.cn/problems/flipping-an-image/
 * @param image
 * @return
 */
vector<vector<int>> Solution::flipAndInvertImage(vector<vector<int>>& image) {
	auto fun = [&](vector<int>& vec) {
		auto beg = vec.begin();
		auto end = vec.end() - 1;
		while (beg < end) {
			if (*beg == *end) {
				*beg ^= 1;
				*end = *beg;
			}
			end--;
			beg++;
		}
		if (beg == end) {
			*beg ^= 1;
		}
	};
	for (int i = 0; i < image.size(); i++) {
		fun(image[i]);
	}
	return image;
}


/**
 * @brief 题目：867. 转置矩阵
 * @url:https://leetcode.cn/problems/transpose-matrix/
 * @param matrix
 * @return
 */
vector<vector<int>> Solution::transpose(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> res;
	for (int j = 0; j < m; j++) {
		vector<int>tmp;
		for (int i = 0; i < n; i++) {
			tmp.push_back(matrix[i][j]);
		}
		res.push_back(tmp);
	}
	return res;

	/*简单粗暴
	int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> transposed(n, vector<int>(m));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				transposed[j][i] = matrix[i][j];
			}
		}
		return transposed;
	*/
}

/**
 * @brief 题目：883. 三维形体投影面积
 * @url:https://leetcode.cn/problems/projection-area-of-3d-shapes/
 * @param grid
 * @return
 */
int Solution::projectionArea(vector<vector<int>>& grid) {
	/*int n = grid.size();
	for (int i = 0; i < n; i++) {
		vector<int>tmp;
		for (int j = 0; j < n; j++) {
			tmp.push_back(grid[i][j]);
		}
	}*/

	auto fun = [](vector<int> vec) {
		int max_num = 0;
		for (auto item : vec) {
			max_num = max(item, max_num);
		}
		return max_num;
	};
	int res = 0;
	int n = grid.size();
	for (int i = 0; i < n; i++) {
		res += fun(grid[i]);
	}
	for (int j = 0; j < n; j++) {
		vector<int>tmp;
		for (int i = 0; i < n; i++) {
			if (grid[i][j] != 0) {
				res++;
			}
			tmp.push_back(grid[i][j]);
		}
		res += fun(tmp);
	}
	return res;
	/*
	算法可以优化
	仅限方阵可以使用，y平面的投影最大值为同列中的最大值，z平面的投影为同行中的最大值，x平面的投影为非零值
	 int n = grid.size();
		int xyArea = 0, yzArea = 0, zxArea = 0;
		for (int i = 0; i < n; i++) {
			int yzHeight = 0, zxHeight = 0;
			for (int j = 0; j < n; j++) {
				xyArea += grid[i][j] > 0 ? 1 : 0;
				yzHeight = max(yzHeight, grid[j][i]);
				zxHeight = max(zxHeight, grid[i][j]);
			}
			yzArea += yzHeight;
			zxArea += zxHeight;
		}
		return xyArea + yzArea + zxArea;
	*/

}

/**
 * @brief 题目：888. 公平的糖果交换
 * @url:https://leetcode.cn/problems/fair-candy-swap/
 * @param aliceSizes
 * @param bobSizes
 * @return
 */
vector<int> Solution::fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
	int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
	int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
	vector<int> res;
	int k = abs(sum1 - sum2) / 2;
	if (sum1 <= sum2) {
		for (int i = 0; i < aliceSizes.size(); i++) {
			auto iter = find(bobSizes.begin(), bobSizes.end(), aliceSizes[i] + k);
			if (iter != bobSizes.end()) {
				res = { aliceSizes[i],*iter };
				return res;
			}
		}
	}
	else {
		for (int i = 0; i < bobSizes.size(); i++) {
			auto iter = find(aliceSizes.begin(), aliceSizes.end(), bobSizes[i] + k);
			if (iter != aliceSizes.end()) {
				res = { *iter,bobSizes[i] };
				return res;
			}
		}
	}
	return res;

	/*
	可以通过hashmap存储，空间换时间
	*/
}


/**
 * @brief 题目：892. 三维形体的表面积
 * @url:https://leetcode.cn/problems/surface-area-of-3d-shapes/
 * @param grid
 * @return
 */
int Solution::surfaceArea(vector<vector<int>>& grid) {
	int n = grid.size();
	int row_block = 0;		//相邻前后遮挡的块数
	int col_block = 0;		//相邻左右遮挡的块数
	int z_block = 0;		//上下遮挡的块数
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < n - 1) {
				row_block += min(grid[i][j], grid[i + 1][j]);
			}
			if (j < n - 1) {
				col_block += min(grid[i][j], grid[i][j + 1]);
			}
			z_block += grid[i][j] > 0 ? grid[i][j] - 1 : 0;		//z_block += max(grid[i][j] - 1, 0);
			total += grid[i][j];
		}
	}
	return total * 6 - (row_block + col_block + z_block) * 2;			//表面积=总的表面积-遮挡的总面积(上下，前后，左右遮挡总块数*2)
}


/**
 * @brief 题目：896. 单调数列
 * @url:https://leetcode.cn/problems/monotonic-array/
 * @param nums
 * @return
 */
bool Solution::isMonotonic(vector<int>& nums) {
	vector<int>tmp = nums;
	if (nums.size() == 1) {
		return true;
	}
	int prev;
	if (nums[0] < nums[1]) {
		prev = -1;
	}
	else if (nums[0] > nums[1]) {
		prev = 1;
	}
	else {
		prev = 0;
	}
	int cur;
	for (int i = 1; i < nums.size() - 1; i++) {
		if (nums[i] < nums[i + 1]) {
			cur = -1;
		}
		else if (nums[i] > nums[i + 1]) {
			cur = 1;
		}
		else {
			cur = 0;
		}
		if (cur != 0) {
			if (prev != 0 && prev != cur) {
				return false;
			}
			prev = cur;
		}
	}
	return true;

	/*算法优化 用两个flag分别表示递增，或者递减，一旦都变成false，说明两个都出现了，必定非单调，否则就是单调。
	 bool inc = true, dec = true;
		int n = nums.size();
		for (int i = 0; i < n - 1; ++i) {
			if (nums[i] > nums[i + 1]) {
				inc = false;
			}
			if (nums[i] < nums[i + 1]) {
				dec = false;
			}
		}
		return inc || dec;

	*/
}

/**
 * @brief 题目：905. 按奇偶排序数组
 * @url:https://leetcode.cn/problems/sort-array-by-parity/
 * @param nums
 * @return
 */
vector<int> Solution::sortArrayByParity(vector<int>& nums) {
	int n = nums.size();
	int left = 0;
	auto swap = [](int& a, int& b) {
		if (a != b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
	};
	for (int right = 0; right < n; right++) {		//双指针
		if (nums[right] % 2 == 0) {
			cout << nums[right] << endl;
			cout << nums[left] << endl;
			swap(nums[right], nums[left]);
			left++;
		}
	}
	return nums;
}

int Solution::smallestRangeI(vector<int>& nums, int k) {
	int max_num = numeric_limits<int>::min();
	int min_num = numeric_limits<int>::max();
	for (auto num : nums) {
		max_num = max(max_num, num);
		min_num = min(min_num, num);
	}
	return max(max_num - min_num - 2 * k, 0);
}
/*求两个数的最大公因数
*/
int gcd(int a, int b) {
	return b > 0 ? gcd(b, a % b) : a;
}

bool Solution::hasGroupsSizeX(vector<int>& deck) {
	//map<int, int>mp;
	//for (auto num : deck) {
	//	mp[num]++;
	//}
	//set<int>count;
	//for (auto p : mp) {
	//	count.emplace(p.second);
	//}
	//int min_num = numeric_limits<int>::max();
	//for (auto num : count) {
	//	min_num = min(min_num, num);
	//}
	//if (min_num < 2) {
	//	return false;
	//}

	//if (count.size() < 2) {
	//	return true;
	//}
	///*int min_num = min(*count.begin(), *count.begin()+1);*/
	//auto it = count.begin();
	//int num1 = *it;
	//int num2 = *(it++);
	//min_num = min(num1, num2);
	//for (int i = 2; i <= min_num; i++) {
	//	if (num1% i == 0&&num2%i==0) {
	//		min_num = i;
	//		break;
	//	}
	//}

	//for (auto num : count) {
	//	if (num % min_num != 0) {
	//		return false;
	//	}
	//}
	//return true;

	/*
	求最大公因数
	*/
	//auto fun = [](int a, int b) {
	//	int r;
	//	while (b>0) {
	//		r = a % b;
	//		a = b;
	//		b = r;
	//	}
	//	return a;
	//};
	map<int, int>mp;
	for (auto item : deck) {
		mp[item]++;
	}
	int max_g = -1;
	for (auto p : mp) {
		if (max_g == -1) {
			max_g = p.second;
		}
		else {
			max_g = gcd(max_g, p.second);
		}
	}
	return max_g >= 2;

}


vector<int> Solution::sortArrayByParityII(vector<int>& nums) {
	vector<int> res1;
	vector<int> res2;
	for (auto num : nums) {
		if (num % 2 == 0) {
			res1.push_back(num);
		}
		else {
			res2.push_back(num);
		}
	}
	for (int i = 0; i < nums.size(); i++) {
		if (i % 2 == 0) {
			nums[i] = *res1.begin();
			res1.erase(res1.begin());
		}
		else {
			nums[i] = *res2.begin();
			res2.erase(res2.begin());
		}
	}
	return nums;
}


int Solution::numUniqueEmails(vector<string>& emails) {
	vector<string> str;
	vector<string> str2;
	for (int i = 0; i < emails.size(); i++) {
		str.push_back(emails[i].substr(0, emails[i].find("@")));
		str2.push_back(emails[i].substr(emails[i].find("@"), emails[i].size()));
	}
	for (int i = 0; i < str.size(); i++) {
		string s = "";
		for (auto ch : str[i]) {
			if (ch == '.') {
				continue;
			}
			else if (ch == '+') {
				break;
			}
			else {
				s += ch;
			}
		}
		str[i] = s + str2[i];
	}
	set<string> email_set;
	for (auto item : str) {
		email_set.emplace(item);
	}
	return email_set.size();

	/*优化写法
	unordered_set<string> emailSet;
		for (auto &email: emails) {
			string local;
			for (char c: email) {
				if (c == '+' || c == '@') {
					break;
				}
				if (c != '.') {
					local += c;
				}
			}
			emailSet.emplace(local + email.substr(email.find('@')));
		}
		return emailSet.size();
	*/
}



bool Solution::validMountainArray(vector<int>& arr) {
	if (arr.size() < 3) {
		return false;
	}
	int point = 0;
	for (int i = 1; i < arr.size() - 1; i++) {
		if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
			point++;
		}
		else if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1]) {
			return false;
		}
		else if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) {
			return false;
		}
	}
	return point == 1;
}


vector<int> Solution::diStringMatch(string s) {
	int left = 0; int right = s.size();
	vector<int> res(s.size() + 1);
	int i = 0;
	while (left <= right)
	{
		if (s[i] == 'D') {
			res[i] = right--;
		}
		else {
			res[i] = left++;
		}
		i++;
	}
	return res;

}


int minDeletionSize(vector<string>& strs) {
	int m = strs.size();
	int n = strs[0].size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (strs[j][i] > strs[j + 1][i]) {
				res++;
				break;
			}
		}
	}
	return res;
}


bool Solution::isAlienSorted(vector<string>& words, string order) {
	int i = 0;
	map<char, int>mp;
	for (auto ch : order) {
		mp[ch] = i;
		i++;
	}
	auto compare = [&](string s1, string s2) {
		int len = min(s1.size(), s2.size());
		for (int i = 0; i < len; i++) {
			if (mp[s1[i]] < mp[s2[i]]) {
				return 1;
			}
			else if (mp[s1[i]] > mp[s2[i]]) {
				return -1;
			}
		}
		return s1.size() <= s2.size() ? 1 : -1;
	};

	for (int i = 0; i < words.size() - 1; i++) {
		if (compare(words[i], words[i + 1]) == -1) {
			return false;
		}
	}
	return true;
}

int Solution::repeatedNTimes(vector<int>& nums) {
	map<int, int>mp;
	for (auto num : nums) {
		mp[num]++;
	}
	for (auto entry : mp) {
		if (entry.second == nums.size() / 2) {
			return entry.first;
		}
	}

	/*出现次数大于一次的则为N次的值
	unordered_set<int> found;
	for (int num : nums) {
		if (found.count(num)) {
			return num;
		}
		found.insert(num);
	}*/

	return 0;
}


int Solution::largestPerimeter(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = nums.size() - 1; i >= 2; i--) {
		if (nums[i - 2] + nums[i - 1] > nums[i]) {
			return nums[i - 2] + nums[i - 1] + nums[i];
		}
	}
	return 0;
}


vector<int> Solution::addToArrayForm(vector<int>& num, int k) {
	/*string s = to_string(k);
	vector<int> vec(s.size());
	int i = 0;
	for (auto ch : s) {
		vec[i] = ch - '0';
	}
	int n = num.size();
	int i = n-1;
	int j = s.size()-1;
	int max_size = max(i, j);
	vector<int>res(max_size);
	while (i!=0&&j!=0)
	{
		res[max_size] = num[i] + vec[j];
	}*/
	string s1;
	for (auto item : num) {
		s1 += (char)(item + '0');
	}
	string s2 = to_string(k);

	int n = s1.size() - 1;
	int m = s2.size() - 1;
	vector<int> res(max(n, m) + 2, 0);
	int res_size = res.size();
	int flag = false;
	while (n >= 0 && m >= 0) {
		int tmp = s1[n] - '0' + s2[m] - '0';
		/*if (tmp >= 10) {
			res[res_size - 1] = (char)(tmp - 10 + '0');
			flag = true;
		}*/
		if (flag) {
			tmp += 1;
			if (tmp >= 10) {
				res[res_size - 1] = tmp - 10;
			}
			else {
				res[res_size - 1] = tmp;
				flag = false;
			}
		}
		else {
			if (tmp >= 10) {
				res[res_size - 1] = tmp - 10;
				flag = true;
			}
			else {
				res[res_size - 1] = tmp;
			}
		}
		n--;
		m--;
		res_size--;
	}
	while (n >= 0)
	{
		if (flag) {
			res[res_size - 1] = s1[n] - '0' + 1;
			if (res[res_size - 1] >= 10) {
				res[res_size - 1] = res[res_size - 1] - 10;
			}
			else {
				flag = false;
			}
		}
		else {
			res[res_size - 1] = s1[n] - '0';
		}
		n--;
		res_size--;
	}

	while (m >= 0)
	{
		if (flag) {
			res[res_size - 1] = s2[m] - '0' + 1;
			if (res[res_size - 1] >= 10) {
				res[res_size - 1] = res[res_size - 1] - 10;
			}
			else {
				flag = false;
			}
		}
		else {
			res[res_size - 1] = s2[m] - '0';
		}
		m--;
		res_size--;
	}
	if (!flag) {
		res.erase(res.begin());
	}
	else {
		res[0] = 1;
	}
	return res;


	/*算法优化，可以使用123+912，我们把它表示成 [1,2,3+912]。然后，我们计算 3+912=9155。5留在当前这一位，将 91 以进位的形式加入下一位。
	  vector<int> res;
		int n = num.size();
		for (int i = n - 1; i >= 0 || k > 0; --i, k /= 10) {
			if (i >= 0) {
				k += num[i];
			}
			res.push_back(k % 10);
		}
		reverse(res.begin(), res.end());
		return res;
	*/
}

int Solution::findJudge(int n, vector<vector<int>>& trust) {
	vector<int> in(n + 1, 0);					//计算出入度，满足条件的出度为0，入度为n-1;
	vector<int> out(n + 1, 0);
	for (int i = 0; i < trust.size(); i++) {
		out[trust[i][0]]++;
		in[trust[i][1]]++;
	}
	for (int i = 1; i < n + 1; i++) {
		if (in[i] == n - 1 && out[i] == 0) {
			return i;
		}
	}

	return -1;
}


int Solution::numRookCaptures(vector<vector<char>>& board) {
	int row = 0;
	int col = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 'R') {
				row = i;
				col = j;
				break;
			}
		}
	}
	int res = 0;
	for (int i = row + 1; i < 8; i++) {
		if (board[i][col] == 'p') {
			res++;

		}
		else if (board[i][col] == 'B') {
			break;
		}
	}
	for (int i = row - 1; i >= 0; i--) {
		if (board[i][col] == 'p') {
			res++;
		}
		else if (board[i][col] == 'B') {
			break;
		}
	}
	for (int j = col + 1; j < 8; j++) {
		if (board[row][j] == 'p') {
			res++;
		}
		else if (board[row][j] == 'B') {
			break;
		}
	}
	for (int j = col - 1; j >= 0; j--) {
		if (board[row][j] == 'p') {
			res++;
		}
		else if (board[row][j] == 'B') {
			break;
		}
	}
	return res;
}



vector<string> Solution::commonChars(vector<string>& words) {
	vector<int> res(26, 0);

	for (auto ch : words[0]) {
		res[ch - 'a']++;
	}
	for (int i = 1; i < words.size(); i++) {
		vector<int> count(26, 0);
		for (auto ch : words[i]) {
			count[ch - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			res[i] = min(res[i], count[i]);
		}
	}
	vector<string> sres;
	for (int i = 0; i < 26; i++) {
		if (res[i] > 0) {
			for (int j = 0; j < res[i]; j++) {
				sres.push_back(string(1, i + 'a'));
			}
		}
	}
	return sres;
}


int Solution::largestSumAfterKNegations(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	int res;
	int i = 0;
	int min_value = numeric_limits<int>::max();
	for (; i < k && i < nums.size(); i++) {
		if (nums[i] < 0) {
			nums[i] = -nums[i];
		}
		else {
			break;
		}
	}
	if (k - i > 0) {
		for (int j = 0; j < nums.size(); j++) {
			min_value = min(min_value, abs(nums[j]));
		}
		if ((i - k) % 2 == 0) {
			return accumulate(nums.begin(), nums.end(), 0);
		}
		else {
			return accumulate(nums.begin(), nums.end(), 0) - 2 * min_value;
		}
	}
	return accumulate(nums.begin(), nums.end(), 0);

}


bool Solution::canThreePartsEqualSum(vector<int>& arr) {
	int sum = accumulate(arr.begin(), arr.end(), 0);
	int target = 0;
	if (sum % 3 != 0) {
		return false;
	}
	else {
		target = sum / 3;
	}
	int count = 0;
	int s = 0;
	for (int i = 0; i < arr.size(); i++) {
		s += arr[i];
		if (s == target) {
			count++;
			s = 0;
		}
		if (count == 2 && i < arr.size() - 1) {
			return true;
		}
	}
	return false;
}


vector<bool> Solution::prefixesDivBy5(vector<int>& nums) {
	int n = nums.size();
	int prefix = 0;
	vector<bool>res;
	for (int i = 0; i < n; i++) {
		prefix = ((prefix << 1) + nums[i]) % 5;
		if (prefix == 0) {
			res.push_back(true);
		}
		else {
			res.push_back(false);
		}
	}
	return res;
}


vector<vector<int>> Solution::allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {

	auto distance = [&](int x, int y) {
		return abs(rCenter - x) + abs(cCenter - y);
	};
	map<int, int> mp;
	int index = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mp[index++] = distance(i, j);
		}
	}
	vector<pair<int, int>>vec(mp.begin(), mp.end());
	sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int>b) {
		return a.second < b.second;
		});
	vector<vector<int>>res;
	for (auto entry : vec) {

		res.push_back({ entry.first / cols,entry.first % cols });				//优化方案需要后续学习
	}
	return res;
}


bool Solution::isBoomerang(vector<vector<int>>& points) {
	set<vector<int>>st;
	for (auto item : points) {
		st.emplace(item);
	}
	if (st.size() < 2) {
		return false;
	}
	double k1 = points[0][0] - points[1][0] == 0 ? numeric_limits<double>::max() : (points[0][1] - points[1][1]) * 1.0 / (points[0][0] - points[1][0]);
	double k2 = points[0][0] - points[2][0] == 0 ? numeric_limits<double>::max() : (points[0][1] - points[2][1]) * 1.0 / (points[0][0] - points[2][0]);

	/*
	共线可以用向量的叉乘表示
	vector<int> v1 = { points[1][0] - points[0][0], points[1][1] - points[0][1] };
	vector<int> v2 = { points[2][0] - points[0][0], points[2][1] - points[0][1] };
	return v1[0] * v2[1] - v1[1] * v2[0] != 0;*/
	return k1 != k2;

}


int Solution::lastStoneWeight(vector<int>& stones) {
	priority_queue<int>q;			//最大堆，优先级队列需要了解。
	for (auto s : stones) {
		q.push(s);
	}
	while (q.size() > 1)
	{
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		if (a != b) {
			q.push(a - b);
		}
	}
	return q.empty() ? 0 : q.top();
}


int Solution::heightChecker(vector<int>& heights) {
	vector<int> tmp = heights;
	sort(tmp.begin(), tmp.end());
	int res = 0;
	for (int i = 0; i < heights.size(); i++) {
		if (heights[i] != tmp[i]) {
			res++;
		}
	}
	return res;
}


void Solution::duplicateZeros(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0) {
			int tmp = arr.size();
			while (tmp - 2 > i)
			{
				arr[tmp - 1] = arr[tmp - 2];
				tmp--;
			}
			if (i + 1 < arr.size()) {
				arr[i + 1] = 0;
				i++;
			}
		}
	}
}

vector<int> Solution::relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
	int slow = 0;
	for (int i = 0; i < arr2.size(); i++) {
		int fast = slow;
		while (fast < arr1.size()) {
			if (arr1[fast] == arr2[i]) {
				int tmp = arr1[slow];
				arr1[slow] = arr1[fast];
				arr1[fast] = tmp;
				slow++;
			}
			fast++;
		}
	}
	if (slow != arr1.size() - 1) {
		sort(arr1.begin() + slow, arr1.end());
	}
	return arr1;
}


int Solution::numEquivDominoPairs(vector<vector<int>>& dominoes) {
	for (int i = 0; i < dominoes.size(); i++) {
		if (dominoes[i][0] > dominoes[i][1]) {
			int tmp = dominoes[i][1];
			dominoes[i][1] = dominoes[i][0];
			dominoes[i][0] = tmp;

		}
	}
	map<vector<int>, int>mp;
	for (auto item : dominoes) {
		mp[item]++;
	}
	int res = 0;
	for (auto entry : mp) {
		res += (entry.second) * (entry.second - 1) / 2;
	}
	return res;

	/*优化写法，可以因为（x,y）都不大于10，可以用100以内的数表示xy的所有可能组合。
	vector<int> num(100);
		int ret = 0;
		for (auto& it : dominoes) {
			int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
			ret += num[val];
			num[val]++;
		}
		return ret;
	*/
}


int Solution::countCharacters(vector<string>& words, string chars) {
	vector<int>dic(26, 0);
	for (auto ch : chars) {
		dic[ch - 'a']++;
	}
	int res = 0;
	for (int i = 0; i < words.size(); i++) {
		vector<int>tmp(26, 0);
		bool flag = true;
		for (auto ch : words[i]) {
tmp[ch - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			if (dic[j] < tmp[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			res += words[i].size();
		}
	}
	return res;
}


int Solution::distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
	return min(accumulate(distance.begin(), distance.end(), 0) - accumulate(distance.begin() + min(start, destination), distance.begin() + max(start, destination), 0), accumulate(distance.begin() + min(start, destination), distance.begin() + max(start, destination), 0));
}


vector<vector<int>> Solution::minimumAbsDifference(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> res;
	vector<int> rst;
	for (int i = 1; i < arr.size(); i++) {
		rst.push_back(abs(arr[i] - arr[i - 1]));
	}
	int min_value = numeric_limits<int>::max();
	for (auto val : rst) {
		min_value = min(min_value, val);
	}
	for (int i = 0; i < rst.size(); i++) {
		if (rst[i] == min_value) {
			res.push_back({ arr[i],arr[i + 1] });
		}
	}
	return res;
}


bool Solution::uniqueOccurrences(vector<int>& arr) {
	vector<int> count(2001, 0);
	for (auto num : arr) {
		count[num + 1000]++;
	}
	int val = 0;
	set<int>st;
	for (auto item : count) {
		if (item != 0) {
			val++;
			st.emplace(item);
		}
	}
	return val == st.size();
}


int Solution::minCostToMoveChips(vector<int>& position) {
	int odd = 0;
	int even = 0;
	for (auto pos : position) {
		if (pos % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}

	return min(even, odd);
}


bool Solution::checkStraightLine(vector<vector<int>>& coordinates) {
	auto entry_corss = [](vector<int> p0, vector<int> p1, vector<int>p2) {
		return (p1[0] - p0[0]) * (p2[1] - p0[1]) - (p2[0] - p0[0]) * (p1[1] - p0[1]);
	};
	for (int i = 1; i < coordinates.size(); i++) {
		int t = entry_corss(coordinates[0], coordinates[i - 1], coordinates[i]);
		if (t != 0) {
			return false;
		}
	}
	return true;
}


int Solution::oddCells(int m, int n, vector<vector<int>>& indices) {
	vector<vector<int>> vec(m, vector<int>(n, 0));
	for (auto index : indices) {
		for (int i = 0; i < n; i++) {
			vec[index[0]][i]++;
		}
		for (int j = 0; j < m; j++) {
			vec[j][index[1]]++;
		}
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++){
			if (vec[i][j] % 2 != 0) {
				res++;
			}
		}
	}
	return res;
}


vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
	vector<int>vec;
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>>res(n, vector<int>(m, 0));
	int mv = k % (n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vec.push_back(grid[i][j]);
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		int pos = (i + k) % (m + n);
		res[pos / m][pos % m] = vec[i];
	}
	return res;
}


int Solution::minTimeToVisitAllPoints(vector<vector<int>>& points) {
	auto distance = [](vector<int> p1, vector<int> p2) {
		int dx = abs(p2[0] - p1[0]);
		int dy = abs(p2[1] - p1[1]);
		return max(dx, dy);
	};
	int res = 0;
	for (int i = 1; i < points.size(); i++) {
		res += distance(points[i - 1], points[i]);
	}
	return res;
}


string Solution::tictactoe(vector<vector<int>>& moves) {
	auto win = [](vector<vector<int>> vec) {
		int res1 = 0;
		int res2 = 0;
		vector<int> tmp(6, 0);
		for (auto v : vec) {
			tmp[v[0]]++;
			tmp[3+v[1]]++;
			if ((v[0] + v[1]) == 2) {
				res1++;
			}
			if (v[0] == v[1]) {
				res2++;
			}
		}
		for (auto t : tmp) {
			if (t == 3) {
				return true;
			}
		}
		return res1 == 3 || res2 == 3;
	};

	vector<vector<int>> A;
	vector < vector<int>> B;
	for (int i = 0; i < moves.size(); i++) {
		if (i % 2 == 0) {
			A.push_back(moves[i]);
		}
		else {
			B.push_back(moves[i]);
		}
	}
	bool bA = win(A);
	bool bB = win(B);
	if (bA) {
		return "A";
	}
	if (bB) {
		return "B";
	}
	if (moves.size() == 9) {
		return "Draw";
	}
	return "Pending";
}


int Solution::findSpecialInteger(vector<int>& arr) {
	int tmp = arr[0];
	int count = 0;
	int stand = arr.size() / 4;
	for (auto num : arr) {
		if (tmp == num) {
			count++;
		}
		else {
			if (count > stand) {
				return tmp;
			}
			tmp = num;
			count = 1;
		}
	}
	return *(arr.end() - 1);
}

int Solution::findNumbers(vector<int>& nums) {
	auto fun = [](int n) {
		int count = 0;
		while (n / 10) {
			n = n / 10;
			count++;
		}
		if ((count + 1) % 2) {
			return false;
		}
		return true;
	};
	int res = 0;
	for (auto num : nums) {
		if (fun(num)) {
			res++;
		}
	}
	return res;
}

vector<int> Solution::replaceElements(vector<int>& arr){
	/*auto fun = [](vector<int> vec, int start) {
		int max_value = numeric_limits<int>::min();
		for (auto iter = vec.begin() + start; iter != vec.end(); iter++) {
			max_value = max(*iter, max_value);
		}
		return max_value;
	};*/
	int n = arr.size();
	int max_val = arr[n-1];
	for (int i = n - 2; i >= 0;i--) {
		if (arr[i] > max_val) {
			arr[i] = arr[i] ^ max_val;
			max_val = arr[i] ^ max_val;
			arr[i] = arr[i] ^ max_val;
		}
		else {
			arr[i] = max_val;
		}
	}
	arr[arr.size() - 1] = -1;
	return arr;
}


vector<int> Solution::sumZero(int n) {
	vector<int> res;
	int i = 1;
	for (; i < n; i = i + 2) {
		res.push_back(i);
		res.push_back(-i);
	}
	if (i <= n) {
		res.push_back(0);
	}
	return res;
}


vector<int> Solution::decompressRLElist(vector<int>& nums) {
	vector<int>res;
	for (int i = 0; i < nums.size(); i = i + 2) {
		for (int j = 0; j < nums[i]; j++) {
			res.push_back(nums[i + 1]);
		}
	}
	return res;
}

vector<int> Solution::arrayRankTransform(vector<int>& arr) {

	if (arr.size() < 1) {
		return arr;
	}
	vector<int>tmp = arr;
	sort(tmp.begin(), tmp.end());
	vector<int>res;
	map<int, int>mp;
	int t = tmp[0];
	int ret = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (mp.find(tmp[i]) == mp.end()) {
			mp[tmp[i]] = ret + 1;
			ret++;
		}
	}
	for (auto a : arr) {
		res.push_back(mp[a]);
	}
	return res;
}


vector<int> Solution::kWeakestRows(vector<vector<int>>& mat, int k) {
	vector<pair<int, int>>vec;
	for (int i = 0; i < mat.size(); i++) {
		int total=accumulate(mat[i].begin(), mat[i].end(), 0);
		pair<int, int> p(i, total);
		vec.push_back(p);
	}
	sort(vec.begin(), vec.end(), [](pair<int, int>p1, pair<int, int>p2) {
		if (p1.second == p2.second) {
			return p1.first < p2.first;
		}
		return p1.second < p2.second;
		});
	vector<int>res;
	for (int i = 0; i < k; i++) {
		res.push_back(vec[i].first);
	}
	return res;
}


bool Solution::checkIfExist(vector<int>& arr){
	for (int i = 0; i < arr.size(); i++) {
		auto iter = find(arr.begin(), arr.end(), arr[i] * 2);
		if (iter != arr.end()) {
			if (*iter == 0) {
				if (find(iter + 1, arr.end(), 0) != arr.end()) {
					return true;
				}
			}
			else {
				return true;
			}
		}
	}
	return false;
}


int countNegatives(vector<vector<int>>& grid) {
	int res = 0;
	int n = grid.size();
	int m = grid[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; i++) {
			if (grid[i][j] < 0) {
				res += m - j;
			}
		}
	}
	return res;
}


vector<int> Solution::sortByBits(vector<int>& arr){
	auto count = [](int num) {
		int cnt = 0;
		while (num != 0) {
			cnt += (num & 1);
			num >>= 1;
		}
		return cnt;
	};
	vector<pair<int, int>>vec;
	for (auto n : arr) {
		pair<int, int>p (n, count(n));
		vec.push_back(p);
	}
	sort(vec.begin(), vec.end(), [](pair<int, int>p1, pair<int, int>p2) {
		if (p1.second == p2.second) {
			return p1.first < p2.first;
		}
		return p1.second < p2.second;
		});
	vector<int> res;
	for (auto entry : vec) {
		res.push_back(entry.first);
	}
	return res;
}


vector<int> Solution::smallerNumbersThanCurrent(vector<int>& nums){
	vector<int>tmp = nums;
	map<int, int>mp;
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		if (mp.find(tmp[i]) == mp.end()) {
			mp[tmp[i]] = i;
		}
	}
	for (int i = 0; i < nums.size(); i++) {
		nums[i] = mp[nums[i]] - 1;
	}
	return nums;

	/*计数排序，计算前缀和，nums[i]取值范围较小
	vector<int> cnt(101, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        for (int i = 1; i <= 100; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            ret.push_back(nums[i] == 0 ? 0: cnt[nums[i]-1]);
        }
        return ret;
	*/
}


int Solution::findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d){
	int res = 0;
	sort(arr2.begin(), arr2.end());
	for (int i = 0; i < arr1.size(); i++) {
		if (find(arr2.begin(), arr2.end(), arr1[i]) != arr2.end()) {
			continue;
		}
		else {
			auto greate = lower_bound(arr2.begin(), arr2.end(), arr1[i])== arr2.end() ? arr2.end() - 1 : lower_bound(arr2.begin(), arr2.end(), arr1[i]);
			auto less = greate;
			while (less != arr2.begin()) {
				if (*less < arr1[i]) {
					break;
				}
				less--;
			}
			if (abs(arr1[i] - *less) > d && abs(arr1[i] - *greate) > d) {
				res++;
			}
		}
	}
	return res;
}


vector<int> Solution::luckyNumbers(vector<vector<int>>& matrix){
	vector<int>res;
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i < m; i++) {
		int min_value = numeric_limits<int>::max();
		int col_index = 0;
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (min_value > matrix[i][j]) {
				min_value = matrix[i][j];
				col_index = j;
			}
		}
		for (int row = 0; row < m; row++) {
			if (min_value < matrix[row][col_index]) {
				flag = false;
			}
		}
		if (flag) {
			res.push_back(min_value);
		}
	}
	return res;

	/*优化，幸运数最多只有一个，可以先找出每一行中的最小值，取其中的最大值，记录其自大值所在的列，如果该值在该列中最大，则是幸运数，否则不是
	 int m = matrix.size();
        int rowMax = 0, k;
        for (int i = 0; i < m; i++) {
            int c = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin();
            if (rowMax < matrix[i][c]) {
                rowMax = matrix[i][c];
                k = c;
            }
        }
        for (int i = 0; i < m; i++) {
            if (rowMax < matrix[i][k]) {
                return {};
            }
        }

	*/
}



vector<int> Solution::createTargetArray(vector<int>& nums, vector<int>& index) {
	vector<int>res;
	for (int i = 0; i < nums.size(); i++) {
		res.insert(res.begin() + index[i], nums[i]);
	}
	return res;

}


int Solution::findLucky(vector<int>& arr){
	vector<int>res(501, 0);
	for (int i = 0; i < arr.size(); i++) {
		res[arr[i]]++;
	}
	int result = -1;
	for (int i = 1; i < res.size(); i++) {
		if (res[i] == i) {
			result = res[i];
		}
	}
	return result;
}


vector<int> minSubsequence(vector<int>& nums){
	sort(nums.begin(), nums.end(), [](int a, int b) {
		return a > b;
		});
	vector<int>res;
	int ans = 0;
	int target = accumulate(nums.begin(), nums.end(), 0) / 2;
	for (int i = 0; i < nums.size(); i++) {
		ans += nums[i];
		res.push_back(nums[i]);
		if (ans > target) {
			break;
		}
	}
	return res;
}


vector<string> Solution::stringMatching(vector<string>& words) {
	vector<string>res;
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words.size(); j++) {
			if (i != j) {
				if (words[j].find(words[i]) != string::npos) {
					res.push_back(words[i]);
					break;
				}
			}
		}
	}
	return res;
}


int Solution::minStartValue(vector<int>& nums){
	int min_value = numeric_limits<int>::max();
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		ans += nums[i];
		min_value = min(ans, min_value);
	}
	if (min_value > 0) {
		return 1;
	}
	return -min_value + 1;
}

vector<bool> Solution::kidsWithCandies(vector<int>& candies, int extraCandies) {
	int max_value = numeric_limits<int>::min();
	for (int i = 0; i < candies.size(); i++) {
		max_value = max(max_value, candies[i]);
	}
	vector<bool>res;
	for (auto num : candies) {
		if (num + extraCandies >= max_value) {
			res.push_back(true);
		}
		else {
			res.push_back(false);
		}
	}
	return res;
}


bool Solution::kLengthApart(vector<int>& nums, int k){
	int min_distance = numeric_limits<int>::max();
	vector<int>index;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			index.push_back(i);
		}
	}
	for (int i = 1; i < index.size(); i++) {
		min_distance = min(min_distance, index[i] - index[i - 1]);
	}
	if (min_distance >= k) {
		return true;
	}
	return false;
}


int Solution::busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime){
	int res = 0;
	for (int i = 0; i < startTime.size(); i++) {
		if (queryTime >= startTime[i] && queryTime <= endTime[i++]) {
			res++;
		}
	}
	return res;
}

bool Solution::canBeEqual(vector<int>& target, vector<int>& arr) {
	vector<int> cnt1(1001, 0);
	vector<int> cnt2(1001, 0);
	for (auto num : target) {
		cnt1[num]++;
	}
	for (auto num : arr) {
		cnt2[num]++;
	}
	for (int i = 1; i < cnt1.size()+1; i++) {
		if (cnt1[i] != cnt2[i]) {
			cout << cnt1[i] << endl;
			cout << cnt2[i] << endl;
			return false;
		}
	}
	return true;
}

int Solution::maxProduct(vector<int>& nums) {
	int first = numeric_limits<int>::min();
	int second = numeric_limits<int>::min();
	for (int i = 0; i < nums.size(); i++) {
		int tmp = first;
		if (first < nums[i]) {
			first = nums[i];
			second = max(tmp, second);
		}
		else {
			second = max(second, nums[i]);
		}
	}
	return (second - 1) * (first - 1);
}


vector<int> Solution::shuffle(vector<int>& nums, int n) {
	/*auto swap = [](int& a, int& b) {
		if (a != b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
	};*/
	vector<int>res;
	for (int i = 0; i < n; i = i + 2) {
		if (i % 2 == 0) {
			res.push_back(nums[i]);
			res.push_back(nums[i + n]);
		}
	}
	return res;
}


vector<int> finalPrices(vector<int>& prices){
	vector<int>res;
	for (int i = 0; i < prices.size()-1; i++) {
		bool flag = true;
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[j] <= prices[i]) {
				res.push_back(prices[i] - prices[j]);
				flag = false;
				break;
			}
		}
		if (flag) {
			res.push_back(prices[i]);
		}
	}
	return res;
}


vector<int> Solution::runningSum(vector<int>& nums){
	int ans = 0;
	vector<int>res;
	for (auto num : nums) {
		ans += num;
		res.push_back(ans);
	}
	return res;
	/*优化写法
	int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
	*/
}


double average(vector<int>& salary){
	int max_value = numeric_limits<int>::min();
	int min_value = numeric_limits<int>::max();
	int total = accumulate(salary.begin(), salary.end(), 0);
	for (auto num : salary) {
		max_value = max(max_value, num);
		min_value = min(min_value, num);
	}
	return (double)(total - max_value - min_value) / (salary.size() - 2);
}

bool canMakeArithmeticProgression(vector<int>& arr) {
	/*int k = abs(arr[0] - arr[1]);
	for (int i = 1; i < arr.size(); i++) {
		if (abs(arr[i] - arr[0]) % k != 0) {
			return false;
		}
	}
	return true;*/
	sort(arr.begin(), arr.end());
	int k = arr[1] - arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] != arr[0] + i * k) {
			return false;
		}
	}
	return true;
}


int numIdenticalPairs(vector<int>& nums){
	vector<int> vec(100, 0);
	for (auto num : nums) {
		vec[num - 1]++;
	}
	int res = 0;
	for (int i = 0; i < 100; i++) {
		res += (vec[i] * (vec[i] - 1)) / 2;
	}
	return res;
}

string restoreString(string s, vector<int>& indices) {
	string res = s;
	for (int i = 0; i < indices.size(); i++) {
		res[indices[i]] = s[i];
	}
	return res;
}


int Solution::countGoodTriplets(vector<int>& arr, int a, int b, int c){
	int res = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			for (int k = j + 1; k < arr.size(); k++) {
				if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
					res++;
				}
			}
		}
	}
	return res;
}


int Solution::findKthPositive(vector<int>& arr, int k){
	vector<int> vec(2000,0);
	int n = arr.size();
	int res = arr[n - 1] - n;
	for (auto a : arr) {
		vec[a - 1]++;
	}
	if (res <= k) {
		for (int i = 0; i < vec.size(); i++) {
			if (k == 0) {
				return i + 1;
			}
			if (vec[i] == 0) {
				k--;
			}
		}
	}
	return 2000;

}
