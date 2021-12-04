/**
 * @file Kruskal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 *   1. 将边从小到大排序
 *   2. 枚举每一条边a , b 权重c     
 *       if  a , b 不连通:
 *           将这条边加入集合S中
 * 
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std ;

const int N = 20010;

int n , m ;
int p[N];

struct Edge
{
    int a , b , w ;

    // 重载比较运算符
    bool operator< (const Edge &W) const{
        return w < W.w;
    }
}egde[N];

// 并查集 找到祖宗节点
int find(int x){
    if(p[x] != x) find(p[x]);
    return p[x];
}


int main(int argc, char const *argv[])
{
    int res = 0 , cnt = 0 ;
    cin >> n >> m;
    for(int i =  0 ; i < m ; i++){
        int a , b , w ;
        cin >> a >> b >> w;
        egde[i] = {a,b,w};
    }
    
    sort(egde , egde + m);

    for(int i = 1 ;  i <= n ; i++) p[i] = i ;

    for(int i = 0 ; i < m ; i++){
        int a = egde[i].a , b = egde[i].b , w = egde[i].w;
        a = find(a), b = find(b);
        if( a != b){
            p[a] = b ;
            res  += w ;
            cnt ++ ;
        }
    }

    if(cnt < n - 1 ) puts("impossible");
    else             cout<<res<<endl;

    return 0;
}

