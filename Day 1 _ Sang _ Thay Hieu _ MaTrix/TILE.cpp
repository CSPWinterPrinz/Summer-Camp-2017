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
#define TITLE "TILE"

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
ll n, f[N];

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

    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= 2; j++) {
            C.Data[i][j] = 0;
            for(int k = 1; k <= 2; k++)
                C.Data[i][j] = (C.Data[i][j] + A.Data[i][k] * B.Data[k][j] % M) % M;
        }
        //cout << 5<<" " ;
    return C;

}

/// Matrix A ^ k;
Matrix Power(Matrix A, ll k)
{
    if(k == 1) return A;
    Matrix T = Power(A , k / 2);
    if(k % 2 == 0) return Multi(T , T);
    else return Multi(A , Multi(T , T));
}

/// f(i) = f(i - 1) + 2 * f(i - 2);
/// MATRIX :
/// 0 1
/// 2 1
/// RES = T ^ n * A;

void Solve()
{
    //cout << 1;

    Matrix T;
    T.Data[1][1] = 0; T.Data[1][2] = 1;
    T.Data[2][1] = 2; T.Data[2][2] = 1;
   // cout << 1;
    Matrix Ans;
    //cout << 1 << endl;
    Ans = Power(T , n);

    cout << (Ans.Data[1][1] + Ans.Data[1][2]) % M << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(TITLE".INP", "r", stdin);
    freopen(TITLE".OUT", "w", stdout);

    int z;
    cin >> z;
    up(i , 1 , z)
    {
        cin >> n;
        Solve();
    }
}


