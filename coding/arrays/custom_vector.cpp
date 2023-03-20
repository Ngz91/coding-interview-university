#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

template <typename T> class CustomVector {

  T *arr;
  int size;
  int capacity;

public:
  CustomVector() : arr(new T[1]), size(0), capacity(1) {}
  ~CustomVector() { delete[] arr; }

  int get_capacity() { return capacity; }

  int get_size() { return size; }

  bool is_empty() { return !(size != 0); }

  T at(int index) {
    if (index < capacity) {
      return arr[index];
    } else {
      throw std::out_of_range("Out of range");
    }
  }

  void push(T item) {
    if (size == capacity) {
      T *temp = new T[2 * capacity];
      for (int i = 0; i < capacity; i++) {
        temp[i] = arr[i];
      }
      delete[] arr;
      capacity *= 2;
      arr = temp;
    }

    arr[size] = item;
    size++;
  }

  void insert(int index, T item) {
    if (index == capacity) {
      push(item);
    } else {
      capacity *= 2;
      T *temp = new T[capacity];
      for (int i = 0; i < size; i++) {
        if (i >= index) {
          temp[i + 1] = arr[i];
        } else {
          temp[i] = arr[i];
        }
      }

      temp[index] = item;
      arr = temp;
      size++;
    }
  }

  void prepend(int item) {
    if (size == 0) {
      push(item);
    } else {
      capacity *= 2;
      T *temp = new T[capacity];
      temp[0] = item;
      for (int i = 0; i < size; i++) {
        temp[i + 1] = arr[i];
      }

      arr = temp;
      size++;
    }
  }

  void pop() {
    capacity--;
    size--;
  }
  
  //TODO
  void del_at(int index) {
    cout << "Deleting " << arr[index] << " from array" << endl;
  }

  void print_all() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << endl;
    }
  }
};

int main() {
  CustomVector<int> v;

  cout << v.get_size() << endl;
  cout << v.get_capacity() << endl;
  cout << v.is_empty() << endl;
  v.push(33);
  v.push(78);
  v.push(55);

  cout << v.at(2) << endl;
  v.print_all();

  v.insert(1, 66);

  cout << endl;
  v.print_all();

  cout << endl;
  v.prepend(69);
  v.print_all();
  
  cout << endl;
  v.pop();
  v.print_all();

  cout << endl;
  v.del_at(2);
}
