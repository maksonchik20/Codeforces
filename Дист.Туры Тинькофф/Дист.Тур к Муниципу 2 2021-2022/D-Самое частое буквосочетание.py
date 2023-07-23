cnts = [[0] * 26 for _ in range(26)]
words = input().split()
for word in words:
    for i in range(1, len(word)):
        cnts[ord(word[i-1]) - ord("A")][ord(word[i]) - ord("A")] += 1
_max = 0
result = ""
for i in range(26):
    for j in range(26):
        if cnts[i][j] == _max:
            if result < chr(ord("A") + i) + chr(ord("A") + j):
                result = chr(ord("A") + i) + chr(ord("A") + j)
        elif cnts[i][j] > _max:
            result = chr(ord("A") + i) + chr(ord("A") + j)
            _max = cnts[i][j]
print(result)
