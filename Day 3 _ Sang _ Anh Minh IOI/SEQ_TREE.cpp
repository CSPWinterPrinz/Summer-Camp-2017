#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
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
#define TITLE "SegmentTree"

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

ll a[N], n, m;

struct Seqment_Tree
{
    ll L[N], H[N], sum[N], leaf[N / 2];

    void Build(int pos, int low, int high) /// node pos, segtree from low -> high
    {
        L[pos] = low; H[pos] = high; sum[pos] = 0;

        if(low == high) {
            leaf[high] = pos; sum[pos] = a[high];
        }
        else {
            ll mid = (low + high) / 2;
            Build(pos * 2, low, mid);
            Build(pos * 2 + 1, mid + 1, high);
        }
    }

    void Update(ll u, ll w)
    {
        int differ = w - a[u];
        for(int i = leaf[u] ; i > 0; i >> 1)
            sum[i] += differ;
        a[u] = w;
    }

    ll QuerrySum(int pos, int i, int j)
    {
        if(L[pos] > j || H[pos] < i) return 0;
        if(L[pos] >= i && H[pos] <= j) return sum[pos];
        return QuerrySum(pos << 1, i , j) + QuerrySum((pos << 1) + 1, i , j);
    }

    ll Ask(ll i, ll j)
    {
        return QuerrySum(1 , i , j);
    }
}
SegmentTree;

void Init()
{
    read(n); read(m);
    memset(a, 0, sizeof(a));
    SegmentTree.Build(1 , 1 , n);
}

void Solve()
{
    up(i , 1 , m)
    {
        int x; cin >> x;
        ll low, high; cin >> low >> high;
        if(x == 1) {
            cout << SegmentTree.QuerrySum(1 , low , high);
        }
        else {
            int val; cin >> val;
            SegmentTree.Update(low , val);
        }
        cout << x << " " << i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   // freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Init();
    Solve();
}
/*
switch(x)
        {
            case 1 :
                writeln(SegmentTree.Ask(low , high));
                break;
            case 2 :
                ll val; cin >> val;
                up(i , low , high)
                    SegmentTree.Update(i , val);
                break;
        }
        */

