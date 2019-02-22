#include <iostream>
using namespace std;

// 原始算法
int countOnes1(unsigned int n)
{
    int ones = 0;
    while(n>0){
        ones += (n&1);
        n>>1;// 右移一位
    }
    // cout<<ones<<endl;
    return ones;
}// 该算法的复杂度为O(logn)

// 改进之后的算法
int countOnes1opti(unsigned int n)
{
    int ones = 0;
    while(n>0){
        ones += 1;
        n &= n-1;// 很巧妙，与最右的1减一之后求与，直接去掉了这个1
    }// 复杂度为n中1的个数
    return ones;
}

// 效率更高的算法
int countoneslopti1(unsigned int n)
{
    return 0;
}

int main(){
    cout<<"nishiwodeer";
    unsigned int testnum = 100;
    int result = countOnes1(testnum);
    cout<<result;
    return 0;
}