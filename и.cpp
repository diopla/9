﻿#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(const T1& f, const T2& s) : first(f), second(s) {}

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }

    void setFirst(const T1& f) { first = f; }
    void setSecond(const T2& s) { second = s; }
};
template <typename T>
T findMin(const T arr[], int size) {


    T minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}
template <typename T>
class Point {
private:
    T x;
    T y;
public:
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    T getX() const { return x; }
    T getY() const { return y; }

    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};
template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int top;

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i <= top; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(int initialCapacity = 10) : capacity(initialCapacity), top(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) {
        if (top == capacity - 1) {
            resize(capacity * 2);
        }
        data[++top] = value;
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Стек пуст");
        }
        return data[top--];
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Стек пуст");
        }
        return data[top];
    }

    bool isEmpty() const {
        return top == -1;
    }
};
template <typename T>
void copyArray(const T source[], T destination[], int size) {
    for (int i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}
template <typename T>
class Array {
private:
    T* data;
    int size;

public:
    Array(int size = 0) : size(size) {
        data = new T[size];
    }

    ~Array() {
        delete[] data;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне границ массива");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне границ массива");
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }

    void resize(int newSize) {
        T* newData = new T[newSize];
        int elementsToCopy = newSize < size ? newSize : size;

        for (int i = 0; i < elementsToCopy; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;
    }
};
template <typename T>
bool areEqual(const T& a, const T& b) {
    return a == b;
}
template <typename T>
class Complex {
private:
    T real;
    T imag;
public:
    Complex(T r = 0, T i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    void print() const {
        std::cout << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << "i";
    }
};
template <typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        std::swap(arr[i], arr[size - 1 - i]);
    }
}
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    T dequeue() {


        T value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;

        if (isEmpty()) {
            rear = nullptr;
        }

        return value;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }
};
template <typename T>
int findElement(const T arr[], int size, const T& value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
template <typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int size;

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void add(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне границ");
        }

        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне границ");
        }
        return data[index];
    }

    int getSize() const {
        return size;
    }
};
template <typename T>
std::vector<T> arrayIntersection(const T* arr1, size_t size1, const T* arr2, size_t size2) {
    std::vector<T> result;
    for (size_t i = 0; i < size1; ++i) {
        for (size_t j = 0; j < size2; ++j) {
            if (arr1[i] == arr2[j]) {

                if (std::find(result.begin(), result.end(), arr1[i]) == result.end()) {
                    result.push_back(arr1[i]);
                }
                break;
            }
        }
    }
    return result;
}


template <typename T>
class Wrapper {
private:
    T value;
public:
    Wrapper(const T& val) : value(val) {}

    T getValue() const {
        return value;
    }


    void setValue(const T& newValue) {
        value = newValue;
    }
};


template <typename T>
void bubbleSort(T* arr, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template <typename T>
void printArray(const T* arr, size_t size, const std::string& message) {
    std::cout << message;
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    setlocale(LC_ALL, "Ru");
    int a = 5, b = 10;
    mySwap(a, b);
    std::cout << "После swap: a = " << a << ", b = " << b << std::endl;


    Pair<std::string, int> person("Иван", 25);
    std::cout << "Pair: " << person.getFirst() << ", " << person.getSecond() << std::endl;


    int intArr[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    std::cout << "Минимальный элемент: " << findMin(intArr, 8) << std::endl;


    Point<double> p1(1.5, 2.5), p2(3.0, 4.0);
    auto p3 = p1 + p2;
    std::cout << "Сумма точек: "; p3.print(); std::cout << std::endl;





    Stack<std::string> stack;
    stack.push("Первый");
    stack.push("Второй");
    std::cout << "Верхний элемент стека: " << stack.peek() << std::endl;


    int source[] = { 1, 2, 3 }, dest[3];
    copyArray(source, dest, 3);
    std::cout << "Скопированный массив: " << dest[0] << ", " << dest[1] << ", " << dest[2] << std::endl;


    Array<float> arr(5);
    arr[0] = 1.5f; arr[1] = 2.5f;
    std::cout << "Элемент массива: " << arr[0] << std::endl;
    int y = 5, c = 5;
    std::cout << ": " << std::boolalpha << areEqual(a, y) << std::endl;

    Complex<double> c1(1.5, 2.5), c2(3.0, -1.0);
    auto c3 = c1 + c2;
    std::cout << ": "; c3.print(); std::cout << std::endl;



    Queue<std::string> q;
    q.enqueue("первое");
    q.enqueue("");
    std::cout << ": " << q.dequeue() << std::endl;


    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 3, 4, 5, 6, 7 };
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

    auto intersection = arrayIntersection(arr1, size1, arr2, size2);
    std::cout << "Пересечение массивов: ";
    for (const auto& num : intersection) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;


    Wrapper<int> wrapper(42);
    std::cout << "Начальное значение обертки: " << wrapper.getValue() << std::endl;
    wrapper.setValue(100);
    std::cout << "Новое значение обертки: " << wrapper.getValue() << std::endl << std::endl;


    double arr3[] = { 5.5, 2.2, 8.8, 1.1, 3.3 };
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);

    printArray(arr3, size3, "Массив до сортировки: ");
    bubbleSort(arr3, size3);
    printArray(arr3, size3, "Массив после сортировки: ");
}