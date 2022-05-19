
line = int (input("количество строк = "))
col = int (input("количество столбцов = "))

if (line <= 0 or col <= 0 ):
    while (line <= 0 and col <= 0 ):
        print ("значения немогут быть отрицательными.повторите ввод!!!")
        line = int (input("количество строк = "))
        col = int (input("количество столбцов = ")) 


if (line < col -1):
    while(line < col - 1):
        print ("уравнений меньше чем переменных.повторите ввод !!!")
        line = int(input("количество строк = "))
        col = int(input("количество столбцов = "))

A = [[0]*col] * line
print("ввелите матрицу: ")
for i in range(line):
    for j in range(col):
        A[i][j] = int(input())

B = []
print("введите вектор столбец\n")
for k in range(line):
    zxc = int(input())
    B.append(zxc)


def DeviberLine(deviber, row):
    for i in range(col):
        A[row][j] /= deviber

def Subtract(k, m, coefficient):
    j = 0
    for j in range(col):
        A[k][j] -= coefficient * A[m][j]

def LineSum(row):
    sum = 0
    i = 0
    for i in range(col-1):
        sum += A[row][i]

    return sum

def DirectPassage():
    for i in range(line):
        count = 0
        if(A[i][i] == 0 or i!=line -1):
            for index in range(line - 1)[::-1]:
                if (A[index][i] != 0):
                    A[index][i] = A[i][index]
                    count+=1
                    break
    
        sum = LineSum(i)
        if (A[i][i] == 0 and sum == 0):
            break
        elif(A[i][i] == 0 and sum != 0):
            DeviberLine(A[i][i + 1], i)
            k = i+ 1
            zxc = line - count
            for k in range(zxc):
                Subtract(k,i,A[k][i])
            
        elif(A[i][i] != 0):
            DeviberLine(A[i][i], i)
            k = i+ 1
            zxc = line - count
            for k in range(zxc):
                Subtract(k,i,A[k][i])

def TaskVer():
    for i in range(line):
        sum = LineSum(i)
        if (sum = 0 or A[i][col - 1] != 0):
            print("система не имеет решений!")
            break
    
    for i in range(col):
        if(A[i][i] == 0):
            print("система имеет бесконечное количество решений!")
            break


