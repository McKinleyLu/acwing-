/**
 * @file 计数类DP.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2022
 * 
 * 计数DP == 分情况讨论
 *  [a,b], 0~9
 *  count(n,x)                    一到n中，x出现的次数
 *  count(b,x) - count(a-1,x)     求出[a,b]中x出现的次数  ==> 类似于前缀和的相关运算
 * 
 * 
 *  分情况考虑
 *  假设一共7位,分别求1在哪一位上出现的次数，abcdefg
 *  
 *  求1在第四位出现的次数
 *   1 <= xxx1yyy <= abcdefg
 *  (1) xxx = 000 ~ abc , 1 , yyy = 000 ~ 999 , 一共abc *1000种情况
 *  (2) xxx = abc
 *      (2.1) d < 1 , abc1yyy > abc0defg   0种情况 
 *      (2.2) d = 1 , abc1yyy , yyy = 000 - efg , efg +1 中情况
 *      (2.3) d > 1 , 此时yyy = 000 ~ 999 ，一共1000种情况
 *       
 * 
 */



#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    
    return 0;
}
