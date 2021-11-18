/**
 * @file 旋转数组.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

输入一个升序的数组的一个旋转，输出旋转数组的最小元素。

例如数组 {3,4,5,1,2} 为 {1,2,3,4,5} 的一个旋转，该数组的最小值为 1。

数组可能包含重复项。

注意：数组内所含元素非负，若数组大小为 0，请返回 −1。

样例
输入：nums = [2, 2, 2, 0, 1]

输出：0
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size()-1  ;
        if(n < 0) return -1;
        // 去重
        while(nums[n] == nums[0] && n > 0) n--;
        //如果去重后，第二个有序序列空了，则第一个序列的第一个值就是最小值
        if(nums[n] >= nums[0])  return nums[0];
        // 否则可以进行二分
        int l  = 0 , r = n ;
        while(l < r){
            int mid = l + r >> 1 ;
            if(nums[mid] < nums[0]) r = mid ;
            else                    l = mid + 1 ;
        }
        return nums[l];
    }
}