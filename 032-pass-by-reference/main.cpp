#include <iostream>
#include <vector>

struct Person {
  std::string name;
  std::string bank_name;
  // 10...
};

void print_person(const Person& p) {
  std::cout << p.name << std::endl;
}

void update_bank(Person& p, std::string new_bank_name) {
  p.bank_name = "JP Morgan";
  // verify
  // send email
  // notifications
}

void add_one(int x) {
  x++;
}

void add_one_by_ref(int& x) {
  x++;
}

int main() {
  int a = 1;
  add_one(a);
  std::cout << "add_one a: " << a << std::endl;
  add_one_by_ref(a);
  std::cout << "add_one_by_ref a: " << a << std::endl;
  return 0;
}
