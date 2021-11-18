/**
 * @file 朴素迪杰斯特拉.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/**
 * 初始化  dist[1] = 0
 *         dist[i]  = MAX
 * 每次找当前最短路的点(贪心)
 *         for  i  in range( 1 - n)
 *              t 不在 s集合中，且距离起点路径最短
 *              s <- t
 *              用t更新到其他所有点的距离
 * 如果有自环:
 * 如果有重边:
 */   

/**
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。
接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式 
如果路径不存在，则输出 −1。

数据范围
1≤n≤500,
1≤m≤105,
图中涉及边长均不超过10000。

输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
int dist[N];
int g[N][N];
bool used[N];
int n , m ;
int dijkstra(){
    memset(dist, 0x3f , sizeof dist);
    memset(used,false,sizeof used);
    dist[1] = 0;
    for(int i = 1 ; i <= n ; ++i){
        //找出未访问过且距离原点最近的点
        //t 不在 s集合中，且距离起点路径最短
        int t = - 1;
        for(int j = 1 ; j <= n ; ++j){
            if(!used[j] && (t == -1 || dist[t] > dist[j])){
                t = j ;
            }
        }


        used[t] = true ;  // t这个点被加入到S集合

        for(int j = 1 ; j <= n ; ++j){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if(dist[n] == 0x3f3f3f3f)       return -1;
    else                            return dist[n];

}
int main(){
    cin >> n >> m;
    memset(g , 0x3f , sizeof g);
    for(int i = 1 , x ,y , w; i <= m ; ++i){
        cin >> x >> y >> w;
        g[x][y] = min(g[x][y],w) ;
    }
    cout<<dijkstra()<<endl;

    return 0 ;
}