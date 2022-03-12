/* mmencode.h - MeowMeow, a stream encoder/decoder */

/*
 * The #ifdef, #define, #endif construction is collectively known as a "guard."
 * This keeps the C compiler from including this file more than once per file.
 * The compiler will complain if it finds multiple definitions/prototypes/
 * declarations, so the guard is a must-have for header files.
 *
 * Aside from the "guard", there are only two things here:
 *  1. An #include directive
 *  2. A function prototype declaration
 *
 * We include <stdio.h> here to bring in the definition of FILE that is used in
 * the function prototype. The prototype can be included by other C files to
 * establish that function in the file's namespace. You can think of each  file
 * as a separate namespace, which means variables and functions in one file are
 * not usable by functions or variables in another file.
 *
 * Writing header files is complex, and it is tough to manage in larger
 * projects. Use guards.
 *
 */

#ifndef _MMENCODE_H
#define _MMENCODE_H

#include <stdio.h>

int mm_encode(FILE *src, FILE *dst);

#endif /* _MMENCODE_H */
