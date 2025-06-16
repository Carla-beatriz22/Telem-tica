//Carla Beatriz da Silva Teixeira
//Enésimo termo = soma de (n-1) + (n-2)
// 1 2 3 4 5 6 7  8  9  10
// 0 1 1 2 3 5 8 13 21  34

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if(n == 1) // primeiro termo
        return 0;
    else{
        if(n == 2) // segundo termo
            return 1;
        else
            return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main () {

    int n;

    printf("Digite um valor maior que zero: ");
    scanf("%d", &n);

    printf("O termo %d eh: %d\n", n, fibonacci(n));

    return 0;
}
