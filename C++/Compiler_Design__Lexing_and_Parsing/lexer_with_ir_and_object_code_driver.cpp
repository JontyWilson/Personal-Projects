#include <iostream>

extern "C" {
    double testLogicalOr(double x, double y);
    double testLogicalXor(double x, double y);
    double testLogicalAnd(double x, double y);
}

int main() {
    printf("0 OR 0: %s\n", testLogicalOr(0, 0) ? "true" : "false");
    printf("0 OR 1: %s\n", testLogicalOr(0, 1) ? "true" : "false");
    printf("1 OR 0: %s\n", testLogicalOr(1, 0) ? "true" : "false");
    printf("1 OR 1: %s\n", testLogicalOr(1, 1) ? "true" : "false");

    printf("\n");

    printf("0 AND 0: %s\n", testLogicalAnd(0, 0) ? "true" : "false");
    printf("0 AND 1: %s\n", testLogicalAnd(0, 1) ? "true" : "false");
    printf("1 AND 0: %s\n", testLogicalAnd(1, 0) ? "true" : "false");
    printf("1 AND 1: %s\n", testLogicalAnd(1, 1) ? "true" : "false");

    printf("\n");

    printf("0 XOR 0: %s\n", testLogicalXor(0, 0) ? "true" : "false");
    printf("0 XOR 1: %s\n", testLogicalXor(0, 1) ? "true" : "false");
    printf("1 XOR 0: %s\n", testLogicalXor(1, 0) ? "true" : "false");
    printf("1 XOR 1: %s\n", testLogicalXor(1, 1) ? "true" : "false");
}

// clang++ lexer_with_ir_and_object_code_driver.cpp output.o -o lexer_with_ir_and_object_code_driver -Wno-everything