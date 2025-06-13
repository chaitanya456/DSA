def to_decimal(oct_num):
    """
    >>> to_decimal(237)
    159
    >>> to_decimal(35)
    29
    >>> to_decimal(600)
    384
    >>> to_decimal(420)
    272
    """
#- YOUR CODE STARTS HERE
    decimal_num = 0
    base = 1
    while oct_num > 0:
        last_digit = oct_num % 10
        oct_num //= 10
        decimal_num += last_digit * base
        base *= 8
    return decimal_num
def run_tests():
    import doctest
# Run start tests in all docstrings
# doctest.testmod(verbose=True)
# Run start tests per function - Uncomment the next line to run doctest by
#function. Replace rectangle with the name of the function you want to test
    doctest.run_docstring_examples(to_decimal, globals(), name='HW1',verbose=True)
if __name__ == "__main__":
    run_tests()
