#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

struct Production {
    char left;
    vector<char> rigths;
    bool operator==(Production& rhs) const {
        if (left != rhs.left)
            return false;
        for (int i = 0; i < rigths.size(); i++) {
            if (i >= rhs.rigths.size())
                return false;
            if (rigths[i] != rhs.rigths[i])
                return false;
        }
        return true;
    }
};

struct LR1Item {
    Production p;
    int location;
    char next;
};

struct LR1Items {
    vector<LR1Item> items;
};

struct CanonicalCollection {
    vector<LR1Items> items;
    vector< pair<int, char> > g[100];
}CC;

struct Grammar {
    int num;  //
    vector<char> T;   //
    vector<char> N;   //
    vector<Production> prods;  //
}grammar;

map<char, set<char> > first;
map<char, set<char> > follow;

queue< pair<LR1Items, int> > Q;

pair<int, int> action[100][100]; //
int goton[100][100];

string str;
stack< pair<int, char> > ST; //

int isInT(char ch)
{
    for (int i = 0; i < grammar.T.size(); i++) {
        if (grammar.T[i] == ch) {
            return i + 1;
        }
    }
    return 0;
}
int isInN(char ch)
{
    for (int i = 0; i < grammar.N.size(); i++) {
        if (grammar.N[i] == ch) {
            return i + 1;
        }
    }
    return 0;
}
void getFirstSet()
{
    for (int i = 0; i < grammar.T.size(); i++) {
        char X = grammar.T[i];
        set<char> tmp;
        tmp.insert(X);
        first[X] = tmp;
    }
    bool change = true;
    while (change) {
        change = false;
        for (int i = 0; i < grammar.prods.size(); i++) {
            Production& P = grammar.prods[i];
            char X = P.left;
            set<char>& FX = first[X];
            if (isInT(P.rigths[0]) || P.rigths[0] == '&') {
                auto it = FX.find(P.rigths[0]);
                if (it == FX.end()) {
                    change = true; //
                    FX.insert(P.rigths[0]);
                }
            }
            else {
                bool next = true;
                int idx = 0;
                while (next && idx < P.rigths.size()) {
                    next = false;
                    char Y = P.rigths[idx];
                    set<char>& FY = first[Y];
                    for (auto it = FY.begin(); it != FY.end(); it++) {
                        if (*it != '&') {
                            auto itt = FX.find(*it);
                            if (itt == FX.end()) {
                                change = true;
                                FX.insert(*it);
                            }
                        }
                    }
                    auto it = FY.find('&');
                    if (it != FY.end()) {
                        next = true;
                        idx = idx + 1;
                    }
                }

            }
        }
    }

    printf("FIRST:\n");
    for (int i = 0; i < grammar.N.size(); i++) {
        char X = grammar.N[i];
        printf("%c: ", X);
        for (auto it = first[X].begin(); it != first[X].end(); it++) {
            printf("%c ", *it);
        }
        printf("\n");
    }
}
void getFirstByAlphaSet(vector<char>& alpha, set<char>& FS)
{
    bool next = true;
    int idx = 0;
    while (idx < alpha.size() && next) {
        next = false;
        if (isInT(alpha[idx]) || alpha[idx] == '&') {
            auto itt = FS.find(alpha[idx]);
            if (itt == FS.end()) {
                FS.insert(alpha[idx]);
            }
        }
        else {
            char B = alpha[idx];
            set<char>& FB = first[B];
            for (auto it = first[B].begin(); it != first[B].end(); it++) {
                if (*it == '&') {
                    next = true;
                    continue;
                }
                auto itt = FS.find(*it);
                if (itt == FS.end()) {
                    FS.insert(*it);
                }
            }
        }
        idx = idx + 1;
    }
    if (next) {
        FS.insert('&');
    }
}

bool isInLR1Items(LR1Items& I, LR1Item& t)
{
    for (auto it = I.items.begin(); it != I.items.end(); it++) {
        LR1Item& item = *it;
        if (item.p == t.p && item.location == t.location && item.next == t.next)
            return true;
    }
    return false;
}

void printLR1Items(LR1Items& I)
{
    for (auto it = I.items.begin(); it != I.items.end(); it++) {
        LR1Item& L = *it;
        printf("%c->", L.p.left);
        for (int i = 0; i < L.p.rigths.size(); i++) {
            if (L.location == i)
                printf(".");
            printf("%c", L.p.rigths[i]);
        }
        if (L.location == L.p.rigths.size())
            printf(".");
        printf(",%c   ", L.next);
    }
    printf("\n");
}

void closure(LR1Items& I)
{
    bool change = true;
    while (change) {
        change = false;
        LR1Items J;
        J.items.assign(I.items.begin(), I.items.end());
        for (auto it = J.items.begin(); it != J.items.end(); it++) {
            LR1Item& L = *it;
            if (L.location < L.p.rigths.size()) {
                char B = L.p.rigths[L.location];
                if (isInN(B)) {

                    set<char> FS;
                    vector<char> alpha;
                    alpha.assign(L.p.rigths.begin() + L.location + 1, L.p.rigths.end());
                    alpha.push_back(L.next);
                    getFirstByAlphaSet(alpha, FS);

                    for (int i = 0; i < grammar.prods.size(); i++) {
                        Production& P = grammar.prods[i];
                        if (P.left == B) {
                            for (auto it = FS.begin(); it != FS.end(); it++) {
                                char b = *it;
                                LR1Item t;
                                t.location = 0;
                                t.next = b;
                                t.p.left = P.left;
                                t.p.rigths.assign(P.rigths.begin(), P.rigths.end());
                                if (!isInLR1Items(I, t)) {
                                    change = true;
                                    I.items.push_back(t);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int isInCanonicalCollection(LR1Items& I)
{
    for (int i = 0; i < CC.items.size(); i++) {
        LR1Items& J = CC.items[i];
        bool flag = true;
        if (J.items.size() != I.items.size()) {
            flag = false;
            continue;
        }
        for (auto it = I.items.begin(); it != I.items.end(); it++) {
            LR1Item& t = *it;
            if (!isInLR1Items(J, t)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i + 1;
        }
    }
    return 0;
}

void go(LR1Items& I, char X, LR1Items& J)
{
    for (auto it = I.items.begin(); it != I.items.end(); it++) {
        LR1Item& L = *it;
        if (L.location < L.p.rigths.size()) {
            char B = L.p.rigths[L.location];
            if (B == X) {
                LR1Item t;
                t.location = L.location + 1;
                t.next = L.next;
                t.p.left = L.p.left;
                t.p.rigths.assign(L.p.rigths.begin(), L.p.rigths.end());
                J.items.push_back(t);
            }
        }
    }
    if (J.items.size() > 0) {
        closure(J);
    }
}

void DFA()
{
    LR1Item t;
    t.location = 0;
    t.next = '$';
    t.p.left = grammar.prods[0].left;
    t.p.rigths.assign(grammar.prods[0].rigths.begin(), grammar.prods[0].rigths.end());
    LR1Items I;
    I.items.push_back(t);
    closure(I);
    CC.items.push_back(I);
    Q.push(pair<LR1Items, int>(I, 0));
    while (!Q.empty()) {
        LR1Items& S = Q.front().first;
        int sidx = Q.front().second;
        for (int i = 0; i < grammar.T.size(); i++) {
            LR1Items D;
            go(S, grammar.T[i], D);
            int idx;
            if (D.items.size() > 0) {
                idx = isInCanonicalCollection(D);
                if (idx > 0) {
                    idx = idx - 1;
                }
                else {
                    idx = CC.items.size();
                    CC.items.push_back(D);
                    Q.push(pair<LR1Items, int>(D, idx));
                }
                CC.g[sidx].push_back(pair<char, int>(grammar.T[i], idx));
            }
        }
        for (int i = 0; i < grammar.N.size(); i++) {
            LR1Items D;
            go(S, grammar.N[i], D);
            int idx;
            if (D.items.size() > 0) {
                idx = isInCanonicalCollection(D);
                if (idx != 0) {
                    idx = idx - 1;
                }
                else {
                    idx = CC.items.size();
                    CC.items.push_back(D);
                    Q.push(pair<LR1Items, int>(D, idx));
                }
                CC.g[sidx].push_back(pair<char, int>(grammar.N[i], idx));
            }
        }
        Q.pop();
    }

    printf("CC size: %d\n", CC.items.size());
    for (int i = 0; i < CC.items.size(); i++) {
        printf("LR1Items %d:\n", i);
        printLR1Items(CC.items[i]);
        for (int j = 0; j < CC.g[i].size(); j++) {
            pair<char, int> p = CC.g[i][j];
            printf("to %d using %c\n", p.second, p.first);
        }
    }
}
void productLR1AnalysisTabel()
{
    for (int i = 0; i < CC.items.size(); i++) {
        LR1Items& LIt = CC.items[i];
        for (auto it = LIt.items.begin(); it != LIt.items.end(); it++) {
            LR1Item& L = *it;
            if (L.location < L.p.rigths.size()) {
                char a = L.p.rigths[L.location];
                int j = isInT(a);
                if (j > 0) {
                    j = j - 1;
                    for (int k = 0; k < CC.g[i].size(); k++) {
                        pair<char, int> p = CC.g[i][k];
                        if (p.first == a) {
                            action[i][j].first = 1; // 1->S
                            action[i][j].second = p.second;  //
                            break;
                        }
                    }
                }
            }
            else { //
                if (L.p.left == grammar.prods[0].left) {
                    if (L.next == '$')
                        action[i][grammar.T.size() - 1].first = 3;
                }
                else {
                    int  j = isInT(L.next) - 1;
                    for (int k = 0; k < grammar.prods.size(); k++) {
                        if (L.p == grammar.prods[k]) {
                            action[i][j].first = 2;
                            action[i][j].second = k;
                            break;
                        }
                    }

                }
            }
        }
        for (int k = 0; k < CC.g[i].size(); k++) {
            pair<char, int> p = CC.g[i][k];
            char A = p.first;
            int j = isInN(A);
            if (j > 0) {
                j = j - 1;
                goton[i][j] = p.second; //
            }
        }
    }
    for (int i = 0; i < grammar.T.size() / 2; i++)
        printf("\t");
    printf("action");
    for (int i = 0; i < grammar.N.size() / 2 + grammar.T.size() / 2 + 1; i++)
        printf("\t");
    printf("goto\n");
    printf("\t");
    for (int i = 0; i < grammar.T.size(); i++) {
        printf("%c\t", grammar.T[i]);
    }
    printf("|\t");
    for (int i = 1; i < grammar.N.size(); i++) {
        printf("%c\t", grammar.N[i]);
    }
    printf("\n");
    for (int i = 0; i < CC.items.size(); i++) {
        printf("%d\t", i);
        for (int j = 0; j < grammar.T.size(); j++) {
            if (action[i][j].first == 1) {
                printf("%c%d\t", 'S', action[i][j].second);
            }
            else if (action[i][j].first == 2) {
                printf("%c%d\t", 'R', action[i][j].second);
            }
            else if (action[i][j].first == 3) {
                printf("ACC\t");
            }
            else {
                printf("\t");
            }
        }
        printf("|\t");
        for (int j = 1; j < grammar.N.size(); j++) {
            if (goton[i][j]) {
                printf("%d\t", goton[i][j]);
            }
            else {
                printf("\t");
            }

        }
        printf("\n");
    }
}


void initGrammar()
{
    printf("Please enter the num of production:\n");
    cin >> grammar.num;
    string s;
    printf("Please enter the production:\n");
    for (int i = 0; i < grammar.num; i++) {
        cin >> s;
        Production tmp;
        tmp.left = s[0];
        for (int j = 3; j < s.size(); j++) {
            tmp.rigths.push_back(s[j]);
        }
        grammar.prods.push_back(tmp);
    }
    printf("Please enter the non-terminators(end with #):\n");
    char ch;
    cin >> ch;
    while (ch != '#') {
        grammar.N.push_back(ch);
        cin >> ch;
    }
    printf("Please enter the terminators(end with #):\n");
    cin >> ch;
    while (ch != '#') {
        grammar.T.push_back(ch);
        cin >> ch;
    }
    grammar.T.push_back('$');
    getFirstSet();

    DFA();
    productLR1AnalysisTabel();

    printf("Please enter the String to be analyzed:\n");
    cin >> str;
    str += '$';
    ST.push(pair<int, char>(0, '-'));
}
void process()
{
    int ip = 0;
    printf("The ans:\n");
    do {
        int s = ST.top().first;
        char a = str[ip];
        int j = isInT(a) - 1;
        if (action[s][j].first == 1) {
            ST.push(pair<int, char>(action[s][j].second, a));
            ip = ip + 1;
        }
        else if (action[s][j].first == 2) { //
            Production& P = grammar.prods[action[s][j].second];
            printf("%c->", P.left);
            for (int i = 0; i < P.rigths.size(); i++) {
                ST.pop();
                printf("%c", P.rigths[i]);
            }
            printf("\n");
            s = ST.top().first;
            char A = P.left;
            j = isInN(A) - 1;
            ST.push(pair<int, char>(goton[s][j], A));
        }
        else if (action[s][j].first == 3) {   //
            printf("All good!\n");
            return;
        }
        else {
            printf("Error!\n");
            return;
        }
    } while (1);
}
int main()
{
    initGrammar();
    process();
    return 0;
}
