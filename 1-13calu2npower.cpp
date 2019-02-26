/*
在每次不超过一次移位操作下
对于非负整数n，计算它的2^n
*/
#include<iostream>
#include<cstdint>
using namespace std;

//迭代版本
int64_t power2BF_I(int n)
{
    int64_t pow = 1;
    while (0<n--)
    {
        pow <<= 1;
    }

    return pow;
}

//递归版本
// 与迭代版本相比，原理一致，只不过计算方向恰好颠倒过来
int64_t power2BF_recu(int n)
{
    return(1>n)? 1:power2BF_recu(n-1)<<1;
}

// 多向(优化)递归版本，大大提高其效率
// 把n二进制展开以后，根据数学归纳法，可归纳出二进制类型的递推关系式
// 之前是n 与 n-1 之间的递归，现在是n的二进制展开式之间项数之间的递归
inline int64_t sqr(int64_t n){return n*n;};
int64_t power2BF_mulrecu(int n)
{
    if(n==0) return 1;
    return (n&1)? sqr(power2BF_mulrecu(n>>1))<<1:sqr(power2BF_mulrecu(n>>1));
}

// 优化迭代版
// 这个复杂度与优化过的多向递归是相同的
// 与递归思想相同，不过是反过来的，由下而上
int64_t power2BF_iter(int n)
{
    int64_t pow = 1;
    int64_t p = 2;

    while(n>0){
        if(n&1)
        {
            pow *= p;
        }
        n>>=1;
        p*=p;
    }
    return pow;
}

int64_t power2BF_iterano(int n)
{
    // 求n的转置n_t
    int n_t = 0;
    while(n>0){
        if(n&1)
        {
            n_t = n_t*2 +1;
        }else
        {
            n_t = n_t*2;
        }
        n>>=1;
    }

    int pow = 1;
    while(n_t>0){
        if(n_t&1)
        {
            pow = (pow^2)*2;
        }else
        {
            pow = pow^2;
        }
        n_t>>=1;
    }

    return pow;
    
}

int main(){
    int testnum = 10;
    // int result = power2BF_I(testnum);
    // int resultano = power2BF_iter(testnum);
    // cout<<result<<endl;
    // cout<<resultano;
    cout<<power2BF_iterano(testnum);
    return 0;
}

