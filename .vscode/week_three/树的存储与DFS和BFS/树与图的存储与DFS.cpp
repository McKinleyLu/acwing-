/**
 * @file 树与图的存储.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
//   树与图的存储
//   由于树是特殊的图，因此只关注图的存储

/*
 * 有向图的存储
 * - 临界矩阵
 * - 邻接表: n个单链表     O(n + m)的遍历消耗
*/ 
// acwing 树的重心
/*
给定一颗树，树中包含n个结点（编号1~n）和n-1条无向边。
请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数n，表示树的结点数。
接下来n-1行，每行包含两个整数a和b，表示点a和点b之间存在一条边。

输出格式
输出一个整数m，表示重心的所有的子树中最大的子树的结点数目。

数据范围
1≤n≤10^5

输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6

输出样例：
4
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std ;
const int num = 20 ;    //树最多有的节点数
int n ;
int h[num],en[num],ne[num],idx = 0;
bool used[num];
int ans = 1e5;
void add_node(int x ,int y){
     en[idx] = y , ne[idx] = h[x],h[x] = idx++;
}
// 可以利用dfs求出一个子树的深度
int dfs(int u ){
    used[u] = true;
    int sum  = 1 , s =  0 , res = 0 ;
    for(int i = h[u] ; i != -1 ; i = ne[i]){
        int j = en[i];
        if(!used[j]) {
            s = dfs(j);
            res = max(res,s);
            sum += s ; 
        }  
    }
    ans = min(ans,max(res,n - sum));
    return sum ;
}

int main(){
    cin >> n ;
    memset(h , -1 , sizeof h);
    memset(used,false,sizeof used);
    for(int i = 1 , x , y ; i <= n - 1 ; ++i){
        // 根据题意是无向图
        cin >> x  >> y ;
        add_node(x,y);
        add_node(y,x);
    }    
    dfs(1);
    cout<<ans<<endl;
}



/**
// 树的深度优先遍历模板
void dfs(int u){
     used[u] = true;
     cout<<u<<" ";
     for(int i = h[u] ; i != -1 ; i = ne[i]){
         if(!used[i]){
            int j = en[i];
            if(!used[j]) dfs(j);
         }
     }
}
 */