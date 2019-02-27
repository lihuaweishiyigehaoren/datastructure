#include <iostream>
using namespace std;

int sum(int A[],int lo, int hi){
    if(lo == hi)
        return A[lo];
    else{
        int mi = (lo + hi)>>1;
        return sum(A,lo,mi)+sum(A,mi+1,hi);
    }
}

int main(){
    
    // cout<<"lihuawei";
    int A[5]={1,2,3,4,5};
    int sums = sum(A,0,4);
    cout<<sums;
    return 0;
}