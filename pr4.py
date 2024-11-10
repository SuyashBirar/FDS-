def linearSearch(I, key):
    for i in range(len(I)):
        if I[i] == key:
            return i
    return -1

def sentinelSearch(I, key):
    ISize = len(I)
    I.append(key)  # Append the key to the end of the list

    i = 0
    while I[i] != key:
        i += 1

    if i == ISize:
        return -1
    else:
        return i

NUMBERS = []
n = int(input("Enter the length of the list: "))
print("\n")

for i in range(n):
    temp = int(input("Enter the number for index " + str(i) + ": "))
    NUMBERS.append(temp)

key = int(input("\nThe key element to be found is: "))

print("\n")

print("Element", key, "at index using linear search:", linearSearch(NUMBERS, key))
print("Element", key, "at index using sentinel search:", sentinelSearch(NUMBERS, key))
