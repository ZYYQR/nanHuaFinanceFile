# -*- coding: UTF-8
'''
比较两个excel不同
'''
import openpyxl
import xlrd
excelpath1 = "D:/PyCharmZyyFile/fileDocument/Departmental_report/systemCpc1.xlsx"
excelpath2 = "D:/PyCharmZyyFile/fileDocument/Departmental_report/systemCweb1.xlsx"
print(excelpath1)
wb1 = openpyxl.load_workbook(excelpath1)
workfile = xlrd.open_workbook(excelpath1)
sheetname = workfile.sheet_names()
print(sheetname)
print(" ===========")
# excelpath1sheet1 = wb1.get_active_sheet()
# print('type1 根据 坐标获取该值', type(excelpath1sheet1))
# x = excelpath1sheet1.cell(1,1).value
# print(x)
table1 = workfile.sheets()[0]          #通过索引顺序获取
print(table1)
table2 = workfile.sheet_by_index(0) #通过索引顺序获取
print(table2)
table3 = workfile.sheet_by_name(u'客户数据明细')#通过名称获取
print(table3)
table_row = table1.row_values(0)

table_row_len_max = table1.nrows
table_col_len_max = table1.ncols
print("table_row_len_max value", table_row_len_max)
print("table_col_len_max value", table_col_len_max)
table_row_len = len(table_row)

print('table_row_len |', table_row_len)
print('is table_row|', table_row)
table_col = table1.col_values(2)[2]
print('is table_col | ', table_col)
# # 按照
# col_sort = sorted(table_col)
# print('It is col_sort', col_sort)
