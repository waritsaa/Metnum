#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Fungsi gabungan f(x) = f2(x) - f1(x)
double fx(double x) {
    return pow(x, 3) - pow(x, 2) + 2*x - (x + 2) * exp(-2 * x);
}

int main() {
    double a, b, x, fa, fb, fx_mid, errA;
    double tolEror;
    int maxIterasi;
    int i = 0; // iterasi dimulai dari 0

    // Input nilai awal
    cout << "Masukkan nilai a (batas bawah): "; cin >> a;
    cout << "Masukkan nilai b (batas atas): "; cin >> b;
    cout << "Masukkan nilai toleransi: "; cin >> tolEror;
    cout << "Masukkan nilai iterasi maksimumnya: "; cin >> maxIterasi;

    // Validasi awal
    if (fx(a) * fx(b) > 0) {
        cout << "f(a) dan f(b) tidak memiliki tanda berlawanan. "
             << "Tidak bisa lanjut metode Bisection.\n";
        return 1;
    }
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                      Bisection Method                                          |" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "| I    ||     a      |     b      |     x      |    f(x)    |    f(a)    |    f(b)    |  |b-a|   |" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;

    do {
        x = (a + b) / 2.0;
        fx_mid = fx(x);
        fa = fx(a);
        fb = fx(b);
        errA = fabs(b - a);

        cout << fixed << setprecision(6);
        cout << "| " << setw(4) << i << " || "
             << setw(10) << a << " | "
             << setw(10) << b << " | "
             << setw(10) << x << " | "
             << setw(10) << fx_mid << " | "
             << setw(10) << fa << " | "
             << setw(10) << fb << " | "
             << setw(8) << errA << " |" << endl;

        if (fabs(fx_mid) < tolEror || errA < tolEror) break;

        if (fa * fx_mid < 0)
            b = x;
        else
            a = x;

        i++;
    } while (i <= maxIterasi);

    cout << "--------------------------------------------------------------------------------------------------" << endl;

    if (i > maxIterasi) {
        cout << "\nProses berhenti karena mencapai iterasi maksimum.\n";
    }

    cout << "Akar persamaan ditemukan pada x = " << x
         << " dengan f(x) = " << fx_mid << endl;

    return 0;
}
