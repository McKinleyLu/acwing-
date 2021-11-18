/**
 * @file 数组中数值和下标相等的元素.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*假设一个单调递增的数组里的每个元素都是整数并且是唯一的。

请编程实现一个函数找出数组中任意一个数值等于其下标的元素。

例如，在数组 [−3,−1,1,3,5] 中，数字 3 和它的下标相等。

样例
输入：[-3, -1, 1, 3, 5]

输出：3
注意:如果不存在，则返回-1
*/
class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1 ;
        int l = 0 ,  r = nums.size() - 1 ;
        while(l < r){
            int mid  = l + r >> 1;
            if(nums[mid] >= mid )  r = mid ;
            else                  l = mid + 1 ;
        }
        if(nums[l] != l)  return -1;
        else              return l ;
    } 
};