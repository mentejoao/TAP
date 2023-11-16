#include <bits/stdc++.h>
using namespace std;

// Alice and Bob are meeting after a long time. As usual they love to play some math games. This times Alice takes the call and decides the game. The game is very simple,
// Alice says out an integer and Bob has to say whether the number is prime or not. Bob as usual knows the logic but since Alice doesn't give Bob much time to think,
// so Bob decides to write a computer program. Help Bob accomplish this task by writing a computer program which will calculate whether the number is prime or not .

// The first line of the input contains an integer T, the number of testcases. T lines follow.
// Each of the next T lines contains an integer N which has to be tested for primality.
// Output: For each test case output in a separate line, "yes" if the number is prime else "no."

 bool isPrime( int n ){
 if ((n < 2) || ((n > 2) && (n % 2 == 0))) return false;

 for (int i = 3; (i * i) <= n; i += 2)
 {
     if (isPrime( i )) // <=== ???????
    {
        if (n % i == 0) return false;
    }
 }

 return true;
}


int main()
{
    int a, b;
    cin >> a;

    for(int i = 0; i < a; i++){
        cin >> b;
        if(isPrime(b))
            cout << "yes" << endl;
       else
            cout << "no" << endl;
    }

    return 0;
}