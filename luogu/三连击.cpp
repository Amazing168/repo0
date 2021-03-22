#include <bits/stdc++.h>
using namespace std;

int main()
{
    int flag[10],s[3];
    for(int k=123;k<=329;k++)
    {   
        
        s[0]=k;
        s[1]=k*2;
        s[2]=k*3;
        
        for(int i=0;i<3;i++)
        {    
            while(s[i]!=0){
                int t=s[i]%10;
                flag[t]=1;
                s[i]/=10;
            }
        }

        int c=0;
        for(int j=1;j<10;j++)
            c=c+flag[j];
        for(int j =1;j<=9;j++) flag[j]=0;

        if(c==9)
            printf("%d %d %d\n",k,k*2,k*3);
    }
    return 0;
}
