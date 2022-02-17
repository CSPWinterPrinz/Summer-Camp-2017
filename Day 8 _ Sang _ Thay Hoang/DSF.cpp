#include <bits/stdc++.h>
#define N 100124
using namespace std;
long long n, m, lab[N];
void MakeSet(int u)
{
        lab[u] = -1;
}

long long FindSet(int u)
{
        return lab[u] < 0 ? u : lab[u] = FindSet(lab[u]); ///Nen' duong, dau tien tim cha cua node u, gradually len goc, sau do gan thang goc cua node u la goc cay
}

void Union(int r, int s)       /// Union by rank
{
        if(lab[r] < lab[s]) swap(r , s); /// Cay s > Cay r (lab < 0)
        /// Cay r to hon cay s
        lab[r] += lab[s];    /// Label r += Label s (label la so phan tu cua cay)
        lab[s] = r;
}
//lab(i) > 0 thi i la con of lab(i)
//lab(i) < 0 thi la am so phan tu

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        freopen("DSF.INP", "r", stdin);
        freopen("DSF.OUT", "w", stdout);

        cin >> n >> m;
        for(int  i = 1; i <= n; i++)
            MakeSet(i);

        long long cnt = n;

        for(int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            long long r = FindSet(u);
            long long s = FindSet(v);

            if(r != s) {
                Union(r , s);
                cnt--;
            }
            cout << cnt << '\n';
        }

}

