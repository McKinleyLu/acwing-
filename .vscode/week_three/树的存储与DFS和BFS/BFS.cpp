/**
 * @file BFS.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
给定一个n*m的二维整数数组，用来表示一个迷宫，数组中只包含0或1，其中0表示可以走的路，1表示不可通过的墙壁。

最初，有一个人位于左上角(1, 1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角(n, m)处，至少需要移动多少次。

数据保证(1, 1)处和(n, m)处的数字为0，且一定至少存在一条通路。

输入格式

第一行包含两个整数n和m。

接下来n行，每行包含m个整数（0或1），表示完整的二维数组迷宫。

输出格式

输出一个整数，表示从左上角移动至右下角的最少移动次数。

数据范围

1≤n,m≤100

输入样例：

5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出样例：
8
*/
//   -1 0 
//   1  0
//   0 -1
//   0  1
#include<iostream>
#include<queue>
#include<cstring>
using namespace std ;
typedef pair<int,int> PII ;
const int N  = 1e2 + 10 ;
int maps[N][N] , d[N][N];
int n , m ; 
int dx[4]  = {-1,1,0,0} , dy[4] = {0,0,-1,1};
int bfs(){
    queue<PII> q ;
    d[0][0] = 0;
    q.push({0,0});
    while(!q.empty()){
       PII tmp =  q.front();
       q.pop();
       for(int i = 0 ; i < 4 ;++i){
           int tmpx = tmp.first + dx[i] , tmpy = tmp.second + dy[i];
           if(tmpx >= 0 && tmpx < n  && tmpy >= 0 && tmpy < m && d[tmpx][tmpy] == -1 && maps[tmpx][tmpy] == 0){
                    q.push({tmpx,tmpy});
                    d[tmpx][tmpy] =  d[tmp.first][tmp.second] + 1 ;
              
           }
       }

    }
    return d[n-1][m-1];

}
int main(){
    cin >> n >> m ;
    memset(d,-1,sizeof d);
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
             cin >> maps[i][j];
    cout<<bfs()<<endl;
    return 0 ;
}
