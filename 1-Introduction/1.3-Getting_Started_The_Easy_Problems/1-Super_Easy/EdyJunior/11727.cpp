//
//  main.cpp
//  11727 Cost Cutting
//
//  Created by Edvaldo Junior on 05/06/17.
//  Copyright © 2017 Edvaldo Junior. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp (int a, int b) {
    return a < b;
}

int main(int argc, const char * argv[]) {
    
    int n, a;
    vector<int> vec;
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        vec.clear();
        for (int i = 0; i < 3; i++) {
            scanf("%d", &a);
            vec.push_back(a);
        }
        sort(vec.begin(), vec.end(), cmp);
        printf("Case %d: %d\n", i, vec[1]);
    }
    return 0;
}
