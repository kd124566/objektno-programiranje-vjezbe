
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T>
class point {
private:
    T x;
    T y;
public:
    point(T xko, T yko) : x(xko), y(yko) {}

    float operator-(const point<T>& other) const {
        T X = x - other.x;
        T Y = y - other.y;
        return sqrt(X * X + Y * Y);
    }
    friend ostream& operator<<(ostream& os, const point<T>& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    point<int> p1(2, 3);
    point<int> p2(3, 4);

    cout << "Udaljenost tocaka " << p1 << " i " << p2 << " je " << p1 - p2 << endl;
    return 0;
}
