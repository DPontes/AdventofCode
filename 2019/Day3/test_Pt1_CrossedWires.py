import pytest
from Pt1_CrossedWires import *

def test_manhattanDistance():
    set1 = 'R8,U5,L5,D3'
    set2 = 'U7,R6,D4,L4'
    assert manhattanDistance(set1, set2) == 6
