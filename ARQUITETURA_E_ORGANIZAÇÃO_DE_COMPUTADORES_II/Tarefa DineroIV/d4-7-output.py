import re
import xlsxwriter
import os

def read_file(file_name):
    ref_file = open(file_name, "r")
    contents = ref_file.read()
    ref_file.close()
    contents = contents.split('l2-ucache')[1].split('Multi-block')[0].splitlines()
    res = []
    for s in contents:
            numbers = re.findall(r"[-+]?\d*\.\d+|\d+", s)
            if numbers:
                res += [numbers[0]]
    return res

def gererate_xlsx(data, row, col):
    workbook = xlsxwriter.Workbook('d4-output.xlsx')
    worksheet = workbook.add_worksheet()

    for i in range(row):
        for j in range(col):
            worksheet.write(j, i, data[i][j])

    workbook.close()

def execute_tests():
    cap = ['64K', '128K', '256K', '512K', '1M', '2M', '4M']
    sub = ['f', 'l']
    index = 0
    for i in sub:
        for j in cap:
            str = "d4-7/dineroIV -l1-dsize 16k -l1-isize 16k -l1-dassoc 8 -l1-ibsize 8 -l1-dbsize 32 -l1-ibsize 32 -l2-usize {} -l2-ubsize 32 -l2-uassoc 8 -l2-urepl {} -l2-uccc -informat d < 085.gcc.din > teste{}.txt".format(j, i, index)
            # print(str)
            os.system(str)
            index+=1


execute_tests()
matrix = []
for i in range(14):
    matrix.append(read_file("teste{}.txt".format(i)))
    os.system("rm teste{}.txt".format(i))

gererate_xlsx(matrix, len(matrix), len(matrix[0]))