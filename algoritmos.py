def masGrande(arr):
    mayor = arr[0]
    for num in arr:
        if num > mayor:
            mayor = num
    return mayor

arr = [1, 2, 3, 4, 5]
mayor = masGrande(arr)
print(f"El numero mayor es: {mayor}")
