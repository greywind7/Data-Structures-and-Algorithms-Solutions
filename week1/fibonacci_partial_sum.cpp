#include <iostream>
#include <vector>
using std::vector;
using namespace std;
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

int get_fibonacci_last_digit(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        previous%=10;
        current%= 10;
    }

    return current;
}

long long biggie_fibonacci_sum_prdnv(long long m, long long n)
{
    long prd = paisano(10);
    vector<long long> prd_vals{-1,1,1};
    // cout << 1 <<  " " << 1 << " ";
    for (int i = 3; i <= prd; i++)
    {
        prd_vals.push_back(get_fibonacci_last_digit(i));
        // cout << get_fibonacci_last_digit(i) << " ";
    }
    // cout << endl;
    long long sum = 0;

    for (int i = m; i <= n; i++)
    {   
        long long ind = i%prd == 0 ? prd : i%prd;
        sum += prd_vals[ind];
        sum%=10;
        // cout << sum << " ";
        
    }
    return sum;
}

long long biggie_fibonacci_sum(long long n, long long m = 10)
{
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

long long biggie_fibonacci_sum_prd(long long m, long long n)
{
    return ( biggie_fibonacci_sum(n) - biggie_fibonacci_sum(m-1) + 10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << biggie_fibonacci_sum_prd(from, to) << '\n';
}
