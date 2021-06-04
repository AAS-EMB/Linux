#include <iostream>

unsigned int Factorial(const unsigned int &Value);

int main(int argc, char *argv[]) {
  unsigned int Value;
  std::cout << "\r\nEnter a value for calculating the factorial: ";
  std::cin >> Value;
  std::cout << Value << "!"
            << " = " << Factorial(Value) << std::endl;
  return 0;
}

/*!
 * @brief A function calculating the factorial
 *
 * @param Value    Reference to the object
 */
unsigned int Factorial(const unsigned int &Value) {
  if (Value == 1)
    return 1;
  return Value * Factorial(Value - 1);
}
