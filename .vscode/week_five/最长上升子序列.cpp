/**
 * @file 最长上升子序列.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 * 
 * @copyright Copyright (c) 2022
 *    动态规划
 *       - 状态表示
 *         - 集合： 所有以第i个数结尾的上升子序列
 *         - 属性： Max
 *      状态计算：  if(a[i] > a[j])  f[i] = max(f[j] + 1)
 *           
 */



#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;
const int N = 1e4 + 10;
int f[N];
int a[N];
int n ;
int main(int argc, char const *argv[])
{
    int ans = 0  ;
    cin >> n ;
    memset(f,n+1,0);
    for(int i = 1; i <= n ; ++i)    {cin >> a[i] ;}
    for(int i = 1; i <= n ; ++i){
        for(int j = 0 ; j < i ; ++j){
            if(a[i] > a[j]){
                f[i] = max(f[i],f[j] + 1);
            }
        }
        if(f[i] == 0) {f[i] += 1;}
        ans = max(ans,f[i]);
    }
    cout << ans <<endl;
    return 0;
}




