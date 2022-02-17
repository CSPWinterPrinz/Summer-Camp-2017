#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 20
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <ll , ll>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "HISTOGRAM"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

/// ***************************** FAST I/O *****************************
inline void read(long long &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline void writeln(long long x)
{
     char buffor[21];
     register int i=0;
     int neg=0; if (x<0) {neg=1; x= -x;}
     do{
           buffor[i++]=(x%10)+'0';
           x/=10;
        } while(x);
       i--;
       if (neg) pc('-');
       while(i>=0) pc(buffor[i--]);
       pc('\n');
}
/// ***************************** FAST I/O *****************************

vector <int> e[N], w[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

ll n, h[N];
bool avail[1<<15][N];

struct T
{
    ll val, cnt;
};
T f[N][N];

void Init()
{
    memset(avail, 0, sizeof(avail));
    up(i , 1 , n)
    cin >> h[i];
}

ll Count(ll y, ll j)
{
    if(y == (1 << (j - 1))) {
        f[y][j].cnt = 1; return (h[j] * 2 + 2);
    }
    if(avail[y][j] == 1) return f[y][j].val;
    if(y == (1 << n)) return 0;

    ll x = y ^ (1 << (j - 1));
    avail[y][j] = 1; f[y][j].val = 0;

    up(i , 1 , n)
        if((x >> (i - 1) & 1) == 1) {
            ll t = Count(x , i) + h[j] - h[i] + abs(h[j] - h[i]) + 2;
            f[y][j].cnt = t > f[y][j].val ? f[x][i].cnt : (t == f[y][j].val ? f[y][j].cnt + f[x][i].cnt : f[y][j].cnt);
            f[y][j].val = max(f[y][j].val , t);
        }
    return f[y][j].val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    while(cin >> n) {
        if(n == 0) break;
        Init();
        ll res = 0, res2 = oo;
        up(i , 1 , n) {
            ll cur = Count((1 << n) - 1 , i);
            if(res < cur)
                res = cur, res2 = f[(1 << n) - 1][i].cnt;
            else if(res == cur) res2 += f[(1 << n) - 1][i].cnt;

        }
        cout << res << endl; //' ' << res2 << endl;
    }
}


