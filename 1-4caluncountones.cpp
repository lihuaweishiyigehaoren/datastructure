// 原始算法
int countOnes1(unsigned int n)
{
    int ones = 0;
    while(n>0){
        ones += (n&1)
        n>>1;// 右移一位
    }
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
    
}