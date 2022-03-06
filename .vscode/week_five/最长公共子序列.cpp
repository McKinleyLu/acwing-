/**
 * @file 最长公共子序列.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 *    动态规划
 *       - 状态表示
 *             - 集合:所有在第一个序列前i个字母中出现，
 *                    且第二个序列前j个字母中出现的子序列
 *             - 属性: Max
 *       - 状态计算
 *               - 选不选 a[i]、b[j]  一共四个子集
 *               - 子集：f[i-1][j-1] , f[i-1][j]、f[i][j-1] 、f[i-1][j-1]+1
 *               - 注意：f[i-1][j]中公共子序列中不一定含b[j]，同理f[i][j-1]中不一定含a[i]
 *               - 由于子集f[i-1][j-1]被包含在f[i-1][j]以及f[i][j-1]中，因此计算时可以不予考虑
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e3+10;
int f[N][N];
int n , m;
char a[N],b[N];
int main(int argc, char const *argv[])
{
    cin >> n >> m ;
    scanf("%s\n%s",a+1,b+1);
    f[0][1] = f[1][0] = f[0][0] =  0;
    for(int i = 1 ; i <=n ; ++i){
        for(int j = 1 ;  j <= m ; ++j){
            if(a[i] == b[j]) {f[i][j] = f[i-1][j-1] + 1;}
            else{
                f[i][j] = max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
