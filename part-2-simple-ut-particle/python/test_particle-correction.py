from unittest import TestCase
from particle import Particle
import pytest

def test_constructor():
	# setup
	particle = Particle(0, 1)

	# test
	assert 0 == particle.get_x()
	assert 1 == particle.get_vx()

def test_move():
	# setup
	particle = Particle(0, 1)

	# action
	particle.move(0.5)

	# check
	assert 0.5 == particle.get_x()
	assert 1 == particle.get_vx(), "Un message pour expliquer"
