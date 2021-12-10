/**
 * @file 匈牙利算法.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 *   匈牙利算法，理论O(mn)，实际上是远小于这个值
 *   以最快时间，返回两两匹配个数(每一个点只能匹配一个另一个点的个数)
 *   
 *  
 *   
 * 
 * 
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std ;
const int N = 510 , M = 100010;
int n1 , n2 , m ;
int h[N],e[M],ne[M],idx;
int match[N];
bool st[N];

void add(int a ,int b){
    e[idx] = b , ne[idx] = h[a] , h[a] = idx++; 
}

bool find(int x){
    for(int i = h[x] ; i != -1 ; i = ne[i]){
        int j = e[i];
        if(!st[j]){   //之前没有考虑过
            st[j] = true ;
            if(match[j] == 0 || find(match[j])){ //没有匹配或者说虽然匹配了，但是另一个匹配的点可以找到下家
                match[j] = x ;
                return true;
            }
        }
    }
    return false ;
}


int main(int argc, char const *argv[])
{
    cin >> n1 >> n2 >> m;
    memset(h , -1 ,sizeof h);
    while(m--){
        int a ,b ;
        cin >> a >> b;
        add(a,b);
    }

    int res = 0 ;
    for(int i = 1; i <= n1 ; ++i){
        memset(st , false , sizeof st);
        if(find(i)) res++;
    }
    cout<<res<<endl;
    return 0;
}
