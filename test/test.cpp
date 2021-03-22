#include <iostream>
using namespace std;
int main()
{
    int a[100][100]={0}, n, i, j, r, c, rows=0, columns=0;
    cin >> n;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++){
            cin >> a[i][j];
            a[0][j] = (a[0][j]+a[i][j])%2;
            a[i][0] = (a[i][0]+a[i][j])%2;
        }
    for (i=1; i<=n; i++){
        if (a[i][0] > 0){

            r = i;
            rows++;
        }
    }
    for (j=1; j<=n; j++){
        if (a[0][j] > 0){
            c = j;
            columns++;
        }
    }
    if (rows==0 && columns==0) cout << "OK" << endl;
    else if (rows==1 && columns==1) cout << r << " " << c << endl;
    else cout << "Corrupt" << endl;
    return 0;
}



//   t=pow(10,d);