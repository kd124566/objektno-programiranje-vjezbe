#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cctype>
#include <fstream>
#include <iterator>
#include <functional>
#include <string>

struct Point {
    double x;
    double y;
};


bool usporedi(const Point& a, const Point& b) {
    return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
}

bool unutarkruga(const Point& p, double radius) {
    return (p.x * p.x + p.y * p.y) < (radius * radius);
}

bool udaljenost(const Point& p, double udaljenostk) {
    return (p.x * p.x + p.y * p.y) == udaljenostk;
}

void zamjena(std::vector<Point>& points, double kvadratPragaUdaljenosti, const Point& zamjenskaTocka) {
    std::replace_if(points.begin(), points.end(), std::bind(udaljenost, std::placeholders::_1, kvadratPragaUdaljenosti), zamjenskaTocka);
}


double brojtocakaukrugu(const std::vector<Point>& points, double radius) {
    return std::count_if(points.begin(), points.end(), std::bind(unutarkruga, std::placeholders::_1, radius));
}






void zadatak2() {
    std::ifstream otvori("points.txt");

    if (!otvori) {
        std::cout << "Datoteka nije otvorena" << std::endl;
        return;
    }

    std::vector<Point> points;

    std::copy(std::istream_iterator<Point>(otvori), std::istream_iterator<Point>(), std::back_inserter(points));

    std::cout << "Ucitane tocke:" << std::endl;
    for (const Point& point : points) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    std::sort(points.begin(), points.end(), usporedi);

    double krugRadijus = 5;
    double brojTocakaUnutarKruga = brojtocakaukrugu(points, krugRadijus);

    std::cout << "Broj tocaka unutar kruga: " << brojTocakaUnutarKruga << std::endl;

    double kvadratPragaUdaljenosti = 3 * 3;
    Point zamjenskaTocka = { 10, 10 };

    zamjena(points, kvadratPragaUdaljenosti, zamjenskaTocka);

    std::reverse(points.begin(), points.end());

    std::cout << "Izmijenjene i sortirane to?ke:" << std::endl;
    for (const Point& point : points) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    std::copy(points.begin(), points.end(), std::ostream_iterator<Point>(std::cout, "\n"));
    otvori.close();
}

int main() {
    zadatak2();

    return 0;
}
