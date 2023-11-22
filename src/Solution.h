/*****************************************************************//**
 * @file   Solution.h
 * @brief  leetcode刷题所有函数全部记录在该类中
 * 
 * @author johnny
 * @date   July 2023
 *********************************************************************/
#pragma once

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<unordered_set>
#include<numeric>
#include<list>
using namespace std;

int gcd(int a, int b);
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score);

    int arrayPairSum(vector<int>& nums);

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c);

    int distributeCandies(vector<int>& candyType);

    int findLHS(vector<int>& nums);

    int maxCount(int m, int n, vector<vector<int>>& ops);

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2);

    bool canPlaceFlowers(vector<int>& flowerbed, int n);

    int maximumProduct(vector<int>& nums);

    double findMaxAverage(vector<int>& nums, int k);

    vector<int> findErrorNums(vector<int>& nums);

    vector<vector<int>> imageSmoother(vector<vector<int>>& img);

    int findLengthOfLCIS(vector<int>& nums);

    int calPoints(vector<string>& operations);

    int findShortestSubArray(vector<int>& nums);

    int search(vector<int>& nums, int target);

    bool isOneBitCharacter(vector<int>& bits);

    int pivotIndex(vector<int>& nums);

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color);

    char nextGreatestLetter(vector<char>& letters, char target);

    int minCostClimbingStairs(vector<int>& cost);

    int dominantIndex(vector<int>& nums);

    string shortestCompletingWord(string licensePlate, vector<string>& words);

    bool isToeplitzMatrix(vector<vector<int>>& matrix);

    int uniqueMorseRepresentations(vector<string>& words);

    vector<int> numberOfLines(vector<int>& widths, string s);

    double largestTriangleArea(vector<vector<int>>& points);

    vector<int> shortestToChar(string s, char c);

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image);

    vector<vector<int>> transpose(vector<vector<int>>& matrix);

    int projectionArea(vector<vector<int>>& grid);

    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes);

    int surfaceArea(vector<vector<int>>& grid);

    bool isMonotonic(vector<int>& nums);

    vector<int> sortArrayByParity(vector<int>& nums);

    int smallestRangeI(vector<int>& nums, int k);

    bool hasGroupsSizeX(vector<int>& deck);

    vector<int> sortArrayByParityII(vector<int>& nums);

    int numUniqueEmails(vector<string>& emails);

    bool validMountainArray(vector<int>& arr);

    vector<int> diStringMatch(string s);

    int minDeletionSize(vector<string>& strs);

    bool isAlienSorted(vector<string>& words, string order);

    int repeatedNTimes(vector<int>& nums);

    int largestPerimeter(vector<int>& nums);

    vector<int> addToArrayForm(vector<int>& num, int k);

    int findJudge(int n, vector<vector<int>>& trust);

    int numRookCaptures(vector<vector<char>>& board);

    vector<string> commonChars(vector<string>& words);

    int largestSumAfterKNegations(vector<int>& nums, int k);

    bool canThreePartsEqualSum(vector<int>& arr);

    vector<bool> prefixesDivBy5(vector<int>& nums);

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter);

    bool isBoomerang(vector<vector<int>>& points);

    int lastStoneWeight(vector<int>& stones);

    int heightChecker(vector<int>& heights);

    void duplicateZeros(vector<int>& arr);

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2);

    int numEquivDominoPairs(vector<vector<int>>& dominoes);

    int countCharacters(vector<string>& words, string chars);

    int distanceBetweenBusStops(vector<int>& distance, int start, int destination);

    vector<vector<int>> minimumAbsDifference(vector<int>& arr);

    bool uniqueOccurrences(vector<int>& arr);

    int minCostToMoveChips(vector<int>& position);

    bool checkStraightLine(vector<vector<int>>& coordinates);

    int oddCells(int m, int n, vector<vector<int>>& indices);


    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k);

    int minTimeToVisitAllPoints(vector<vector<int>>& points);

    string tictactoe(vector<vector<int>>& moves);

    int findSpecialInteger(vector<int>& arr);

    int findNumbers(vector<int>& nums);

    vector<int> replaceElements(vector<int>& arr);

    vector<int> sumZero(int n);

    vector<int> decompressRLElist(vector<int>& nums);

    vector<int> arrayRankTransform(vector<int>& arr);

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k);

    bool checkIfExist(vector<int>& arr);
  
    int countNegatives(vector<vector<int>>& grid);


    vector<int> sortByBits(vector<int>& arr);

    vector<int> smallerNumbersThanCurrent(vector<int>& nums);

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d);

    vector<int> luckyNumbers(vector<vector<int>>& matrix);

    vector<int> createTargetArray(vector<int>& nums, vector<int>& index);

    int findLucky(vector<int>& arr);

    vector<int> minSubsequence(vector<int>& nums);

    vector<string> stringMatching(vector<string>& words);

    int minStartValue(vector<int>& nums);

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);

    bool kLengthApart(vector<int>& nums, int k);


    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime);

    bool canBeEqual(vector<int>& target, vector<int>& arr);

    int maxProduct(vector<int>& nums);

    vector<int> shuffle(vector<int>& nums, int n);

    vector<int> finalPrices(vector<int>& prices);

    vector<int> runningSum(vector<int>& nums);

    int numIdenticalPairs(vector<int>& nums);

    int countGoodTriplets(vector<int>& arr, int a, int b, int c);

    int findKthPositive(vector<int>& arr, int k);
};

/**
 * @brief 题目：705. 设计哈希集合
 * @url:https://leetcode.cn/problems/design-hashset/
 * .
 */
class MyHashSet {
public:
    int base = 997;
    vector<list<int>> vec= std::vector<std::list<int>>(base, std::list<int>());     //类的成员变量不能使用括号初始化方法，可以使用列表初始化或者在构造函数中使用括号初始化
    int hash(int key) {
        return key % base;
    }
    MyHashSet(){
    }

    void add(int key) {
        int index = hash(key);
        for (auto iter = vec[index].begin(); iter != vec[index].end(); iter++) {
            if (*iter == key) {
                return;
            }
        }
        vec[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);
        for (auto iter = vec[index].begin(); iter != vec[index].end(); iter++) {
            if (*iter == key) {
                vec[index].erase(iter);
                return;
            }
        }
    }

    bool contains(int key) {
        int index = hash(key);
        for (auto iter = vec[index].begin(); iter != vec[index].end(); iter++) {
            if (*iter == key) {
                return true;
            }
        }
        return false;
    }
};


struct myentry      //等价于c++数据结构pair<int,int> ,pair用于表示单个键值对
{
    int key;
    int val;
};

/**
 * @brief 题目：705. 设计哈希集合
 * @url:https://leetcode.cn/problems/design-hashmap/
 */
class MyHashMap {
public:
    int base = 997;
    vector<list<myentry>> vec = std::vector<std::list<myentry>>(base, std::list<myentry>());
    int hash(int key) {
        return key % base;
    }
    MyHashMap() {

    }

    void put(int key, int value) {
        int index = hash(key);
        for (auto iter = vec[index].begin(); iter != vec[index].end(); iter++) {
            if ((*iter).key==key) {
                (*iter).val = value;
                return;
            }
        }
        vec[index].push_back({ key,value });
    }

    int get(int key) {
        int index = hash(key);
        for (auto iter = vec[index].begin(); iter != vec[index].end(); iter++) {
            if ((*iter).key == key) {
                return (*iter).val;
            }
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        for (auto iter = vec[index].begin(); iter != vec[index].end(); iter++) {
            if ((*iter).key == key) {
                vec[index].erase(iter);
                return;
            }
        }
    }
};


