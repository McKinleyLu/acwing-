#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
// 如果是稀疏图，若n特别大，会爆炸
// 迪杰斯特拉找一个离原点最小的数计算量最大，是n^2
// 从一堆数找一个最小的数，堆是O(1),修改一个数是O(logn)
// 用对存储所有点到原点的距离
// 手写堆，保证堆仅仅只有n个元素
// 也可以使用优先队列，但是不允许修改一个数，
// 只能插入，从而创造了冗余

typedef pair<int ,int> PLL;
const int N = 1e5+10;
int n , m ;
int h[N] , en[N],ne[N] , w[N];
int dist[N];
bool used[N];
int idx = 0 ;
//稀疏图，邻接表存储
void add_node(int a , int b , int c){
    en[idx] = b , ne[idx] = h[a] , w[idx] = c , h[a] = idx++ ;
}

int dijkstra(){
     memset(dist , 0x3f , sizeof(dist));
     dist[1] = 0 ;

     priority_queue<PLL , vector<PLL> , greater<PLL>> heap;
     // 1号点，距离为0
     heap.push({0,1});
     while (heap.size()){
         auto top = heap.top();
         heap.pop();
         
        int ver = top.second , distance = top.first ;
        if (used[ver]) continue;
        for(int i = h[ver] ; i != - 1 ; i = ne[i]){
            int j = en[ver];
            if(dist[j] > distance + w[j] ){
                dist[j] = distance + w[j];
                heap.push({dist[j],j});
            } 
        }
     }
     
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    memset(h , -1 , sizeof h);
    
    while(m --){

    int a , b , c  ;
    cin >> a >> b >> c ;
    add_node(a,b,c);
    }

    cout<<dijkstra()<<endl;
    return 0;
}



