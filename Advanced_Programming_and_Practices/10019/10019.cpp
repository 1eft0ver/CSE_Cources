#include <iostream>
#include <cmath>
using namespace std;

int count_bi(int m) {
    int count = 0;
    while(m > 1) {
        int quotient = m / 2;
        if(m - quotient * 2 == 1)
            ++count;
        m = quotient;
    }
    return count + 1;
}

int count_hex(int m) {
    int count = 0;
    int expo = 0;
    int dec = 0;
    while(m / 10 > 0) {
        int in_queue = m / 10;
        int remain = m - in_queue * 10;
        m = in_queue;
        dec += remain * pow(16, expo);
        expo++;
    }
    dec += m * pow(16, expo);

    return count_bi(dec);
}

int main()
{
    int n;
    while(cin >> n) {
        for (int i = 0 ; i < n ; ++i) {
            int m;
            cin >> m;
            cout << count_bi(m) << " " << count_hex(m) << endl;
        }
    }
}
