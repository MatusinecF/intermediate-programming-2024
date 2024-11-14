#include <cassert>
#include<iostream>
// TODO: doplťe co potřebujete

int power_digit_sum(unsigned int number){
    int pocet_cifer = 0;
    int podil;
    int cislo = number;
    while(podil > 0){//zjisti pocet cifer pro vypocet prvni a nasledujicich mocnin
        podil = number/7;
        number  = podil;
        pocet_cifer += 1;
    }
    int sum =0;
    int mocnina = pocet_cifer;
    
    for(int i = 0; i < pocet_cifer; i++){//provadi soucet mocnin na cifrach
        int cislo_cifra = cislo % 7;
        int podil2 = cislo / 7;
        cislo = podil2;
        int cifra_umocnena = 1;
        for(int i = 0; i < mocnina; i++){//umocnuje cislo na cifre
            cifra_umocnena *= cislo_cifra;
            std::cout << "cislo na cifre je ";
            std::cout << cislo_cifra <<std::endl;
        }
        mocnina -= 1;
        sum += cifra_umocnena;
        std::cout << cifra_umocnena << std::endl;
    }
    
    std::cout<< pocet_cifer << std::endl;
    return sum;
}
// Implementujte funkci ‹power_digit_sum›, která vrátí „speciální“
// ciferný součet čísla ‹number›, který se od běžného ciferného
// součtu liší tím, že každou cifru před přičtením umocníme na číslo
// její pozice. Pozice číslujeme zleva, přičemž první má číslo 1.
// Vstupem funkce ‹power_digit_sum› bude libovolné nezáporné celé
// číslo, na výstupu se očekává celé číslo. Výpočet budeme provádět
// v číselné soustavě se základem 7.
//// Příklad: Číslo ⟦1234⟧ zapíšeme v sedmičkové soustavě jako
// ⟦(3412)₇⟧ – skutečně, ⟦3⋅7³ + 4⋅7² + 1⋅7¹ + 2⋅7⁰ = 1029 + 196 + 7
// + 2 = 1234⟧.  Proto ‹power_digit_sum(1234)› získáme jako ⟦3¹ + 4²
// + 1³ + 2⁴ = 36⟧.



// Napište funkci, která najde celé číslo ‹x›, které leží mezi
// hodnotami ‹low› a ‹high› (včetně), a pro které vrátí funkce ‹poly›
// maximální hodnotu (tzn. libovolné ⟦x⟧ takové, že pro všechny ⟦x'⟧
// platí ⟦f(x) ≥ f(x')⟧, kde ⟦f⟧ je funkce, kterou počítá podprogram
// ‹poly›).

int poly(int low, int high) {
    int x = low;
    int diference = high - low;
    int position;
    int value = 10 + 30 * x - 15 * x * x * x + x * x * x * x * x;
    int max_value = value;
    for(int i = 0; i <= diference; i++){
        value = 10 + 30 * x - 15 * x * x * x + x * x * x * x * x;
        if(max_value < value){
            max_value = value;
            position = x;
        }
        x += 1;
    }
    std::cout<<"Hledané číslo x je: ";
    std::cout<< position << std::endl;
    std::cout << "Hodnota je: ";
    return max_value;
}


// Napište funkci, která zjistí, kolik bude pracovních dnů v roce
// ‹year›. Dny v týdnu mají hodnoty 0–6 počínaje pondělím s hodnotou 0.
// Předpokládejte, že ‹year› je větší než 1600.
// České státní svátky jsou:
//
// │  datum │ svátek                                         │
// ├┄┄┄┄┄┄┄▻┼◅┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄│
// │   1.1. │ Den obnovy samostatného českého státu          │
// │      — │ Velký pátek                                    │
// │      — │ Velikonoční pondělí                            │
// │   1.5. │ Svátek práce                                   │
// │   8.5. │ Den vítězství                                  │
// │   5.7. │ Den slovanských věrozvěstů Cyrila a Metoděje   │
// │   6.7. │ Den upálení mistra Jana Husa                   │
// │  28.9. │ Den české státnosti                            │
// │ 28.10. │ Den vzniku samostatného československého státu │
// │ 17.11. │ Den boje za svobodu a demokracii               │
// │ 24.12. │ Štědrý den                                     │
// │ 25.12. │ 1. svátek vánoční                              │
// │ 26.12. │ 2. svátek vánoční                              │
// Přestupné roky: v některých letech se na konec února přidává 29.
// den. Jsou to roky, které jsou dělitelné čtyřmi, s výjimkou těch,
// které jsou zároveň dělitelné 100 a nedělitelné 400.
// Čistou funkci ‹first_day› můžete použít k tomu, abyste zjistili,
// na který den v týdnu padne 1. leden daného roku. Např.
// ‹first_day(2001)› vrátí nulu, protože rok 2001 začínal pondělím.

int first_day(int year) {
    assert(year >= 1601);
    int years = year - 1601;
    int offset = years + years / 4 - years / 100 + years / 400;
    return offset % 7;
}
int work_days(int year){
    int prvni_den = first_day(year);
    int pocet_prac_dni = 365;
    bool prestupny_rok = false;
    if(year % 4 == 0){
        pocet_prac_dni = 366;
        prestupny_rok = true;
    }
    pocet_prac_dni -= 2;//odecte 2 dny velikonoc
    if(prestupny_rok == false){//normalní rok
        pocet_prac_dni -= 104;
        if(prvni_den == 5 || prvni_den == 6) pocet_prac_dni-= 1;
        if(prvni_den != 5 && prvni_den != 6)pocet_prac_dni -= 1;//novy rok
        if(121 % 7 + prvni_den -1 != 5 && 121 % 7 + prvni_den -1 != 6 && 122 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//svatek prace
        if(128 % 7 + prvni_den -1 != 5 && 128 % 7 + prvni_den -1 != 6 && 128 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//den vitezstvi
        if(186 % 7 + prvni_den -1 != 5 && 186 % 7 + prvni_den -1 != 6 && 186 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//cyril a metodej
        if(187 % 7 + prvni_den -1 != 5 && 187 % 7 + prvni_den -1 != 6 && 187 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//jan hus
        if(271 % 7 + prvni_den -1 != 5 && 271 % 7 + prvni_den -1 != 6 && 271 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//vaclav
        if(301 % 7 + prvni_den -1 != 5 && 301 % 7 + prvni_den -1 != 6 && 301 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//den vzniku csr
        if(321 % 7 + prvni_den -1 != 5 && 321 % 7 + prvni_den -1 != 6 && 321 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//den boje za svobodu a demokracii
        if(358 % 7 + prvni_den -1 != 5 && 358 % 7 + prvni_den -1 != 6 && 358 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//stedry den
        if(359 % 7 + prvni_den -1 != 5 && 359 % 7 + prvni_den -1 != 6 && 359 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//1 svatek vanocni
        if(360 % 7 + prvni_den -1 != 5 && 360 % 7 + prvni_den -1 != 6 && 360 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//2 svatek vanocni
    }
    else{//prestupny rok
        pocet_prac_dni -= 104;
        if(prvni_den == 5){
            pocet_prac_dni -= 2;
        }
        if(prvni_den == 6){
            pocet_prac_dni -= 1;
        }
        if(prvni_den != 5 && prvni_den != 6)pocet_prac_dni -= 1;//novy rok-1
        if(122 % 7 + prvni_den -1 != 5 && 122 % 7 + prvni_den -1 != 6 && 122 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//svatek prace-1
        if(129 % 7 + prvni_den -1 != 5 && 129 % 7 + prvni_den -1 != 6 && 129 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//den vitezstvi-1
        if(187 % 7 + prvni_den -1 != 5 && 187 % 7 + prvni_den -1 != 6 && 187 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//cyril a metodej-1
        if(188 % 7 + prvni_den -1 != 5 && 188 % 7 + prvni_den -1 != 6 && 188 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//jan hus 0
        if(272 % 7 + prvni_den -1 != 5 && 272 % 7 + prvni_den -1 != 6 && 272 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//vaclav 0
        if(302 % 7 + prvni_den -1 != 5 && 302 % 7 + prvni_den -1 != 6 && 302 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//den vzniku csr-1
        if(322 % 7 + prvni_den -1 != 5 && 322 % 7 + prvni_den -1 != 6 && 322 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//den boje za svobodu a demokracii 0
        if(359 % 7 + prvni_den -1 != 5 && 359 % 7 + prvni_den -1 != 6 && 359 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//stedry den -1
        if(360 % 7 + prvni_den -1 != 5 && 360 % 7 + prvni_den -1 != 6 && 360 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//1 svatek vanocni -1
        if(361 % 7 + prvni_den -1 != 5 && 361 % 7 + prvni_den -1 != 6 && 361 % 7 + prvni_den -1 != -1)pocet_prac_dni -= 1;//2 svatek vanocni -1
    }

    return pocet_prac_dni;
}
int main(){
    std::cout << work_days(2024) << std::endl;
    //std::cout << power_digit_sum(353) <<std::endl;
    //std::cout<< poly(5, 15) << std::endl;

}
