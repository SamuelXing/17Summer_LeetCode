#! /usr/bin/env python
#coding:utf-8

# the arabic multiplication algorithm

def arabic_multiplication(num1, num2):
    num_lst1 = [int(i) for i in str(num1)]
    num_lst2 = [int(i) for i in str(num2)]

    int_matrix = [[i*j for i in num_lst1] for j in num_lst2]

    str_matrix = [map(convertToStr, int_matrix[i]) for i in range(len(int_matrix))]

    matrix = [[int(str_matrix[i][j][z]) for j in range(len(str_matrix[i]))] for i in range(len(str_matrix)) for z in range(2)]

    print(matrix)

def convertToStr(num):
    if num < 10:
        return "0" + str(num)
    else:
        return str(num)

def multiply(x, y):
    return lambda: x * y

if __name__ == "__main__":
    arabic_multiplication(469, 38)