// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n,max=0,sum=0;
    int a,b;
    scanf("%d",&n);
    for(int i=0; i<n ; i++){
        scanf("%d %d", &a, &b);
        sum=sum-a+b;
        if (sum>max){
            max=sum;
        }
    }
    printf("%d",max);
    return 0;
}
