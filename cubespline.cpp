#include "cubespline.h"


void CubeSpline::build()
{
    size_t n = points.size();
    std::map<double, double>::iterator it = points.begin();
    it++;
    std::map<double, double>::iterator it_1;
    for (it; it != points.end(); it++)
    {
        Polinom S;
        it_1 = --it;
        it++;
        S.h = (*it).first - (*it_1).first;
        S.a = (*it_1).second;
        S.x_i = (*it_1).first;
        spline.push_back(S);
    }
    spline[0].c = 0.0;
    Polinom S;
    it_1++;
    S.a = (*it_1).second;
    S.x_i = (*it_1).first;
    spline.push_back(S);

    // метод прогонки
    // прямой ход
    std::vector<double> alpha(n-1), beta(n-1);
    alpha[0] = 0.0;
    beta[0] = 0.0; // = c_n
    double A, B, C, F;
    std::map<double, double>::iterator j = points.begin();
    j++;
    for (int i = 1; i < n-1; i++)
    {
        C = 2.0 * (spline[i - 1].h + spline[i].h);
        A = spline[i - 1].h;
        B = spline[i].h;
        std::map<double, double>::iterator j_minus_1 = --j;
        j++;
        std::map<double, double>::iterator j_plus_1 = ++j;
        j--;
        F = 6.0 * ((j_plus_1->second - j->second) / spline[i].h - (j->second - j_minus_1->second) / spline[i - 1].h);
        double tmp = A * alpha[i - 1] + C;
        alpha[i] = -B / tmp;
        beta[i] = (F - A * beta[i - 1]) / tmp;
        j++;
    }

    // обратный ход метода прогонки
    spline[n - 1].c = 0;
    for (int i = n - 2; i > 0; --i)
        spline[i].c = alpha[i] * spline[i + 1].c + beta[i];

    // вычисление d и b
    j = points.begin();
    for (int i = 1; i < n; i++)
    {
        spline[i].d = (spline[i].c - spline[i - 1].c) / spline[i - 1].h;
        std::map<double, double>::iterator j_minus_1 = j;
        j++;
        spline[i].b = (spline[i - 1].h * (2.0 * spline[i].c + spline[i - 1].c)) / 6.0 +
            (j->second - j_minus_1->second) / spline[i - 1].h;
    }

}

double CubeSpline::f(double x)
{
    Polinom S;
    if (x <= spline[0].x_i)
        S = spline[1];
    else if (x >= spline[spline.size()-1].x_i)
        S = spline[spline.size() - 1];
    else {
        std::size_t i = 0, j = spline.size() - 1;
        while (i + 1 < j)
        {
            int mid = i + (j - i) / 2;
            if (x <= spline[mid].x_i)
                j = mid;
            else
                i = mid;
        }
        S = spline[j];
    }

    return S.a + (S.b + (S.c / 2.0 + S.d * (x - S.x_i) / 6.0) * (x - S.x_i)) * (x - S.x_i);
}

std::vector<std::vector<double> > CubeSpline::get()
{
    std::vector<std::vector<double> > res;
    res.resize(spline.size(), std::vector<double>(5));
    for ( size_t i = 0; i < spline.size(); i++)
    {
        res[i][0] = spline[i].x_i;
        res[i][1] = spline[i].a;
        res[i][2] = spline[i].b;
        res[i][3] = spline[i].c;
        res[i][4] = spline[i].d;
    }

    return res;
}
