/**
 * @file 朴素版Prim.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 *   朴素Prim
 *   dist[i]  <- INF
 *   for i = 0 in range n
 *      t <- 找到集合外距离最近的距离
 *      用t来更新其他点到集合的距离
 *      s[t] = true 
 * 
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std ;
const int N = 510;
bool used[N];
int dist[N];
int g[N][N];
int n , m ;
int prim(){
   memset(dist , 0x3f , sizeof dist);
   memset(used , false , sizeof used);
   int res = 0 ;
   for(int i = 0 ; i < n ; i++){
       int t  = -1 ;
       for(int j = 1 ; j <- n ; ++j){
        if(!used[j] && (t == -1 || dist[t] > dist[j])) {t = j;}
       }
       
       if(i && t == INF)  return INF ;
       if(i) res += dist[t];

       for(int j = 1 ; j <= n ; ++j) {dist[j] = min(dist[j] , g[t][j]);}

       used[t] = true ;
   }
   return res ;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;

    memset(g, 0x3f , sizeof g);

    while(m--){
        int a , b , c ;
        cin >> a  >> b >> c ;
        // 处理重边
        g[a][b] = g[b][a] = min(g[a][b],c);
    }

    int t = prim();

    if(t == INF)  puts("impossible");
    else          cout<<t<<endl;

    return 0;
}
