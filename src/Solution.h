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
};