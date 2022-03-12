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
};

void print_reverse(list::node *p) {
  if (p == nullptr)
    return;

  print_reverse(p->next);
  std::cout << p->value << " ";
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

  print_reverse(l.start);
  std::cout << std::endl;
}
