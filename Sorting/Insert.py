#Insert sort O(n):
#insert the small element before the bigger one
a=[4,60,2,100,3,7000,456,489,1034]

for i in range(1,len(a)):
    index=i
    for j in range(i-1,0-1,-1):
        if(a[j]>a[index]):
            temp=a[j]
            a[j]=a[index]
            a[index]=temp
            index=j
        else:
            break
    print(a)