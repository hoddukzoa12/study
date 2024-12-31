#include<stdio.h>

long long int fiboData[90] = {0, };

long long int bottomUp(int n) {
    fiboData[0] = 0;
    fiboData[1] = 1;
    
    for (int i=2; i<=n; i++)
      fiboData[i] = fiboData[i - 1] + fiboData[i - 2];

    return fiboData[n];
}

int main(){
    long long int n;

    scanf("%d", &n);

    printf("%lld", bottomUp(n));

    return 0;

}