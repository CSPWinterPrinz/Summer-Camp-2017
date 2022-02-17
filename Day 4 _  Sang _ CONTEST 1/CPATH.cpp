#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 6
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "CPATH"

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
bool f[N][N];

ll m, n, k;

struct Matrix
{
    ll Data[N][N];
};

void Init()
{
    up(i , 1 , N)
        up(j , 1 , N)
        f[i][j] = 0;
    cin >> n >> m >> k;
    cout<<1;
    up(i , 1 , m) {
        int u, v; cin >> u >> v;
        f[u][v] = 1;
    }
    cout<<1;
}

Matrix Sum(Matrix A, Matrix B)
{
    Matrix C;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            C.Data[i][j] = (A.Data[i][j] + B.Data[i][j]) % 2017;

    return C;
}

/// MAtrix A * B
Matrix Multi(Matrix A, Matrix B)
{
    Matrix C;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            C.Data[i][j] = 0;
            for(int k = 1; i <= n; k++)
                C.Data[i][j] = (C.Data[i][j] + A.Data[i][k] * B.Data[k][j] % 2017) % 2017;
        }
    return C;
}

/// Matrix A ^ k;
Matrix Power(Matrix A, int k)
{
    if(k == 1) return A;
    Matrix T = Power(A , k / 2);
    if(k % 2 == 0) return Multi(T , T);
    else return Multi(T , Multi(T , A));
}

void Build(Matrix &A)
{
    up(i , 1 , n)
        up(j , 1 , n)
            A.Data[i][j] = 0;

    up(i , 1 , n)
        up(j , 1 , n)
            if(f[i][j])
                A.Data[i][j] = 1;
}

void Solve()
{
    Matrix A;
    Build(A);
    Matrix Res = Power(A , k);
    cout << Res.Data[1][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

  //  Init();
    //Solve();
    cout << 2;
}



