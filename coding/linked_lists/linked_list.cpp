#include <iostream>
#include <exception>
#include <memory>

using namespace std;

struct Node {
  int value;
  Node *next;

  // Unique pointer to test
  std::unique_ptr<Node> unext;
};

// Only int values to keep it simple. For a multiple values types LinkedList use
// templates. Also, it's better to use a tail pointer to optimize a lot of the
// funtions.
class LinkedList {
  Node *head;
  int size;

  // Unique pointer to test
  std::unique_ptr<Node> uhead;

public:
  LinkedList() : head{nullptr}, size{0} {};

  int get_size() { return size; }

  bool is_empty() {
    if (head == nullptr) {
      return true;
    }
    return false;
  }

  int value_at(int index) {
    if (head == nullptr || size - 1 < index) {
      throw out_of_range("Out of range");
    }

    Node *current = head;
    int count = 0;

    while (current != nullptr && count != index) {
      current = current->next;
      count++;
    }
    cout << "Found at index " << index << ": " << current->value << endl;
    return current->value;
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

  /*void unique_push_back(int value) {
    // Function that uses smart pointer instead of normal pointer, implement
    // after linked list is complete
    std::unique_ptr<Node> n = std::make_unique<Node>();
    n->value = value;
    n->next = nullptr;

    if (uhead == nullptr) {
      uhead = std::move(n);
      size++;
      return;
    }

    Node *current;
    for (current = uhead.get(); current != nullptr; current = current->next) {
      if (current->unext == nullptr) {
        current->unext = std::move(n);
        size++;
        return;
      }
    }
  }*/

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
    for (current = head; current->next != nullptr; current = current->next) {
    }
    return current->value;
  }

  void insert(int index, int value) {
    if (head == nullptr || index > size - 1) {
      throw out_of_range("Empty linked list.");
    }

    Node *n = new Node();
    n->value = value;
    n->next = nullptr;

    if (size == 1) {
      n->next = head;
      head = n;
      return;
    }

    Node *current;
    current = head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    n->next = current->next;
    current->next = n;
    size++;
  }

  void erase(int index) {
    if (head == nullptr || index > size - 1) {
      throw out_of_range("Empty linked list");
    } else if (index == size - 1) {
      this->pop_back();
      return;
    } else if (size == 1 && index == 1) {
      this->pop_front();
      return;
    }

    Node *prev = new Node();
    Node *current;
    current = head;
    for (int i = 0; i < index; i++) {
      prev = current;
      current = current->next;
    }

    prev->next = current->next;
    delete current;
    size--;
  }

  int value_n_from_end(int n) {
    if (head == nullptr || n > size - 1) {
      throw out_of_range("Empty linked list");
    } else if (n == size) {
      return front();
    }
    Node *current;
    current = head;
    for (int diff = (size - n) - 1; diff != 0; diff--) {
      current = current->next;
    }

    return current->value;
  }

  void reverse() {
    if (head == nullptr || size == 1) {
      cout << "Empty linked list or size equal 1";
      return;
    }

    Node *current = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current != nullptr) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    head = prev;
  }

  // TODO
  void remove_value(int n) {}

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

  cout << endl;
  linkL.insert(2, 9);

  linkL.print_ll();

  cout << endl;
  linkL.erase(1);

  linkL.print_ll();
  linkL.push_back(7);
  linkL.push_back(6);

  cout << endl;

  linkL.print_ll();

  cout << endl;
  cout << linkL.value_n_from_end(3) << endl;

  cout << endl;

  linkL.reverse();
  linkL.print_ll();
}
