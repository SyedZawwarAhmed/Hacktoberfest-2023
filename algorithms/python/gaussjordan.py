M3 = []
r  = int(input("Number of equations: "))
c = r + 1
for i in range(r):
        r3 = []
        for j in range(c):
                x = float(input("Enter the number: "))
                r3.append(x)
        M3.append(r3)

M2 = []
r1 = r
c1 = c
for i in range(r1):
        r2 = []
        for j in range(c1):
                r2.append(0)
        M2.append(r2)



for i in range(len(M3)):
        pivt = M3[i][i]
        for j in range(len(M3[i])):
                M3[i][j] = M3[i][j]/pivt
                M2[i][j] = M3[i][j]
        j = i
        for  k in range(len(M3)):
                if(k==j):
                        continue
                else:
                        x = M3[k][i]
                        for r in range(len(M3[i])):
                                M3[k][r] = M3[k][r] - (x*M2[j][r])
# print(M3)

for i in range(len(M3)):
        print("The value of ", i+1, " variable is: ", M3[i][-1])
