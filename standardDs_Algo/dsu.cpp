#include <bits/stdc++.h>
using namespace std;

class Dsu {
public:
    int numOfOperations = 0;
    Dsu() {}
};

class DsuSimple: public Dsu {
    /// fast union slow find
public:
    vector<int> parent; //values are parent of index
    DsuSimple(int size): parent{vector<int>(size)} {
        for (int i=0; i<parent.size(); i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        numOfOperations++;
        if (parent[u] == u) {
            return u;
        }
        return find(parent[u]);
    }
    bool merge(int u, int v) {
        numOfOperations++;
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        parent[pu] = pv;
        return true;
    }

    void print() {
        for (int i=0; i<parent.size(); i++) {
            cout << parent[i] <<", ";
        }
        cout << endl;
        cout << "numOfOperations: " << numOfOperations << endl;
    }
};


class DsuBySize: public Dsu {
    /// Fast union quick find
public:
    vector<int> parent; // positive values are parent of index, negative values are root with size
    DsuBySize(int size): parent{vector<int>(size, -1)} {}
    int find(int u) {
        numOfOperations++;
        if (parent[u] < 0) {
            return u;
        }
        return find(parent[u]);
    }
    bool merge(int u, int v) {
        numOfOperations++;
        int pu = find(u); // will be always negative
        int pv = find(v); // will be always negative
        if (pu == pv) return false;
        if (parent[pu] < parent[pv]) {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        } else {
          parent[pv] += parent[pu];
          parent[pu] = pv;
        }
        return true;
    }

    void print() {
        for (int i=0; i<parent.size(); i++) {
            cout << parent[i] <<", ";
        }
        cout << endl;
        cout << "numOfOperations: " << numOfOperations << endl;
    }
};

class DsuByRank: public Dsu {
public:
    vector<int> parent; // positive values are parent of index, negative values are root with height
    DsuByRank(int size): parent{vector<int>(size, -1)} {}
    int find(int u) {
        numOfOperations++;
        if (parent[u] < 0) return u;
        return find(parent[u]);
    }
    bool merge(int u, int v) {
        numOfOperations++;
        int pu = find(u); // will always be negative
        int pv = find(v); // will always be negative
        if (pu == pv) return false;
        if (parent[pu] < parent[pv]) {
            parent[pv] = pu;
        } else if (parent[pu] > parent[pv]){
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            parent[pv]--;
        }
        return true;
    }

    void print() {
        for (int i=0; i<parent.size(); i++) {
            cout << parent[i] <<", ";
        }
        cout << endl;
        cout << "numOfOperations: " << numOfOperations << endl;
    }
};

class DsuPathCompression: public Dsu {
public:
    vector<int> parent;
    DsuPathCompression(int size): parent{vector<int>(size, -1)} {}
    int find(int u) {
        numOfOperations++;
        if (parent[u] < 0) {
            return u;
        }
        return (parent[u] = find(parent[u]));
    }

    // union by rank
    int merge(int u, int v) {
        numOfOperations++;
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (parent[pu] < parent[pv]) {
            parent[pv] = pu;
        } else if(parent[pu] > parent[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            parent[pv]--;
        }
        return true;
    }

    void print() {
        for (int i=0; i<parent.size(); i++) {
            cout << parent[i] <<", ";
        }
        cout << endl;
        cout << "numOfOperations: " << numOfOperations << endl;
    }
};

class DsuWeighted: public Dsu { // wightedByRank
public:
    vector<int> parent;
    vector<int> weight; // rank/height
    DsuWeighted(int size): parent{vector<int>(size, -1)}, weight(size, 1) {}

    int find(int u) {
        numOfOperations++;
        if (parent[u] < 0) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    bool merge(int u, int v) {
        numOfOperations++;
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (weight[pu] < weight[pv]) {
            parent[pu] = pv;
        } else if (weight[pu] > weight[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            weight[pv]++;
        }
        return true;
    }

    void print() {
        for (int i=0; i<parent.size(); i++) {
            cout << parent[i] << " : " << weight[i] << endl;
        }
        cout << endl;
        cout << "numOfOperations: " << numOfOperations << endl;
    }
};


void testDsu() {
    DsuSimple dsu = DsuSimple(7);
    dsu.merge(0,2);
    dsu.merge(1,2);
    dsu.merge(3,5);
    dsu.merge(4,3);
    dsu.merge(5,6);
    dsu.merge(3,0);
    cout << "Dsu Generoc:" <<endl;
    cout << dsu.find(3) << endl;
    cout << dsu.find(4) << endl;
    dsu.print();
}

void testDsuBySize() {
    DsuBySize dsu = DsuBySize(7);
    dsu.merge(0,2);
    dsu.merge(1,2);
    dsu.merge(3,5);
    dsu.merge(4,3);
    dsu.merge(5,6);
    dsu.merge(3,0);
    cout << "Dsu By Size:" <<endl;
    cout << dsu.find(3) << endl;
    cout << dsu.find(4) << endl;
    dsu.print();
}

void testDsuByRank() {
    DsuByRank dsu = DsuByRank(7);
    dsu.merge(0,2);
    dsu.merge(1,2);
    dsu.merge(3,5);
    dsu.merge(4,3);
    dsu.merge(5,6);
    dsu.merge(3,0);
    cout << "Dsu By Rank:" <<endl;
    cout << dsu.find(3) << endl;
    cout << dsu.find(4) << endl;
    dsu.print();
}

void testDsuPathComp() {
    DsuPathCompression dsu = DsuPathCompression(7);
    dsu.merge(0,2);
    dsu.merge(1,2);
    dsu.merge(3,5);
    dsu.merge(4,3);
    dsu.merge(5,6);
    dsu.merge(3,0);
    cout << "Dsu By Path Compression:" <<endl;
    cout << dsu.find(3) << endl;
    cout << dsu.find(4) << endl;
    dsu.print();
}

void testDsuWeighted() {
    DsuWeighted dsu = DsuWeighted(7);
    dsu.merge(0,2);
    dsu.merge(1,2);
    dsu.merge(3,5);
    dsu.merge(4,3);
    dsu.merge(5,6);
    dsu.merge(3,0);
    cout << "Dsu Weighted:" <<endl;
    cout << dsu.find(3) << endl;
    cout << dsu.find(4) << endl;
    dsu.print();
}

int main() {
    testDsu();
    testDsuBySize();
    testDsuByRank();
    testDsuPathComp();
    testDsuWeighted();
}