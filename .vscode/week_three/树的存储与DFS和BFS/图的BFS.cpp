/**
 * @file 图的BFS.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*题目描述
给定一个n个点m条边的有向图，图中可能存在重边和自环。
所有边的长度都是1，点的编号为1~n。
请你求出1号点到n号点的最短距离，如果从1号点无法走到n号点，输出-1。

输入格式
第一行包含两个整数n和m。
接下来m行，每行包含两个整数a和b，表示存在一条从a走到b的长度为1的边。

输出格式
输出一个整数，表示1号点到n号点的最短距离。

数据范围
1≤n,m≤10^5

样例
输入样例：
4 5
1 2
2 3
3 4
1 3
1 4
输出样例：
1
*/
// 第一次发现这个点的距离，就是最短路径
#include<iostream>
#include<queue>
#include<cstring>
using namespace std ;
const int N = 1e5+10;
int  d[N];
int n , m ;

int en[N],ne[N],h[N],idx = 0 ;
void add_node(int x , int y){
    en[idx] = y , ne[idx] = h[x] , h[x] = idx++;
}
int  bfs(){
     queue<int> q ;
     d[1] = 0 ;
     q.push(1);
     while(!q.empty()){
         int s = q.front();
         q.pop();
         for(int i = h[s] ; i != -1 ; i = ne[i]){
              int j = en[i];
              if(d[j] == -1)  d[j]  = d[s] + 1 , q.push(j);
         }
     }
     return d[n];
}
int main(){
    memset(h , -1 , sizeof h);
    memset(d ,  -1 , sizeof d);
    cin >> n >> m ;
    for(int i = 1 ,a ,b  ; i <= m ; ++i){
        cin >> a >> b ;
        add_node(a,b);
    }
    cout<<bfs()<<endl;
    return 0 ;
}