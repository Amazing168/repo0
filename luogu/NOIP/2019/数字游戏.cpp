//P5660

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string number;
    cin >> number;
    int res = 0;
    for (int i = 0; i < number.size(); i ++ )
        if (number[i] == '1')
            res ++ ;
    cout << res << endl;
    return 0;
}