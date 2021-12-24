/*
___mennat khoday ra azz o va jall ke taatash mojebe ghorbat ast o be shokr andarash mazide nemat.
___har nafasi ke foro miravad momedde hayatast o chon bar miayad mofarrahe zat.
___pas dar har nafasi 2 nemat mojod ast o bar har nematy shokry vajeb.

___az dast o zabane ke barayad ?
___kaz ohdeye shokrash be dar ayad !


___man be to dami gharar natvanam kard
___va ehsane to ra shomar natvanam kard
####################
___gar bar tane man zaban shavad har moyee
___yek shokre to az hezar natvanam kard

*/

#include <bits/stdc++.h>


#define pb push_back
#define SALI main
#define left(x) ((x)*2)
#define right(x) (((x)*2)+1)
#define fuck(x) cout << #x << " : " << x << "  "
#define shit(x) cout << "fuck " << x << endl;
#define findLowVec(v,x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define findUpVec(v,x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define findLowArr(a,n,x) (lower_bound(a, a+n, x) - a)
#define findUpArr(a,n,x) (upper_bound(a, a+n, x) - a)
//#define int long long

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,char> pic;
typedef long double ld;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p)
{return out << "(" << p.first << ", " << p.second << ")";}

template<class A> ostream& operator <<(ostream& out, const vector<A> &v)
{out << "[";for(int i = 0; i < v.size(); i++) {if(i) out << ", ";out << v[i];}return out << "]";}

template<class A,class B> ostream& operator <<(ostream& out, const set<A,B> &s)
{out << "[";for(auto i = s.begin(); i != s.end(); i++) {out << ", ";out << *i;}return out << "]";}

template<class A> ostream& operator <<(ostream& out, const set<A> &s)
{out << "[";for(auto i = s.begin(); i != s.end(); i++) {out << ", ";out << *i;}return out << "]";}

const int N = 20;
int number_of_back_tracking;
vector<pii> v; // varaibles
int n,m; // size of matrix
int total_pole; // number of pole should placed
int domain[N][3]; // domain[i][j] = 1 : j can be assigned to variable i
// 0 -> -1 +1
// 1 ->  0  0
// 2 -> +1 -1
int assigned[N]; // assigned[i] = -1 : not assigned      assigned[i] = j : j assigned to i
int row_plus[N];// row_plus[i] = 2 : sum + a[i][1 ... m] = 2
int row_neg[N];  // row_neg[i] = 4 : sum - a[i][1 ... m] = 4
int cul_plus[N];// cul_plus[i] = 5 : sum + a[1 ... n][i] = 5
int cul_neg[N];  // cul_neg[i] = 5 : sum - a[1 ... n][i] = 5
int mark[N*N]; // just needed at the start to set coordinates for variables
int a[N][N]; // matrix
int state[N][N]; // shows the current state

int next_var;

void place_variable(int var) /// done
{
    int x = v[var].first;
    int y = v[var].second;
    if(assigned[var] == -1){ // has not assigned yet
        state[x][y] = 2;
        if(a[x][y+1] == a[x][y]){
            state[x][y+1] = 2;
        }
        if(a[x+1][y] == a[x][y]){
            state[x+1][y] = 2;
        }
    }
    if(assigned[var] == 0){
        state[x][y] = -1;
        if(a[x][y+1] == a[x][y]){
            state[x][y+1] = +1;
        }
        if(a[x+1][y] == a[x][y]){
            state[x+1][y] = +1;
        }
    }
    if(assigned[var] == 1){
        state[x][y] = 0;
        if(a[x][y+1] == a[x][y]){
            state[x][y+1] = 0;
        }
        if(a[x+1][y] == a[x][y]){
            state[x+1][y] = 0;
        }
    }
    if(assigned[var] == 2){
        state[x][y] = +1;
        if(a[x][y+1] == a[x][y]){
            state[x][y+1] = -1;
        }
        if(a[x+1][y] == a[x][y]){
            state[x+1][y] = -1;
        }
    }
}

int get_sum_plus_column(int x) /// done
{
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (state[i][x] == 1? 1 : 0);
    }
    return sum;
}

int get_sum_neg_column(int x) /// done
{
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (state[i][x] == -1? 1 : 0);
    }
    return sum;
}
int get_sum_plus_row(int x) /// done
{
    int sum = 0;
    for(int i = 1; i <= m; i++){
        sum += (state[x][i] == 1 ? 1 : 0);
    }
    return sum;
}
int get_sum_neg_row(int x) /// done
{
    int sum = 0;
    for(int i = 1; i <= m; i++){
        sum += (state[x][i] == -1 ? 1 : 0);
    }
    return sum;
}



int get_empty_column(int x) /// done
{
    set<int> s;
    s.clear();
    for(int i = 1; i <= n; i++){
        if(state[i][x] == 2){
            s.insert(a[i][x]);
        }
    }
    int ans = s.size();
    return ans;
}
int get_empty_row(int x) /// done
{
    set<int> s;
    s.clear();
    for(int i = 1; i <= m; i++){
        if(state[x][i] == 2){
            s.insert(a[x][i]);
        }
    }
    int ans = s.size();
    return ans;
}

int fuck_domain()
{

    for(int i = 0; i < v.size(); i++){
        cout << i << " : " << domain[i][0] << " " << domain[i][1] << " " << domain[i][2] << endl;
    }
    return 0;
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        for(int k = 0; k < 3; k++){
            sum += domain[i][k];
        }
    }
    return sum;
}

void update_state() /// done
{
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) state[i][j] = 0;

    for(int i = 0; i < v.size(); i++){
        if(assigned[i] != -1){
            place_variable(i);
        }
    }

}

/// done
bool is_consistant() // check if current state is consistent in every aspects
{
    //update_state();
    int pole = 0;
    for(int i = 0; i < v.size(); i++){
        pole += ((assigned[i] == 0 || assigned[i] == 2) ? 1 : 0);
    }
    int not_assigned = 0;
    for(int i = 0; i < v.size(); i++){
        not_assigned += (assigned[i] == -1 ? 1 : 0);
    }
    if(pole > total_pole){
        return false;
    }
    if(pole + not_assigned < total_pole){
        return false;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(state[i][j] == state[i+1][j] && state[i][j] != 0 && state[i][j] != 2){
                return false;
            }
            if(state[i][j] == state[i][j+1] && state[i][j] != 0 && state[i][j] != 2){
                return false;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int pty = get_empty_row(i);
        int gspr = get_sum_plus_row(i);
        int gsnr = get_sum_neg_row(i);
        if(row_plus[i] < gspr){
            return false;
        }
        if(row_neg[i] < gsnr){
            return false;
        }

        if(row_plus[i] > pty + gspr){
            return false;
        }
        if(row_neg[i] > pty + gsnr){
            return false;
        }

    }
    for(int i = 1; i <= m; i++){
        int pty = get_empty_column(i);
        int gspc = get_sum_plus_column(i);
        int gsnc = get_sum_neg_column(i);
        if(cul_plus[i] < gspc){
            return false;
        }
        if(cul_neg[i] < gsnc){
            return false;
        }

        if(cul_plus[i] > pty + gspc){
            return false;
        }
        if(cul_neg[i] > pty + gsnc){
            return false;
        }

    }

    return true;
}
void print_state() /// done
{
    //update_state();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(state[i][j] == 1){
                cout << "+ ";
            }
            if(state[i][j] == -1){
                cout << "- ";
            }
            if(state[i][j] == 0){
                cout << "0 ";
            }
            if(state[i][j] == 2){
                cout << "2 ";
            }
        }
        cout << endl;
    }
}

bool is_goal() /// done
{
    //update_state();

    for(int i = 1; i <= n; i++){
        if(row_plus[i] != get_sum_plus_row(i)){
            return false;
        }
        if(row_neg[i] != get_sum_neg_row(i)){
            return false;
        }
    }
    for(int i = 1; i <= m; i++){
        if(cul_plus[i] != get_sum_plus_column(i)){
            return false;
        }
        if(cul_neg[i] != get_sum_neg_column(i)){
            return false;
        }
    }
    if(!is_consistant()){
        return false;
    }
    return true;
}

/// done
void pre_process() // at first no assignment is done and all domain are avalible
{
    next_var = -1;
    memset(assigned, -1, sizeof(assigned));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            domain[i][j] = 1;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            state[i][j] = 2;
        }
    }
}

void update_domain(int var) /// done
{
    for(int i = 0; i < 3; i++){
        assigned[var] = i;
        place_variable(var);
        if(is_consistant()){
            domain[var][i] = 1;
        }
        else{
            domain[var][i] = 0;
        }
        assigned[var] = -1;
        place_variable(var);
    }
}
void forward_checking() /// done
{
    for(int i = 0; i < v.size(); i++){
        if(assigned[i] == -1){
            update_domain(i);
        }
    }
}

bool check_arc_consistancy(int x, int d, int y) // if assigned[x] = d then can y be assigned by any consistant value
{
    assigned[x] = d;
    place_variable(x);
    bool arc_consistant = false;
    for(int i = 0; i < 3; i++){
        if(domain[y][i] == 1){
            assigned[y] = i;
            place_variable(y);
            if(is_consistant()){
               arc_consistant = true;
            }
        }
    }
    assigned[x] = -1;
    place_variable(x);
    assigned[y] = -1;
    place_variable(y);
    return arc_consistant;
}
void AC3()
{
    for(int i = 0; i < v.size(); i++){
        if(assigned[i] != -1){
            continue;
        }
        for(int j = 0; j < v.size(); j++){
            if(assigned[j] != -1){
                continue;
            }
            if(i == j){
                continue;
            }
            for(int k = 0; k < 3; k++){
                if(domain[i][k] == 1){
                    if(!check_arc_consistancy(i, k, j)){
                        domain[i][k] = 0;
                    }
                }
            }
        }
    }
}
/// done
int MRV() // returns the index of the next element according to MRV heuristic
{
    int id_var = -1;
    int min_domain_size = 5;
    for(int i = 0; i < v.size(); i++){
        if(assigned[i] != -1){
            continue;
        }
        int sum = 0;
        for(int j = 0; j < 3; j++){
            sum += domain[i][j];
        }
        if(sum < min_domain_size){
            min_domain_size = sum;
            id_var = i;
        }
    }
    return id_var;
}

int constraint_number(int var, int val)
{
    assigned[var] = val;
    place_variable(var);
    forward_checking();
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < 3; j++){
            if(assigned[i] == -1 && i != var){
                sum += domain[i][j];
            }
        }
    }
    assigned[var] = -1;
    place_variable(var);
    return sum;
}

/// done
int no_LCV(int var) // returns the value of the chosen variable according to LCV heuristic
{

    if(var == -1){
        return -1;
    }
    int val = -1;
    int maximum_legal_domain = 0;
    for(int i = 0; i < 3; i++){
        if(domain[var][i] == 1){
            return i;
        }
    }

    return val;
}

vector<pii> LCV(int var)
{
    vector<pii> vals;
    for(int i = 0; i < 3; i++){
        if(domain[var][i] == 1){
            vals.pb(pii(constraint_number(var, i), i));
        }
    }
    forward_checking();
    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());
    return vals;
}

/// done
void back_tracking()
{
    /*
    cout << "hihihihihihih" << endl;
    for(int i = 0; i < v.size(); i++){
        cout << assigned[i] << " ";
    }
    cout << endl;
    print_state();
    cout << endl;
    if(assigned[0] == 1 && assigned[1] == 0 && assigned[2] == 1 && assigned[3] == 1
       && assigned[4] == 2 && assigned[5] == 2 && assigned[6] == 2 && assigned[7] == 1
       && assigned[8] == 2 && assigned[9] == 2 && assigned[10] == 1 && assigned[11] == 2
       && assigned[12] == 1 && assigned[13] == 2 && assigned[14] == 0 && assigned[15] == 1){
        print_state();
        cout << endl;
        fuck(is_goal()) << endl;
    }
    */

    number_of_back_tracking++;
    if(is_goal()){
        print_state();
        fuck(number_of_back_tracking) << endl;
        exit(0);
    }
    forward_checking(); // checks each variable domain
    AC3();
    int id = MRV();
    int value;
    ///*
    while((value = no_LCV(id)) != -1){
        assigned[id] = value;
        place_variable(id);
        back_tracking();
        assigned[id] = -1;
        place_variable(id);
        domain[id][value] = 0;
    }
    //*/
    /*
    vector<pii> vals = LCV(id);
    for(int i = 0; i < vals.size(); i++){
        value = vals[i].second;
        assigned[id] = value;
        place_variable(id);
        back_tracking();
        assigned[id] = -1;
        place_variable(id);
        domain[id][value] = 0;
    }
    */

}

/// done
void read_input()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> row_plus[i];
        total_pole += row_plus[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> row_neg[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> cul_plus[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> cul_neg[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

}

/// done
void find_variable_cordinate()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mark[a[i][j]] == 0){
                v.pb(pii(i,j));
                mark[a[i][j]] = 1;
            }
        }
    }
}
int32_t SALI()
{
    pre_process();
    read_input();
    find_variable_cordinate();
    back_tracking();
    print_state();
    fuck(number_of_back_tracking) << endl;
}

/**< WRITEN BY ALI ADELKHAH */

/*
6 6
1 2 3 1 2 1
1 2 1 3 1 2
2 1 2 2 2 1
2 1 2 2 1 2
1 2 2 3 4 4
1 5 5 3 6 6
7 8 8 9 9 10
7 11 12 12 13 10
14 11 15 15 13 16
14 17 17 18 18 16
*/

/*
10 9
3 4 4 4 0 3 3 3 4 3
3 4 4 3 2 2 2 3 4 4
4 2 3 4 3 3 4 5 3
4 2 4 3 5 1 4 4 4
1 2 3 4 4 5 6 7 7
1 2 3 8 9 5 6 10 10
11 11 12 8 9 13 14 14 15
16 17 12 18 18 13 19 19 15
16 17 20 21 22 22 23 24 25
26 26 20 21 27 27 23 24 25
28 28 29 29 30 30 31 31 32
33 34 35 35 36 36 37 37 32
33 34 38 39 39 40 40 41 42
43 43 38 44 44 45 45 41 42
*/

/*
    if(assigned[0] == 1 && assigned[1] == 0 && assigned[2] == 1 && assigned[3] == 1
       && assigned[4] == 2 && assigned[5] == 2 && assigned[6] == 2 && assigned[7] == 1
       && assigned[8] == 2 && assigned[9] == 2 && assigned[10] == 1 && assigned[11] == 2
       && assigned[12] == 1 && assigned[13] == 2 && assigned[14] == 0 && assigned[15] == 1){
        print_state();
        cout << endl;
        fuck(is_goal()) << endl;
    }
    */

