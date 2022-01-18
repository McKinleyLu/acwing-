#include <iostream>
#include <algorithm>
using namespace std;
const int N  = 1e3+10;
const int V  = 1e3+10;
int w[N], value[N];
int f[N][V];
//没有优化的完全背包
void pakageComplete(int n , int m){
     for(int i = 1 ; i <= n ; ++i){
         for(int j = 0 ; j <= m ; j++){
             for(int k = 0 ; k*w[i] <= j ; k++){
                f[i][j] = max(f[i-1][j],f[i][j - k*w[i]] + value[i]*k);
             }
         }
     }
     cout<<f[n][m]<<endl;
}

//优化的完全背包
void pakageCompleteSuper(int n , int m){
     for(int i = 1 ; i <= n ; ++i){
         for(int j = 0 ; j <= m ; j++){
                f[i][j] = f[i-1][j];   //理解这句话为什么放在if前面而不是if内部
                if(j >= w[i]){
                    f[i][j] = max(f[i][j],f[i][j - w[i]] + value[i]);
                }
             }
     }
     cout<<f[n][m]<<endl;
}
int main(int argc, char const *argv[])
{
    int n , m ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; ++i){
        cin >> w[i] >> value[i];
    }
    pakageCompleteSuper(n,m);
    return 0;
}
