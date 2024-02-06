from unittest import TestCase, mock

class ToBeMocked:
    def __init__(self):
        self.state = 0
    def complex(self, value):
        self.state += value * 8
        return self.state

class TestBasic(TestCase):
    def test_complex(self):
        obj = ToBeMocked()

        #TODO: mock obj.complex
        #...
        obj.complex = mock.MagicMock(return_value=16)

        # call & check
        res = obj.complex(10)
        self.assertEqual(res, 16)

        #TODO: check that the mock complex has been called
        #...
        obj.complex.assert_called_once_with(10)