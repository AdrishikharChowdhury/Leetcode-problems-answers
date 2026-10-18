class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # 1. Handle 32-bit overflow boundary
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX
            
        # 2. Determine if the result is negative
        is_minus = (dividend < 0) ^ (divisor < 0)
        
        # 3. Work entirely with positive values
        dividend, divisor = abs(dividend), abs(divisor)
        count = 0
        
        # 4. Exponential search / Bit-shifting approach
        while dividend >= divisor:
            temp_divisor, multiple = divisor, 1
            while dividend >= (temp_divisor << 1):
                temp_divisor <<= 1
                multiple <<= 1
            dividend -= temp_divisor
            count += multiple
            
        return -count if is_minus else count
