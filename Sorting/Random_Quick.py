#Random Quick sort O(nlogn):

#for generating the random number
import numpy as np

a=[10,5,6,1,7,3,4,55,23,77]

def split(m):
    if(len(m)<=1):
        return m
    pivot=np.random.randint(len(m))
    left=[]
    right=[]
    for i in range(len(m)):
        if(i!=pivot):
            if(m[i]<m[pivot]):
                left.append(m[i])
            else:
                right.append(m[i])
    #splite result
    print("left:",left,"pivot:",m[pivot],"right:",right)
    
    #recursion
    left=split(left)
    right=split(right)
    
    #merge reult
    if(type(left)==list):
        output=left
    else:
        output=[left]
    mid=[m[pivot]]
    mid.extend(right)
    output.extend(mid)

    return output
    
print(split(a))