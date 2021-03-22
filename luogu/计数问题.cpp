#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int i,j,n,x,cnt=0; 
    scanf("%d%d",&n,&x);
    for (i=1;i<=n;i++)  //对1到n的所有数进行判断
      {
        j=i;  
        while (j!=0){ 
            if (x==j%10) cnt++;
            j/=10; 
        }
      }
    printf("%d\n",cnt);  
    return 0;
}