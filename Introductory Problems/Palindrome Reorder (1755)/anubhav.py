s,a,o,c,l=input(),'','',0,[0]*27
for i in s:
    l[ord(i)-ord('A')+1]+=1
for i in range(1,27):
    a+=chr(i+ord('A')-1)*(l[i]//2)
    if l[i]%2==1:o,c=chr(i+65-1),c+1
    if(c>1):break
if c>1:print("NO SOLUTION")
else:print(a+o+a[::-1])
