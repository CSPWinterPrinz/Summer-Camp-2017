#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 100006
#define M 1000000007
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "SEARCH"

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
string s, t;
bool l;

ll m, n, HashS[N], HashT[N], Pow26[N];

struct T
{

};

void Build()
{
    Pow26[0] = 1;
    up(i , 1 , N) Pow26[i] = (Pow26[i - 1] * 26) % M;
}

ll GetHash(int i, int j)
{
    ll l = ((ll) HashS[j] - HashS[i - 1] * Pow26[j - i + 1]) % M;
    if(l < 0) l+=M;
    return l;
}

void Init()
{
    cin >> s;
    n = s.length(); HashS[0] = s[0] - 'a';

    cin >> t;
    m = t.length(); HashT[0] = t[0] - 'a';

    up(i , 1 , n-1) {HashS[i] = (HashS[i - 1] * 26 + (s[i] - 'a')) % M;}// cout << HashS[i] << " ";}
    //cout<<endl;
    up(i , 1 , m-1) {HashT[i] = (HashT[i - 1] * 26 + (t[i] - 'a')) % M;}
}

void Solve()
{
    //cout << HashT[m - 1] << endl;
    ll res = 0;
    up(i , m - 1, n)
    {
        if(GetHash(i - m + 1 , i) == HashT[m - 1]) res++;
       // cout << GetHash(i , i + m - 1) << " ";
    }
    cout << res;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  //  freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Build();
    Init();
    Solve();
}


