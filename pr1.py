def read(n):
    i = 0
    while i < n :
        a = input()
        if a.isdigit() or a.upper() == 'NA':
            i += 1
            l.append(a)
        else:
            print("Please re-enter the same students score")

def average():
    t = 0
    for i in l:
        if i.upper() != 'NA':
            t += int(i)
    print("Average",t/len(l))

def max_min():
    maxi = mini = l[0]
    for i in l:
        if i.upper() != 'NA':
            if i > maxi :
                maxi = i
            if i < mini :
                mini = i
    print("Highest Score Obtained is",maxi)
    print("Lowest Score Obtained is",mini)

def absent():
    a = 0
    for i in l:
        if i.upper() == 'NA':
            a += 1
    print("There are",a,"Students Absent")


def frequency():
    frequency_1 =0
    frequency_2 = 0
    high_marks = 0
    for i in l:
        if i.isdigit():
            for j in l:
                if j.isdigit():
                    if int(i) == int(j) :
                        frequency_1 += 1
        if frequency_1 > frequency_2:
            frequency_2 = frequency_1
            high_marks = int(i)
        frequency_1 = 0
    if frequency_2 == 1:
        print("All marks are having equal frequency.")
    else:
        print("The marks with highest frequency is:",high_marks)
        print("It occured",frequency_2,"times")


print("Practical No 1")
print()
n = int(input("Enter total numbers of Students"))
print("Enter marks of each student in case of Absenty enter 'NA'")
global l
l = []
read(n)
print(l)
print("1. Calculate the Average Score of Class")
print("2. Display Highest Score and Lowest Score")
print("3. To Calculate the number of Students Absent")
print("4. To Calculate the marks with highest frequency")
print("5. Exit")
ch = int(input())
if ch == 1:
    average()
elif ch == 2:
    max_min()
elif ch == 3:
    absent()
elif ch == 4:
    frequency()
elif ch == 5:
    print("Thank You")
else:
    print("Invalid Input Please Try Again")
