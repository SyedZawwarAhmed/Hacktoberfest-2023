b=float(input("How many coulumns do you want?_"))
a=float(input("How many rows do you want?_"))
d=[]
l=0
while l < a :
	c=[]
	k=0
	while  k < b :
		x=int(input("Enter the number_"))
		c.append (x)
		k += 1
	d.append (c)	
	l += 1
u=0
while u < len(d) :
	v=0
	while v < len(c) :
		print (d[u][v],end=" ")
		v += 1
	u += 1
	print ("\n")
