#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node {
  int value;
  Node *next;
};

class LinkedList {
  Node *head;
  int size;

public:
  LinkedList() : head{nullptr}, size{0} {};

  int get_size() { return size; }

  bool is_empty() {
    if (head == nullptr) {
      return true;
    }
    return false;
  }

  // TODO Test
  int value_at(int index) {
    Node *current;
    int count = 0;
    for (current = head; current != nullptr; current = current->next) {
      if (count == index) {
        return current->value;
      }
      count++;
    }
    return 0;
  }

  void push_front(int value) {
    Node *n = new Node();
    n->value = value;
    if (head != nullptr) {
      n->next = head;
      head = n;
      size++;
    } else {
      head = n;
      head->next = nullptr;
      size++;
    }
  }

  void print_ll() {
    while (head != nullptr) {
      std::cout << head->value << std::endl;
      head = head->next;
    }
  }
};

int main() {
  LinkedList linkL;
  linkL.get_size();
  linkL.is_empty();
  linkL.push_front(1);
  linkL.push_front(3);
  linkL.push_front(5);
  linkL.push_front(7);
  linkL.value_at(2);
  linkL.print_ll();
}
