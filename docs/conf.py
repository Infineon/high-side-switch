# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# http://www.sphinx-doc.org/en/master/config

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import sys
sys.path.insert(0, os.path.abspath('./../xfpdev'))

import subprocess, os, sys

# def configureDoxyfile(input_dir, output_dir):

# 	with open('doxygen/rtd_doxygen.in', 'r') as file :
# 		filedata = file.read()

# 	filedata = filedata.replace('@DOXYGEN_INPUT_DIR@', input_dir)
# 	filedata = filedata.replace('@DOXYGEN_OUTPUT_DIR@', output_dir)

# 	with open('Doxyfile', 'w') as file:
# 		file.write(filedata)

# Check if we're running on Read the Docs' servers
read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

# breathe_projects = {}
# if read_the_docs_build:
# 	input_dir = '../src'
# 	output_dir = 'build'
# 	configureDoxyfile(input_dir, output_dir)
# 	subprocess.call('doxygen', shell=True)
# 	breathe_projects[''] = output_dir + '/xml'

# -- Project information -----------------------------------------------------

project = 'High-Side Switch'
copyright = '2021 Infineon Technologies AG'
author = 'Infineon Technologies AG'

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
#...

# At top on conf.py (with other import statements)
# import recommonmark
# from recommonmark.transform import AutoStructify

# # At the bottom of conf.py
# def setup(app):
#     app.add_config_value('recommonmark_config', {
#             'url_resolver': lambda url: github_doc_root + url,
#             'auto_toc_tree_section': 'Contents',
#             }, True)
#     app.add_transform(AutoStructify)

extensions = [
    'sphinx.ext.autodoc',
    'sphinxemoji.sphinxemoji',
    'sphinx_tabs.tabs'
]

# source_parsers = {
#    '.md': 'recommonmark.parser.CommonMarkParser',
# }

source_suffix = [
    '.rst',
    # '.md'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['build', 'Thumbs.db', '.DS_Store']

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
# import sphinx_theme_pd

html_theme = 'sphinx_rtd_theme'
# html_theme_options = {
# 	"head_font_family" : "Source Sans Pro",
# 	"font_family" : "Source Sans Pro",
# 	"body_text_align" : "justify",
# }

html_logo = 'img/ifx_logo_white_green_s.png'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_templates']

# # Breathe Configuration
# breathe_default_project = "xfp-dev"

# breathe_domain_by_extension = {
#         "hpp" : "cpp",
#         }