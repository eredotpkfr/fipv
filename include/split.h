#ifndef _SPLIT_H_
#define _SPLIT_H_

#define DEFAULT_BUFFER_SIZE 8

#include "types.h"
#include "xalloc.h"
#include <string.h>

struct split_t split(char *target_str, char *delimiters);
void free_split(struct split_t *split_ptr);
bool free_split_r(struct split_t *p, bool ret);

/**
 * Basically it splits dynamically given string.
 *
 * Args:
 *     target_str(char *): target string to be splitted
 *     delimiters(char *): list of delimiter characters as a char pointer
 *
 * Returns:
 *     splitted results as a :class:`struct split_t` type
 */
struct split_t split(char *target_str, char *delimiters) {
  struct split_t ret = {0, NULL};
  size_t buffer_size = DEFAULT_BUFFER_SIZE;
  size_t temp = 0;

  ret.tokens = (char **)xcalloc(buffer_size, sizeof(char *));

  while (true) {
    target_str += strspn(target_str, delimiters);
    temp = strcspn(target_str, delimiters);

    if (!temp)
      break;

    if (ret.length >= buffer_size) {
      buffer_size += DEFAULT_BUFFER_SIZE;
      ret.tokens = (char **)xrealloc(ret.tokens, buffer_size * sizeof(char *));
    }

    ret.tokens[ret.length] = strndup(target_str, temp);
    ret.length++;
    target_str += temp;
  }

  return ret;
}

/**
 * Deallocate any type of :class:`struct split_t` object.
 *
 * Args:
 *     split_ptr(struct split_t *): target address of split_t object
 */
void free_split(struct split_t *split_ptr) {
  for (size_t i = 0; i < split_ptr->length; i++) {
    free(split_ptr->tokens[i]);
    split_ptr->tokens[i] = NULL;
  }

  free(split_ptr->tokens);
  split_ptr->tokens = NULL;
  split_ptr->length = 0;
}
/**
 * Reentrant function for free_split. The `_r` indicates
 *     that. Basically it frees given split_t pointer address
 *     (uses ``free_split``) and returns given return value.
 *
 * Args:
 *     ptr(struct split_t *): target address of split_t object
 *     ret(bool): return value as a bool
 *
 * Returns:
 *     directly given ret value
 */
bool free_split_r(struct split_t *ptr, bool ret) {
  free_split(ptr);
  return ret;
}

#endif
