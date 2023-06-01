# def find_anagrams(roman_digits):
#     if not roman_digits:
#         count_anagrams += 1
#         return
    
#     for d in roman_digits.keys():
#         if roman_digits[d] == 0:
#             continue
        
#         roman_digits[d] -= 1
#         find_anagrams(roman_digits)
#         roman_digits[d] += 1


# S = input("Введите строку S: ")
# roman_digits = {'I': 0, 'V': 0, 'X': 0, 'L': 0, 'C': 0, 'D': 0, 'M': 0}

# # Подсчет количества вхождений римских цифр в строку S
# for c in S:
#     if c in roman_digits:
#         roman_digits[c] += 1

# count_anagrams = 0
# find_anagrams(roman_digits)
# print(roman_digits)

# print("Количество анаграмм, являющихся верными римскими цифрами:", count_anagrams)
def is_trapezoid(a, b, c, d):
    if a == c or b != d:
        return False
    return True

def is_right_trapezoid(a, b, c, d):
    if a**2 + b**2 == c**2 + d**2:
        return True
    return False

def is_possible_to_cut_trapezoid(a, b, c, d):
    if is_trapezoid(a, b, c, d):
        if is_right_trapezoid(a, b, c, d):
            return True
        elif a == c and b == d:
            return True
    return False

a = int(input("Введите сторону a: "))
b = int(input("Введите сторону b: "))
c = int(input("Введите сторону c: "))
d = int(input("Введите сторону d: "))

if is_possible_to_cut_trapezoid(a, b, c, d):
    print("Разделение трапеции на равные треугольники возможно")
else:
    print("Разделение трапеции на равные треугольники невозможно")
