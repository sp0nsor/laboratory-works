import random
import string


def get_random_string(length):
    result_str = ''.join(random.choice(string.ascii_letters + '1234567890') for i in range(length))
    return result_str


def main():
    try:
        string_length = int(input('Введите длину строк (целое число >= 1): '))

        if string_length <= 0:
            raise ValueError('Длина строки должна быть строго больше нуля')

        str1 = get_random_string(string_length)
        print(f'\nПервая строка: {str1}')

        str2 = get_random_string(string_length)
        print(f'Вторая строка: {str2}')

        count_1 = int(input('\nВведите количество первых символов первой строки: '))
        if count_1 <= 0 or count_1 > string_length:
            raise ValueError('Количество символов должно быть больше нуля и меньше длины строки')

        count_2 = int(input('Введите количество последних символов второй строки: '))
        if count_2 <= 0 or count_2 > string_length:
            raise ValueError('Количество символов должно быть больше нуля и меньше длины строки')

        result = str1[:count_1]
        result += str2[len(str2) - count_2:]

        print(f'\nРезультат: {result}')
    except ValueError as error:
        print(f'\nНекорректный ввод!!!\n{error}')


if __name__ == '__main__':
    main()