#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

// In number theory there is a very deep unsolved conjecture of the Hungarian Paul Erdős (1913-1996), that there exist infinitely many primes of the form x2+1, where x is an integer.
// However, a weaker form of this conjecture has been proved: there are infinitely many primes of the form x^2+y^4. You don't need to prove this, it is only your task to find the number
// of (positive) primes not larger than n which are of the form x^2+y^4 (where x and y are integers).

// An integer T, denoting the number of testcases (T≤10000). Each of the T following lines contains a positive integer n, where n<10000000.
// Output: Output the answer for each n.

// Example input:   
// 4
// 1
// 2
// 10
// 9999999

// Example output:
// 0
// 1
// 2
// 13175

typedef long long ll;

typedef struct MaxBase{
    int x2, y4;
}maxBase;

void getBases(ll N, maxBase* input){
    int count2 = 1;
    int count4 = 1;
    
    ll x = N;
    ll y = N;
    
    //std::cout << "valor de N" << N << std::endl;
    while (x > 0) {
        int K = pow(count2, 2);
        //std::cout << count2 << std::endl;
        x /= K;
        if(x <= 0 ){
            break;
        }
        count2++;
    }
    
    //std::cout << "valor do count2 " << count2 << std::endl;
    
    while (y > 0) {
        int J = pow(count4, 4);
        y /= J;
        if(y <= 0 ){
            break;
        }
        count4++;
    }
    //std::cout << "valor do count4 " << count4 << std::endl;
    
    input->x2 = count2;
    input->y4 = count4;
}

bool isPrime(int n) {
 if ((n < 2) || ((n > 2) && (n % 2 == 0))) return false;

 for (int i = 3; (i * i) <= n; i += 2){
    if (n % i == 0) return false;
 }
 return true;
}

bool Erdos(ll result) {
    int x, y;
    maxBase bases;
    
    //std::cout << "to aqui" << std::endl;
    // descobrir a maior potencia ^2 que cabe em result e a maior potencia de ^4 que cabe em result para determinar n2 e n4
   getBases(result, &bases);
   
   //std::cout << "valor max de x2" << bases.x2 << std::endl;
   //std::cout << "valor max de y4" << bases.y4 << std::endl;
   
    for(int i = 1; i < bases.x2; i++){
       for(int k = 1; k < bases.y4; k++){
                if(result == pow(i, 2) + pow(k, 4))
                    return true;
        }
    }
    return false;
}

int main()
{
    int A, countErdosNumber;
    ll b;
    
    std::cin >> A;
    
    if(A <= 10000) {
       for(int i = 0; i < A; i++){ // loop casos de teste
       //std::cout << "onde q eu to" << std::endl;
           std::cin >> b;
           if(b < 10000000){
               //std::cout << "esse eh o b" << b << std::endl;
               for(int j = 1; j <= b; j++){ 
                   //std::cout << "esse eh o j" << j << std::endl;
                   if(isPrime(j) && Erdos(j)){
                       countErdosNumber++;
                   }
                   else{
                       //std::cout << "nao eh primo, nem mexo" << std::endl;
                   }
               }
           }
           std::cout << countErdosNumber << std::endl;
           countErdosNumber = 0;
       }
    }

    return 0;
}