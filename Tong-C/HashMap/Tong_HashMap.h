//
//  Tong_HashMap.h
//  Tong-C
//
//  Created by PrinceSmall on 2021/8/13.
//

#ifndef Tong_HashMap_h
#define Tong_HashMap_h

#include <stdio.h>

typedef struct hashEntray{
    void *key;
    void *value;
    struct hashEntray *next;
}*Entray;

#endif /* Tong_HashMap_h */
