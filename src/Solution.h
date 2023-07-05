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
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score);
    int arrayPairSum(vector<int>& nums);
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c);
    int distributeCandies(vector<int>& candyType);
    int findLHS(vector<int>& nums);
};