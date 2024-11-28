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

int main() {
    std::vector<int> vec1 = { 1, 9, 4, 8, 4, 0, 9, 2, 3, 5, 6 };
    std::vector<int> asc1 = { 0, 2, 4, 7, 8 };
    std::vector<int> asc2 = { 1, 3, 5, 6, 7, 9 };

    std::cout << "sum(vec1): " << sum(vec1) << std::endl;
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
}
