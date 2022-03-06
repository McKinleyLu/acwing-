/**
 * @file 石子合并.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 *  动态规划(区间DP)
 *       - 状态表示
 *            -  集合
 *                所有将第i所有合并方式
 *            -  属性:Min
 *       - 状态计算(以最后一次分界线位置分类)
 *            - 集合
 *              左边一个  右边n-1个
 *              左边两个  右边n-2个
 *              左边三个  右边n-3个
 *              ..................
 *            f[i,j] = min( min(f[i,k]) + min(f[k,j]) + s[j] - s[i-1] )
 *                   (  k ∈ (i,j-1)  至少有一堆的数量为1)
 * 时间复杂度： 两维状态O(n^2) * k的取值O(n)
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 310;
int n ;
int s[N];
int f[N][N];
int main(int argc, char const *argv[])
{
    cin >> n ;
    for(int i = 1 ; i <= n; ++i) cin >>s[i];
    for(int i = 1 ; i <= n; ++i) s[i] += s[i-1];
    for(int len = 2 ; len <= n ; len ++){     //枚举区间长度
        for(int i = 1 ; i + len -1 <= n ; i++){  //枚举起点    [i , i + len - 1] 维持一个长度为len的动态区间
            int l = i , r = i + len -1;
            //init
            f[l][r] = 1e8;
            for(int k = l ;k < r  ;k++){       //枚举分界点k
                f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]+s[r] - s[l-1]);
            }
        }
    }
    cout << f[1][n] <<endl;
    return 0;
}
