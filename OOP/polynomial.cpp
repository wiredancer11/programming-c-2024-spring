#include <iostream>
#include <cmath>
#include <initializer_list>
using namespace std;

class Polynomial {
    public:
    int deg;
    double *coefs;
    Polynomial() {
        deg = 0;
        coefs = new double[1]{0};
    }

    Polynomial(int d, double *c) {
        deg = d;
        coefs = c;
    }

    Polynomial(int a0) { //Конструктор преобразования
       deg = 0;
       coefs = new double[1];
       coefs[0] = a0;
    }

    Polynomial(const initializer_list<double> &c) {
        deg = c.size() - 1;
        coefs = new double[c.size()];
        copy(c.begin(), c.end(), coefs);
    }

    double &coef(int i) {
        return coefs[i];
    }

    int get_deg() {
        return deg;
    }

    double value(double x) {
        double result = 0;
        for (int i = 0; i <= deg; i++) {
            result += coefs[i] * pow(10, i);
        }
        return result;
    }

    Polynomial(Polynomial &x) { //Конструктор копирования
        deg = x.deg;
        coefs = new double[deg+1];
        for (int i = 0; i <= deg; i++) {
            coefs[i] = x.coefs[i];
        }
    }

    Polynomial & operator=(const Polynomial & p) {
        if (this == &p) return *this;
        delete[] coefs;
        deg = p.deg;
        coefs = new double[deg + 1];
        for (int i = 0; i <= deg; i++) {
            coefs[i] = p.coefs[i];
        }
        return *this;
    }

    double & operator[] (int i) {
       static double c = -1;
       if (i >= 0 && i <= deg) return coefs[i];
       else return c;
    }

    ~Polynomial() {
        delete[] coefs;
    }

};

Polynomial operator+(Polynomial &x, Polynomial &y) {
    Polynomial result, p_max_deg, p_min_deg;
    if (x.get_deg() <= y.get_deg()) {
        p_max_deg = y;
        p_min_deg = x;
    } else {
        p_max_deg = x;
        p_min_deg = y;
    }
    double *coef = new double[p_max_deg.get_deg() + 1];
    for (int i = 0; i <= p_max_deg.get_deg(); i++) {
        if (i <= p_min_deg.get_deg()) coef[i] = p_max_deg.coef(i) + p_min_deg.coef(i);
        else coef[i] = p_max_deg.coef(i);
    }
    result = Polynomial(p_max_deg.get_deg(), coef);
    return result;
}


Polynomial operator-(Polynomial &x, Polynomial &y) {
    Polynomial result, p_max_deg, p_min_deg;
    int sign;
    if (x.get_deg() <= y.get_deg()) {
        p_max_deg = y;
        p_min_deg = x;
        sign = -1;
    } else {
        p_max_deg = x;
        p_min_deg = y;
        sign = 1;
    }
    double *coef = new double[p_max_deg.get_deg() + 1];
    for (int i = 0; i <= p_max_deg.get_deg(); i++) {
        if (i <= p_min_deg.get_deg()) coef[i] = p_max_deg.coef(i) - p_min_deg.coef(i);
        else coef[i] = sign * p_max_deg.coef(i);
    }
    result = Polynomial(p_max_deg.get_deg(), coef);
    return result;
}

Polynomial operator*(Polynomial &x, Polynomial &y) {
    Polynomial result;
    double *coef = new double[x.get_deg() + y.get_deg() + 1];
    double a;
    for (int i = 0; i <= x.get_deg() + y.get_deg(); i++) {
        a = 0;
        for (int j = 0; j <= i; j++) {
           a += x.coef(j) * y.coef(i-j);
        }
        coef[i] = a;
    }
    result = Polynomial(x.get_deg() + y.get_deg(), coef);
    return result;
}


ostream &operator <<(ostream &st, Polynomial p) {
    for (int i = 0; i <= p.get_deg(); i++)
    {
        st << p.coef(i) << " ";
    }
    return st;
}

istream &operator >>(istream &st, Polynomial &p) {
    int deg;
    st >> deg;
    p.deg = deg;
    delete[] p.coefs;
    p.coefs = new double[deg+1];
    for (int i = 0; i <=deg; i++) {
        st >> p.coef(i);
    }
    return st;
}

    

int main() {
    double *coef;
    Polynomial x(2);
    Polynomial y {1, 2, 3};
    Polynomial z;
    cin >> z;
    cout << z;
    return EXIT_SUCCESS;
}