#include <cstdlib>
#include <iostream>

struct node {
  int number;
  node *next;
};

int main() {
  node *head;
  node *n1 = nullptr;
  node *n2 = nullptr;
  node *n3 = nullptr;
  node *n4 = nullptr;

  n1 = new node();
  n2 = new node();
  n3 = new node(); // use it for insertion
  n4 = new node();

  n1->number = 1;
  n2->number = 2;
  n4->number = 4;

  n1->next = n2;
  n2->next = n4;
  n4->next = nullptr;

  head = n1;
  while (head != nullptr) {
    std::cout << head->number << std::endl;
    head = head->next;
  }

  std::cout << std::endl;

  // Insert
  head = n1; // Used like this only for this example
  n3->number = 3;
  n3->next = n4;
  n2->next = n3;
  while (head != nullptr) {
    std::cout << head->number << std::endl;
    head = head->next;
  }
}
