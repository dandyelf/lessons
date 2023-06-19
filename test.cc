//
// Created by Left Ranae on 15.04.2023.
//

#include <iostream>

class Point;

class Point {
public:
  Point() {};
  ~Point() {};
private:
  int counter_{};
  double x_{}, y_{};
  Point(double x, double y, int counter) {};
};

class UnicPoint {
  private:
    int count_;
    UnicPoint() {
  }
};

using namespace std;

template <typename T> T Sum(T a, T b) { return a + b; }

int main(int argc, char const *argv[]) {
  if (argc > 0 || argv[0]) {
    cout << Sum(4, 4) << " Sum 4 + 4" << endl;
    cout << Sum(4.5, 4.1) << " Sum 4.5 + 4.1" << endl;
  }
  Point first;
  return 0;
}
