#!/usr/bin/python3

"""
Module installation file
"""

from setuptools import Extension, setup

extension = Extension(
    name="fipv",
    include_dirs=["include"],
    sources=["fipv/fipv.c"],
    extra_compile_args=["-O3"],
)

setup(ext_modules=[extension])
