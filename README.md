[![Test](https://github.com/eredotpkfr/fipv/actions/workflows/python-package-test.yml/badge.svg)](https://github.com/eredotpkfr/fipv/actions/workflows/python-package-test.yml)
[![PyPI](https://img.shields.io/pypi/v/fipv)](https://pypi.org/project/fipv/)
[![Github Pages](https://img.shields.io/badge/github-pages-orange.svg)](https://www.erdoganyoksul.com/fipv/)
![PyPI - Python Version](https://img.shields.io/pypi/pyversions/fipv)
[![License: MIT](https://img.shields.io/badge/license-MIT-informational.svg)](https://opensource.org/licenses/MIT)
[![Stars](https://img.shields.io/github/stars/eredotpkfr/fipv?style=social)](https://github.com/eredotpkfr/fipv/stargazers)
# fipv
It stands out as a high-speed Python package meticulously built in C language 🤙 It elegantly consolidates core IP address validation functions into a robust C-based implementation, ensuring unparalleled speed compared to alternatives

🎯 **Key Features**
- 🚀 **Efficiency and Performance:** The C-based implementation of `fipv` guarantees exceptional speed and minimal RAM usage, making it a top choice for high-performance IP address validation in Python applications
- 📚 **Simplified Usage:** Explore [github pages](https://www.erdoganyoksul.com/fipv/) for easy-to-follow documentation and package references

⚡ **Available Validators**
- IPv4
- IPv4 CIDR
- IPv6
- IPv6 CIDR

## Installation
```sh
$ pip3 install fipv
```
## Usage
### Basic Validation
```python
import fipv

# Basic C validation functions
print(
    fipv.ipv4("127.0.0.1"),
    fipv.ipv4_cidr("127.0.0.1/44"),
    fipv.ipv6("::1"),
    fipv.ipv6_cidr("::1/129"),
)

# Output
# True False True False
```
### Bulk Validation
```python
import fipv

# Validate bulk IPv4 data
ips = ['127.0.0.1'] * 1000000
valids = [ip for ip in ips if fipv.ipv4(ip)]
print(len(valids))

# Output
# 1000000
```

## Test Benchmark (2021-10-07)
In this test, it was tested validation speed and average RAM usage with different python validators and different data types. Finally results saved to below table

🟢 Valid 🔴 Invalid
<table>
  <thead>
    <tr>
      <th align="center" scope="col">Test ID</th>
      <th align="center" scope="col" colspan="2" scope="colgroup">Test Data Count</th>
      <th align="center" scope="col">Total Data</th>
      <th align="center" scope="col">Data Type</th>
      <th align="center">Project</th>
      <th align="center">Validation Duration</th>
      <th align="center">Avr. RAM Usage (MB)</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th align="center" rowspan="3" scope="rowgroup">1</th>
      <th align="center" scope="row">🟢</th>
      <td align="center">500K</td>
      <td align="center" rowspan="3">1M</td>
      <td align="center" rowspan="3">IPv4</td>
      <td align="center">
        <a href="https://github.com/kvesteri/validators" target="_blank">validators</a>
      </td>
      <td align="center">0m12,975s</td>
      <td align="center">85M</td>
    </tr>
    <tr>
      <th align="center" scope="row">🔴</th>
      <td align="center">500K</td>
      <td align="center">
        <a href="https://docs.python.org/3/library/ipaddress.html" target="_blank">ipaddress</a>
      </td>
      <td align="center">0m2,007s</td>
      <td align="center">80M</td>
    </tr>
    <tr>
      <th align="center" scope="row">N/A</th>
      <td align="center">N/A</td>
      <td align="center">fipv</td>
      <td align="center">0m0,635s</td>
      <td align="center">76M</td>
    </tr>
  </tbody>
  <tbody>
    <tr>
      <th align="center" rowspan="3" scope="rowgroup">2</th>
      <th align="center" scope="row">🟢</th>
      <td align="center">1M</td>
      <td align="center" rowspan="3">2M</td>
      <td align="center" rowspan="3">IPv4</td>
      <td align="center">
        <a href="https://github.com/kvesteri/validators" target="_blank">validators</a>
      </td>
      <td align="center">0m25,682s</td>
      <td align="center">151M</td>
    </tr>
    <tr>
      <th align="center" scope="row">🔴</th>
      <td align="center">1M</td>
      <td align="center">
        <a href="https://docs.python.org/3/library/ipaddress.html" target="_blank">ipaddress</a>
      </td>
      <td align="center">0m3,937s</td>
      <td align="center">154M</td>
    </tr>
    <tr>
      <th align="center" scope="row">N/A</th>
      <td align="center">N/A</td>
      <td align="center">fipv</td>
      <td align="center">0m1,193s</td>
      <td align="center">150M</td>
    </tr>
  </tbody>
  <tbody>
    <tr>
      <th align="center" rowspan="3" scope="rowgroup">3</th>
      <th align="center" scope="row">🟢</th>
      <td align="center">500K</td>
      <td align="center" rowspan="3">1M</td>
      <td align="center" rowspan="3">IPv4 CIDR</td>
      <td align="center">
        <a href="https://github.com/kvesteri/validators" target="_blank">validators</a>
      </td>
      <td align="center">0m19,721s</td>
      <td align="center">96M</td>
    </tr>
    <tr>
      <th align="center" scope="row">🔴</th>
      <td align="center">500K</td>
      <td align="center">
        <a href="https://docs.python.org/3/library/ipaddress.html" target="_blank">ipaddress</a>
      </td>
      <td align="center">0m8,662s</td>
      <td align="center">89M</td>
    </tr>
    <tr>
      <th align="center" scope="row">N/A</th>
      <td align="center">N/A</td>
      <td align="center">fipv</td>
      <td align="center">0m0,909s</td>
      <td align="center">77M</td>
    </tr>
  </tbody>
  <tbody>
    <tr>
      <th align="center" rowspan="3" scope="rowgroup">4</th>
      <th align="center" scope="row">🟢</th>
      <td align="center">1M</td>
      <td align="center" rowspan="3">2M</td>
      <td align="center" rowspan="3">IPv4 CIDR</td>
      <td align="center">
        <a href="https://github.com/kvesteri/validators" target="_blank">validators</a>
      </td>
      <td align="center">0m39,457s</td>
      <td align="center">179M</td>
    </tr>
    <tr>
      <th align="center" scope="row">🔴</th>
      <td align="center">1M</td>
      <td align="center">
        <a href="https://docs.python.org/3/library/ipaddress.html" target="_blank">ipaddress</a>
      </td>
      <td align="center">0m17,029s</td>
      <td align="center">174M</td>
    </tr>
    <tr>
      <th align="center" scope="row">N/A</th>
      <td align="center">N/A</td>
      <td align="center">fipv</td>
      <td align="center">0m1,779s</td>
      <td align="center">174M</td>
    </tr>
  </tbody>
  <tbody>
    <tr>
      <th align="center" rowspan="3" scope="rowgroup">5</th>
      <th align="center" scope="row">🟢</th>
      <td align="center">500K</td>
      <td align="center" rowspan="3">1M</td>
      <td align="center" rowspan="3">IPv6</td>
      <td align="center">
        <a href="https://github.com/kvesteri/validators" target="_blank">validators</a>
      </td>
      <td align="center">0m12,633s</td>
      <td align="center">96M</td>
    </tr>
    <tr>
      <th align="center" scope="row">🔴</th>
      <td align="center">500K</td>
      <td align="center">
        <a href="https://docs.python.org/3/library/ipaddress.html" target="_blank">ipaddress</a>
      </td>
      <td align="center">0m2,802s</td>
      <td align="center">92M</td>
    </tr>
    <tr>
      <th align="center" scope="row">N/A</th>
      <td align="center">N/A</td>
      <td align="center">fipv</td>
      <td align="center">0m0,684s</td>
      <td align="center">87M</td>
    </tr>
  </tbody>
  <tbody>
    <tr>
      <th align="center" rowspan="3" scope="rowgroup">6</th>
      <th align="center" scope="row">🟢</th>
      <td align="center">1M</td>
      <td align="center" rowspan="3">2M</td>
      <td align="center" rowspan="3">IPv6</td>
      <td align="center">
        <a href="https://github.com/kvesteri/validators" target="_blank">validators</a>
      </td>
      <td align="center">0m26,449s</td>
      <td align="center">183M</td>
    </tr>
    <tr>
      <th align="center" scope="row">🔴</th>
      <td align="center">1M</td>
      <td align="center">
        <a href="https://docs.python.org/3/library/ipaddress.html" target="_blank">ipaddress</a>
      </td>
      <td align="center">0m5,605s</td>
      <td align="center">177M</td>
    </tr>
    <tr>
      <th align="center" scope="row">N/A</th>
      <td align="center">N/A</td>
      <td align="center">fipv</td>
      <td align="center">0m1,308s</td>
      <td align="center">172M</td>
    </tr>
  </tbody>
  <tbody>
    <tr>
      <th align="center" rowspan="3" scope="rowgroup">7</th>
      <th align="center" scope="row">🟢</th>
      <td align="center">500K</td>
      <td align="center" rowspan="3">1M</td>
      <td align="center" rowspan="3">IPv6 CIDR</td>
      <td align="center">
        <a href="https://github.com/kvesteri/validators" target="_blank">validators</a>
      </td>
      <td align="center">0m20,936s</td>
      <td align="center">99M</td>
    </tr>
    <tr>
      <th align="center" scope="row">🔴</th>
      <td align="center">500K</td>
      <td align="center">
        <a href="https://docs.python.org/3/library/ipaddress.html" target="_blank">ipaddress</a>
      </td>
      <td align="center">0m10,778s</td>
      <td align="center">95M</td>
    </tr>
    <tr>
      <th align="center" scope="row">N/A</th>
      <td align="center">N/A</td>
      <td align="center">fipv</td>
      <td align="center">0m0,958s</td>
      <td align="center">93M</td>
    </tr>
  </tbody>
  <tbody>
    <tr>
      <th align="center" rowspan="3" scope="rowgroup">8</th>
      <th align="center" scope="row">🟢</th>
      <td align="center">1M</td>
      <td align="center" rowspan="3">2M</td>
      <td align="center" rowspan="3">IPv6 CIDR</td>
      <td align="center">
        <a href="https://github.com/kvesteri/validators" target="_blank">validators</a>
      </td>
      <td align="center">0m51,382s</td>
      <td align="center">184M</td>
    </tr>
    <tr>
      <th align="center" scope="row">🔴</th>
      <td align="center">1M</td>
      <td align="center">
        <a href="https://docs.python.org/3/library/ipaddress.html" target="_blank">ipaddress</a>
      </td>
      <td align="center">0m25,563s</td>
      <td align="center">184M</td>
    </tr>
    <tr>
      <th align="center" scope="row">N/A</th>
      <td align="center">N/A</td>
      <td align="center">fipv</td>
      <td align="center">0m1,862s</td>
      <td align="center">168M</td>
    </tr>
  </tbody>
</table>

## Contact
Blog - [erdoganyoksul.com](https://www.erdoganyoksul.com)<br/>
Mail - erdoganyoksul3@gmail.com
