#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 2000060
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; ++i)
#define down(i , a , b) for (int i = a; i >= b; --i)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "CARRIAGE"

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

ll m, n, Dif, sum[N], sumA, len, a[N], b[N];

struct T
{

};

void Init()
{
    sum[0] = 0, sumA = 0;
    read(n); read(m); read(len);

    down(i , n , 1)
        read(a[i]), sumA += a[i];
    up(i , 1 , m)
        read(b[i]);

    sort(b + 1, b + m + 1);
    up(i , 1 , n) sum[i] = sum[i - 1] + b[i];
    Dif = - sumA + len;
    //cout << sumA << " " << len << endl;
}

void Solve()
{
    ll res = oo;
    up(id , 1 , n) {
        Dif += a[id];
        if(Dif == 0) {cout << id << " "; exit(0);}
       // cout << Dif << " ";
        if(Dif > 0) {
            up(i , 1 , m) {
                ll L = 1, H = i - 1, x = - Dif + sum[i];
                //cout << i << " ";
                while(L <= H) {
                    ll M = (L + H) / 2;
                    if(sum[M] < x) L = M + 1;
                    else H = M - 1;
                }
                if(sum[L] == x) {
                    res = min(res , id + i - L);
                    //cout << id << ' ' << i << " " << L << endl;
                }
            }
        }
    }
    writeln(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Init();
    Solve();
}


