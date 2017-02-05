/*
 Problem: Given x, n, and d, compute (x^n)%d without using pow function

 Solution approach: We gradually reduce n:
 - If n%2 = 0 we substitute x by (x^2)%d then n=n/2 and continue
 - If n%2 = 1 we substitute the current result by (result*x)%d and n by
   n - 1

 Solution time complexity: O(logn)
 */

int pow_mod(int x, int n, int d) {
           if (n == 0) return 1 % d;

            long long ans = 1, base = x;
            while (n > 0) {
                // We need (base ** n) % p. 
                // Now there are 2 cases. 
                // 1) n is even. Then we can make base = base^2 and n = n / 2.
                // 2) n is odd. So we need base * base^(n-1) 
                if (n % 2 == 1) {
                    ans = (ans * base) % d;
                    n--;
                } else {
                    base = (base * base) % d;
                    n /= 2;
                }
            }
            if (ans < 0) ans = (ans + d) % d;
            return ans;
 
}
