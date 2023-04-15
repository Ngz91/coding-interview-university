#include <iostream>
#include <exception>

using namespace std;

struct Node {
  int value;
  Node *next;
};

// Only int values to keep it simple. For a multiple values types LinkedList use
// templates.
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
        cout << "Found at index " << index << ": " << current->value << endl;
        return current->value;
      }
      count++;
    }
    return 0;
  }

  void push_front(int value) {
    Node *n = new Node();
    n->value = value;
    if (head == nullptr) {
      head = n;
      head->next = nullptr;
      size++;
      return;
    }
    n->next = head;
    head = n;
    size++;
  }

  void pop_front() {
    if (head != nullptr) {
      Node *tmp = head;
      head = head->next;
      delete tmp;
      size--;
    }
  }

  void push_back(int value) {
    Node *n = new Node();
    n->value = value;
    n->next = nullptr;

    if (head == nullptr) {
      head = n;
      size++;
      return;
    }

    Node *current;
    for (current = head; current != nullptr; current = current->next) {
      if (current->next == nullptr) {
        current->next = n;
        size++;
        return;
      }
    }
  }

  void pop_back() {
    if (head == nullptr) {
      return;
    } else if (size == 1) {
      delete head;
      Node *head = new Node();
      head->next = nullptr;
      return;
    }

    Node *current;
    for (current = head; current != nullptr; current = current->next) {
      if (current->next->next == nullptr) {
        current->next = nullptr;
        size--;
        return;
      }
    }
  }

  int front() {
    if (head == nullptr) {
      throw out_of_range("Empty linked list.");
    }
    return head->value;
  }

  int back() {
    if (head == nullptr) {
      throw out_of_range("Empty linked list.");
    }
    Node *current;
    for (current = head; current != nullptr; current = current->next) {
      if (current->next == nullptr) {
        return current->value;
      }
    }
    return 1;
  }

  void print_ll() {
    Node *tmp = head;
    while (tmp != nullptr) {
      std::cout << tmp->value << std::endl;
      tmp = tmp->next;
    }
    delete tmp;
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

  cout << "Size: " << linkL.get_size() << endl;

  linkL.pop_front();
  linkL.print_ll();

  linkL.push_back(2);
  cout << endl;
  linkL.print_ll();

  linkL.pop_back();
  cout << endl;
  linkL.print_ll();

  cout << endl;
  cout << "Front: " << linkL.front() << " Back: " << linkL.back() << endl;
}
