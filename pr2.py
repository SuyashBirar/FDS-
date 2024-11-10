total_students = int(input("Enter the total number of students in class: "))

groupA = []  # cricket
groupB = []  # badminton
groupC = []  # football

def get():
    n = int(input("Enter the number of students who play cricket: "))
    for i in range(n):
        temp = int(input("Enter the roll number: "))
        groupA.append(temp)
    print("\nGroup A (Cricket):", groupA, "\n")

    n = int(input("Enter the number of students who play badminton: "))
    for i in range(n):
        temp = int(input("Enter the roll number: "))
        groupB.append(temp)
    print("Group B (Badminton):", groupB, "\n")

    n = int(input("Enter the number of students who play football: "))
    for i in range(n):
        temp = int(input("Enter the roll number: "))
        groupC.append(temp)
    print("Group C (Football):", groupC, "\n")

def cricAndbad():
    cAb = []
    for i in groupA:
        if i in groupB:
            cAb.append(i)
    print("Students who play both cricket and badminton:", cAb)

def cricOrbad():
    cob = []
    for i in groupA:
        if i not in groupB:
            cob.append(i)
    for i in groupB:
        if i not in groupA:
            cob.append(i)
    print("Students who play either cricket or badminton but not both:", cob)

def cricNorbad():
    # Assuming "neither cricket nor badminton" means players of football only
    nf = [i for i in groupC if i not in groupA and i not in groupB]
    print("Students who play neither cricket nor badminton:", nf)

def cricAndfootNotbad():
    cNf = [i for i in groupA if i not in groupB]
    result = [i for i in cNf if i in groupC]
    print("Students who play cricket and football but not badminton:", result)

if __name__ == '__main__':
    get()
    print("\n")

    print("----")

    # MENU
    print("1. Press 1 for students who play cricket and badminton")
    print("2. Press 2 for students who play either cricket or badminton but not both")
    print("3. Press 3 for students who play neither cricket nor badminton")
    print("4. Press 4 for students who play cricket and football but not badminton")
    print("5. Press 5 to exit")

    while True:
        case = int(input("Enter your input here >\n"))

        match case:
            case 1:
                cricAndbad()
            case 2:
                cricOrbad()
            case 3:
                cricNorbad()
            case 4:
                cricAndfootNotbad()
            case 5:
                print("Exiting...")
                break
            case _:
                print("Invalid input")
