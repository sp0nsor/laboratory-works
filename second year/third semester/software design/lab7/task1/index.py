import math


def function_expression(x):
    if x == 1:
        raise ZeroDivisionError ('ошибка деления на ноль!')
    if x <= 0:
        raise ValueError ('значение долно быть > 0')
    return 1 / math.sqrt(x * x - 1) 

def main():
    for i in range(10):
        try:
            x = float(input('Введите х > '))
            print (function_expression(x))
        except ValueError as value_error:
            print('введено некорректное значение!')
            print(value_error)
        except OverflowError as overflow_error:
            print('число слишком велико!')
            print(overflow_error)
        except ZeroDivisionError as zero_division_error:
            print (zero_division_error)
        except KeyboardInterrupt:
            print ('количество попыток > ', str(100 - i))
            return


main()
