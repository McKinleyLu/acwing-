/**
 * @file 数字在排序数组中出现的次数.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
统计一个数字在排序数组中出现的次数。

例如输入排序数组 [1,2,3,3,3,3,4,5] 和数字 3，由于 3 在这个数组中出现了 4 次，因此输出 4。

样例
输入：[1, 2, 3, 3, 3, 3, 4, 5] ,  3

输出：4
*/
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        int n = nums.size() - 1,cnt = 1 ;
        if(n < 0) return 0;
        int l = 0 , r = n ;
        while(l < r){
            int mid  = l + r >> 1 ;
            if(nums[mid] >= k) r = mid;
            else               l = mid + 1 ;         
        }

        if(nums[l] != k)  return 0 ;
        while(1){
            if(nums[++l] == k && l <= n)    ++cnt;
            else                  break;  
        }
        return cnt;
    }
};