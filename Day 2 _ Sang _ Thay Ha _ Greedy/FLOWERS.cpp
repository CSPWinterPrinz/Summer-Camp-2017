#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 1000006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "FLOWERS"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

ll n, sum, res = 0;

struct T
{
    ll t, d;
};
T a[N];

void Init()
{
    sum = 0;
    cin >> n;
    up(i , 1 , n)
        cin >> a[i].t >> a[i].d , sum += a[i].d;
}

void Solve()
{
    sort(a + 1, a + n + 1, [] (const T &p, const T &q)
         {
             return p.t * q.d < q.t * p.d;
         });

    up(i , 1 , n)
    {
        res += (sum - a[i].d) * a[i].t * 2;
        sum -= a[i].d;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    Init();
    Solve();
}


