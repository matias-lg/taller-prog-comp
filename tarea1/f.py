n = 150000
i = 10**9
with open("./cout.txt", "w") as f:
    f.write(str(n) + "\n")
    for k in range(n):
        f.write(str(i) + " ")
    f.close()
