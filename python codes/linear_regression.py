n = int(input())
xarr = [int(x) for x in input().split()]
yarr = [int(x) for x in input().split()]

sy = sum(yarr)
sx = sum(xarr)
sx2 = sum([x**2 for x in xarr])
sxy = sum([xarr[i]*yarr[i] for i in range(n)])

# y = mx + c

m = (n*sxy-sx*sy)/(n*sx2-(sx)**2)
c = (sx2*sy-sx*sxy)/(n*sx2-(sx)**2)

print('y = ',str(m)+'x + ',c)

