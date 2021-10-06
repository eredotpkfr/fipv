#!/usr/bin/python3

"""
Test cases listed in this file
"""

IPV4_CASES = {
    '127.0.0.1': True,
    '123.5.77.88': True,
    '12.12.12.12': True,
    '192.168.1.43': True,
    '95.67.123.56': True,
    '': False,
    'abc.0.0.1': False,
    '1278.0.0.1': False,
    '127.0.0.abc': False,
    '900.200.100.75': False,
    'foo/bar': False,
    'foo': False,
    '::1::2': False,
    '::1': False,
    '127.0.0.1.1.2.3': False,
}

IPV4_CIDR_CASES = {
    '127.0.0.1/0': True,
    '123.5.77.88/8': True,
    '12.12.12.12/32': True,
    '127.0.0.1/12': True,
    '192.168.1.45/24': True,
    'abc.0.0.1': False,
    '1.1.1.1': False,
    '1.1.1.1/-1': False,
    '1.1.1.1/33': False,
    '1.1.1.1/foo': False,
    '127.0.b.a/12': False,
    'a.b.c/123/': False,
    '////': False,
    '': False,
    'foo': False,
    '/foo/bar/': False,
    'foo/bar': False,
}

IPV6_CASES = {
    '::1': True,
    'dead:beef:0:0:0:0:42:1': True,
    'abcd:ef::42:1': True,
    '0:0:0:0:0:ffff:1.2.3.4': True,
    '::192.168.30.2': True,
    '': False,
    'foo': False,
    '////': False,
    ':': False,
    '::::': False,
    'abc.0.0.1': False,
    'abcd:1234::123::1': False,
    '1:2:3:4:5:6:7:8:9': False,
    'abcd::1ffff': False,
    'deag:beef:0:0:0:0:42:1': False,
}

IPV6_CIDR_CASES = {
    '::1/0': True,
    'dead:beef:0:0:0:0:42:1/8': True,
    'abcd:ef::42:1/32': True,
    '0:0:0:0:0:ffff:1.2.3.4/64': True,
    '::192.168.30.2/128': True,
    'abc.0.0.1': False,
    'abcd:1234::123::1': False,
    '1:2:3:4:5:6:7:8:9': False,
    'abcd::1ffff': False,
    '1.1.1.1': False,
    '': False,
    '////': False,
    ':': False,
    'foo/bar': False,
    '::1': False,
    '::1/129': False,
    '::1/-1': False,
    '::1/foo': False,
}
