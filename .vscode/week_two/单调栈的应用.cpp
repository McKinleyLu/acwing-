/**
 * @file 单调栈的应用.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出-1。
输入格式
第一行包含整数N，表示数列长度。
第二行包含N个整数，表示整数数列。
输出格式
共一行，包含N个整数，其中第i个数表示第i个数的左边第一个比它小的数，如果不存在则输出-1。
数据范围
1 ≤ N ≤105
1 ≤ 数列中元素 ≤10^9
输入样例：
5
3 4 2 7 5
输出样例：
-1 3 -1 2 2
*/
/*
 **  先考虑暴力做法  ->  发现某些性质  -> 找到合适的方法
 **  若 AX >= AY && X < Y 则 AX肯定不会加入到栈中，即删除逆序的点，使得变成单调的直线
 */
#include<iostream>
#include<stack>
using namespace std ;
const int N =  1e5+10;
int a[N];
int main(){
    int n ;
    stack<int> q ;
    cin >> n ;
    for(int i = 1 ,x ; i <= n ; ++i){
        cin >> x ;
        while(!q.empty() && q.top() >= x) q.pop();
        if(!q.empty())   cout<<q.top()<<" ";
        else             cout<<"-1"<<" ";

        q.push(x);  
    }
    return 0;
}