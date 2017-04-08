#Select sort O(n):
#From the begin to the end to find the smallest element and swift those elements
a=[16,2,4,83,3,11]
print(a)
for i in range(len(a)-1,0,-1):
    start=len(a)-i-1
    index=start
    for j in range(i):   
        if(a[j+1+start]<a[index]):
            index=j+1+start   
    temp=a[start]
    a[start]=a[index]
    a[index]=temp
    print(a)