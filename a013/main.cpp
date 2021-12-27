#include <iostream>
#include <string.h>
using namespace std;

int value(char c)
{
    int n = 0;
    switch (c)
    {
    case 'I':
        n = 1;
        break;
    case 'V':
        n = 5;
        break;
    case 'X':
        n = 10;
        break;
    case 'L':
        n = 50;
        break;
    case 'C':
        n = 100;
        break;
    case 'D':
        n = 500;
        break;
    case 'M':
        n = 1000;
        break;
    }
    return n;
}


int parse(char * s)
{
    int n = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        //cout << s[i] << ":" << value(s[i]) <<endl;
        if (( value(s[i]) >= value(s[i+1]) ) )
        {
            n += value(s[i]);
        }
        else
        {
            n -= value(s[i]);
        }
    }
    return n;
}

void output2 (int n, char c[])
{
    if (n == 0)
    {
        c = "ZERO";
        return;
    }
    int i = 0;
    while (n > 0)
    {
        if ( n / 1000 > 0)
        {
            c[i++] = 'M';
            n = n-1000;
        }
        else if (n / 500 > 0 )
        {
            if ( (n / 100) == 9)
            {
                c[i++] = 'C';
                c[i++] = 'M';
                n = n - 900;
            }
            else
            {
                c[i++] = 'D';
                n = n - 500;
            }
        }
        else if (n / 100 > 0 )
        {
            if ( (n / 100) == 4 )
            {
                c[i++] = 'C';
                c[i++] = 'D';
                n = n - 400;
            }
            else
            {
                c[i++] = 'C';
                n = n - 100;
            }
        }
        else if (n / 50 > 0 )
        {
            if ( (n / 10) == 9)
            {
                c[i++] = 'X';
                c[i++] = 'C';
                n = n - 90;
            }
            else
            {
                c[i++] = 'L';
                n = n - 50;
            }
        }
        else if (n / 10 > 0 )
        {
            if ( (n / 10) == 4 )
            {
                c[i++] = 'X';
                c[i++] = 'L';
                n = n - 40;
            }
            else
            {
                c[i++] = 'X';
                n = n - 10;
            }
        }
        else if (n / 5 > 0 )
        {
            if ( n == 9 )
            {
                c[i++] = 'I';
                c[i++] = 'X';
                n = n - 9;
            }
            else
            {
                c[i++] = 'V';
                n = n - 5;
            }
        }
        else if (n / 1 > 0 )
        {
            if ( n == 4 )
            {
                c[i++] = 'I';
                c[i++] = 'V';
                n = n - 4;
            }
            else
            {
                c[i++] = 'I';
                n = n - 1;
            }
        }
    }
    c[i] = 0;
}

void output(int n)
{
    if (n == 0)
    {
        cout << "ZERO" << endl;
        return;
    }
    while (n > 0)
    {
        if ( n / 1000 > 0)
        {
            cout << "M";
            n = n-1000;
        }
        else if (n / 500 > 0 )
        {
            if ( (n / 100) == 9)
            {
                cout << "CM";
                n = n - 900;
            }
            else
            {
                cout << "D";
                n = n - 500;
            }
        }
        else if (n / 100 > 0 )
        {
            if ( (n / 100) == 4 )
            {
                cout << "CD";
                n = n - 400;
            }
            else
            {
                cout << "C";
                n = n - 100;
            }
        }
        else if (n / 50 > 0 )
        {
            if ( (n / 10) == 9)
            {
                cout << "XC";
                n = n - 90;
            }
            else
            {
                cout << "L";
                n = n - 50;
            }
        }
        else if (n / 10 > 0 )
        {
            if ( (n / 10) == 4 )
            {
                cout << "XL";
                n = n - 40;
            }
            else
            {
                cout << "X";
                n = n - 10;
            }
        }
        else if (n / 5 > 0 )
        {
            if ( n == 9 )
            {
                cout << "IX";
                n = n - 9;
            }
            else
            {
                cout << "V";
                n = n - 5;
            }
        }
        else if (n / 1 > 0 )
        {
            if ( n == 4 )
            {
                cout << "IV";
                n = n - 4;
            }
            else
            {
                cout << "I";
                n = n - 1;
            }
        }
    }
    cout << endl;
}


int main()
{
    int n1,n2 = 0;
    const int len = 50;
    char s1[len]= {}, s2[len]= {};
    char s3[len] = {};

//    for (int t = 1 ; t <= 150; t++) {
//        char s3[30] = {0};
//        output2(t, s3);
//        n1 = parse(s3);
//        cout << t << "\t" << s3 << endl;
//        //cout << t << " : " << s3 << " : " << n1 << endl;
//        if (n1 != t) {
//            cout << t << " <> " << n1 << endl;
//            exit(1);
//        }
//    }
//    exit(0);

    cin >> s1 >> s2;
    while ( 1 )
    {

        n1 = parse(s1);
        //cout << "n1: " << n1 <<endl;
        n2 = parse(s2);
        //cout << "n2: " << n2 <<endl;

        int ans = n1 - n2;
        if (ans < 0) ans = 0 - ans;
        if (ans == 0) {
            cout << "ZERO" << endl;
        } else {
            output2(ans, s3);
            cout << s3 << endl;
        }
        //cout << ans << ": " << s3 << endl;
        //cout << ans << ": " ;
        //output(ans);

        cin >> s1;
        if (s1[0] == '#') {
            break;
        }
        cin >> s2;
    }
    return 0;
}
