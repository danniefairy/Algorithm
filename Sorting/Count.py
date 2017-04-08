#Count sort O(n+d):

a=[5,6,1,2,3,7,8,5,6,7,9,0]

digit=[[],[],[],[],[],[],[],[],[],[]]
for i in range(len(a)):
    digit[a[i]].append(a[i])
output=[]
for i in range(10):
    output.extend(digit[i])
    
print(output)