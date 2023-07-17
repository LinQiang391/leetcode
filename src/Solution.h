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