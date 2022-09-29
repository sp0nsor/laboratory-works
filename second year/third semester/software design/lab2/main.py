import random

def main():
    length = int(input("Введите количество элементов массива: "))
    array = []
    for i in range(length):
        array.append(random.randint(0, 100))
    
    print(f'Исходный массив: {array}')

    new_map = {array[i]: array[i + 1] for i in range(0, length - 1, 2)}

    print(f'Результат: {new_map}')


if __name__ == '__main__':
    main()