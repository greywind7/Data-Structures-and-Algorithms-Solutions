#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        previous%=10;
        current%=10;
        sum += current;
        sum%=10;
    }

    return sum % 10;
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

long long biggie_fibonacci_sum(long long n, long long m)
{
    // This solution works because the sum of the paisano period of 10
    // Has a sum that is divisible by 10
    // Otherwise you would have to calculate the sum of the remainders under modulo m
    // Then multiply that with the number of such periods and then cumpute it under odulo m
    // Then you can continue with the following solution

    long prd = n%paisano(m);
    long long sum = 0;
    long f = 0, s = 1, res;
    for(long i = 0; i < prd ; i++)
    {
        res = (f+s) % m;
        s = f;
        f = res;
        sum += res;
        sum%= m;
    }

    return sum % m;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << biggie_fibonacci_sum(n,10);
}
