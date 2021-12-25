#include "macrolib.h"

#define M(p, x) (p##x)
#define R(p, r, x) (p)r (p##x)
#define RM(p, r, x) (p)r MACROLIB_MAP(M, x, p)
#define MR(p, x) MACROLIB_REDUCE(R, (x)i, p)
MACROLIB_MAP(M, a, (x)(y)(z)) 
MACROLIB_REDUCE(R, (a)i, (x)(y)(z)) 
MACROLIB_REDUCE(RM, ((a)(b)(c))i, (x)(y)(z)) 
MACROLIB_MAP(MR, (a)(b)(c), (x)(y)(z)) 
