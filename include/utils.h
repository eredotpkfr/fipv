/*
 * Some helpful functions listed in this header file.
 *
 * Function: is_digit
 * ----------------------------
 * Checks if the given string is a digit.
 *
 * target_str: target string to be checked (char *)
 * returns: true if string is a digit otherwise false (bool)
 *
 * Function: is_xdigit
 * ----------------------------
 * Checks if the given string is a hexadecimal.
 *
 * target_str: target string to be checked (char *)
 * returns: true if string is a hexadecimal otherwise false (bool)
 *
 * Function: blanks
 * ----------------------------
 * Definition of "blank" is python empty string (''). If you split ".."
 * with "." in python, you get 3 empty string (['', '', ''])
 * simply blanks function counts these empty strings.
 *
 * target_str: target string (char *)
 * delimiter: delimiter character (char)
 * returns: returns count of empty strings (int)
 *
 * Function: startswith
 * ----------------------------
 * Returns true if the given string startswith given character
 *
 * target_str: target string (char *)
 * chr: comparing character (char)
 * returns: returns true if target_str startswith chr (bool)
 *
 * Function: endswith
 * ----------------------------
 * Returns true if the given string endswith given character
 *
 * target_str: target string (char *)
 * chr: comparing character (char)
 * returns: returns true if target_str endswith chr (bool)
 */

#ifndef _UTILS_H_
#define _UTILS_H_

#include <ctype.h> /* for isdigit and isxdigit */

bool is_digit(char *target_str);
bool is_xdigit(char *target_str);
bool startswith(char *target_str, char chr);
bool endswith(char *target_str, char chr);
int blanks(char *target_str, char delimiter);

bool startswith(char *target_str, char chr) {
  if (!target_str)
    return false;

  return target_str[0] == chr;
}

bool endswith(char *target_str, char chr) {
  if (!target_str)
    return false;

  return target_str[strlen(target_str) - 1] == chr;
}

bool is_digit(char *target_str) {
  for (size_t i = 0; i < strlen(target_str); i++) {
    if (!isdigit(target_str[i]))
      return false;
  }
  return true;
}

bool is_xdigit(char *target_str) {
  for (size_t i = 0; i < strlen(target_str); i++) {
    if (!isxdigit(target_str[i]))
      return false;
  }
  return true;
}

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
