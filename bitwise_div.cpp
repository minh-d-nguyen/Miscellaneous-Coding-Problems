/* 
Problem: Implement the integer divide operation using bit manipulation
*/
unsigned int ui_div(unsigned numer, unsigned denom);

int divide(int dividend, int divisor) {
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
    temp = denom;
    while (temp != 0) {
        num_bits_denom += 1;
        temp >>= 1;
    }
    
    if (num_bits_numer < num_bits_denom) return 0;
    denom <<= (num_bits_numer - num_bits_denom);
    while (numer > 0) {
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
