/**
 * @file 数字三角形.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 * 线性DP  即递推方程有线性关系的(比如说一行一行的求)
 *          
 * 动态规划:
 *    - 状态标识
 *         - 集合   所有从起点走到(i,j)这个点的路径
 *         - 属性： Max
 *    - 状态计算(集合划分): 
 *      两类：  
 *            * 左上方   f[i-1,j-1] + a[i,j]
 *            * 右上方   f[i-1,j]   + a[i , j]
 *      f[i,j] = max(左上方，右上方)       
 *         
 */
#include <iostream>
#include <algorithm>
using namespace std;
#define INF  -1e9
const int N = 510;
int n ;
int f[N][N];
int a[N][N];
// 一般涉及 i-1 下标，从1开始，否则从零开始
// 时间复杂度:状态数量 * 转移的计算量
int main(int argc, char const *argv[])
{
    cin >> n ;
    // input
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= i ; ++j){
            cin >> a[i][j];
        }
    }
    // init
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <=i + 1; ++j){
            f[i][j] = INF ;
        }
    }

    //cal
    f[1][1] = a[1][1];
    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= i  ; ++j){
            f[i][j] = max(f[i-1][j-1] + a[i][j],f[i-1][j] + a[i][j]);
        }
    }
    int ans = INF ;
    for(int i = 1 ; i <= n ; ++i) {
        ans = max(ans , f[n][i]);
    }
    cout << ans<< endl;
    return 0;
}



