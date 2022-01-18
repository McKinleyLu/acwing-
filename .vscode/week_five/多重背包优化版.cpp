/**
 * @file 多重背包优化版.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 *   // 优化法
 * 
 * 
 * f[i,j]        = max(f[i-1,j],f[i-1,j - v[i]] + value[i] , f[i-1,j - 2*v[i]] + 2*value[i] , ...,   f[i-1,j - s*v[i]] + value[i])
 * f[i,j - w[i]] = max(         f[i-1,j-w[i]],             , f[i-1,j - 2*v[i]] + value[i]   , ...,   f[i-1,j - s*v[i]] + (s-1)value[i] + f[i-1,j - (s+1)*v[i]] + (s+1)value[i])
 *  
 * 若S =  1023
 * 1 2 4 8 ... 2^k
 * 
 * 1+2 = 3    3+4 = 7
 * 因此可以使用这种方法求出0-2^k的所有数
 * 时间复杂度：O(NSlogS)
 *
 * 如果 S = 200 不是2的^k次方
 * 1 2 4 8 16 32 64 73
 * 1,2,4,8,16,32,64,可以凑出来0 - 127的任何一个数字
 * 
 * 
 *  S   =>  log S
 *  将 S 个物品进行拆分，然后进行0-1背包处理
 *  N * v * logS  
 * 
 * 
 * 
 * // 核心思想： 把多重背包的每一个物品，用过上述公式，分成多个物品，然后所有物品进行0-1背包装入
 *    
 */
 
 #include <iostream>
 #include <algorithm>
 using  namespace std;
 const int N = 25000 , M = 2010;
 int n , m ;
 int v[N] , w[N];
 int f[N];

 int main(int argc, char const *argv[])
 {
     cin >> n >> m;
     int cnt = 0 ;
     for(int i = 1 ; i <= n ; ++i){
         int a , b , s ;
         cin >> a >> b >> s;
         int k = 1 ;
         while(k <= s){
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s  -= k ;
            k *= 2 ; 
         }
         if(s > 0){
             cnt++;
             v[cnt] = a * s ;
             w[cnt] = b * s ;
         }
     }
      n = cnt ;

      for(int i = 1 ; i <= n ; ++i){
          for(int j = m ; j >= v[i] ; j--){
              f[j] = max(f[j],f[j - v[i]] + w[i]);
          }
      }
      cout << f[m] << endl;
     return 0;
 }
 