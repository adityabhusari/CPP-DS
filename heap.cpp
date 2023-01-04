#include <iostream>

using namespace std;

template<class T>
class MinHeap {
    T *arr;
    int capacity;
    int size;

    void swapAt(int a, int b) {
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

public:

    MinHeap(int capacity) {
        this->capacity = capacity;
        this->arr = new T[capacity];
        this->size = 0;
    }

    bool insert(T newItem) {
        if (capacity > size) {
            arr[size++] = newItem;
            int n = size - 1;
            while (n && arr[(n - 1) / 2] > arr[n]) {
                this->swapAt(n, (n - 1) / 2);
                n = (n - 1) / 2;
            }
            return true;
        } else {
            return false;
        }
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    T* remove() {
        if (size) {
            swapAt(0, --size);
            int n = 0;
            while (1) {
                if (size > 2 * n + 1) {
                    if (size > 2 * n + 2) {
                        if (arr[n] > arr[2*n+1] || arr[n] > arr[2*n + 2]) {
                            int nextPosition = arr[2*n+1] > arr[2*n+2] ? 2*n+2 : 2*n+1;
                            swapAt(nextPosition, n);
                            n = nextPosition;
                        } else {
                            break;
                        }
                    } else {
                        if (arr[n] > arr[2*n+1]) {
                            int nextPosition = 2*n+1;
                            swapAt(nextPosition, n);
                            n = nextPosition;
                        } else {
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
            return &arr[size];
        } else {
            return NULL;
        }
    }
};