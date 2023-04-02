#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> seg_tree, lazy;

void segtree_init(int n)
{
    seg_tree = vector<long long>(1 << (int)ceil(log2((double)n+2)) + 1);
    lazy = vector<long long>(1 << (int)ceil(log2((double)n+2)) + 1);
}

void segtree_update(const int start, const int end, const long long delta, int root, int left, int right)
{
    // Lazy값 Loading
    seg_tree[root] += lazy[root] * (right - left + 1);
    if(left != right) {
        // lazy값이 있으면 하위노드로 전파
        lazy[root<<1] += lazy[root];
        lazy[(root<<1)+1] += lazy[root];
    }
    lazy[root] = 0;

    // 범위 밖
    if(end < left || right < start) return;

    // Delta값 갱신
    seg_tree[root] += delta * (min(end, right) - max(start, left) + 1);
    if(left != right) {
        // 탐색 필요 없음
        if(start <= left && right <= end) {
            // 자식 노드에 delta값을 lazy값으로 전파
            lazy[root<<1] += delta;
            lazy[(root<<1)+1] += delta;
        } else {
            // 추가 탐새 필요
            int mid = (left + right) >> 1;
            segtree_update(start, end, delta, root<<1, left, mid);
            segtree_update(start, end, delta, (root<<1)+1, mid+1, right);
        }
    }
}

long long segtree_sum(const int start, const int end, int root, int left, int right)
{
    // lazy값 Loading
    seg_tree[root] += lazy[root] * (right - left + 1);
    if(left != right) {
        // 하위 노드로 전파
        lazy[root<<1] += lazy[root];
        lazy[(root<<1)+1] += lazy[root];
    }
    lazy[root] = 0;

    if(end < left || right < start) return 0;
    
    if(start <= left && right <= end) {
        return seg_tree[root];
    } else {
        int mid = (left + right) >> 1;
        return segtree_sum(start, end, root<<1, left, mid)
                + segtree_sum(start, end, (root<<1)+1, mid+1, right);
    }
}