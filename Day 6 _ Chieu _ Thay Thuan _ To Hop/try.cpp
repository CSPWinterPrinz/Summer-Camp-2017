#include <bits/stdc++.h>
#define N 24

using namespace std;
bool c[N];
long long GT[N], n, a[N], ans = 0, z;
/// Cai tien  : phan tu c co bnh phan tu o trc do > no;
void Init()
{
    cin >> n;
    memset(c, 1, sizeof(c));
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> z; z--;
}

void Giaithua(long long x)
{
    long long res = 1;
    for(int i = 1; i <= x; i++)
    {
        res = res * i;
        GT[i] = res;
    }
}

void Solve()
{
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        //if(a[i] == 1) break;
        for(int j = 1; j < a[i]; j++) {
            if(c[j]) cnt++;
        }
        ans = ans + (long long) cnt * GT[n - i];
        c[a[i]] = false;
    }
    cout << ans + 1 << endl;
}

void Solve2()
{
    memset(c , 1, sizeof(c));
    for(int i = 1; i < n; i++)
    {
        long long cur = 0;
        while(cur * GT[n - i] <= z)
            cur++;
        cur--;
        z -= cur * GT[n - i];
        int lessnum = 0, y = 1;
        while(lessnum <= cur && y <= n)
        {
            if(c[y]) lessnum++;
            y++;
        } y--;

        cout << y << " ";
        c[y] = false;
    }
    for(int i = 1; i <= n; i++)
    {
        if(c[i]) {
            cout << i;
            break;
        }
    }
}

int main()
{
  //  freopen("PERMUTATION.INP", "r", stdin);
    //freopen("PERMUTATION.OUT", "w", stdout);

    Giaithua(20);
    Init();
    Solve();
    Solve2();
}

