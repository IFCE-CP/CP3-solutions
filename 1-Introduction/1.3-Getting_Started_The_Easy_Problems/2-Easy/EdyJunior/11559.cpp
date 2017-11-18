//
//  main.cpp
//  11559 Event Planning
//
//  Created by Edvaldo Junior on 08/06/17.
//  Copyright © 2017 Edvaldo Junior. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

#define INF 123456789

int main(int argc, const char * argv[]) {
    
    int n, b, h, w, p, a;
    
    while (scanf("%d %d %d %d", &n, &b, &h, &w) == 4 && n > 0) {
        int menor = INF;
        for (int i = 0; i < h; i++) {
            bool flag = false;
            scanf("%d", &p);
            for (int j = 0; j < w; j++) {
                scanf("%d", &a);
                if (n <= a)
                    flag = true;
            }
            
            int custo = flag ? n * p : INF;
            if (custo < menor)
                menor = custo;
        }
        if (menor <= b)
            printf("%d\n", menor);
        else
            printf("stay home\n");
    }
    
    return 0;
}
