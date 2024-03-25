#include <iostream>
#include <vector>

using namespace std;
unsigned long long factorial(int n) 
{
    int x = 1;
    if (n == 0 || n == 1) {
        return 1;
    } else {
        for(int i = n; i > 1; i--)
        {
            x = x * i;
        }
    }
    return x;
}
long long gcd(int a, int b) 
{
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() 
{
    long long a,b;
    cin >> a >> b;

    long long result1, result2;
    result1 = factorial(a);
    result2 = factorial(b);
    int GCD;
    GCD = gcd(result1, result2);
    cout << GCD;

}