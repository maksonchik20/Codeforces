from functools import lru_cache
n = int(input())
a, b = input(), input()

@lru_cache(maxsize=None)
def req(s):
    