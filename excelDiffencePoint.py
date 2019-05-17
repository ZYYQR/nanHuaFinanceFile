# -*- coding: UTF-8
'''
比较两个excel不同
'''
import openpyxl
import xlrd
print("输入两个excel的路径")
excelpath1 = "D:/PyCharmZyyFile/fileDocument/Departmental_report/systemCpc1.xlsx"
excelpath2 = "D:/PyCharmZyyFile/fileDocument/Departmental_report/systemCweb1.xlsx"
# print(excelpath1)
wb1 = openpyxl.load_workbook(excelpath1)
workfile1 = xlrd.open_workbook(excelpath1)
workfile2 = xlrd.open_workbook(excelpath2)

sheetname1 = workfile1.sheet_names()
sheetname2excel = workfile2.sheet_names()

print('sheetname1 sheet 的名字', sheetname1)
print(" ===========")
table1 = workfile1.sheets()[0]       #通过索引顺序获取
# print(table1)
table2 = workfile1.sheet_by_index(0) #通过索引顺序获取
# print(table2)
table3 = workfile1.sheet_by_name(u'客户数据明细')#通过名称获取
# print(table3)
table_row = table1.row_values(0)

table_row_len_max = table1.nrows
table_col_len_max = table1.ncols
print("table_row_len_max value", table_row_len_max)
print("table_col_len_max value", table_col_len_max)
table_row_len = len(table_row)
print('table_row_len |', table_row_len)
print('输入该行value is table_row|', table_row)
table_col = table1.col_values(2)[2]
print('输出该列value is table_col | ', table_col)




'''
比较 row 有啥不同

比较 col 有哪些不同. 

相同的 跳过, value不同时, 打印 行, 列. 对比 
'''

# # 按照
# col_sort = sorted(table_col)
# print('It is col_sort', col_sort)
