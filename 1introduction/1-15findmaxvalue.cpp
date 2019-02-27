/*
*考察最大元素问题，从n个整数中找出最大者
*/

#include <iostream>
using namespace std;

int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }else
    {
        return b;
    }
    
}

// 线性递归版本
int maxR(int A[],int n)
{
    if(n<2){
        return A[n-1];
    }else
    {
        return max(maxR(A,n-1),A[n-1]); // 记住！这里的参数输入是A
    }
    
}

// 这个问题-二分递归是一个比较好的解决办法
int maxR_twodiv(int A[],int lo,int hi)
{
    if(lo+1==hi)
    {
        return A[lo];
    }else
    {
        int me = (lo+hi)>>1;
        return max(maxR_twodiv(A,lo,me),maxR_twodiv(A,me,hi));
    }
    
}

int main(){

    int values[] = {1,2,3,4,5,4,3};
    // int result = maxR(values,7);
    int result = maxR_twodiv(values,0,6);

    cout<<result;

    return 0;
}