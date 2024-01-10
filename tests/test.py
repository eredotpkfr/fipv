#!/usr/bin/python3

"""
Main test file, fipv module tests.
"""


from typing import Callable
from unittest import TestCase, main

from cases import IPV4_CASES, IPV4_CIDR_CASES, IPV6_CASES, IPV6_CIDR_CASES

import fipv


class TestFipv(TestCase):
    """Main module test class."""

    def _global_test_func(
        self,
        cases: dict[str, bool],
        validator: Callable[[str], bool],
    ) -> None:
        """Global test function, other methods uses it.

        Simply does test by given cases and validator.

        Args:
            cases: test cases as a dictionary
            validator: any `fipv` validator function object
        """
        for case, expected in cases.items():
            self.assertEqual(validator(case), expected, case)

    def test_ipv4(self) -> None:
        """Test for fipv.ipv4 func."""
        self._global_test_func(IPV4_CASES, fipv.ipv4)

    def test_ipv4_cidr(self) -> None:
        """Test for fipv.ipv4_cidr func."""
        self._global_test_func(IPV4_CIDR_CASES, fipv.ipv4_cidr)

    def test_ipv6(self) -> None:
        """Test for fipv.ipv6 func."""
        self._global_test_func(IPV6_CASES, fipv.ipv6)

    def test_ipv6_cidr(self) -> None:
        """Test for fipv.ipv6_cidr func."""
        self._global_test_func(IPV6_CIDR_CASES, fipv.ipv6_cidr)


if __name__ == "__main__":
    main()
