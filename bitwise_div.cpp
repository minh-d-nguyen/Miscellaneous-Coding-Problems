#include<iostream>
using namespace std;
int divide(int dividend, int divisor);
unsigned int ui_div(unsigned numer, unsigned denom);

int main()
{
    cout << divide(3, 2) << endl;
    return 0;
}

int divide(int dividend, int divisor) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if ((dividend == -2147483648 && divisor == -1) || divisor == 0) {
        return  INT_MAX;
    }
    unsigned numer, denom;
    numer = abs(dividend);
    denom = abs(divisor);
    unsigned result = ui_div(numer, denom);
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
        if(result*denom == numer) return - result;
        else return - result - 1;
    }
    return result;
}

unsigned int ui_div(unsigned numer, unsigned denom)
{
    unsigned num_bits_numer = 0;
    unsigned num_bits_denom = 0;
    unsigned result = 0;
    if (numer == 0) return result;
    unsigned temp = numer;
    while (temp != 0) {
        num_bits_numer += 1;
        temp >>= 1;
    }
    cout << "Numer bits: " << num_bits_numer << endl;
    temp = denom;
    while (temp != 0) {
        num_bits_denom += 1;
        temp >>= 1;
    }
    cout << "Denom bits: " << num_bits_denom << endl;

    if (num_bits_numer < num_bits_denom) return 0;
    denom <<= (num_bits_numer - num_bits_denom);
    while (numer > 0) {
        cout << numer << " " << denom << " " << result << endl;
        int t = numer - denom;
        if (t >= 0) {
            result += 1;
            numer = t;
        }
        result <<= 1;
        numer <<= 1;
    }
    return (result >> (num_bits_numer - num_bits_denom + 1));
}