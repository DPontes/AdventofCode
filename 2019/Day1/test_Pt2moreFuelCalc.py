import pytest
from Pt2moreFuelCalc import *


def test_calculateTotalFuel():
    assert calculateTotalFuel(12) == 2
    assert calculateTotalFuel(14) == 2
    assert calculateTotalFuel(1969) == 966
    assert calculateTotalFuel(100756) == 50346
