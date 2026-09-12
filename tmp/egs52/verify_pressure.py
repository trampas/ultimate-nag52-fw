import sys
import os

# Mocking the EGS52 RAM and registers for the test
class EGS52Sim:
    def __init__(self):
        self.ram = [0] * 0xFFFF
        
    def write_word(self, addr, val):
        self.ram[addr] = val & 0xFF
        self.ram[addr+1] = (val >> 8) & 0xFF
        
    def read_word(self, addr):
        return self.ram[addr] | (self.ram[addr+1] << 8)

    # Reconstructed function from 0x0D8166
    def egs52_sum_pressure_terms(self):
        i1 = self.read_word(0xD4D2)
        i2 = self.read_word(0xD47C)
        i3 = self.read_word(0xD490)
        i4 = self.read_word(0xD4B2)
        # Sign-extend the 16-bit values if needed, but here they are used as int
        # In C166 'int' is 16-bit. We'll use 16-bit math with wrapping
        res = (i1 + i2 - i3 - i4) & 0xFFFF
        if res & 0x8000: # Handle negative 16-bit
            return res - 0x10000
        return res

def test_sum_pressure():
    sim = EGS52Sim()
    # Test Case 1: Normal values
    sim.write_word(0xD4D2, 3000) # Base
    sim.write_word(0xD47C, 500)  # Dynamic
    sim.write_word(0xD490, 200)  # SPC Reduc
    sim.write_word(0xD4B2, 100)  # Static Floor
    
    expected = (3000 + 500 - 200 - 100)
    actual = sim.egs52_sum_pressure_terms()
    
    print(f"Test 1: Expected {expected}, Actual {actual}")
    assert actual == expected

    # Test Case 2: Underflow check
    sim.write_word(0xD4D2, 100)
    sim.write_word(0xD47C, 100)
    sim.write_word(0xD490, 500)
    sim.write_word(0xD4B2, 0)
    
    expected = (100 + 100 - 500 - 0) # -300
    actual = sim.egs52_sum_pressure_terms()
    
    print(f"Test 2: Expected {expected}, Actual {actual}")
    assert actual == expected

if __name__ == "__main__":
    test_sum_pressure()
    print("Verification Successful")
