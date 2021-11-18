/**
 * @file 有向图拓扑排序.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-14
 * @copyright Copyright (c) 2021
 * 
 */
/*
给定一个n个点m条边的有向图，图中可能存在重边和自环。
请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出-1。
若一个由图中所有点构成的序列A满足：对于图中的每条边(x, y)，x在A中都出现在y之前，则称A是该图的一个拓扑序列。

输入格式
第一行包含两个整数n和m
接下来m行，每行包含两个整数x和y，表示点x和点y之间存在一条有向边(x, y)。

输出格式
共一行，如果存在拓扑序列，则输出拓扑序列。否则输出-1。

数据范围
1≤n,m≤10^5

输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3
*/
/*
有环就没有拓扑序了，一个有向无环图，一定存在一个拓扑序列
度:  入度  出度
如何求拓扑排序： 每次选一个入度为0的点输出，它指向的点入度减一
具体实现：
将入读为一的点加入队列，然后出队，它指向的所有点的入度减一，之后再看这些点的入度是否为0，若为0就加入到队列中
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std ;
const int N = 1e5+10;
int idx = 0 ;
int d[N],h[N],en[N],ne[N];
bool used[N];   // 判断是否所有点都进入过队列，如果存在未进入队列的点，则不存在拓扑序
int n , m ;
void add_node(int x ,int y){
    en[idx] = y , ne[idx] = h[x] , h[x] = idx++;
}
int main(){
    cin >> n >> m;
    memset(d,0,sizeof d);
    memset(h,-1,sizeof h);
    memset(used,true,sizeof used);
    for(int i = 1 , x, y ; i <= n ; ++i){
        cin >> x >> y ;
        d[y]++;
        add_node(x,y);
    }
    queue<int> q ;
    queue<int> save_queue;
    // 找到入度为0的点
    for(int i = 1 ; i <= n ; ++i){
        if(!d[i])   q.push(i),used[i] = false;
    }
    //开始输出拓扑队列
    while(!q.empty()){
        int m = q.front();
        q.pop(),save_queue.push(m);
        for(int i = h[m] ; i != -1 ; i = ne[i]){
            int j =  en[i];
            d[j]--;
            if(d[j] == 0)  {q.push(j),used[j] = false;}
        }
    }
    for(int i = 1 ; i<= n ; ++i) {
        if(used[i]) {cout<<-1<<endl;return 0;}
    }

    while(!save_queue.empty()){
         cout<<save_queue.front()<<" ";
         save_queue.pop();
     }
}