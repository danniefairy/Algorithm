#Merge sort O(nlogn):
a=[9,3,7,8,1,2,0,-1,100,50]

def merge(m):
    if(len(m)==1):
        print(m)
        return m
    ml=merge(m[:int(len(m)/2)])
    mr=merge(m[int(len(m)/2):])
    print(ml,mr)
    return sort(ml,mr)

def sort(ml,mr):
    output=[]
    index_l=0
    index_r=0
    for i in range(len(ml)+len(mr)):
        if(index_l==len(ml)):
            output.append(mr[index_r])
            index_r+=1
        elif(index_r==len(mr)):
            output.append(ml[index_l])
            index_l+=1
        elif(ml[index_l]<mr[index_r]):
            output.append(ml[index_l])
            index_l+=1
        elif(ml[index_l]>mr[index_r]):
            output.append(mr[index_r])
            index_r+=1
    return output

print("a:",a)
print("---Merge sorting---")
result=merge(a)
print("---Finish---")
print("result:",result)