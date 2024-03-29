#include <iostream>

using namespace std;

template <typename T> T maxium (T x, T y){
    return (x>y)?x:y;
}

int main () {
    int x=10,y=20;
    cout << maxium<int> (x,y) << endl;

}