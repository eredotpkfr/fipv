#ifndef _IPV6_H_
#define _IPV6_H_

#define HEX_BASE 16
#define IP_CIDR_DELIMITER "/"
#define IPV4_DELIMITER "."
#define IPV6_DELIMITER ":"
#define IPV6_DELIMITER_CHAR ':'

#include "split.h"
#include "utils.h"

bool is_ipv6(char *ipv6_addr);
bool is_ipv6_cidr(char *ipv6_addr_cidr);

/**
 * Returns ``true`` if given string is a IPv6 otherwise ``false``.
 *
 * Args:
 *     ipv6_addr(char *): target string to be validated
 *
 * Returns:
 *     ``true`` if given address is a IPv6 address
 */
bool is_ipv6(char *ipv6_addr) {
  struct split_t ipv6_groups;
  struct split_t ipv4_groups;

  char *ipv4_part;
  int blankctr, number;
  bool is_freed_ipv4;

  ipv6_groups = split(ipv6_addr, IPV6_DELIMITER);
  blankctr = blanks(ipv6_addr, IPV6_DELIMITER_CHAR);

  if (!ipv6_groups.length || ipv6_groups.length + blankctr <= 1)
    return free_split_r(&ipv6_groups, false);

  ipv4_part = ipv6_groups.tokens[ipv6_groups.length - 1];
  ipv4_groups = split(ipv4_part, IPV4_DELIMITER);
  is_freed_ipv4 = false;

  if (ipv4_groups.length > 1) {

    if (!is_ipv4(ipv4_part))
      return free_split_r(&ipv4_groups, free_split_r(&ipv6_groups, false));

    free(ipv4_part);
    ipv4_part = NULL;
    ipv6_groups.length--;
  } else {
    free_split(&ipv4_groups);
    is_freed_ipv4 = true;
  }

  size_t max_groups = ipv4_groups.tokens ? 6 : 8;

  if (ipv6_groups.length + blankctr > max_groups) {
    if (!is_freed_ipv4)
      free_split(&ipv4_groups);

    return free_split_r(&ipv6_groups, false);
  }

  for (size_t i = 0; i < ipv6_groups.length; i++) {
    char *part = ipv6_groups.tokens[i];

    if (!is_xdigit(part)) {
      if (!is_freed_ipv4)
        free_split(&ipv4_groups);

      return free_split_r(&ipv6_groups, false);
    }

    number = (int)strtol(part, NULL, HEX_BASE);

    if (!(0 <= number && number <= 65536)) {
      if (!is_freed_ipv4)
        free_split(&ipv4_groups);

      return free_split_r(&ipv6_groups, false);
    }
  }

  if (blankctr <= 2) {
    if (!is_freed_ipv4)
      free_split(&ipv4_groups);

    return free_split_r(&ipv6_groups, true);
  }

  if (!is_freed_ipv4)
    free_split(&ipv4_groups);

  return free_split_r(&ipv6_groups, false);
}

/**
 * Returns ``true`` if given string is a IPv6CIDR otherwise ``false``.
 *
 * Args:
 *     ipv6_addr_cidr(char *): target string to be validated
 *
 * Returns:
 *     ``true`` if given address is a IPv6CIDR
 */
bool is_ipv6_cidr(char *ipv6_addr_cidr) {
  struct split_t splitted = split(ipv6_addr_cidr, IP_CIDR_DELIMITER);

  if (splitted.length != 2)
    return free_split_r(&splitted, false);

  char *prefix = splitted.tokens[0];
  char *suffix = splitted.tokens[1];

  if (!is_ipv6(prefix) || !is_digit(suffix))
    return free_split_r(&splitted, false);

  if (!(0 <= atoi(suffix) && atoi(suffix) <= 128))
    return free_split_r(&splitted, false);

  return free_split_r(&splitted, true);
}

#endif
