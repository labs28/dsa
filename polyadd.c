#include <stdio.h>

int main() {
    int degree;
    printf("Enter the highest degree of the polynomials: ");
    scanf("%d", &degree);

    int poly1[10], poly2[10], sum[10];

    // Accept first polynomial
    printf("Enter coefficients of first polynomial:\n");
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    // Accept second polynomial
    printf("\nEnter coefficients of second polynomial:\n");
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    // Add both polynomials
    for (int i = degree; i >= 0; i--) {
        sum[i] = poly1[i] + poly2[i];
    }

    // Display result
    printf("\nResultant Polynomial after addition:\n");
    for (int i = degree; i >= 0; i--) {
        if (sum[i] != 0) {
            printf("%dx^%d", sum[i], i);
            if (i != 0) printf(" + ");
        }
    }

    printf("\n");
    return 0;
}
