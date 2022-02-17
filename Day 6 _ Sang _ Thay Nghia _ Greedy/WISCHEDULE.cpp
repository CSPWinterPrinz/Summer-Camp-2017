#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 300006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "WISCHEDULE"

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

ll n, f[N];

struct T
{
    ll fir, las, val;
};
T a[N];

bool maximize(ll a, ll b)
{
    if(a < b) {a = b; return true;}
    return false;
}

void Init()
{
    read(n);
    up(i , 1 , n)
        read(a[i].fir), read(a[i].las) , read(a[i].val);
    sort(a + 1, a + n + 1, [] (const T &p, const T &q)
         {
             return p.fir < q.fir || (p.fir == q.fir && p.val < q.val);
         });
       //  up(i , 1 , n)
         //cout << a[i].fir << " " <<  a[i].las <<  " " << a[i].val << endl;
}

void Solve()
{
    ll res = 0;
    up(i , 1 , n) {
        f[i] = 0;
        up(j , 0 , i) {
            if(a[i].fir >= a[j].las)
                f[i] = max(f[i], f[j] + a[i].val);
                //maximize(f[i], f[j] + a[i].val);
        }
        //cout << f[i] << " ";
        res = max(res , f[i]);
    }
    writeln(res);
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


