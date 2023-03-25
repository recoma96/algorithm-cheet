#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int process_binary_search(vector<int>& arr, int e)
{
    int n = (int)arr.size();
    int left = 0, right = n-1, mid;

    while(left <= right) {
        mid = (left + right) >> 1;
        if(arr[mid] == e)
            return mid;
        else if(arr[mid] > e)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int process_upper_bound(vector<int>& arr, int e)
{
    int n = (int)arr.size();
    int left = 0, right = n-1, mid;

    while(left < right) {
        mid = (left + right) >> 1;
        if(arr[mid] > e) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

int process_lower_bound(vector<int>& arr, int e)
{
    int n = (int)arr.size();
    int left = 0, right = n-1, mid;

    while(left < right) {
        mid = (left + right) >> 1;
        if(arr[mid] >= e) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// 검증 코드
// TMI: C++에서는 이분탐색, upper bound, lower bound 전부 다 지원한다.
int main()
{
    vector<int> arr = {1,2,3,3,5,7,8,9};
    int n = (int)arr.size();
    int output, answer;

    // upper bound
    for(int e = 0; e <= 8; e++) {
        output = arr[process_upper_bound(arr, e)];
        answer = *upper_bound(arr.begin(), arr.end(), e);
        assert(output == answer);
    }

    // lower bound
    for(int e = 0; e <= 9; e++) {
        output = arr[process_lower_bound(arr, e)];
        answer = *lower_bound(arr.begin(), arr.end(), e);
        assert(output == answer);
    }
    return 0;
}

