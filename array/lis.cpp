#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int>& a, int n)
{
    vector<int> cache;

    for(int i = 0; i < n; i++) {
        int e = a[i];
        if(i == 0 || cache[cache.size()-1] < e)
            cache.push_back(e);
        else
            cache[lower_bound(cache.begin(), cache.end(), e) - cache.begin()] = e;
    }
    return (int)cache.size();
}