#include <iostream>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long paisano(long long m)
{
    long firs = 0, secon = 1;
    for(long i = 1; i < m*m; i++)
    {
        long long res = (firs + secon) % m;
        firs = secon; 
        secon = res;
        if(firs == 0 && secon == 1) return i;
    }
    return 0;
}

long long biggie_fibonacci(long long n, long long m)
{
    long prd = n%paisano(m);

    long f = 0, s = 1, res;
    for(long i = 0; i < prd ; i++)
    {
        res = (f+s) % m;
        s = f;
        f = res;
    }

    return res % m;
}

int main() {
    // cout << paisano(3) << endl;
    long long n, m;
    std::cin >> n >> m;
    std::cout << biggie_fibonacci(n, m) << '\n';
}
