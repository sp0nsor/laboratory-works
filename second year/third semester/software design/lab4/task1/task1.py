
def main ():
    s = input ("Введите основную строку >>")
    s0 = input ("Введите строку для удаления >> ")
    print(' '.join(s.replace(s0, '', 1).split()))

if __name__ == "__main__":
    main()