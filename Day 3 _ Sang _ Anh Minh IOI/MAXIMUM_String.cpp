#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 1000006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "MAXIMUM"

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
ll a[N], sum[N], minle = oo + 2, minchan = 0, n , f[N];

struct T
{

};

void Init()
{
    sum[0] = 0;
    cin >> n;
    up(i , 1 , n)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];// cout << sum[i] << " ";
        //cout << endl;
}

void Solve()
{
    ll res = -1000000000000000;
    up(i , 1 , n) {

        if(i % 2 == 1) {
            res = max(res , sum[i] - minle);
            minle = min(minle, sum[i]);
        }
        else {
            res = max(res , sum[i] - minchan);
            minchan = min(minchan, sum[i]);
        }
        //cout << res << " " << minle << " " << minchan << endl;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);

    Init();
    Solve();
}


