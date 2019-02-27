#include <iostream>
#include <cstdint>
using namespace std;

// 常规算法 O(2^n)
int64_t fib(int n)
{
    return (n<2)? (int64_t)n : fib(n-1)+fib(n-2);
}

// 线性递归版本 时间复杂度O(n)，空间复杂度也是O(n)!
// 计算一段相邻的Fibonacci数 (fib(k-1),fib(k))  忽略了对fib(n-2)的递归选择保存它的值
int64_t fib_linearrec(int n,int64_t &prev)
{
    if(n==0)
    {
        prev = 1;
        return 0;
    }else
    {
        int64_t prevPrev;
        prev = fib_linearrec(n-1,prevPrev);
        return prevPrev+prev;
    }

}// 用辅助变量记录前一项，返回数列的当前项O(n)

// 动态规划方法改进 时间复杂度为O(n)，仅需常数空间规模的附加空间
int64_t fib_DP(int n)
{
    int64_t f=1,g=0;// 初始化f(-1) f(0)
    while(0<n--){// 先比较后相减
        /* code */
        g = g+f;
        f= g-f;
        cout<<g<<" "<<f<<endl;
    }
    return g;
    
}

// 效率更高的迭代，时间复杂度仅为O(logn)
// 计算矩阵的平方
int[][2] calu_martix_squ(int A[][2],int n)
{
    int B[n][2];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<2;j++)
        {
            int num=0;
            for(int k=0;k<2;k++)
            {
                num += A[i][k]*A[k][j];
            }
            B[i][j]=num;
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return B;
}




int main()
{
    int testnum=2;
    // int result = fib(testnum);
    // int64_t prevValue;
    // int result = fib_linearrec(testnum,prevValue);
    // int result = fib_DP(testnum);

    int A[2][2]={0,1,1,1};

    calu_martix_squ(A,2);
    // cout<<result<<endl;

    return 0;
}