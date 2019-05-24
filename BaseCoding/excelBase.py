#!/usr/bin/python
# -*- coding: UTF-8 -*-
import xlrd
import os
class excelCompare():
    '''
    excel文件差异对比
    对比, 行, 列;
    对比, 限定列
    跳过 m 列 对比;

    '''
    def __init__(self, pathExcel , pathExcel2):
        self.pathExcel = pathExcel
        self.pathExce2 = pathExcel2
        print(self.pathExcel)
        print(self.pathExce2)
        print('-----------------------------------------------------')
        workfile1 = xlrd.open_workbook(self.pathExcel)
        workfile2 = xlrd.open_workbook(self.pathExce2)
        sheetname1 = workfile1.sheet_names()
        sheetname2excel = workfile2.sheet_names()
        print("输出excel1的sheetname", sheetname1, '\n', '输出excel2的 sheetname', sheetname2excel)
        print('-----------------------------------------------------')
        self.worlfile11 = workfile1
        self.worlfile22 = workfile2
        self.sheetname11 = sheetname1
        self.sheetname22 = sheetname2excel

    # def doubleExcelConRow(self,nsheets = 0,nrows = 0, ncols = 0, k = 0 ):
    #     # excelpath1 = pathExcel
    #     # excelpath2 = pathExce2
    #
    #     workfile1 = self.worlfile11
    #     workfile2 = self.worlfile22
    #     sheetname1 = self.sheetname11
    #     sheetname2excel = self.sheetname22
    #     print("输出excel1的sheetname", sheetname1, '\n', '输出excel2的 sheetname', sheetname2excel)
    #     print('-----------------------------------------------------')
    #     table_excel1 = workfile1.sheets()[nsheets]  # 通过索引顺序获取
    #     table_excel2 = workfile2.sheets()[nsheets]  # 通过索引顺序获取
    #     table_excel1_row_len_max = table_excel1.nrows
    #     table_excel1_col_len_max = table_excel1.ncols
    #     print("excle1 行 max_value", table_excel1_row_len_max)
    #     print("excel2 列 max_value", table_excel1_col_len_max)
    #     print('-----------------------------------------------------')
    #     table_excel2_row_len_max = table_excel2.nrows
    #     table_excel2_col_len_max = table_excel2.ncols
    #     print("table_excel2_row_len_max value", table_excel2_row_len_max)
    #     print("table_excel2_col_len_max value", table_excel2_col_len_max)
    #     print('-----------------------------------------------------')
    #
    #     table_excel1_row = table_excel1.row_values(nrows)
    #     table_excel2_row = table_excel2.row_values(nrows)
    #
    #     cha1 = set(table_excel1_row).difference(table_excel2_row)
    #     cha2 = set(table_excel2_row).difference(table_excel1_row)
    #     print('excel1 与excel2 row(0)不同', cha1,'\n', 'excel2 与excel1 row(0)不同', cha2)
    #     print('-----------------------------------------------------')
    #
    #     table_excel1_row_len_maxss = max(table_excel1_row_len_max, table_excel1_col_len_max)
    #     while k:
    #         print('table_excel1_row_len_maxss', table_excel1_row_len_maxss)
    #         ss = table_excel1_row_len_maxss - 2
    #         # ss = 5
    #         while ss:
    #             i = ss
    #             # print('%s  %s'%(ss, i ))
    #             table_excel1_row = table_excel1.row_values(i)
    #             table_excel2_row = table_excel2.row_values(i)
    #             cha1 = set(table_excel1_row).difference(table_excel2_row)
    #             cha2 = set(table_excel2_row).difference(table_excel1_row)
    #             print('excel1 与excel2 row(0)不同', cha1, '\n', 'excel2 与excel1 row(0)不同', cha2,'\n', table_excel1_row,'\n',table_excel2_row)
    #             print('-----------------------------------------------------')
    #             ss = ss - 1
    #             k = - 1
    #         # print('k is ', k)
    #         if k < 0 :
    #             break
    #     pass
    #
    # global isnotSave
    # def writeTheExcel(self, n = 'tmp001', innerD = [], sheetname = 'sjsj', ncol = 0 , isnotSave = 0):
    #     '''加1 列
    #     isnotSave 为1 时,保存 excel
    #     n 文件名
    #     innerD 文件 数据
    #     '''
    #     import os
    #     from xlwt import Workbook
    #     import xlwt
    #     import os
    #     namefile = n # 文件名称,检查文件是否存在
    #     efile = os.path.exists(namefile)
    #     if efile:
    #         print("请先删除文件 %s"%(n))
    #     else:
    #         w = xlwt.Workbook()  # 创建一个工作簿
    #         ws = w.add_sheet(sheetname)  # 创建一个工作表
    #         if len(innerD)>2:
    #             global o
    #             o = 0
    #             for i in innerD:
    #                 ws.write(ncol,o, innerD[o])
    #                 o = o + 1
    #         else:
    #             pass
    #         if isnotSave == 1:
    #             w.save('%s.xls'%(n))
    #             print("写入 不全, 查看 isnotSave条件")
    #         else:
    #             print("文件写入中, 未达到关闭条件")
    #             if o == len(innerD) + 1:
    #                 isnotSave = 1
    #             else:
    #                 pass
    #

if __name__ == "__main__":
    excelpath1 = "F:/tmp/121.xls"
    excelpath2 = "F:/tmp/122.xls"
    pathExcel11 = excelpath1
    pathExce2222 = excelpath2
    s = excelCompare(pathExcel=pathExcel11, pathExcel2= pathExce2222)
