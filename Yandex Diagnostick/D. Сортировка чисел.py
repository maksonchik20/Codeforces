import requests
url = input()
port = input()
a = int(input())
b = int(input())

resp = (requests.get(f"{url}:{port}?a={a}&b={b}")).json()
print(*sorted(list(map(int, list(resp)))), sep="\n")


