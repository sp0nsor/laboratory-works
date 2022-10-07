def main():
    s = input("Введите строку: ")

    s1 = input("Введите подстроку для поиска: ")

    s2 = input("Введите подстроку для замены: ")

    s = s.replace(s1, s2)

    print(s)


if __name__ == "__main__":
    main()
