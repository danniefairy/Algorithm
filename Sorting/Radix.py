#Radix sort O(d*n):
#sort each element by allocating each digit number 
a=[23456,102,5687,6654,5687,2394,0,12,110000000,4684,100000000]
d=1
while(True):
    temp=[[],[],[],[],[],[],[],[],[],[]]
    a_copy=[]
    a_max=-10000
    for i in range(len(a)):
        a_copy.append(a[i])
        temp[(int(a[i]/d)%10)].append(i)
        if(a[i]>a_max):
            a_max=a[i]
    queue=[]
    for i in range(10):
        queue.extend(temp[i])
    for i in range(len(a)):
        a[i]=a_copy[queue[i]]
    d*=10
    print(a)
    if(int(a_max/d)==0):
        break
    
    