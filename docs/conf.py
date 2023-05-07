# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#

import configparser
import os
import sys
from pathlib import Path

sys.path.insert(0, os.path.abspath(".."))


# -- Project information -----------------------------------------------------
def _get_project_metadata() -> configparser.SectionProxy:
    """Read project metadata informations and return all of them."""
    config_file = Path(__file__).parent.parent.joinpath("setup.cfg")
    configs = configparser.ConfigParser()
    configs.read(config_file)

    return configs["metadata"]


def _get_version() -> str:
    """Read version from VERSION file."""
    version_file = Path(__file__).parent.parent.joinpath("VERSION")

    with open(version_file) as file_desc:
        return file_desc.read().strip()


project_metadata = _get_project_metadata()

project = project_metadata["name"]
copyright = "2023, Erdoğan YOKSUL"
author = project_metadata["author"]

# The full version, including alpha/beta/rc tags
release = _get_version()

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    "sphinx_c_autodoc",
    "sphinx_c_autodoc.napoleon",
    "sphinx_c_autodoc.viewcode",
    "m2r2",
]

# c autodoc paths
c_autodoc_roots = [".."]

# source_suffix = '.rst'
source_suffix = [".rst", ".md"]

# Add any paths that contain templates here, relative to this directory.
templates_path = ["_templates"]

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = "furo"

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ["_static"]
