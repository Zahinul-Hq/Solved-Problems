#include <iostream>
#include <cmath>

#define error 0.00001

float f(float p[], int n, float x) {
    float result = 0;
    for (int i = 0; i <= n; i++) {
        result = result * x + p[i];
    }
    return result;
}

int main() {
    std::cout << "\nEnter the highest degree of the equation: ";
    int n, i;
    std::cin >> n;

    float a, b, x0, x1, x2, f0, f1, f2, e, ds = 0.1;

    float coeff[n + 1];

    std::cout << "\nEnter values of coefficients: ";
    for (i = 0; i <= n; i++) {
        std::cout << "\nCoefficient x^" << n - i << " = ";
        std::cin >> coeff[i];
    }

    float xmax = sqrt(pow((coeff[1] / coeff[0]), 2) - 2 * (coeff[2] / coeff[0]));
    std::cout << "Possible interval " << -xmax << " and " << xmax << "\n";
    b = xmax;
    for (a = -xmax; a <= xmax; a += 0.005) {
        int itrCount = 0;
        int rootCount = 1;
        float err;
        x0 = a;
        x1 = x0 + ds;

        std::cout << "Number of Root\tApproximate Root\tNumber of Iteration\tRelative Error\n";
        while (x1 < b) {
            x0 = a;
            x1 = x0 + ds;
            f0 = f(coeff, n, x0);
            f1 = f(coeff, n, x1);

            if (f0 * f1 > 0) {
                //std::cout << "Wrong Guess\n";
            } else {
                do {
                    x2 = (x0 + x1) / 2;
                    f2 = f(coeff, n, x2);

                    if ((f0 * f2) < 0) {
                        x1 = x2;
                    } else {
                        x0 = x2;
                        //f0 = f2;
                    }
                    err = fabs((x1 - x0) / x1);

                } while (fabs((x1 - x0) / x1) >= error);

                std::cout << rootCount << "\t\t" << x2 << "\t\t" << itrCount << "\t\t\t" << err << "\n";
                rootCount++;
                if (x1 > b) {
                    break;
                }
            }
            itrCount++;
            a = x1;
        }
    }
    return 0;
}
