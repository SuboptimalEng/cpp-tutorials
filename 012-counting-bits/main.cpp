#include <bitset>
#include <iostream>
using namespace std;

void print(int number, int result, int expected) {
  cout << "=> number -> " << number << ", binary -> " << bitset<4>(number) << ", result -> "
       << result << ", expected -> " << expected << endl;
}

// count the number of `1` bits
// 12 -> 1100 -> 2
int counting_bits(int num) {
  int count = 0;
  while (true) {
    if (num == 0) {
      break;
    }
    // 1101 & 1 -> 1
    // 110 & 1 -> 0
    // 11 & 1 -> 1
    // 1 & 1 -> 1
    if ((num & 1) == 1) {
      count++;
    }
    num = num >> 1;
  }
  return count;
}

// thumbnail code...
int counting_bits_2(int num) {
  int count = 0;
  while (num) {
    if (num & 1)
      count++;
    num = num >> 1;
  }
  return count;
}

int main() {
  // 0 -> 0000 -> 0
  // 1 -> 0001 -> 1
  // 2 -> 0010 -> 1
  // 3 -> 0011 -> 2
  // 4 -> 0100 -> 1
  // 8 -> 1000 -> 1
  // 13 -> 1101 -> 3
  // 15 -> 1111 -> 4
  vector<int> numbers{0, 1, 2, 3, 4, 8, 13, 15};
  vector<int> expected_result{0, 1, 1, 2, 1, 1, 3, 4};

  for (int i = 0; i < numbers.size(); i++) {
    int result = counting_bits(numbers[i]);
    // result = counting_bits_2(numbers[i]);
    print(numbers[i], result, expected_result[i]);
  }

  return 0;
}
