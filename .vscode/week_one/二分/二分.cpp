/**
 * @file 二分.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 *  整数二分
 *  有单调性一定可以二分   
 *  给定区间，定义某种性质，左区间不满足性质，右边区间满足
 *  由于是整数二分，所以两个区间边界不重合
 * 
 * 
 *    如何二分出红色边界点(满足红色性质)
 *      1. mid =  l + r + 1 >> 1;
 *      2. check(mid) == true   则边界一定在[ mid , r ] ( l = mid)
 *                    == false  则         [l , mid-1] (r = mid - 1)
 *      
 *   
 *    如何二分出绿色边界点(满足绿色性质)
 *    1. mid =  l + r >> 1
 *    2. chech(mid) == true     则边界一定在 [l,mid]    (r = mid)
 *                  == false                [mid+1,r]  (l = mid + 1)
 * 
 *    1.首先写出check函数  
 *      如果当true时  -> l = mid   mid = l + r + 1 >> 1
 *                      r = mid   mid = l + r >> 1
 *      
 *    为何要加1：
 *      当 l =  r - 1 , mid = l + r >> 1 ,由于整数下取整，则 mid  = l
 *      若为true , 则 l = mid ,其实就是l还是等于原来的l，陷入死循环
 * 
 * 
 *   
 * 
 */

/*
题目描述

给定一个按照升序排列的长度为n的整数数组，以及 q 个查询。
对于每个查询，返回一个元素k的起始位置和终止位置（位置从0开始计数）。
如果数组中不存在该元素，则返回“-1 -1”。
输入格式
第一行包含整数n和q，表示数组长度和询问个数。
第二行包含n个整数（均在1~10000范围内），表示完整数组。
接下来q行，每行包含一个整数k，表示一个询问元素。
输出格式
共q行，每行包含两个整数，表示所求元素的起始位置和终止位置。
如果数组中不存在该元素，则返回“-1 -1”。

数据范围
1≤n≤100000

1≤q≤10000

1≤k≤10000

样例
输入样例：
6 3
1 2 2 3 3 4
3
4
5
输出样例：
3 4
5 5
-1 -1
*/
#include<iostream>
using namespace std;
const int N = 1e5 + 10 ;
int a[N];
int n ,q , k;
bool check(int mid, int x){
    if(a[mid] >= x )  return true;
    return false ;
}
int main(){
    cin >> n >> q ;
    for(int i = 0 ; i < n ; ++i)  {cin >> a[i];}
    while(q--){
        int x , l = 0 , r = n - 1 ;
        cin >> x ;
        while(l < r){
            int mid = l + r + 1 >> 1 ;
            if(check(mid,x)) r = mid ;
            else             l = mid + 1 ;
        } 
        if(a[l] != x)  {cout<<"-1,-1"<<endl;}
        cout<<l<<","<<l+1<<endl;
    }
    return 0 ;
}