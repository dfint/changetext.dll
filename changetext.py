

def ChangeText(s):
    print('ChangeText() received:', s)
    decoded = s.decode("utf-16")
    print('Decoded:', decoded)
    
    if decoded == 'hello':
        returned = 'world'
    
    b = returned.encode("utf-16")[2:]+b'\0\0'
    
    return b


if __name__ == '__main__':
    print(ChangeText(b'h\0e\0l\0l\0o\0'))
    input()
