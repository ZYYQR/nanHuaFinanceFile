
# -*- coding: UTF-8

import os
from xlwt import Workbook
import xlwt
abspath = os.getcwd()  # 获取当前路径
rootpath = os.path.abspath('..')  # 获取上级路径
print(abspath)
print(rootpath)
s =abspath
op = s.replace('\\', '/')
print(op)

import os
from xlwt import Workbook
import xlwt
import xlrd

namefile =  '111.xls'
efile = os.path.exists(namefile)
print('is efile_exists', efile)

if efile:
    wb = xlrd.open_workbook(namefile)
    sheetwri = wb.sheets()
    sheetwri.insert(index=4,object = 'kkkkkk')
else:
    w = xlwt.Workbook() #创建一个工作簿
    ws = w.add_sheet('1') #创建一个工作表
    ws.write(1,2,'ssss')
    w.save('111.xls')