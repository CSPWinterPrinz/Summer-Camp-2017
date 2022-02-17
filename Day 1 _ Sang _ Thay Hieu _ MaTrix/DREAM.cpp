#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// CT qhd : f(x) = sigma p(1 -> 100) : f(x - p) * c[p];
///  f(x) = c1 * f(x - 1) + c2 * f(x - 2) + ... + c100 * f(x - 100)
///  f(x-1)= 1 * f(x - 1) + 0 * f(x - 2) + .... + 0 * f(x - 100)
///  .....................
/// f(x-99)= 0 * f(x - 1) + 0 * f(x - 2) + .... + 1 * f(x - 99) + 0 * f(x - 100)
/// P khỏi tạo ma trận 101 * 101
//-----------------------------------------------------

#define N 103
#define M 1000000007
#define oo 1000000007

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "DREAM"

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

struct Matrix
{
    ll Data[N][N];

    Matrix()
    {
        memset(Data, 0, sizeof(Data));
    }
};

Matrix Multi(Matrix A, Matrix B, ll p) /// Nhan ma tran
{
    Matrix C;

    for(int i = 1; i <= 101; i++)
        for(int j = 1; j <= p; j++)
        {
            C.Data[i][j] = 0;
            for(int kt = 1; kt <= 101; kt++)
                C.Data[i][j] = (C.Data[i][j] + A.Data[i][kt] * B.Data[kt][j] % oo) % oo;
        }
    return C;
}

Matrix Power(Matrix A, ll kt)        /// Matrix A ^ k
{
    Matrix Cur;
    up(i , 1 , 101)                 /// Khoi tao ma tran don vi =))
        up(j , 1 , 101)
            Cur.Data[i][j] = (ll) i == j;

    for(; kt ; kt >> 1 , A = Multi(A , A , 101))
        if(kt & 1) Cur = Multi(Cur , A , 101);

    return Cur;
}

ll d[100006], m;
ll n, F[100006], k, c[100006], Ans[100006];
Matrix T;

void Init()
{
    cin >> n >> k;
    memset(c , 0 , sizeof(c));
    up(i , 1 , n) {
        int x; cin >> x;
        c[x]++;
    }
}

bool Debug = 1;

void Count_F()        /// F(i) : số cách sinh tổng i
{
    memset(F , 0 , sizeof(F));
    F[0] = 1; Ans[0] = 1;
    up(i , 1 , 100) {
        up(j , 1 , i)
            F[i] = (F[i] + (F[i - j] * c[j]) % oo) % oo;
        Ans[i] = (Ans[i - 1] + F[i]) % oo;
    }
}

void Build()
{
    up(i , 1 , 102)  up(j , 1 , 102) T.Data[i][j] = 0;

    up(i , 1 , 100)    T.Data[1][i + 1] = T.Data[2][i + 1] = c[i];

    T.Data[1][1] = 1;
    up(i , 3 , 101)   T.Data[i][i - 1] = 1;

    if(Debug)
        up(i , 1 , 101) {
            up(j , 1 , 101) cout << T.Data[i][j];
            cout << endl;
        }
}

void Solve()
{
    if(k <= 100) cout << Ans[k] , exit(0);

    Matrix A, Res;
    A.Data[1][1] = Ans[100]; cout << Ans[100] << " ";
    up(i , 2 , 101)
        A.Data[i][1] = F[101 - (i - 2)] , cout << A.Data[i][1] << " ";

    Res = Power(T , k - 100);
    Res = Multi(Res , A , 1);
    cout << Res.Data[1][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Init();
    Count_F();
    Build();
    Solve();

}


