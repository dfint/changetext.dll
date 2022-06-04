import os

from ctypes import *
from pathlib import Path

import pytest


@pytest.fixture(scope="module")
def changetext_function():
    lib = cdll.LoadLibrary("libchangetext.so")
    lib.ChangeText.restype = c_wchar_p
    return lib.ChangeText


@pytest.mark.parametrize("text", [
    ("hello", "world"),
])
def test_changetext(changetext_function, text, result):
    actual_result = changetext_function(text.encode('utf-16-le'))
    assert result == actual_result
