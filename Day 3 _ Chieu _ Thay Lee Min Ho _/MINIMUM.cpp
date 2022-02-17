#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
/// Trc khi cho i vào deque, đẩy tất cả những thg > i ra ngoài, nhét nó vào.
/// Đẩy tất cả những thằng có chỉ số lớn hơn i - k ra, mỗi bước đều pop 1 lần -> O(1) thay vì dùng while
/// Phần tử lớn nhất trong k phần tử trc đấy là phần tử đầu

//-----------------------------------------------------

#define N 5000006
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "MINIMUM"

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
deque <int> Dq;
stack <int> st;
string s;
bool l;

ll n, k, h[N];

struct T
{

};

void Init()
{
    cin >> n >> k;
    up(i , 1 , n)
        cin >> h[i];
}

void Solve()
{
    up(i , 1 , n)
    {
        while(!Dq.empty() && h[Dq.back()] >= h[i])
            Dq.pop_back();

        Dq.pb(i);

        if(i >= k) {
            cout << h[Dq.front()] << endl;
            if(i - Dq.front() + 1 >= k) Dq.pop_front();
        }

    }
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



