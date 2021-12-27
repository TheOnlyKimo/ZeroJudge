#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    cin >> n;
    int c = n/2+1;
    int b = 0;

    for (int i = 2; i < c; i++) {
        if ( n % i == 0 ) {
            m++;
            n = n / i;
            i--;
        } else {
            if (m > 0) {
                if (b==0) {
                    if (m > 1)
                        cout << i << "^" << m;
                    else
                        cout << i ;

                    b = 1;
                } else {
                    if (m > 1)
                        cout << " * " << i << "^" << m ;
                    else
                        cout << " * " << i ;
                }
                m = 0;
            }
        }
    }

    if (b == 0) cout << n;

    return 0;
}
