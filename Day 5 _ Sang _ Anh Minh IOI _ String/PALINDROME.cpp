#include <bits/stdc++.h>

//-----------------------------------------------------
/// SOL
///
///
//-----------------------------------------------------

#define N 200006
#define M 1000000007
#define oo 1000000000

#define up(i , a , b) for(int i = a ; i <= b; i++)
#define down(i , a , b) for (int i = a; i >= b; i--)

#define II pair <int, int>
#define III pair<int, pair<int, int> >

#define pb push_back
#define mp make_pair

#define endl '\n'
#define TITLE "PALINDROME"

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
bool l;

ll n, HashR[N], HashL[N], Pow26[N];

struct T
{

};

void Build()
{
    Pow26[0] = 1;
    up(i , 1 , N) {Pow26[i] = (Pow26[i - 1] * 26) % M; cout << Pow26[i] << " ";}
    cout<<endl;
}

void Init()
{
    cin >> s;
    n = s.length();

}
const char DUMMY = '@';

    int manacher(string s) {
  // Để tránh phải xét riêng trường hợp độ dài xâu đối xứng chẵn / lẻ,
  // ta thêm 1 ký tự DUMMY vào giữa các ký tự của s.
  // CHÚ Ý: Phải đảm bảo DUMMY không có trong xâu s

	int n = s.size() * 2 - 1;
	vector <int> f = vector <int>(n, 0);

  // Tạo xâu a bằng cách chèn ký tự DUMMY vào giữa các ký tự của s.
  // Ví dụ:
  // s = aabcb
  // a = a.a.b.c.b
	string a = string(n, DUMMY);
	for (int i = 0; i < n; i += 2) a[i] = s[i / 2];

	int l = 0, r = -1, center, res = 0;
	for (int i = 0, j = 0; i < n; i++) {
		j = (i > r ? 0 : min(f[l + r - i], r - i)) + 1;
		//cout << j << " " << f[l + r - i] << " " << l + r - i << " " << l << " " << r <<  endl;
		while (i - j >= 0 && i + j < n && a[i - j] == a[i + j]) j++;
		f[i] = --j;
		if (i + j > r) {
			r = i + j;
			l = i - j;
		}

		int len = (f[i] + i % 2) / 2 * 2 + 1 - i % 2;
		if (len > res) {
			res = len;
			center = i;
		}
	}
  // Với mỗi vị trí i, xâu đối xứng dài nhất nhận i là tâm là [i - f[i], i + f[i]].
  // Ví dụ:
  // s = aabcb
  // a = a.a.b.c.b
  // f = 011010200
	return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen(TITLE".INP", "r", stdin);
    //freopen(TITLE".OUT", "w", stdout);


    Init();
    cout << manacher(s);
}



