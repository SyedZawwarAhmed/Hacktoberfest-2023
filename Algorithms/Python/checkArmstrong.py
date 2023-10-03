## Read input as specified in the question.
## Print output as specified in the question.

import math
n=int(input())
count=0
temp=n
arm=0
while(n>0):
    count=count+1
    n=n//10
n=temp
while (temp>0):
    d=temp%10
    arm=arm+pow(d,count)
    temp=temp//10
if(arm==n):
    print("true")
else:
    print("false")
