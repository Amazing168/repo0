/*

贪心
将区间按左端点排序
然后遍历找到覆盖目标区间右端点最大的区间更新

*/
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
struct Range{
    int l,r;
    bool operator< (const Range & W) const {
        return l<W.l;
    }
}range[N];

int main(){
    int st,ed;
    cin>>st>>ed;
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        range[i]={l,r};
    }
    sort(range,range+n);
    int res=0;
    bool success =false;//设置一个标志来判断最后有没有覆盖目标线段
    for(int i=0;i<n;i++){
        int j=i,r=-2e9;
        while(j<n&&range[j].l<=st){
            r=max(r,range[j].r);
            j++;
        }
        if(r<st){
            res=-1;
            break;
        }
        res++;
        if(r>=ed){
            success =true;//标志一下有没有覆盖完全
            break;
        }
        st=r;
        i=j-1;//跟新i的值，使得下次循环从j开始，减少循环次数
    }
    if(!success) res=-1;
    printf("%d\n",res);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){



    return 0;
    }