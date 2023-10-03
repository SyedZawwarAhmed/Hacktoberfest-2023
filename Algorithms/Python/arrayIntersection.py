def intersection(arr1,arr2,n,m):
  arr1.sort()
  arr2.sort()
  i,j=0,0
  final=[]
  count=0
  while (i<n and j<m):
    if (arr1[i]==arr2[j]):
      final.append(arr1[i])
      count=count+1
      i=i+1
      j=j+1
    elif (arr1[i]<arr2[j]):
      i=i+1
    else:
      j=j+1
  return final

n=4
arr1=[2,6,1,2]
m=5
arr2=[1,2,3,4,2]
ans = intersection(arr1,arr2,n,m)
print(ans)
