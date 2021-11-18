/**
 * @file BFS_DFS.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
// 回溯时一定要注意恢复现场
// 全排列
#include<iostream>
using namespace std ;
const int N = 10 ;
int n ;
bool used[N]; // 如果是true表示已经使用过
int path[N]; // 用来存状态，也可以使用位运算
void dfs(int u ){
     if(u == n ){
         for(int i = 0 ; i < n ; ++i){
           cout << path[i] << " ";
         }
         cout<<endl;
     }

     for(int i = 1 ; i <= n ; ++i){
         if(!used[i]){
             path[u] = i ;
             used[i] = true;
             dfs(u+1);
             used[i] = false;
         }
     }
}

int main(){
    cin >> n ;
    dfs(0);
    return 0 ;
}