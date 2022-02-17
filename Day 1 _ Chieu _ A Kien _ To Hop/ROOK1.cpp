#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 100
#define M 1000000007
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "ROOK1"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

ll GT[N], n, m, k, C[N][N];

struct T
{

};

void Build_Giai_Thua()
{
    GT[0] = 1;
    up(i , 1 , 100)
        {GT[i] = (GT[i - 1] * i) % M;}

}

void Build_C()
{
    up(i , 1 , 70)
        up(j , 1 , 70)
            C[i][j] = 0;

    C[0][0] = 1;
    up(i , 1 , 70)
        up(j , 1 , 70)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
}

void Solve()
{
    int T;
    cin >> T;
    up(i , 1 , T)
    {
        ll m , n , k;
        cin >> m >> n >> k;
        cout << (GT[k] * (C[k][n] * C[k][m]) % M) % M;
    }
}

int main()
{
  //  ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    //freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Build_Giai_Thua();
    Build_C();
    Solve();
}



