#ifndef _IPV4_H_
#define _IPV4_H_

#define IPV4_DELIMITER "."
#define IPV4_DELIMITER_CHAR '.'
#define IP_CIDR_DELIMITER "/"

#include "split.h"
#include "utils.h"

bool is_ipv4(char *ipv4_addr);
bool is_ipv4_cidr(char *ipv4_addr_cidr);

/**
 * Returns ``true`` if given string is a IPv4 otherwise ``false``.
 *
 * Args:
 *     ipv4_addr(char *): target string to be validated
 *
 * Returns:
 *     ``true`` if given address is a IPv4 address
 */
bool is_ipv4(char *ipv4_addr) {
  if (startswith(ipv4_addr, IPV4_DELIMITER_CHAR) ||
      endswith(ipv4_addr, IPV4_DELIMITER_CHAR))
    return false;

  struct split_t splitted = split(ipv4_addr, IPV4_DELIMITER);
  int blank_counts = blanks(ipv4_addr, IPV4_DELIMITER_CHAR);

  if (splitted.length + blank_counts != 4)
    return free_split_r(&splitted, false);

  for (size_t i = 0; i < splitted.length; i++) {
    char *part = splitted.tokens[i];

    if (!is_digit(part))
      return free_split_r(&splitted, false);

    if (!(0 <= atoi(part) && atoi(part) < 256))
      return free_split_r(&splitted, false);
  }

  return free_split_r(&splitted, true);
}

/**
 * Returns ``true`` if given string is a IPv4CIDR otherwise ``false``.
 *
 * Args:
 *     ipv4_addr_cidrr(char *): target string to be validated
 *
 * Returns:
 *     ``true`` if given address is a IPv4CIDR
 */
bool is_ipv4_cidr(char *ipv4_addr_cidr) {
  struct split_t splitted = split(ipv4_addr_cidr, IP_CIDR_DELIMITER);

  if (splitted.length != 2)
    return free_split_r(&splitted, false);

  char *prefix = splitted.tokens[0];
  char *suffix = splitted.tokens[1];

  if (!is_ipv4(prefix) || !is_digit(suffix))
    return free_split_r(&splitted, false);

  if (!(0 <= atoi(suffix) && atoi(suffix) <= 32))
    return free_split_r(&splitted, false);

  return free_split_r(&splitted, true);
}

#endif
