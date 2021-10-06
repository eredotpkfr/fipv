/*
 * Type definitions are listed in this header file.
 */

#include <stdbool.h> /* for bool data types */

#ifndef _TYPES_H_
#define _TYPES_H_

// Struct type definition for store splitted results
typedef struct split_t {
  size_t length; /* splitted tokens length */
  char **tokens; /* tokenizer */
} split_t;

#endif
