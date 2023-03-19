long long gcd(long long n) {
    long long res = n;
    for(long long k = 2; k*k <= n; k++) {
        if(n%k == 0) {
            res *= (1 - (1/(double)k));
            while(n%k == 0) n /= k;
        }
    }
    if(n > 1)
        res *= (1 - (1/(double)n));

    return res;
}