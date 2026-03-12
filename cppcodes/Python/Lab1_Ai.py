# LAB1 
 
def frequency(txt): 
    """ 
    Returns a dictionary with the frequency count of each alphabet letter (in lowercase) in txt. 
 
    >>> frequency('mama') 
    {'m': 2, 'a': 2} 
    >>> answer = frequency('We ARE Penn State!!!') 
    >>> answer 
    {'w': 1, 'e': 4, 'a': 2, 'r': 1, 'p': 1, 'n': 2, 's': 1, 't': 2} 
    >>> frequency('One who IS being Trained') 
    {'o': 2, 'n': 3, 'e': 3, 'w': 1, 'h': 1, 'i': 3, 's': 1, 'b': 1, 'g': 1, 
    't': 1, 'r': 1, 'a': 1, 'd': 1} 
    """ 
    freq = {} 
    for char in txt: 
        if char.isalpha(): 
            c = char.lower() 
            if c in freq: 
                freq[c] += 1 
            else: 
                freq[c] = 1 
    return freq 
 
 
def invert(d): 
    """ 
    Returns a new dictionary where keys and values are inverted from d, 
    but only for values that appear exactly once in d. 
 
    >>> invert({'one':1, 'two':2, 'three':3, 'four':4}) 
    {1: 'one', 2: 'two', 3: 'three', 4: 'four'} 
    >>> invert({'one':1, 'two':2, 'uno':1, 'dos':2, 'three':3}) 
    {3: 'three'} 
    >>> invert({'123-456-78':'Sara', '987-12-585':'Alex', '258715':'sara', 
    '00000':'Alex'}) 
    {'Sara': '123-456-78', 'sara': '258715'} 
    """ 
    
    value_counts = {} 
    for key in d: 
        val = d[key] 
        if val in value_counts: 
            value_counts[val] += 1 
        else: 
            value_counts[val] = 1 
 
     
    inverted = {} 
    for key in d: 
        val = d[key] 
        if value_counts[val] == 1: 
            inverted[val] = key 
    return inverted 
 
 
def employee_update(d, bonus, year): 
    """ 
    Adds a new year entry to the employee records in d by copying the previous yearâ€™s 
    records and increasing each salary by bonus. 
 
    >>> records = { 
    2020: {"John":["Managing Director","Full-time",65000], 
            "Sally":["HR Director","Full-time",60000], 
            "Max":["Sales Associate","Part-time",20000]}, 
     2021: {"John":["Managing Director","Full-time",70000], 
            "Sally":["HR Director","Full-time",65000], 
            "Max":["Sales Associate","Part-time",25000]} 
 } 
    >>> employee_update(records, 7500, 2022) 
    {2020: {'John': ['Managing Director', 'Full-time', 65000], 'Sally': ['HR Director', 'Full-time', 
60000], 'Max': ['Sales Associate', 'Part-time', 20000]}, 
      2021: {'John': ['Managing Director', 'Full-time', 70000], 'Sally': ['HR Director', 'Full-time', 
65000], 'Max': ['Sales Associate', 'Part-time', 25000]}, 
      2022: {'John': ['Managing Director', 'Full-time', 77500], 'Sally': ['HR Director', 'Full-time', 
72500], 'Max': ['Sales Associate', 'Part-time', 32500]}} 
 """ 
  
    prev_year = year - 1 
    prev_records = d[prev_year] 
  
      
    new_year_record = {} 
    for emp in prev_records: 
        details = prev_records[emp] 
        position = details[0] 
        status = details[1] 
        salary = details[2] 
          
        updated_salary = salary + bonus 
        new_year_record[emp] = [position, status, updated_salary] 
  
    d[year] = new_year_record 
    return d 
  
def run_tests(): 
    import doctest 
    doctest.testmod() 
    if __name__ == "__main__": 
        run_tests()