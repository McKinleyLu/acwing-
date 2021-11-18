/**
 * @file 改变数组元素.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/* 给定一个空数组 V 和一个整数数组 a1,a2,…,an。

现在要对数组 V 进行 n 次操作。

第 i 次操作的具体流程如下：

从数组 V 尾部插入整数 0。
将位于数组 V 末尾的 ai 个元素都变为 1（已经是 1 的不予理会）。
注意：

ai 可能为 0，即不做任何改变。
ai 可能大于目前数组 V 所包含的元素个数，此时视为将数组内所有元素变为 1。
请你输出所有操作完成后的数组 V。

输入格式
第一行包含整数 T，表示共有 T 组测试数据。

每组数据第一行包含整数 n。

第二行包含 n 个整数 a1,a2,…,an。

输出格式
每组数据输出一行结果，表示所有操作完成后的数组 V，数组内元素之间用空格隔开。

数据范围
1≤T≤20000,
1≤n≤2×10^5,
0≤ai≤n,
保证一个测试点内所有 n 的和不超过 2×105。

输入样例：
3

6
0 3 0 0 1 3

10
0 0 0 1 0 5 0 0 0 2

3
0 0 0
输出样例：
1 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 0 0
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int v[N];
// 区间合并
void merge(vector<PII> &q , vector<PII> &re){
     int st = -N , eg = -N ;
     for(auto i : q){
         if(eg < i.first){
             if(st != -N) {re.push_back({st,eg});}
             st = i.first , eg = i.second;
         }
         else  eg = max(eg,i.second);
     }

     if(st != -N)  re.push_back({st,eg});
}


void merge( vector<PII> &segs , vector<PII> &re )
{
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for ( auto seg : segs )
    {
        if( ed < seg.first )
        {
            if( st != -2e9 ) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }

    if( st != -2e9 ) res.push_back({st, ed});
    segs = res;
    re = segs;

}




int main(){
    int n , t ;
    cin >> t ;
    while(t--){
        memset(v,0,sizeof v);
        vector<PII> q ;
        vector<PII> re ;
        cin >> n ;
      // 生成加一的区间
      for(int i =  0 , x ; i < n ; ++i){
          cin >> x ;
          if(x == 0)     continue;
          else if(i - x < 0 ) q.push_back({0,i});
          else                 q.push_back({i-x+1,i});
      }
      // 区间合并
      if(q.size() > 0) {sort(q.begin(),q.end());}
      if(q.size() > 0) {merge(q,re);}

      // 批量加1
      for(int i = 0 ; i < re.size() && re.size() > 0 ; ++i){
          for(int j = re[i].first ; j <= re[i].second; ++j)  v[j] = 1 ;
      }
      // 输出
      for(int i = 0 ; i < n ; ++i ){
          if(i == 0) cout << v[i];
          else       cout <<" "<<v[i];
      }
      cout<<endl;
    }
    return 0 ;
}