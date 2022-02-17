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
#define TITLE "FIBONACCI"

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
ll n;

struct Matrix
{
    ll Data[N][N];

    Matrix()
    {
        memset(Data, 0, sizeof(Data));
    }
};

Matrix Multi(Matrix A, Matrix B)
{
    Matrix C;
    up(i , 1 , 2)
        up(j , 1 , 2)
            up(k , 1 , 2)
                C.Data[i][j] = (C.Data[i][j] + A.Data[i][k] * B.Data[k][j] % M) % M;

    return C;
}
Matrix Power(Matrix A, ll k)
{
    if(k == 1) return A;
    Matrix T = Power(A , k / 2);
    if(k % 2 == 0) return Multi(T , T);
    else return Multi(Multi(T , T) , A);
}

void Init()
{
    cin >> n;
}

void Solve()
{
    Matrix A;
    A.Data[1][1] = 0; A.Data[1][2] = 1;
    A.Data[2][1] = 1; A.Data[2][2] = 1;

    Matrix Res;
    Res = Power(A , n - 2);
    cout << (Res.Data[2][1] + Res.Data[2][2]) % M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
 //   freopen(TITLE".OUT", "w", stdout);

    Init();
    if(n > 2) Solve();
    else cout << 1;
}



