def isPalindrome(x):
    x = str(x)
    test = x
    length = len(x)
    
    for i in range(length-1, -1, -1):
        if x[length-1-i] != test[i]:
            return False
    
    return True

x = -121
print(isPalindrome(x))