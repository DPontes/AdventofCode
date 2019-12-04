import pytest
from Pt1fuelCalc import *

def test_calculateMass():
    assert calculateMass() == 3464458
