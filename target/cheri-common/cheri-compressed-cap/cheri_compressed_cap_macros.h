    do {                                                                                                               \
        if (!(cond)) {                                                                                                 \
// NB: Do not use GNU statement expressions as this is used by LLVM which warns
// on any uses during its build. These are therefore unsafe if any arguments
// have side-effects.
#define _CC_MIN(a, b) ((a) < (b) ? (a) : (b))
#define _CC_MAX(a, b) ((a) > (b) ? (a) : (b))
    __extension__({                                                                                                    \
    })
