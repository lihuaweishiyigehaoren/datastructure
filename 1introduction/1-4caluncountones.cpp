#include <iostream>
using namespace std;

// 十进制转二进制
void printbinary(const unsigned int val)
{
	for(int i = 16; i >= 0; i--) // 就输出16位的二进制，超过不行，不超过前面会有0
	{
		if(val & (1 << i)) // 16位每个位置逐一验证
			cout << "1";
		else
			cout << "0";
	}
    cout<<endl;
}

// 原始算法
int countOnes1(unsigned int n)
{
    int ones = 0;
    while(n>0){
        ones += (n&1);
        n = n>>1;// 右移一位
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
#define POW(c) (1<<(c))
#define MASK(c) (((unsigned long)-1)/(POW(POW(c))+1))

// 输入：n的二进制展开中，以2^c为单位分组，各组数值已经
#define ROUND(n,c) (((n) & MASK(c))+((n)>>POW(c) & MASK(c)))// 先右移，再位与

int countoneslopti1(unsigned int n)
{
    n = ROUND(n,0);
    n = ROUND(n,1);
    n = ROUND(n,2);
    n = ROUND(n,3);
    n = ROUND(n,4);
    return n;
}

int main(){
    unsigned int testnum = 1000;
    // int result = countOnes1(testnum);
    // int result = countOnes1opti(testnum);
    // int result = countoneslopti1(testnum);

    printbinary(testnum);
    printbinary(ROUND(testnum,0));
    return 0;
}