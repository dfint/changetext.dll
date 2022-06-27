def ChangeText(s):
    print('ChangeText() received:', s)
    decoded = s.decode("utf-16-le")
    print('Decoded:', decoded)
    
    returned = None
    if decoded == 'hello':
        returned = 'world'
    
    if returned is None:
        return None
    else:
        b = returned.encode("utf-16-le") + b'\0\0'
        return b
