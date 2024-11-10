def quick_sort(percent):
    if len(percent) <= 1:
        return percent
    else:
        pivot = percent[0]
        left_element = [i for i in percent[1:] if i <= pivot]
        right_element = [i for i in percent[1:] if i > pivot]

        return quick_sort(left_element) + [pivot] + quick_sort(right_element)

percentages = []

students = int(input("Enter the number of students: "))

for i in range(students):
    percentage = float(input(f"Enter percentage for student {i + 1}: "))
    percentages.append(percentage)

sorted_percentages = quick_sort(percentages)

# Get the top five scores
if len(sorted_percentages) < 5:
    top_five = sorted_percentages
else:
    top_five = sorted_percentages[-5:]

print("Top Scores:")
for score in top_five:
    print(score)

