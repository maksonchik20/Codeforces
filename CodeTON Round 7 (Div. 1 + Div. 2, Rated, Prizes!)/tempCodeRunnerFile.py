import os, sys
# _, good, bad, gen, iters = sys.argv
_, bad, checker, gen, iters = sys.argv
for i in range(int(iters)):
    try:
        if (i % 10 == 0):
            print("Test", i, end=": \n", flush=True)
        os.system(f"{gen} > input.dat " + str(i))
        os.system(f"{bad} < input.dat > bad.ans")
        bd = open("bad.ans").read()
        string = open("input.dat").read().split("\n")[1]
        # print(string)
        os.system(f"{checker} < bad.ans > checker.dat " + string)
        check = open(f"{checker}.dat").read();
        if (check != "YES\n"):
            print(open("input.dat").read())
            print("bad: ")
            print(bd)
            break
    except:
        print("ТУТ RE")