//
//  main.cpp
//  11172 - Relational Operators
//
//  Created by Edvaldo Junior on 05/06/17.
//  Copyright © 2017 Edvaldo Junior. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n, a, b;
    
    for(scanf("%d", &n); n > 0; n--) {
        scanf("%d %d", &a, &b);
        printf("%c\n", a < b ? '<' : (a > b ? '>' : '='));
    }
    return 0;
}
