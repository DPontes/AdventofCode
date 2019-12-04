import pytest
from Pt1fuelCalc import *


def test_calculateFuel():
    assert calculateFuel(12) == 2
    assert calculateFuel(14) == 2
    assert calculateFuel(1969) == 654
    assert calculateFuel(100756) == 33583
