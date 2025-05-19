a,b,c = map(float, input().split())

if a + b > c and a + c > b and c + b > a:
    print("Perimetro = %.1f" % (a + b + c))
else: 
    print("Area = %.1f" % ((a + b) * c/2))

