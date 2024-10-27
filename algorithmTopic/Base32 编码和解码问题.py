#NO FINISHED
def encode(rawStr):
    binary_data = ''.join(format(ord(char), '08b') for char in rawStr)
    

    while len(binary_data) % 5 != 0:
        binary_data += '0'
    
    index_char_map = '9876543210mnbvcxzasdfghjklpoiuyt'
    encoded = ''
    
    for i in range(0, len(binary_data), 5):
        five_bit = binary_data[i:i+5]
        index = int(five_bit, 2)
        encoded += index_char_map[index]
    

    remainder = len(rawStr) * 8 % 40
    if remainder == 0:
        encoded += ''
    elif remainder == 8:
        encoded += '++++++'
    elif remainder == 16:
        encoded += '++++'
    elif remainder == 24:
        encoded += '+++'
    elif remainder == 32:
        encoded += '+'
    
    return encoded

def decode(encodedStr):
    index_char_map = '9876543210mnbvcxzasdfghjklpoiuyt'
    binary_data = ''
    
    for char in encodedStr:
        if char in index_char_map:
            index = index_char_map.index(char)
            binary_data += format(index, '05b')
        elif char == '+':
            continue
        else:
            raise ValueError(f"Unexpected character '{char}' in encoded string.")

    num_bits = len(binary_data)
    original_length = num_bits * 5 // 8 

    decoded_chars = []
    for i in range(0, len(binary_data), 8):
        byte = binary_data[i:i+8]
        if len(byte) == 8:
            decoded_chars.append(chr(int(byte, 2)))
    
    return ''.join(decoded_chars)

# Example usage
rawStr = "foo"
encodedStr = "bljhy+++b0zj5+++"

encoded_result = encode(rawStr)
decoded_result = decode(encodedStr)

print(f"Encoded: {encoded_result}")
print(f"Decoded: {decoded_result}")
