n, m = map(int, input().split())

result = 1;

if(m > (n>>1)):
    m = n-m

x= n-m

for i in range(n, x, -1):
    result = result * i

for i in range(2, m+1):
    result = result//i

print(result)
