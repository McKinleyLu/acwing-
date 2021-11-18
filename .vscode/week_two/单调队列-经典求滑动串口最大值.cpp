/**
 * @file 单调队列(经典求滑动串口最大值).cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/**
 * 问题描述：
给定一个大小为n ≤ 1 0 6 n≤10^6n≤10 
6
 的数组。

有一个大小为k的滑动窗口，它从数组的最左边移动到最右边。

你只能在窗口中看到k kk个数字。

每次滑动窗口向右移动一个位置。

以下是一个例子：

该数组为[1 3 -1 -3 5 3 6 7]，k为3。

窗口位置	最小值	最大值
[1 3 -1] -3 5 3 6 7	-1	3
1 [3 -1 -3] 5 3 6 7	-3	3
1 3 [-1 -3 5] 3 6 7	-3	5
1 3 -1 [-3 5 3] 6 7	-3	5
1 3 -1 -3 [5 3 6] 7	3	6
1 3 -1 -3 5 [3 6 7]	3	7
输入格式：
输入包含两行。

第一行包含两个整数n和k，分别代表数组长度和滑动窗口的长度。

第二行有n个整数，代表数组的具体数值。

同行数据之间用空格隔开。

输出格式：
输出包含两个。

第一行输出，从左至右，每个位置滑动窗口中的最小值。

第二行输出，从左至右，每个位置滑动窗口中的最大值。

数据范围：
1 ≤ n , k ≤ 100000 

输入样例：
8 3
1 3 -1 -3 5 3 6 7
输出样例：
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/

/* 使用单调栈 
   我们可以发现，如果是 [1 3 -1]  3 6 去除比当前加入队列点大的元素去掉
   通过画图可知最后的队列是一个单调递增序列 

   对于队列，先进先出，先进入的元素变成队尾元素，后进的元素变成对头元素
*/
#include<iostream>
#include<deque>
const int N = 1e5+10;
int a[N];
using namespace std;
int main(){
    deque<int> q ;
    int  n , k ;
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; ++i) {cin >>a[i];}
    for(int i = 1 ; i <= n ; ++i){
         if(!q.empty() && q.back() <= i - k ) q.pop_back();
         while(!q.empty() && a[q.front()] >= a[i]) q.pop_front();
         q.push_front(i);
         if(i >= k) cout<<a[q.back()]<<" "; 
    }
    cout<<endl;
    q.clear();
    for(int i = 1 ; i <= n ; ++i){
        if(!q.empty() && q.back() < i - k ) q.pop_back();
        while(!q.empty() && a[q.front()] <= a[i]) q.pop_front();
        q.push_front(i);
        if(i >= k)  cout <<a[q.back()]<<" ";
    }



    return 0 ;
}

