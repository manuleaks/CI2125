#include <iostream>

int main(int argc, char* argv[])
{
  if (argc > 1) {
    std::cout << "Arguments passed:\n";
    for (int i = 1; i < argc; ++i) {
      std::cout << argv[i] << "\n";
    }
  } else {
    std::cout << "No arguments passed.\n";
  }
	return 0;
}
