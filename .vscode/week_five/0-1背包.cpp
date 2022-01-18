#include <iostream>
#include <algorithm>
using namespace std;
// 0-1 背包， 每个物品之多仅用一次
// 完全背包   每个物品无限个
// 多重背包   每个物品个数不一样
// 分组背包   物品分组。每一组只能选一个
const int N  =  1e3 + 10 ;
const int V  =  1e3 + 10 ;
int n , v ;
int w[N];
int value[N];
int f[V];
void pakage0_1(){
    // 0-1 背包， 每个物品之多仅用一次
    cin >> n  >> v ;
    for(int i = 1 ; i <= n ; ++i)  cin >> w[i] >> value[i];
    // init
    for(int i = 0 ; i <= v ; ++i)  f[i] = 0;
    //work
    for(int i = 1 ; i <= n ; ++i){
        for(int j = v; j >= w[i] ; --j){
            f[j] = max(f[j],f[j - w[i] ] + value[i]);
        }
    }
    cout<<f[v]<<endl;
}


int main(int argc, char const *argv[])
{
    //0-1背包
    cout<<"0-1背包： ";
    pakage0_1();

    return 0;
}
 