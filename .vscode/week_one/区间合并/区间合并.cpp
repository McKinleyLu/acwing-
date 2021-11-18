/**
 * @file 区间合并.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*给定 n 个区间 [li,ri]，要求合并所有有交集的区间。

注意如果在端点处相交，也算有交集。

输出合并完成后的区间个数。


例如：[1,3]和[2,6]可以合并为一个区间[1,6]。
输入格式
第一行包含整数n。

接下来n行，每行包含两个整数 l 和 r。

输出格式
共一行，包含一个整数，表示合并区间完成后的区间个数。

数据范围
1 ≤ n ≤ 100000,
−10^9 ≤ li ≤ ri ≤ 10^9
输入样例：
5
1 2
2 4
5 6
7 8
7 9
输出样例：
3*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
typedef pair<int,int> PII;
const int N  =  1e5 + 10 ;
vector<PII> eg , ans;

int merge(vector<PII> &eg){
    if(eg.size() == 0 )  return 0 ;
    if(eg.size() == 1 )  return 1 ;
    int st = -N , ed = -N ;
    for(int i = 1 ; i < eg.size() ; ++i){
        if(ed < eg[i].first){
            if(eg[i].first != -N)  ans.push_back({st,ed});
            st = eg[i].first , ed = eg[i].second;
        }
        else   ed = max(ed,eg[i].second);
    }
    return ans.size();
}


int main(){
  int n ;
  cin >> n ;
  for(int i = 1,st,ed ; i <= n ; ++i){
      cin >> st >> ed ;
      eg.push_back({st,ed});
  }
  cout<<merge(eg)<<endl;
  return 0 ;
}
