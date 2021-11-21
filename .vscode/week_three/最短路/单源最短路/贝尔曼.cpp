/**
 * @file 贝尔曼.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 *    迪杰斯特拉不能处理负权边
 *     注意： 负权回路如果存在，则不能求最短路 
 *       
 *  可以处理有负权边的算法
 *  迭代k次，1号点，经过不超过k条边的到所有节点的最短路距离, 因此，如果循环到第n次时，仍然有dist更新，则证明有回路(即那个顶点有至少n个边，必有负环)
 *  迭代n次,每一次循环遍历边,
 *     for  i in range n :
 *          for all edge ->  a ,b w
 *               dist[b] = min(dist[b] , dist[a] + w) 
 *   松弛操作 ，循环完毕以后， 所有边，一定满足 dist[b] <= dist[a] + w(三角不能式)
 */

/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。
注意：图中可能存在负权回路 。

输入格式
第一行包含三个整数 n,m,k。
接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。

如果不存在满足条件的路径，则输出 impossible。

数据范围
1≤n,k≤500,
1≤m≤10000,
任意边长的绝对值不超过 10000。

输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510 , M = 10010;

int n, m , k;

struct  Edge
{
    int a , b , w ;
}edge[M];

int dist[N],backup[N];

int bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0 ;

    for(int i =  0 ; i < k ; ++i){
        memcpy(backup , dist , sizeof dist);
        for(int j = 0 ; j < m ; ++j){
            int a = edge[j].a , b = edge[j].b , w = edge[j].w;
            dist[b] = min(dist[b] , backup[a] + w) ;
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2)  return -9999999 ;
    return dist[n];
}


int main(int argc, char const *argv[])
{
    cin >> n >> m >> k;
    for(int i  = 0 ; i < m ; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;     
    }
    int res = bellman_ford();
    if (res == -9999999) puts("impossible");
    else cout << res;
    return 0;
}
