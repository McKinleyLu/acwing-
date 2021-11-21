/**
 * @file spfa算法.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 *    贝尔曼算法，并非每一次dist都变小，spfa是从这里对其优化
 *        (dist[b] = min(dist[b] , backup[a] + w))
 *          因为backup变小了，因此dist[b]才变小
 *    刚开始，向队列中放入起始节点。之后取出队头元素，判断其出边是否需要更新，更新后，把更新的点放入队列。
 *    因为更新的点更新了，该更新的点的后继点才有可能更新。
 *     
 * 
 */

/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 impossible。
数据保证不存在负权回路。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。
如果路径不存在，则输出 impossible。

数据范围
1≤n,m≤105,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3
1 2 5
2 3 -3
1 3 4
输出样例：
2*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std ;

const int N = 1e5+10;
int n , m ;
int h[N] , en[N],ne[N] , w[N];
int dist[N];
bool used[N];
int idx = 0 ;
//稀疏图，邻接表存储
void add_node(int a , int b , int c){
    en[idx] = b , ne[idx] = h[a] , w[idx] = c , h[a] = idx++ ;
}

int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;

    queue<int> q ;
    q.push(1);
    used[1] = true;

    while(!q.empty()){
        int t = q.front();
        q.pop();

       used[t] = false ; // used 数组用来防止点重复加入队列之中
       for(int i = h[t] ; i != - 1 ; i = ne[i]){
           int j = en[i];
           if(dist[j] > dist[t] + w[i]){
               dist[j] = dist[t] + w[i];
               if(!used[j])  q.push(j), used[j]  = true ;
           }
       }
    }
    if(dist[n] > 0x3f3f3f /2)  return -999999;
    return dist[n];
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    memset(h , -1 , sizeof h);
    
    while(m --){

    int a , b , c  ;
    cin >> a >> b >> c ;
    add_node(a,b,c);
    }
    int res = spfa();
    if(res == -999999)  {puts("impossible"); return 0;}
    cout<<res<<endl;
    return 0;
}