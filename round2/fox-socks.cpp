#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

#define MAXN 1000000
#define MOD 1000000000

using namespace std;

int n;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }

// --- begin segment tree ---

template<class Node, class Op> struct SegTree {
  int size;
  vector<Node> tree;
  vector<bool> hasPending;
  vector<Op> pending;

  SegTree(int n) {
    size = n;
    tree.resize(4 * n + 1);
    hasPending.resize(4 * n + 1);
    pending.resize(4 * n + 1);
  }

  inline int left(int node) { return 2 * node; }
  inline int right(int node) { return 2 * node + 1; }

  void build(int* arr, int node, int st, int end) {
    if (st == end) { tree[node] = Node(st, arr[st]); return; }

    build(arr, left(node), st, (st + end) / 2);
    build(arr, right(node), (st + end) / 2 + 1, end);
    tree[node] = tree[left(node)].join(tree[right(node)]);
  }

  void applyPending(int node, int st, int end) {
    if(hasPending[node]) {
      update(left(node), st, (st + end) / 2, st, end, pending[node]);
      update(right(node), (st + end) / 2 + 1, end, st, end, pending[node]);
      hasPending[node] = false;
    }
  }

  Node query(int node, int st, int end, int i, int j) {
    if (j < st || i > end) return Node();
    if (st >= i && end <= j) return tree[node];

    applyPending(node, st, end);
    Node p1 = query(left(node), st, (st + end) / 2, i, j);
    Node p2 = query(right(node), (st + end) / 2 + 1, end, i, j);
    return p1.join(p2);
  }

  ll update(int node, int st, int end, int i, int j, Op op) {
    if (j < st || i > end) return 0;
    if (st == end) { return op.apply(tree[node], st, end); }
    if (st >= i && end <= j) {
      ll res = op.apply(tree[node], st, end);
      pending[node] = hasPending[node] ? pending[node].merge(op, st, end) : op;
      hasPending[node] = true;
      return res;
    }
    applyPending(node, st, end);
    ll res = 0;
    if(i <= (st + end) / 2) res = madd(res, update(left(node), st, (st + end) / 2, i, j, op));
    if(j > (st + end) / 2) res = madd(res, update(right(node), (st + end) / 2 + 1, end, i, j, op));
    tree[node] = tree[left(node)].join(tree[right(node)]);
    return res;
  }

  void build(int* arr) { build(arr, 1, 0, size - 1); }
  Node query(int i, int j) { return query(1, 0, size - 1, i, j); }
  ll update(int i, int j, Op op) { return update(1, 0, size - 1, i, j, op); }
};

// --- end segment tree ---

struct Node {
  ll total, odd0, odd1;

  Node(): total(0), odd0(0), odd1(0) {}
  Node(int idx, ll bin): total(bin), odd0(idx % 2 == 0 ? bin % 2 : 0),
                         odd1(idx % 2 == 1 ? bin % 2 : 0) {}
  Node(ll t, ll o0, ll o1): total(t), odd0(o0), odd1(o1) {}

  ll odd() { return odd0 + odd1; }

  Node join(Node& o) {
    return Node(madd(total, o.total), odd0 + o.odd0, odd1 + o.odd1);
  }
};

struct Op {
  ll x0, m, b; bool del;

  Op() {} // nop
  Op(ll _x0, ll _m, ll _b, bool _del): x0(_x0), m(_m), b(_b), del(_del) {}

  ll calcY0(int st) {
    return madd(mmul(m, st >= x0 ? st - x0 : (n - x0) + st), b);
  }

  ll apply(Node& node, int st, int end) {
    ll size = end - st + 1;
    ll odd0Max = (size + (st % 2 == 0)) / 2, odd1Max = size - odd0Max;

    ll res = 0;
    if(del) {
      res = node.total;
      node.total = node.odd0 = node.odd1 = 0;
    }

    ll y0 = calcY0(st);
    ll toAdd = madd(mmul(size, y0), mmul(size * (size - 1) / 2 % MOD, m));
    node.total = madd(node.total, toAdd);
    res = madd(res, toAdd);

    if(m % 2) {
      if(y0 % 2 == st % 2) node.odd1 = odd1Max - node.odd1;
      else node.odd0 = odd0Max - node.odd0;
    } else if(y0 % 2) {
      node.odd0 = odd0Max - node.odd0;
      node.odd1 = odd1Max - node.odd1;
    }
    return res;
  }

  Op merge(Op& op, int st, int end) {
    if(op.del) return op;
    return Op(st, madd(m, op.m), madd(calcY0(st), op.calcY0(st)), del);
  }
};

ll v1[6], v2[6], x[6], y[6], z[6];

ll mod[] = { MOD, 4, 0, 0, MOD, MOD }, adder[] = { 0, 1, 1, 1, 0, 0 };
int arr[MAXN];

ll next(int vi, int mi) {
  if(mi == 0) return v1[vi];
  if(mi == 1) return v2[vi];
  ll v = x[vi] * v1[vi] % mod[vi] + y[vi] * v2[vi] % mod[vi] + z[vi];
  v = v % mod[vi] + adder[vi];
  v1[vi] = v2[vi]; v2[vi] = v; return v;
}

ll applyOp(SegTree<Node, Op>& tree,
           int o, int a, int c, int d, int st, int end) {
  switch(o) {
    case 1: return tree.update(st, end, Op(a, d, c, false));
    case 2: return tree.update(st, end, Op(a, 0, c, true));
    case 3: return tree.query(st, end).total;
    case 4: return tree.query(st, end).odd();
    default: return -1;
  }
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int m; cin >> n >> m;

    for(int i = 0; i < 6; i++)
      cin >> v1[i] >> v2[i] >> x[i] >> y[i] >> z[i];

    for(int i = 0; i < n; i++)
      arr[i] = next(0, i);

    mod[2] = mod[3] = n;

    SegTree<Node, Op> tree(n);
    tree.build(arr);

    ll val = 0;
    for(int i = 0; i < m; i++) {
      int o = next(1, i), a = next(2, i) - 1, b = next(3, i),
        c = next(4, i), d = next(5, i);

      int st = a, end = (st + b - 1) % n;
      if(end >= st) {
        val = madd(val, applyOp(tree, o, a, c, d, st, end));
      } else {
        val = madd(val, applyOp(tree, o, a, c, d, st, n - 1));
        val = madd(val, applyOp(tree, o, a, c, d, 0, end));
      }
    }
    cout << "Case #" << tc << ": " << val << endl;
  }
  return 0;
}
