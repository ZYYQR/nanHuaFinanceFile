# -*- coding: UTF-8
import base64
import re
import os
# import iSearch


# pa = os.pardir  自定义编程 学习编程
pathfile1 = "E:/PyCharmZyyFile/NoteFinance/FuturesTrade/期货合约示例1.png"
print('新添加注释行')
# path =pathfile1.replace("\\", "/")
# print(path)

# # pathfile1 = pathfile1.replace()
print(pathfile1)
#
f = open(pathfile1, 'rb')

is_f = base64.b64encode(f.read())

f.close()

print(is_f)

# ll = "E:\PyCharmZyyFile\NoteFinance\FuturesTrade\期货合约示例1.png"
# open(r'll')

newPic = 165
BuyCall = 150
PutCall = 170
DueExecutionPrice = 175
EachContract = 100
# 假设到期执行价 DueExecutionPrice>170 ;EachContract 100份/合约
Scene1 = ((DueExecutionPrice-BuyCall)+(PutCall-DueExecutionPrice))*EachContract - 1300+250

print(Scene1)

DueExecutionPrice = 177.751
Scene1 = ((DueExecutionPrice - 170)*3-(DueExecutionPrice - 150))*100 - 750 + 1200
print(Scene1)

Amplitude = str((((DueExecutionPrice - 160)/160)/30)*100) + '%'
print(Amplitude)


def string2List(ustring):
    """将ustring按照中文，字母，数字分开"""
    retList=[]
    utmp=[]
    for uchar in ustring:
        if is_other(uchar):
            if len(utmp)==0:
                continue
            else:
                retList.append("".join(utmp))
                utmp=[]
        else:
            utmp.append(uchar)
        if len(utmp)!=0:
            retList.append("".join(utmp))
            print('retList', retList)
        return retList

def is_other(uchar):
    """判断是否非汉字，数字和英文字符"""
    if not (is_chinese(uchar) or is_number(uchar) or is_alphabet(uchar)):
        return True
    else:
        return False

def is_chinese(uchar):
    """判断一个unicode是否是汉字"""
    if uchar >= u'\u4e00' and uchar<=u'\u9fa5':
        return True
    else:
        return False
def is_number(uchar):
    """判断一个unicode是否是数字"""
    if uchar >= u'\u0030' and uchar<=u'\u0039':
        return True
    else:
        return False

def is_alphabet(uchar):
    """判断一个unicode是否是英文字母"""
    if (uchar >= u'\u0041' and uchar<=u'\u005a') or (uchar >= u'\u0061' and uchar<=u'\u007a'):
        return True
    else:
        return False
import re
print('=========================')
jpath = 'E:/PyCharmZyyFile/NoteFinance/FuturesTrade/TradeRuleNote1'

# i = jpath.replace("\\", "/")
# print(i)
with open(jpath, 'r+', encoding="utf8") as jF:
    for i in jF.readlines():
        print("   ", i)

