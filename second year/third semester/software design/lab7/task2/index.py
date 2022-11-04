def number_of_dividers(x):
    cnt = 0
    for i in range(x):
        if (x % (i + 1) == 0):
            cnt += 1
    return cnt

def main ():
    with open('data.txt', 'w') as f:
        for i in range(1, 1000001):
            f.write(str(i) + " : " + str(number_of_dividers(i)) + '\n')
    return

main()
