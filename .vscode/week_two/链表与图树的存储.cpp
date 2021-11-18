/**
 * @file 链表与图树的存储.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
// 数组模拟单链表c
#include<iostream>
using namespace std;
const int N = 1e5+10;
int head , e[N] , ne[N];
int idx = 0;
void init(){
    head = -1 ;
}
void insert_to_head(int value){
     e[idx] = value;
     ne[idx] = head;
     head = idx++;
}
// 插入到下标是pos点的后面   注意不是值是下标
void add(int pos , int value){
     e[idx] = value;
     ne[idx] = ne[pos];
     ne[pos] = idx++;
}
// 删除下标为pos后面的元素
void remove(int pos){
    ne[pos] = ne[ne[pos]];
}
int main(){
    init();
    insert_to_head(12);
}
