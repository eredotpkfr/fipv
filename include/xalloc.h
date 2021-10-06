/*
 * Header file for managing memory allocations
 * and allocation exceptions.
 *
 * Function: xmem_err
 * ----------------------------
 * Throw exception and exit program if p is NULL pointer.
 *
 * p: target pointer (void *)
 * returns: returns p if p is not NULL (void *)
 *
 * Function: xmalloc
 * ----------------------------
 * Allocate memory from heap and initialize with zero values.
 *
 * size: allocation byte size (size_t)
 * returns: returns head of allocated address (void *)
 *
 * Function: xrealloc
 * ----------------------------
 * Reallocate given pointer address.
 *
 * target: target pointer to be reallocated (void *)
 * new_size: new allocation size (size_t)
 * returns: returns head of reallocated address (void *)
 *
 * Function: xcalloc
 * ----------------------------
 * Allocate memory from heap with count and
 * automatic initialize with zero values.
 *
 * count: allocation count (size_t)
 * size: allocation size (size_t)
 * returns: returns head of allocated address (void *)
 */

#ifndef _XALLOC_H_
#define _XALLOC_H_

// printed error message when allocation is failed.
#define MEMORY_ERR "Out of memory!\n"

#include <stdlib.h> /* for allocating operations */

void *xmem_err(void *p);
void *xmalloc(size_t size);
void *xrealloc(void *target, size_t new_size);
void *xcalloc(size_t count, size_t size);

void *xmem_err(void *p) {
  if (!p) {
    fprintf(stderr, MEMORY_ERR);
    exit(EXIT_FAILURE); /* 1 */
  }
  return p;
}

void *xmalloc(size_t size) {
  void *pointer = xmem_err(malloc(size));
  memset(pointer, 0, size); /* set zero values */

  return pointer;
}

void *xrealloc(void *target, size_t new_size) {
  return xmem_err(realloc(target, new_size));
}

void *xcalloc(size_t count, size_t size) {
  return xmem_err(calloc(count, size));
}

#endif
