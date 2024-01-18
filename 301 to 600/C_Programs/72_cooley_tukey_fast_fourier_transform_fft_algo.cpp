#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

typedef complex<double> Complex;

void fft(vector<Complex> &a, bool invert)
{
    int n = a.size();
    if (n <= 1)
    {
        return;
    }

    vector<Complex> a0(n / 2), a1(n / 2);
    for (int i = 0, j = 0; i < n; i += 2, ++j)
    {
        a0[j] = a[i];
        a1[j] = a[i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double angle = 2 * M_PI / n * (invert ? -1 : 1);
    Complex w(1), wn(cos(angle), sin(angle));

    for (int i = 0; i < n / 2; ++i)
    {
        Complex t = w * a1[i];
        a[i] = a0[i] + t;
        a[i + n / 2] = a0[i] - t;
        if (invert)
        {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<Complex> fastFourierTransform(const vector<Complex> &input, bool invert = false)
{
    vector<Complex> a = input;
    int n = a.size();

    int power = 1;
    while (power < n)
    {
        power *= 2;
    }
    while (a.size() < power)
    {
        a.push_back(0);
    }

    fft(a, invert);

    return a;
}

vector<Complex> multiplyPolynomials(const vector<Complex> &A, const vector<Complex> &B)
{
    vector<Complex> fftA = fastFourierTransform(A);
    vector<Complex> fftB = fastFourierTransform(B);

    vector<Complex> result;
    for (size_t i = 0; i < fftA.size(); ++i)
    {
        result.push_back(fftA[i] * fftB[i]);
    }

    result = fastFourierTransform(result, true);

    return result;
}

int main()
{

    vector<Complex> A = {1, 1};
    vector<Complex> B = {2, 1};

    vector<Complex> result = multiplyPolynomials(A, B);

    cout << "Resulting polynomial coefficients: ";
    for (const Complex &coeff : result)
    {
        cout << real(coeff) << " ";
    }
    cout << endl;

    return 0;
}
