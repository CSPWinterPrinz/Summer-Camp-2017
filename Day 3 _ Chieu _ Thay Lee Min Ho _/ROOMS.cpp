#include <bits/stdc++.h>

//-----------------------------------------------------
/// Chia phong hoi thao, n phong, start at S, end at F;
/// in ra chia khoa nao dung cho phong nao, vs so chia khoa it nhat
//-----------------------------------------------------
/// SOL
/// Struct, Id phòng, x là tọa độ tương ứng Room(i) = s = start, Room(i + n) = f = finish ; Kind = 1 : start, Kind = 0 : end'
/// Nhét all key vào stack
/// Mỗi lần gặp cuộc hội thảo, lấy ra từng chìa một, mỗi lần kết thúc hội thảo, nhét lại chìa ấy vào stack;
/// Làm đến khi kết thúc tất cả các cuộc hội thảo
/// Key(i) : Chia khoa cho phong i;
/// Phong i dung key j -> ans(j).pb(i)
//-----------------------------------------------------

#define N 200024
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "ROOMS"

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

vector <int> ans[N];
priority_queue <int> PQ; /// max
//priority_queue <int , vector <int>, greater <int> > PQ; /// min
queue <int> Q;
deque <int> DQ;
stack <ll> st;
string s;
bool l;

ll n, res = 0, Key[N];

struct Room
{
    ll ID, kind, coor;
};
Room a[N];

void Init()
{
    cin >> n;
    up(i , 1 , n) {
        ll s, f; cin >> s >> f;
        a[i].coor = s; a[i].kind = 1; a[i].ID = i;
        a[i + n].coor = f; a[i + n].kind = 0; a[i + n].ID = i;
    }

    sort(a + 1, a + n * 2 + 1, [] (const Room &p, const Room &q)
         {
             return p.coor < q.coor || (p.coor == q.coor && p.kind < q.kind);
         });

    down(i , n , 1) st.push(i); /// Nhet all chia vao stack
}
/// cur : so chia khoa hien tai dang dung, res = max of all cur
void Solve()
{
    ll cur = 0;
    up(i , 1 , 2 * n)
    {
        if(a[i].kind == 0) {        /// Ket thuc
            st.push(Key[a[i].ID]);
            cur--;
        }
        else {                      /// Bat dau
            Key[a[i].ID] = st.top();
            ans[st.top()].pb(a[i].ID);
            st.pop();
            cur++;
            res = max(res , cur);
        }
    }
}

void Print()
{
    cout << res << endl;
    up(i , 1 , res) {
        up(j , 0 , ans[i].size() - 1)
            cout << ans[i][j] << " ";
        cout << endl;
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
    Print();
}


