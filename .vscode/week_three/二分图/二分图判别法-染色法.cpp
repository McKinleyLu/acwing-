/**
 * @file 匈牙利算法.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/**
 *   二分图 
 *   
 *   染色法，判断是否是二分图
 *   
 *   性质：一个图是二分图，当且仅当可以被二染色(即图中不含有奇数环)
 *   奇数环： 一个环中有奇数个点 
 * 
 *   使用DFS
 *   for i in range(V):
 *      if i 未染色：
 *          dfs(i，1)   将i所在连通块全部染色，1为颜色
 * 
 * 
 * 
*/



#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std ;

const int N = 100010 , M = 20010;

int n ,m ;
int h[N],e[M],ne[M],idx = 0;
int color[N];



void add(int a ,int b){
    e[idx] = b , ne[idx] = h[a] , h[a] = idx++; 
}

bool dfs(int u , int c){
    color[u] = c ;
    for(int i = h[u] ; i != -1 ; i = ne[i]){
        int j = e[i];
        if(!color[j]){  //当前的点没有染过颜色
            if(!dfs(j,3 - c))  return false;  
        }
        else{
            if(color[j] == c) return false ;
        }
    }
    return true ;
}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--){
        int a , b ;
        cin >> a >> b ;
        add(a,b),add(b,a);
    }

    bool flag = true;
    for(int i = 1 ; i <= n ; i++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag = false ;
                break;
            }
        }
    }

    if(flag) {puts("Yes");}
    else{
        puts("No");
    }

    return 0;
}
