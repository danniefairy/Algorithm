#Bubble sorting O(n):
#comparison of two adjacent element from the begin to the end
a=[3,38,5,44,15,26,37,41,2,9,4]

#include len(a)-1 without 0
for j in range(len(a)-1,0,-1):
    for i in range(j):
        if(a[i]>a[i+1]):
            temp=a[i]
            a[i]=a[i+1]
            a[i+1]=temp
        print(a)

