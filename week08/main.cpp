#include <iostream>
#include <vector>

void print(std::vector<int> data) {
    if (data.size() == 0) {
        std::cout << "[]";
        return;
    }

    std::cout << "[ ";
    for (std::size_t i = 0; i < data.size() - 1; i++) {
        std::cout << data[i] << ", ";
    }

    std::cout << data.back() << " ]";
}

void print_vektor(std::vector<std::vector<int>> data){
    if (data.size() == 0) {
        std::cout << "[]";
        return;
    }
    std::cout << "[ ";
    for (std::size_t i = 0; i < data.size(); i++) {
        std::vector<int> clen = data[i];
        
        print(clen);
        if(i < data.size() - 1)std::cout << ", ";
        clen.resize(0);
    }

    std::cout << " ]";
}

int sum(std::vector<int> data) {
    int soucet= 0;
    for(std::size_t i = 0; i < data.size(); i++ ){
        soucet += data[i]; 
    }
    return soucet;
}

float average(std::vector<int> data) {
    float avarage = 1.0;
    int sum = 0;
    float pocet = data.size();
    for(std::size_t i = 0; i < data.size(); i++){
        sum += data[i];
    }
    avarage = sum/pocet;
    return avarage;
}

float median(std::vector<int> data) {
    float median_2;
    if(data.size() % 2 == 1){
        median_2 = data[(data.size() - 1)/2];
    }
    else{
        median_2 = (data[(data.size()/2 )- 1] + data[data.size()/2 ])/2.0;
    }
  
    return median_2;
}

std::vector<int> range(int start, int end) {
    
    if(start < end){
        int diference = end - start;
        int number = start;
        std::vector<int> vysledek;
        for(int i = 0; i < diference; i++){
            vysledek.push_back(number);
            number++;
        }
        return vysledek;
    }
    if(start > end){
        int diference = start - end;
        int number = end;
        std::vector<int> vysledek;
        for(int i = 0; i < diference; i++){
            vysledek.push_back(number);
            number++;
        }
        return vysledek;
    }

    return {};
}

std::vector<int> runningSum(std::vector<int> data) {
    std::vector<int>vysledek;
    int number = 0;
    for(std::size_t i = 0; i < data.size(); i++){
        vysledek.push_back(data[i] + number);
        number = vysledek[i];
    }
    return vysledek;
}

std::vector<int> rotateRight(std::vector<int> data, int count) {
    std::vector<int>vysledek;
    int posunuti = count % data.size();
    for(int i = 0; i < posunuti; i++){
        vysledek.push_back(data[data.size() - posunuti + i]);
    }
    for(std::size_t i = 0; i < data.size(); i++){
        vysledek.push_back(data[i]);
    }
    vysledek.resize(data.size());
    return vysledek;
}

std::vector<int> filter_larger(std::vector<int> original, int value){
    std::vector<int> vysledek;
    for(std::size_t i = 0; i < original.size(); i++){
        if(original[i] > value){
            vysledek.push_back(original[i]);
        }
    }
    return vysledek;
}
std::vector<int> serazeni(std::vector<int> data, int cislo){
    //std::vector<int> vysledek;
    
    for(std::size_t i = 0; i < data.size(); i++){
        if(data[i] < cislo){
            data[i] = data[i];
        }


    }
    return data;
}

bool palindron(std::vector<int> data){
    for(std::size_t i = 0; i < data.size()/2; i++){
        if(data[i] != data[data.size() - i - 1]){
            return false;
        }
    }
    return true;
}

std::vector<int> sum(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {1, 2, 0}
    std::vector<int> vysledek;
    for(std::size_t i = 0; i < vec.size(); i++){
        int soucet = 0;
        for(std::size_t j = 0; j < vec[i].size(); j++){
            soucet += vec[i][j];
        }
        vysledek.push_back(soucet);
    }
    return vysledek;
}

std::vector<int> concat(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {0, 1, 2}
    std::vector<int> vysledek;
    for(std::size_t i = 0; i < vec.size(); i++){
        for(std::size_t j = 0; j < vec[i].size(); j++){
            vysledek.push_back(vec[i][j]);
        }
    }
    return vysledek;
}

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> vec) {
    // {
    //   {0, 1, 2},
    //   {3, 4, 5},
    //   {6, 7, 8},
    // } -> {
    //   {0, 3, 6},
    //   {1, 4, 7},
    //   {2, 5, 8},
    // }
    std::vector<std::vector<int>> vysledek;
    std::vector<int> clen;
    for(std::size_t i = 0; i < vec[1].size(); i++){
        for(std::size_t j = 0; j < vec.size(); j++){
            clen.push_back(vec[j][i]);
        }
        
        vysledek.push_back(clen);
        clen.resize(0);
    }
    return vysledek;
}

std::vector<std::vector<int>> cartesian_product(std::vector<int> a, std::vector<int> b) {
    // {0, 1} {2, 4} -> {{0, 2}, {0, 4}, {1, 2}, {1, 4}}
    // {0, 1} {} -> {} 
    std::vector<std::vector<int>> vysledek;
    std::vector<int> clen;
    for(std::size_t j = 0; j < a.size(); j++){
        for(std::size_t i = 0; i < b.size(); i++){
            clen.push_back(a[j]);
            clen.push_back(b[i]);
            vysledek.push_back(clen);
            clen.resize(0);
        }
    }
    return vysledek;
}
int get(std::vector<std::vector<int>> b, std::size_t i, std::size_t j){
    if (i > b.size()-1){
        return 0;
    }
    if (j > b[i].size()){
        return 0;
    }
    else{
        return b[i][j];
    }
}

std::vector<std::vector<int>> sum_2(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b){
    std::vector<std::vector<int>> vysledek;
    std::vector<int> clen;
    int sum = 0;
    for(std::size_t i = 0; i < a.size(); i++){
        for(std::size_t j = 0; j < a[i].size(); j++){
            sum = a[i][j] + get(b, i, j);
            clen.push_back(sum);
            sum = 0;
        }
        vysledek.push_back(clen);
        clen.resize(0);
    }
    return vysledek;
}

std::vector<std::vector<int>> split(std::vector<int> a, int n){
    std::vector<std::vector<int>> vysledek;
    std::vector<int> clen;
    for(std::size_t i = 0; i < a.size()/n; i++){
        for(int j = 0; j < n; j++){
            clen.push_back(a[j + i*n]);
        }
        vysledek.push_back(clen);
        clen.resize(0);
    }
    return vysledek;
}

int main() {
    std::vector<std::vector<int>> vec4 = {{0, 1}, {2, 3}};
    std::vector<std::vector<int>> vec2 = {{0, 1} , {2}, {}};
    std::vector<std::vector<int>> vec3 = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
    };
    std::vector<int> vec5 ={0,1};
    std::vector<int> vec6 = {2,4};
    std::vector<std::vector<int>> vec7 ={{ 1, 2, 3, 4}, {5, 6, 7}, {8, 9}};
    std::vector<std::vector<int>> vec8 = {{1, 5}, {4,6}};
    std::vector<int> vec9 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    /*std::vector<int> asc3 = { 1, 2, 1};
    std::vector<int> vec1 = { 1, 9, 4, 8, 4, 0, 9, 2, 3, 5, 6 };
    std::vector<int> asc1 = { 0, 2, 4, 7, 8 };
    std::vector<int> asc2 = { 1, 3, 5, 6, 7, 9 };*/

    /*std::cout << "sum(vec1): " << sum(vec1) << std::endl;
    std::cout << "average(vec1): " << average(vec1) << std::endl;
    std::cout << "median(asc1): " << median(asc1) << std::endl;

    std::cout << "range(5, 10): ";
    print(range(5, 10));
    std::cout << std::endl;

    std::cout << "range(11, 4): ";
    print(range(11, 4));
    std::cout << std::endl;

    std::cout << "runningSum(vec1): ";
    print(runningSum(vec1));
    std::cout << std::endl;
    
    std::cout << "rotetaRight(vec1): ";
    print(rotateRight(vec1, 12));
    std::cout << std::endl;

    std::cout << "filter_large(vec1): ";
    print(filter_larger(vec1, 4));
    std::cout << std::endl;

    std::cout << "serazeni(vec1): ";
    print(serazeni(vec1, 4));
    std::cout << std::endl;


    std::cout << "palindron(vec1): ";
    std::cout << palindron(asc3);
    std::cout << std::endl; */
    std::cout << "Hello world" << std::endl;

    std::cout << "sum(vec2): ";
    print(sum(vec2));
    std::cout << std::endl;

    std::cout << "concat(vec2): ";
    print(concat(vec2));
    std::cout << std::endl;    

    std::cout << "transpose(vec3): ";
    print_vektor(transpose(vec3));
    std::cout << std::endl;

    std::cout << "cartesian_product(vec4 , vec5): ";
    print_vektor(cartesian_product(vec5 , vec6));
    std::cout << std::endl;

    std::cout << "sum_2(vec4 , vec5): ";
    print_vektor(sum_2(vec7 , vec8));
    std::cout << std::endl;

    std::cout << "split(vec4 , vec5): ";
    print_vektor(split(vec9 , 1));
    std::cout << std::endl; 

}
