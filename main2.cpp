#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%lld %lld", &n, &q);
        
        long long circles[n][3];
        for (int i = 0; i < n; i++) {
            long long x, y, r;
            scanf("%lld %lld %lld", &x, &y, &r);
            circles[i][0] = x;
            circles[i][1] = y;
            circles[i][2] = r * r;
        }
        
        for (int i = 0; i < q; i++) {
            long long px, py, count = 0;
            scanf("%lld %lld", &px, &py);
            
            for (int j = 0; j < n; j++) {
                long long dx = px - circles[j][0];
                long long dy = py - circles[j][1];
                if (dx * dx + dy * dy <= circles[j][2]) {
                    count++;
                }
            }
            
            printf("%d\n", count);
        }
    }
    
    return 0;
}