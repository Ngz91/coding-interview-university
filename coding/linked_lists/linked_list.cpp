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

  // TODO
  void add_node() {}
};

int main() {
  LinkedList linkL;
  linkL.get_size();
  linkL.is_empty();
  linkL.value_at(2);
}
