#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Khởi tạo mảng C(k , n) = C(k - 1, n - 1) + C(k , n - 1)
///        2 vòng for
/// if(P > A) return 0;
/// if(Q > B) return 0;
//-----------------------------------------------------

#define N 1001
#define oo 1000000007

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <char, ll>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "TEAM"

#define gc getchar
#define pc putchar

//-----------------------------------------------------

typedef long long ull;
typedef unsigned long long ll;
typedef long double ld;

using namespace std;

vector <II> e;
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <int> st;
string s;
bool l;

char a[N];
ull Mid, A, B, X, Y ,C[N][N];

struct T
{

};

void Init()
{
    cin >> A >> B >> X >> Y;
}

void Build_C()
{
    up(i , 1 , N)
        up(j , 1 , N)
            C[i][j] = i == j ? 1 : 0;
    C[0][0] = 1;
    up(i , 1 , N) {
        up(j , 1 , i)
            {C[i][j] = ( C[i - 1][j] + C[i - 1][j - 1] ) % oo; cout << C[i][j] << " ";}
            cout << endl;
    }
}

void Solve()
{
   ull res = 0;
   if(A + B < X || X < Y)
   {
       cout << 0; exit(0);
   }
   up(i , 0 , min(A , A))
        up(j , 0 , B)
            if(abs(i - j) <= Y && i + j == X) {
                res += C[A + 1][i + 1] * C[B + 1][j + 1]; res %= oo;
            }

   cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Build_C();
 //   Init();
   // Solve();
}


