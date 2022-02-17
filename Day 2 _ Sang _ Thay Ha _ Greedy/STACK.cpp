#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 2600
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "STACK"

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

ll n, res = 0, f[N], sum = 0;

struct T
{
    ll w, c;
};
T a[N];

void Init()
{
    cin >> n;
    up(i , 1 , n)
        cin >> a[i].w;

    up(i , 1 , n)
        cin >> a[i].c;
}

void Solve()
{
    sort(a + 1 , a + n + 1 , [] (const T &p, const T &q)
         {
             return p.c - q.w < q.c - p.w;
         });

    up(i , 1 , n)
    {
        if(a[i].c >= sum) {
            res++;
            PQ.push(a[i].w);
            sum += a[i].w;
        }
        else {
            if(a[i].w < PQ.top()) {
                sum = sum - PQ.top() + a[i].w;
                PQ.pop();
                PQ.push(a[i].w);
            }
        }
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



