#include <cstdio>

typedef int Z;

Z lt(Z n, Z k) {
    return k < n ? 1 : 0;
}

Z sub(Z n, Z k) {
    return k - n;
}

Z chs(Z n) {
    return sub(0, n); 
}

Z add(Z n, Z k) {
    return sub(chs(n), k);  
}

Z le(Z n, Z k) {
  
    return lt(add(n, 1), k) ? 0 : 1; 
}

Z not(Z p) {
    return lt(p, 1);  
}

Z le_proper(Z n, Z k) {

    return not(lt(k, n));
}


void test00() {
    fprintf(stdout, "lt(0, -1) ==> %3d\n", lt(0, -1));
    fprintf(stdout, "lt(0,  0) ==> %3d\n", lt(0,  0));
    fprintf(stdout, "lt(0,  1) ==> %3d\n", lt(0,  1));
}

void test01() {
    fprintf(stdout, "sub(0, 42) ==> %3d\n", sub(0, 42));
    fprintf(stdout, "sub(42, 0) ==> %3d\n", sub(42, 0));
    fprintf(stdout, "sub(0, 67) ==> %3d\n", sub(0, 67));
    fprintf(stdout, "sub(67, 0) ==> %3d\n", sub(67, 0));
    fprintf(stdout, "sub(42, 67) ==> %3d\n", sub(42, 67));
    fprintf(stdout, "sub(67, 42) ==> %3d\n", sub(67, 42));
}

void test02() {
    Z r1 = 42 - (67 - 25);
    Z r2 = sub(25, sub(67, 42));

    fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
}

void test03() {
    Z r1 = 1024 - 512 - (67 - (42 - 512));
    Z r2 = sub(sub(512, sub(67, sub(42, 512))), 1024);

    fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
}

void test04() {
    fprintf(stdout, "chs(5) ==> %3d\n", chs(5));
    fprintf(stdout, "chs(-3) ==> %3d\n", chs(-3));
    fprintf(stdout, "chs(0) ==> %3d\n", chs(0));
}

void test05() {
    fprintf(stdout, "add(5, 3) ==> %3d\n", add(5, 3));
    fprintf(stdout, "add(-2, 7) ==> %3d\n", add(-2, 7));
    fprintf(stdout, "add(4, -6) ==> %3d\n", add(4, -6));
}

void test06() {
    fprintf(stdout, "le(5, 3) ==> %3d\n", le(5, 3));  
    fprintf(stdout, "le(5, 5) ==> %3d\n", le(5, 5)); 
    fprintf(stdout, "le(3, 5) ==> %3d\n", le(3, 5));  
}

int square(int n) {

    if (lt(n, 1)) {  
        return 0;
    }
  
    Z prev_square = square(sub(n, 1));
    Z odd_term = sub(add(n, n), 1);  
    return add(prev_square, odd_term);
}

void test07() {
    for (int i = 0; i < 9; ++i) {
        Z r1 = i * i;
        Z r2 = square(i);
        fprintf(stdout, "C++ : %3d | Zilly: %3d\n", r1, r2);
    }
}

int reverse(int n, int acc) {
    if (lt(n, 1)) { 
        return acc;
    }
    Z last_digit = sub(n, add(mul(div(n, 10), 10));  
    Z new_acc = add(mul(acc, 10), last_digit);
    return reverse(div(n, 10), new_acc);
}


int div(int a, int b) {
    
    if (lt(a, b)) {
        return 0;
    }
    return add(1, div(sub(a, b), b));
}

int mul(int a, int b) {
    if (lt(b, 1)) {
        return 0;
    }
    return add(a, mul(a, sub(b, 1)));
}

int palindromo(int n) {

    if (lt(n, 0)) {
        n = chs(n);  
    }

    
    if (lt(n, 10)) {
        return 1;  
    }


    if (le(n, 999)) { 
        Z first = div(n, 100);
        Z last = sub(n, mul(div(n, 10), 10));
        return lt(sub(first, last), 1) && lt(sub(last, first), 1) ? 1 : 0;
    }

    return 0;  
}

void test08() {
    int numeros[] = {121, 123, 454, 789, 1331, 12321, 1234321, 123456};
    for(int i = 0; i < 8; ++i) {
        int n = numeros[i];
        int r = palindromo(n);
        fprintf(stdout, "palindromo(%d) ==> %d\n", n, r);
    }
}

int main() {
    test00();
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08();
    return 0;
}