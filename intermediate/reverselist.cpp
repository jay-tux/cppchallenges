#include <iostream>

struct list {
  struct node {
    int value;
    node *next;
  };

  node *start;
  node *last;

  inline void add(int v) {
    if (last == nullptr) {
      start = new node{v, nullptr};
      last = start;
    } else {
      last->next = new node{v, nullptr};
      last = last->next;
    }
  }

  inline void print() {
    node *curr = start;
    while (curr != nullptr) {
      std::cout << "[ " << curr->value << " ] -> ";
      curr = curr->next;
    }
    std::cout << "[ NULL ]" << std::endl;
  }
};

void revert(list &l) {
  auto inner = [](list::node *p1, list::node *p2) {
    list::node *next = p2->next;
    p2->next = p1;
    return next;
  };

  list::node *newfirst = l.last;
  list::node *prev = nullptr;
  list::node *ptr = l.start;
  while (ptr != nullptr) {
    list::node *tmp = inner(prev, ptr);
    prev = ptr;
    ptr = tmp;
  }

  l.start = newfirst;
  l.last = prev;
}

int main(int argc, const char **argv) {
  if (argc == 1) {
    std::cout << "Empty list" << std::endl;
    return 0;
  }

  list l{nullptr, nullptr};
  for (int i = 1; i < argc; i++) {
    l.add(std::stoi(argv[i]));
  }

  l.print();
  revert(l);
  l.print();
}
