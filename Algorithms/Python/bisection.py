a=float(input("enter lower limit in which solution lies :"))
b=float(input("enter upper limit in which solution lies :"))

x = a
fa= x**2 +  x - 6

x = b
fb= x**2 + x - 6

f = fa * fb
if (f > 0):
    print("given range does not exist solution")
else:
    fc = 1
    k=1
    while fc != 0:
        c= (a+b)/2
        x=c
        fc= x**2 + 3 *x - 10
        f=fa*fc
        print("k= a={}  b= {}  c={}".format(k,a,b,c))

        if f < 0:
            b = c
        else:
            a = c
        k += 1

print("solution of given equation is {}".format(c))
