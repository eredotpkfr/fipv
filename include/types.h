#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdbool.h> /* for bool data types */

/**
 * Struct type definition for store splitted results.
 *
 * Members:
 *     length(size_t): splitted tokens length
 *     tokens(char **): tokenizer
 */
typedef struct split_t {
  size_t length;
  char **tokens;
} split_t;

#endif
