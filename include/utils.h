#ifndef _UTILS_H_
#define _UTILS_H_

#include <ctype.h> /* for isdigit and isxdigit */

bool is_digit(char *target_str);
bool is_xdigit(char *target_str);
bool startswith(char *target_str, char chr);
bool endswith(char *target_str, char chr);
int blanks(char *target_str, char delimiter);

/**
 * Returns ``true`` if the given string startswith given character.
 *
 * Args:
 *     target_str(char *): target string
 *     chr(char): comparing character
 *
 * Returns:
 *     ``true`` if ``target_str`` startswith ``chr``
 */
bool startswith(char *target_str, char chr) {
  if (!target_str)
    return false;

  return target_str[0] == chr;
}

/**
 * Returns ``true`` if the given string endswith given character.
 *
 * Args:
 *     target_str(char *): target string
 *     chr(char): comparing character
 *
 * Returns:
 *     ``true`` if ``target_str`` endswith ``chr``
 */
bool endswith(char *target_str, char chr) {
  if (!target_str)
    return false;

  return target_str[strlen(target_str) - 1] == chr;
}

/**
 * Checks if the given string is a digit.
 *
 * Args:
 *     target_str(char *): target string to be checked
 *
 * Returns:
 *     ``true`` if string is a digit otherwise ``false``
 */
bool is_digit(char *target_str) {
  for (size_t i = 0; i < strlen(target_str); i++) {
    if (!isdigit(target_str[i]))
      return false;
  }
  return true;
}

/**
 * Checks if the given string is a hexadecimal.
 *
 * Args:
 *     target_str(char *): target string to be checked
 *
 * Returns:
 *     ``true`` if string is a hexadecimal otherwise ``false``
 */
bool is_xdigit(char *target_str) {
  for (size_t i = 0; i < strlen(target_str); i++) {
    if (!isxdigit(target_str[i]))
      return false;
  }
  return true;
}

/**
 * Definition of `blank` is python empty string (``''``). If you split ``..``
 *     with ``.`` in python, you get 3 empty string (``['', '', '']``)
 *     simply blanks function counts these empty strings.
 *
 * Args:
 *     target_str(char *): target string to count blanks
 *     delimiter(char): delimiter character
 *
 * Returns:
 *     count of empty strings
 */
int blanks(char *target_str, char delimiter) {
  int counter = 0;

  for (size_t i = 0; i < strlen(target_str); i++) {
    if (target_str[i] != delimiter)
      continue;

    if (target_str[i] == target_str[i + 1])
      counter++;
  }

  return !counter ? counter : counter + 1;
}

#endif
