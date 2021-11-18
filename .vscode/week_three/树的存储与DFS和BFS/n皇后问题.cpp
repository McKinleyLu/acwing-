/**
 * @file n皇后问题.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
using namespace std;
const int N = 10;
char path[N][N];
bool col[N],dg[2*N],udg[2*N];
// b = y  + x   b = y - x + 
// u 代表行   i代表列
int n ;
void dfs(int u ){
     if(u == n)  {
        for(int i = 0 ; i < n ; ++i) puts(path[i]);
        puts(" ");
        return;
     }

     for(int i = 0 ;  i < n ; i++){
        if(!col[i] && !dg[u+i] && !udg[n - u + i]){
            path[u][i] = 'Q';
            col[i] = dg[u+i] = udg[n - u + i] = true ;
            dfs(u + 1);
            path[u][i] = '.';
            col[i] = dg[u+i] = udg[n - u + i] = false ;
        }
     }
}



int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j)
            path[i][j] = '.';
    }
    dfs(0);
    return 0 ;
}