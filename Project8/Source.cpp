#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

//��� ������������ ��������� ����������� �������� ������ ����������
//��� ������������ count_if ���� ������� unordered_map � ������ ����-�������� <string, int>

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

    std::cout << "1) copy � ����������� ���������� �����������" << std::endl;
    std::vector<int*> myVector;
    std::vector<int*> newVector;    //������ ��� ���������� �����������

    //��������� ������
    int a = 10;
    int b = 20;
    int c = 30;

    myVector.push_back(&a);
    myVector.push_back(&b);
    myVector.push_back(&c);


    std::cout << "���������� �������" << std::endl;
    std::for_each(begin(myVector), end(myVector), printElement);

    copy(&myVector, &newVector);


    std::cout << "\n���������� ������ �������" << std::endl;
    std::for_each(begin(newVector), end(newVector), printElement);

    std::for_each(myVector.begin(), myVector.end(), [](int* value) {
        *value += 1;
        });


    std::cout << "\n���������� ��������� �������, ����� ����, ��� ��� �������� ��������� �� 1" << std::endl;
    std::for_each(begin(myVector), end(myVector), printElement);

    std::cout << "\n���������� ������ �������(�� ����������!)" << std::endl;
    std::for_each(begin(newVector), end(newVector), printElement);

    std::cout << "\n\n2) count_if ��� std::unordered_map" << std::endl;
    std::unordered_map<std::string, int> myMap;

    // ��������� unordered_map ����������
    myMap["apple"] = 5;
    myMap["banana"] = 3;
    myMap["cherry"] = 7;
    myMap["date"] = 2;
    myMap["elderberry"] = 6;

    std::cout << "���������� unordered_map" << std::endl;
    std::for_each(begin(myMap), end(myMap), printPair);

    // ������ ��������� �������� ��� ��������
    int threshold = 4;

    // ���������� std::count_if ��� �������� ���������, � ������� �������� ������ ������
    int count = std::count_if(myMap.begin(), myMap.end(), [threshold](const std::pair<std::string, int>& pair) {
        return pair.second > threshold;
        });

    std::cout << "���������� ��������� � ��������� ������ " << threshold << ": " << count << std::endl;


    std::cout << "\n3) fill ��� ���������� ������� ������ �������." << std::endl;
    const int size = 5;
    int myArray[size];

    // ���������� std::fill ��� ���������� ������� ��������� 42
    int valueToFill = 42;
    std::fill(myArray, myArray + size, valueToFill);

    // ������� ���������� �������
    std::cout << "������ ����������� ������ 42:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}