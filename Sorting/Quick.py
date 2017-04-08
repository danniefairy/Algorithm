#Quick sort O(nlogn):
a=[10,5,6,1,7,3,4,55,23,77]
def split(m):
    if(len(m)<=1):
        return m
    pivot=0
    left=[]
    right=[]
    for i in range(len(m)-1):
        if(m[i+1]<m[pivot]):
            left.append(m[i+1])
        else:
            right.append(m[i+1])
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
