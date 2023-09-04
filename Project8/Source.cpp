#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

//Для демонстрации глубокого копирования создадим вектор указателей
//Для демонстрации count_if была создана unordered_map с парами ключ-значение <string, int>

void copy(std::vector<int*>* myVector, std::vector<int*>* newVector) {
    std::vector<int*>::iterator it = begin(*myVector);
    while (it != end(*myVector)) {
        (*newVector).push_back(new int(*(*it)));
        it++;
    }
}


void printElement(int* element) {
    std::cout << *element << " ";
}

void printPair(std::pair<std::string, int> product) {
    std::cout << product.first << " - " << product.second << std::endl;
}

int main() {
    std::setlocale(LC_ALL, "RUSSIAN");

    std::cout << "1) copy с применением «глубокого» копирования" << std::endl;
    std::vector<int*> myVector;
    std::vector<int*> newVector;    //вектор для выполнения копирования

    //заполняем вектор
    int a = 10;
    int b = 20;
    int c = 30;

    myVector.push_back(&a);
    myVector.push_back(&b);
    myVector.push_back(&c);


    std::cout << "Содержимое вектора" << std::endl;
    std::for_each(begin(myVector), end(myVector), printElement);

    copy(&myVector, &newVector);


    std::cout << "\nСодержимое нового вектора" << std::endl;
    std::for_each(begin(newVector), end(newVector), printElement);

    std::for_each(myVector.begin(), myVector.end(), [](int* value) {
        *value += 1;
        });


    std::cout << "\nСодержимое исходного вектора, после того, как все значения увеличили на 1" << std::endl;
    std::for_each(begin(myVector), end(myVector), printElement);

    std::cout << "\nСодержимое нового вектора(не изменилось!)" << std::endl;
    std::for_each(begin(newVector), end(newVector), printElement);

    std::cout << "\n\n2) count_if для std::unordered_map" << std::endl;
    std::unordered_map<std::string, int> myMap;

    // Заполняем unordered_map элементами
    myMap["apple"] = 5;
    myMap["banana"] = 3;
    myMap["cherry"] = 7;
    myMap["date"] = 2;
    myMap["elderberry"] = 6;

    std::cout << "Содержимое unordered_map" << std::endl;
    std::for_each(begin(myMap), end(myMap), printPair);

    // Задаем пороговое значение для подсчета
    int threshold = 4;

    // Используем std::count_if для подсчета элементов, у которых значение больше порога
    int count = std::count_if(myMap.begin(), myMap.end(), [threshold](const std::pair<std::string, int>& pair) {
        return pair.second > threshold;
        });

    std::cout << "Количество элементов с значением больше " << threshold << ": " << count << std::endl;


    std::cout << "\n3) fill для заполнения массива любыми данными." << std::endl;
    const int size = 5;
    int myArray[size];

    // Используем std::fill для заполнения массива значением 42
    int valueToFill = 42;
    std::fill(myArray, myArray + size, valueToFill);

    // Выводим содержимое массива
    std::cout << "Массив заполненный числом 42:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}