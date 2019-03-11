//
//  Fib.c
//  stack
//
//  Created by 王俊 on 2019/3/11.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "Fib.h"

#pragma mark - test
void FibonacciTest(void) {
    printf("========= FibonacciTest =========\n");
    for (int i=0; i<40; i++) {
        printf("i: %d -- fib: %d\n", i, Fibonacci(i));
    }
}
#pragma makr - functions
int Fibonacci(int i) {
    if (i<2) {
        return i==0?0:1;
    }
    return Fibonacci(i-1)+Fibonacci(i-2);
}

