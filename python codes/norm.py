from math import sqrt

def mean(arr:list)-> int:
    return sum(arr)/len(arr)

def sd(arr)->float:
    n = len(arr)
    mn = mean(arr)
    return sqrt(sum([(x-mn)**2 for x in arr])/n)

def min_max(arr:list,n_min:float,n_max:float)->list:
    ans = []
    mn = min(arr)
    mx = max(arr)
    for i in arr:
        tmp = (n_max-n_min)*(i-mn)/(mx-mn)+(n_min)
        ans.append(tmp)
    return ans

def dec_scal(arr):
    den = 1
    mx = max(arr)
    while mx>0:
        den*=10
        mx//=10
    return [x/den for x in arr]

def z_score(arr:list)->list:
    mn = mean(arr)
    s = sd(arr)
    return [(x-mn)/s for x in arr]

n = int(input())
arr = [int(x) for x in input().split()]

print('Min Max Normalization : ',min_max(arr,0,1))
print(mean(arr))
print(sd(arr))

print('Decimal Scaling Normalization : ',dec_scal(arr))

print('Z-Score Normalization : ',z_score(arr))

