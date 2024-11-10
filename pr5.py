def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# Example input
percentage = [85, 62, 90, 73, 88]
print("Marks of students before sorting:", percentage)

# Sort using Shell Sort
shell_sort(percentage)
print("\nMarks after sorting using Shell Sort:")
for i in range(len(percentage)):
    print(percentage[i], end=" ")

# Sort using Insertion Sort
# Resetting percentage for demonstration
percentage = [85, 62, 90, 73, 88]  # Resetting to original for a second sort
insertion_sort(percentage)
print("\n\nMarks after sorting using Insertion Sort:")
for i in range(len(percentage)):
    print(percentage[i], end=" ")
