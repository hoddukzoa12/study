#include<stdio.h>

int fiboData[90] = {0, };

int bottomUp(int n) {
    fiboData[0] = 0;
    fiboData[1] = 1;
    
    for (int i=2; i<=n; i++)
      fiboData[i] = fiboData[i - 1] + fiboData[i - 2];

    return fiboData[n];
}

int main(){
    int n;

    scanf("%d", &n);

    printf("%d\n", bottomUp(n));

    return 0;

}