/*
有一个贪心的典型题型，
将区间进行分组
先按照左端点进行排序，
然后从左到右进行遍历，如果已有区间的右端点与此时遍历到的区间的左端点不重叠
则将器加入到组
否则就开新组。


重点是一点要会如何使用小根堆进行实现呀！！


#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
struct  Range{
    int l,r;
    bool operator < (const Range &W)const{//重载运算符，一定要记住语法的实现
        return l<W.l;
    }
}range[N];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        range[i]={l,r};
    }
    sort(range ,range+n);

    priority_queue<int ,vector<int>,greater<int> >heap;//小根堆!!

    for(int i=0;i<n;i++){
        auto r=range[i];
        if(heap.empty()||heap.top()>=r.l) heap.push(r.r);//不能放到一组的话就新开组
        else {//可以在一组的话就更新此时组的右端点
            heap.pop();
            heap.push(r.r);
        }
    }

    printf("%d\n",heap.size());

    return 0;
}

*/

/*

还可以将问题看作
有若干个活动，第i个活动开始时间和结束时间是[SiSi,fifi]，
同一个教室安排的活动之间不能交叠，求要安排所有活动，少需要几个教室？

做法是：有时间冲突的活动不能安排在同一间教室，
与该问题的限制条件相同，即最小需要的教室个数即为该题答案

本种方法的巧妙地方就在于
把所有开始时间和结束时间排序，
遇到开始时间就把需要的教室加1，遇到结束时间就把需要的教室减1,
在一系列需要的教室个数变化的过程中，
峰值就是多同时进行的活动数，也是我们至少需要的教室数。

*/
#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n;
int b[2*N],idx;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        b[idx++]=l*2;//标记左端点为偶数
        b[idx++]=r*2+1;//标记右端点为奇数
                        //这样处理是为了处理边界重合问题
                        //若是开始时间和结束时间重叠但不冲突的话，
                        //将左端点初始化为奇数，右端点初始化为偶数即可
    }
    sort(b,b+idx);
    
    int res=0,t=0;
    for(int i=0;i<idx ;i++){
        if(b[i]%2==0) t++;
        else t--;
        res=max(res,t);

    }
    cout<<res<<endl;
    return 0;
}









