//
// Created by Left Ranae on 15.04.2023.
//

#include <iostream>

using namespace std;

template <typename T>
T Sum(T a, T b){
    return a + b;
}

int main(int argc, char const *argv[])
{
    if(argc > 0 || argv[0] != "0") {
        cout << Sum(4, 4) << "Sum 4 + 4" << endl;
        cout << Sum(4.5, 4.1) << "Sum 4 + 4" << endl;
    }

    return 0;
}
