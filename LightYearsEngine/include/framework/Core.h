#include <stdio.h>

namespace ly {
// add macro
#define  LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}