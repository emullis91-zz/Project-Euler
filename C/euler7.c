#include <stdio.h>
#include <math.h>
int trialdiv(int n) {
    int i;
    if(n <= 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        for (i = 3; i < (int)sqrt(n) + 1; i += 2) {
            if (n % i == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    int limit = 10001;
    int n;
    int count = 1;
    for(n = 3; count < limit; n += 2) {
        if (trialdiv(n)) {
            count++;
        }
    }
    printf("%d\n", n-2);
}
