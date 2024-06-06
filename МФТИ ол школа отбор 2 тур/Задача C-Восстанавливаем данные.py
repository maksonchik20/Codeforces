def encode(arr):
    encoded = []
    xor_result = 0

    for num in arr:
        encoded.append(num ^ xor_result)
        xor_result ^= encoded[-1]

    return encoded + [xor_result]


def decode(encoded):
    decoded = []
    xor_result = encoded[-1]

    for num in encoded[:-1]:
        decoded.append(num ^ xor_result)
        xor_result ^= num

    return decoded


# Пример использования
arr = [10, 20, 30]
encoded_arr = encode(arr)
print("Закодированный массив:", encoded_arr)

decoded_arr = decode(encoded_arr)
print("Декодированный массив:", decoded_arr)
