#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 6
#define M 1000000007
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "LOCO"

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
ll n, f[N], k;

struct Matrix
{
    ll Data[N][N];

    Matrix()
    {
        memset(Data, 0, sizeof(Data));
    }
};

Matrix Multi(Matrix A, Matrix B, ll z)
{
    Matrix C;

    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
        {
            C.Data[i][j] = 0;
            for(int k = 1; k <= 3; k++)
                C.Data[i][j] = (C.Data[i][j] + A.Data[i][k] * B.Data[k][j] % z) % z;
        }
    return C;
}

/// Matrix A ^ k;
Matrix Power(Matrix A, ll kt)
{
    if(kt == 1) return A;
    Matrix T = Power(A , kt / 2);
    if(kt % 2 == 0) return Multi(T , T, k);
    else return Multi(A , Multi(T , T , k) , k);
}

/// f(i) = f(i - 1) + 2 * f(i - 2);
/// MATRIX :
/// 0 1
/// 2 1
/// RES = T ^ n * A;

void Init()
{
    cin >> n >> k;
}

void Solve()
{
    ll f[N];
    f[0] = 1; f[1] = 1; f[2] = 2; f[3] = 4;
    Matrix A;
    A.Data[1][1] = 0; A.Data[1][2] = 1; A.Data[1][3] = 0;
    A.Data[2][1] = 0; A.Data[2][2] = 0; A.Data[2][3] = 1;
    A.Data[3][1] = 1; A.Data[3][2] = 1; A.Data[3][3] = 1;

    Matrix Ans;
    if(n > 2) {
        Ans = Power(A , n - 2);
        cout << (1 * Ans.Data[3][1] + 1 * Ans.Data[3][2] + 2 * Ans.Data[3][3]) % k;
    }
    else cout << f[n];
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


