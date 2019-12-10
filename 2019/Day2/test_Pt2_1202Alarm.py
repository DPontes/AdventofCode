import pytest
from Pt2_1202Alarm import *


def test_getNounAndVerb():
    assert getNounAndVerb(19690720) == 6429
    assert getNounAndVerb(19283712938) == "Failed"
