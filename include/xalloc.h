#ifndef _XALLOC_H_
#define _XALLOC_H_

// printed error message when allocation is failed.
#define MEMORY_ERR "Out of memory!\n"

#include <stdlib.h> /* for allocating operations */

void *xmem_err(void *p);
void *xmalloc(size_t size);
void *xrealloc(void *target, size_t new_size);
void *xcalloc(size_t count, size_t size);

/**
 * Throw exception and exit program if p is ``NULL`` pointer.
 *
 * Args:
 *     p(void *): target pointer
 *
 * Returns:
 *     ``p`` if ``p`` is not ``NULL``
 */
void *xmem_err(void *p) {
  if (!p) {
    fprintf(stderr, MEMORY_ERR);
    exit(EXIT_FAILURE); /* 1 */
  }
  return p;
}

/**
 * Allocate memory from heap and initialize with zero values.
 *
 * Args:
 *     size(size_t): allocation byte size
 *
 * Returns:
 *     head of allocated address
 */
void *xmalloc(size_t size) {
  void *pointer = xmem_err(malloc(size));
  memset(pointer, 0, size); /* set zero values */

  return pointer;
}

/**
 * Reallocate given pointer address.
 *
 * Args:
 *     target(void *): target pointer to be reallocated
 *     new_size(size_t): new allocation size
 *
 * Returns:
 *     head of reallocated address
 */
void *xrealloc(void *target, size_t new_size) {
  return xmem_err(realloc(target, new_size));
}

/**
 * Allocate memory from heap with count and
 *     automatic initialize with zero values.
 *
 * Args:
 *     count(size_t): allocation count
 *     size(size_t): allocation size
 *
 * Returns:
 *     head of allocated address
 */
void *xcalloc(size_t count, size_t size) {
  return xmem_err(calloc(count, size));
}

#endif
