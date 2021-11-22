/**
 * @file Flord.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
 *     d[i,j]  基于动态规划
 * 
 *         for i in range n
 *             for j in range n
 *                for k in range n
 *                  d[i,j] = min(d[i,j] , d[i,k] + d[k ,j])
 *      
 */
/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，边权可能为负数。
再给定k个询问，每个询问包含两个整数x和y，表示查询从点x到点y的最短距离，
如果路径不存在，则输出“impossible”。数据保证图中不存在负权回路。

输入格式：
第一行包含三个整数n，m，k。接下来m行，每行包含三个整数x，y，z，表示存在一条从点x到点y的有向边，边长为z。接下来k行，每行包含两个整数x，y，表示询问点x到点y的最短距离。

输出格式：
共k行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出“impossible”。

输入样例
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3

输出样例
impossible
1

数据范围：
1 ≤ n ≤ 200 
1 ≤ k ≤ n^2
1 ≤ m ≤ 20000
0 ≤ ∣ e ∣ ≤ 10000
e 是边长
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std ;
const int N =  210 ;
const int M = 20000+ 10 ;
const int INF = 0x3f3f3f3f;
int n , m, q ;
int dist[210][210];

void floyd(){
    for(int k = 1 ; k < n ; ++k)
       for(int i = 1 ; i <= n ; ++i)
           for(int j = 1 ; j <= n ; ++j)
              dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
}


int main(int argc, char const *argv[])
{
    //init 
    cin >> n >> m >> q ;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j<+ n ; ++j){
            if(i ==j)  {dist[i][j] = 0 ; continue;}
            dist[i][j] = INF;
        }
    }

    for(int i = 1 , x , y ,z ; i <= m ; ++i){
        cin >> x >> y >> z ;
        dist[x][y] = z ;
    }

    floyd();
    
    while(q--){
        int x ,y ;
        cin >> x >> y ;
        if(dist[x][y] > INF / 2)  {cout<<"impossible"<<endl; continue;}
        cout<<dist[x][y]<<endl;
    }


    return 0;
}
