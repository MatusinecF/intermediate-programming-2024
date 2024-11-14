#include <iostream>
// TODO: Doplňte potřebné hlavičky

// Vypište obdélník o zadaných parametrech
// Vraťte 0 pokud vše v pořádku, -1 pokud nastala chyba
int hollow_rect(int x, int y, int thickness) {
    int mezera = y-(2*thickness);
    int mezera2 = x-(2*thickness);
    for(int i = 0; i < thickness; i++){
        for(int i = 0; i < x; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < mezera; i++){
        for(int i = 0; i < thickness; i++){
            std::cout << "*";
        }
        for(int i = 0; i < mezera2; i++){
            std::cout << " ";
        }
        for(int i = 0; i < thickness; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < thickness; i++){
        for(int i = 0;i < x; i++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return -1;
}

// Vraťte a na n
int power(int a, int n) {
    int cislo = 1;
    for(int i = 0; i < n; i++){
        cislo = cislo*a;
    }
    std::cout << cislo << std::endl;
    return 0;
}

// Vraťte idx-té fibonacciho číslo
int fibonacci(int idx) {
    int vysledek2 = 0;
    int vysledek = 1;
    int indx = (idx/2);
    for(int i = 1; i < indx; i++){
        vysledek2 += vysledek;
        vysledek += vysledek2;  
    }
    if(idx % 2 == 0){
        std::cout << vysledek2 << std::endl;
    }
    else{
        std::cout << vysledek << std::endl;
    }
    return 0;
}

int main() {

//hollow_rect(20, 20, 4);
//power(4, 3);
fibonacci(7);

}
