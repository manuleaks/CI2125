#include <iostream>
#include <functional>
auto not_ = [](int x) -> int { 
    return x ? 0 : 1; 
};
auto and_ = [](int x) { 
    return [x](int y) -> int { 
        return (x && y) ? 1 : 0; 
    }; 
};
auto or_ = [](int x) { 
    return [x](int y) -> int { 
        return (x || y) ? 1 : 0; 
    }; 
};
auto nand = [](int x) { 
    return [x](int y) -> int { 
        return not_(and_(x)(y)); 
    }; 
};
auto D = [](int x) {
    return [x](int y) {
        return [x, y](int z) -> int {
            return and_(or_(x)(y))(nand(y)(z));
        };
    };
};

int main(int argc, char* argv[])
{
  if (argc == 2) {
    int x = std::stoi(argv[1]);
    std::cout << "not_(" << x << ") = " << not_(x) << "\n";
  } 
  else if (argc == 3) {
    int x = std::stoi(argv[1]);
    int y = std::stoi(argv[2]);
    std::cout << "and_(" << x << ")(" << y << ") = " << and_(x)(y) << "\n";
    std::cout << "or_(" << x << ")(" << y << ") = " << or_(x)(y) << "\n";
    std::cout << "nand(" << x << ")(" << y << ") = " << nand(x)(y) << "\n";
  }
  else if (argc == 4) {
    int x = std::stoi(argv[1]);
    int y = std::stoi(argv[2]);
    int z = std::stoi(argv[3]);
    std::cout << "D(" << x << ")(" << y << ")(" << z << ") = " << D(x)(y)(z) << "\n";
    std::cout << "\nDesglose:\n";
    std::cout << "or_(" << x << ")(" << y << ") = " << or_(x)(y) << "\n";
    std::cout << "nand(" << y << ")(" << z << ") = " << nand(y)(z) << "\n";
    std::cout << "and_(" << or_(x)(y) << ")(" << nand(y)(z) << ") = " << D(x)(y)(z) << "\n";
  }
  else {
    std::cout << "Uso:\n";
    std::cout << "  1 argumento:  ./main x         -> calcula not_(x)\n";
    std::cout << "  2 argumentos: ./main x y       -> calcula and_, or_, nand\n";
    std::cout << "  3 argumentos: ./main x y z     -> calcula D(x)(y)(z)\n";
  }
  return 0;
}