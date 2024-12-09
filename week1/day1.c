#include<stdio.h>

int main()
{
    int  N;
    scanf("%d",&N);

    for(int i=0; i<N; i++)
    {
        int num[7]={0,};
        int k=0,M=i;
        for(int j=1000000; j>=1; j=j/10)
        {
            num[k] = M/j;
            M=M%j;
            k++;
        }
        if(N==i+num[0]+num[1]+num[2]+num[3]+num[4]+num[5]+num[6])
        {
            printf("%d",i);
            break;
        }
        else if(i==N-1)
        {
            printf("0");
            break;
        }
    }
    return 0;
}