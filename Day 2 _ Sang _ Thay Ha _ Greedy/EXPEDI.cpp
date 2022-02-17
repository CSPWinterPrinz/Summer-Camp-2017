#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Đến từ trạm i -> i + 1, có số xăng là F
/// Nếu F >= d(i + 1) - d(i) : Thì đi tiếp
/// Else, lấy ra các trạm có nh xăng nhất từ các trạm bỏ qua

/// => Chỉ chọn or ko chọn -> Chọn lại

//-----------------------------------------------------

#define N 10006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "EXPEDI"

#define gc getchar
#define pc putchar

#define Exit {cout << -1; exit(0);}

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

vector <int> e[N], w[N];
priority_queue <ll> NoPick; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

ll n, sum = 0, L, P;

struct T
{
    ll len, petr;
};
T a[N];

void Init()
{
    cin >> n;
    up(i , 1 , n)
        cin >> a[i].len;
    up(i , 1 , n)
        cin >> a[i].petr, sum += a[i].petr;

    if(sum + P < L) {cout << -1; exit(0);}
    cin >> L >> P;
    up(i , 1 , n)
        a[i].len = L - a[i].len;
    a[++n].len = L; a[n].petr = 0;
}

void Solve()
{
    sort(a + 1, a + n + 1, [] (const T &p, const T &q)
         {
             return p.len < q.len;
         });

    ll res = 0;

    up(i , 1 , n)
    {
        while(!NoPick.empty() && P < a[i + 1].len - a[i].len)
        {
            res++;
            P += NoPick.top();
            NoPick.pop();
        }
        if(P < a[i + 1].len - a[i].len) {cout << -1; exit(0);}
        NoPick.push(a[i].petr);
        P = P - (a[i + 1].len - a[i].len);

    }
    cout << res;
}

void Print()
{
    long long c[N];
    memset(c , 0 , sizeof(c));
    while(!NoPick.empty())
    {
        c[NoPick.top()] = 1;
        NoPick.pop();
    }

    up(i , 1 , n - 1)
        if(!c[i]) cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  //  freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Init();
    Solve();
    //Print();
}


