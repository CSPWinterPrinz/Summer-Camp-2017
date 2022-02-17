#include <bits/stdc++.h>
#define N 10004

using namespace std;
bool c[N];
long long GT[N], n, a[N], ans = 0, z;
/// Cai tien  : phan tu c co bnh phan tu o trc do > no;
void Init()
{
    cin >> n >> z; z--;
    memset(c, 1, sizeof(c));
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
  //  freopen("PERMUTATIONGEN.INP", "r", stdin);
    //freopen("PERMUTATIONGEN.OUT", "w", stdout);

    Giaithua(20);
    Init();
    Solve2();
}

