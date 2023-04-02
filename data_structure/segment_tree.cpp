#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> seg_tree;

void segtree_init(int n)
{
    seg_tree = vector<long long>(1 << (int)ceil(log2((double)n+2)) + 1);
}
void segtree_update(const int idx, const long long delta, int root, int left, int right)
{
    if(idx < left || idx > right) return;
    seg_tree[root] += delta;
    
    int mid = (left + right) >> 1;
    if(left != right) {
        segtree_update(idx, delta, root<<1, left, mid);
        segtree_update(idx, delta, (root<<1)+1, mid+1, right);
    }
}
long long segtree_sum(const int start, const int end, int root, int left, int right)
{
    if(end < left || right < start) return 0;
    else if(start <= left && right <= end) return seg_tree[root];
    else {
        int mid = (left + right) >> 1;
        return segtree_sum(start, end, root<<1, left, mid)
                + segtree_sum(start, end, (root<<1)+1, mid+1, right);
    }
}
