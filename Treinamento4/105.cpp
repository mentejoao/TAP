#include <iostream>

//The number 105 is quite special - it is odd but still it has eight divisors. Now, your task is this: how many odd numbers with exactly eight positive divisors are there between
// 1 and N (inclusive)

int main()
{
    int A, count, countOddAndEight;
    
    count = 0;
    countOddAndEight = 0;
    std::cin >> A;
    
    if(A >= 1 || A <= 200){
        for(int i = 1; i <= A; i++){
            if( i % 2 != 0){
                for(int j = 1; j <= i; j++){
                    if( i % j == 0){
                        count++;
                    }
                }
                if(count == 8){
                    countOddAndEight++;
                }
            }
            count = 0;
        }
    }
    std::cout << countOddAndEight << std::endl;

    return 0;
}