/**
 * @file 多重背包I.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 *   滑动窗口最大值
 *  
 *   f[i][j] = max(f[i-1][j - w[i]*k] + value[i]*k)   k∈s
 */
#include <iostream>
using namespace std;
const int N = 25000;
const int V = 25000;
int f[N][V];
int sf[N];
int w[N],value[N],s[N];
// 暴力法  O(n^3)
void mulityPakage(int n , int m){
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j <= m ; ++j){
            f[i][j] = f[i - 1][j];
            for(int k = 0 ; k*w[i] <= j && k <= s[i] ; ++k){
               f[i][j] = max(f[i][j],f[i-1][j - w[i]*k] + value[i]*k);
            }
        }
    }
    cout << f[n][m] <<endl;
}


int main(int argc, char const *argv[])
{
    int n, m ;
    int cnt = 0;
    cin >> n >> m ;
    for(int i = 1 ;i <= n ; ++i){
        cin >> w[i] >> value[i] >> s[i];
    }
    mulityPakage(n , m);
    return 0;
}
