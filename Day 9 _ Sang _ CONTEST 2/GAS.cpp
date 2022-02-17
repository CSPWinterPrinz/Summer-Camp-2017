#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 1000006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "GAS"

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
//priority_queue <int> PQ; /// max
priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

ll n, K, k[N], a[N], c[N];

struct T
{

};

void Init()
{
    memset(c , 0 , sizeof(c));
    cin >> n >> K;
    up(i , 1 , n)
        cin >> a[i];
    fill(k + 1, k + n + 1, K);
}

void Solve()
{
    ll P = 0, res = 0;
    up(i , 1 , n) {
        PQ.push(a[i]);
        if(P < 1) {
            res += PQ.top();
            //cout << PQ.top() << " ";
            c[PQ.top()]++;
            ll cur = PQ.top();
            if(c[PQ.top()] == k[PQ.top()]) {PQ.pop();}
            c[cur + 1] = 1;
            up(j , cur + 2, cur + K + 1)
                k[j] = min(k[j - 1] + 1, K);
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


