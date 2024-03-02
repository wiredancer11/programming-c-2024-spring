#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void enlarge(vector<double> &v) {
    double s;
    vector<double>::iterator i;
    for (i = v.begin()+1; i!= v.end(); i++) {
        s = (*i + *(i-1)) / 2;
        i = v.insert(i, s);
        i++;
    }

}

void del(vector <double> &v) {
    vector<double> new_v;
    vector<double>::iterator i;

    for (i = v.begin(); i != v.end(); i++) {
        if ((i - v.begin()) % 2 != 0) new_v.push_back(*i);
    }
    v = new_v;
}

vector<double> concat(vector<double> &v1, vector<double> &v2) {
    vector<double> new_v;
    new_v.resize(v1.size() + v2.size());
    copy(v1.begin(), v1.end(), new_v.begin());
    copy(v2.begin(), v2.end(), new_v.begin()+v1.size());
    return new_v;
}

vector<double> repeat(vector<double> v1, int n) {
   vector<double> new_v;
   new_v.resize(v1.size() * n);
   for (int i = 0; i<n;i++) {
    copy(v1.begin(), v1.end(), new_v.begin() + v1.size()*i);
   }
   return new_v;
}

vector<double>::iterator second_occure(vector<double> &v, double x) {
    return find(find(v.begin(), v.end(), x)+1, v.end(), x);
}

vector<double>::iterator last_occure(vector<double> &v, double x) {
    vector<double>::iterator i= find(v.begin(), v.end(), x);
    vector<double>::iterator result = v.end();
    while (i != v.end()) {
        result = i;
        i = find(i+1, v.end(), x);
    }
    return result;
}

vector<double>::iterator last_occure_sorted(vector<double> &v, double x) {
    return upper_bound(v.begin(), v.end(), x) - 1;
}

void bounds(vector<double> &v, double x, int & i, int & j) {
    j = lower_bound(v.begin(), v.end(), x) - v.begin();
    if (v[j] == x) i = j;
    else i = lower_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

int main() {
    /*vector<double> v {1, 4, 5, 6};
    double arr[4];
    copy(v.begin(), v.end(), arr);
    for (int i = 0; i < v.size(); i++) {
        cout << arr[i] << " ";
    }
    */
    vector<double> v1{1, 1, 2, 2, 4};
    int i, j;
    i = 0;
    j = 0;
    bounds(v1, 3, i, j);
    cout << i << j << "\n";
    cout << last_occure_sorted(v1, 2) - v1.begin() << "\n";
    vector<double> new_v = repeat(v1, 3);
    for (int i = 0; i < new_v.size(); i++) {
        cout << new_v[i] << " ";
    }




    return EXIT_SUCCESS;
}