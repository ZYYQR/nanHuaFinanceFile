# -*- coding: UTF-8

'''
Under the water in one day。。。  水一天下， 大家来吹牛
水一天下, 1-9, J-K,
若 X=X1 且 X1 = 1 + (X-1) 则 X < X1;
若 X=X2 且

四张一样的牌最大, 水艺天下. 8倍; A 水一最大

闷, 三倍. 可过, 可杀
强攻, 2倍;  必开

亮牌, 可杀, (不认, 两铺牌, 一铺大于庄家)
亮牌, 可过. (反, 两铺牌, 都大于庄家)

庄家可以看所有人的牌

闲家可以看 所有人的牌.

闲家可以知道 , 那些牌被杀, 哪些牌, 过;

三次不算, 当天封号; 封号状态 loginStatus

第一张牌， 可以移动两次。 第二张牌， 移动一次。

'''

'''
xp = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47]

x = []
for i in range(0,48):
    x.append(i)
print(x)
'''

# xxx = len(sourceClub)
# kxxx = int(xxx/4)
# print("几个人", kxxx, "|", type(sourceClub))计算 能有， 多少组人， 来玩；


import random

sourceKey = ["2","3","4","5","6","7","8","9","J","Q","K", "A"]
sourceColor = ["黑桃", "红桃", "梅花", "方片"]

blackAndOpen1 = ['blackCover', 'openOn']
blackAndOpen = ['blackCover']
sourceClub = []

for x in sourceKey:
    for y in sourceColor:
        for z in blackAndOpen:
            x = x
            y = y
            z = z
            club = (x, y, z)
            # print(club)
            sourceClub.append(club)

print("==============================")

s = 4
s = s + 1
print(sourceClub[9], " 牌的 张数", len(sourceClub)) # 一张牌 ， 翻开， 盖着。


'''
s 表示 参与组数； 一组 四张牌； 一组牌， 两个元素 

'''
siren = ['x1', 'x2', 'x3', 'x4', 'x5', 'x6', 'x7', 'x8', 'x9', 'x10', 'x11', 'x12']

while s:
    '''
    s 表示 参与组数, 也就是发几组牌;
    一组四张牌. 
    '''
    s = s - 1

def fourUniqueNum():
    # print(' 开始1, fourUniqueNum, 取12组')
    club12 = []
    print('开始分派')
    xp = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
          28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47]
    # print('xp 的属性', type(xp), "开始有的牌\n", xp)
    for i in range(0, 12):
        ssss = 1
        while ssss:
            numx1 = random.sample(xp, 4)
            # print(numx1)
            print("这是第%s组牌," % (i + 1) + str(numx1))

            x1 = numx1[0]
            x2 = numx1[1]
            x3 = numx1[2]
            x4 = numx1[3]
            # print(x1)
            xp.remove(x1)
            # print(x2)
            xp.remove(x2)
            # print(x3)
            xp.remove(x3)
            # print(x4)
            xp.remove(x4)
            # print('查询 剩余的牌', len(xp),'\n', xp)
            club12.append(numx1)
            ssss = ssss - 1
    #         if len(ss) == 4:
    #             print('fourUniqueNum:', numx1, numx2, numx3, numx4)
    #             ssss = ssss - 1
    #             pass
    #         else:
    #             continue
    # # return s
    # # pass
    # print(club12)
    return club12
#
# speople = fourUniqueNum()
# #
# print('speople', speople) # 输出 某人的 牌序号；

def extractionPoker(s4 = [], n = 2):
    '''
    根据组数， 分派
    s4 表示 组的 index， n表示组数
    :param s4:
    :return:
    '''
    # print(s4, '\n', n)
    # print("Poker ", sourceClub)
    print('开始发牌========')
    while n:
        x = 'lue' + str(n)
        x = list(x)
        # print(x, type(x), '|', type(sourceClub))
        c1, c2, c3, c4 = s4[n]
        # print('元素%s'%(n), sourceClub[c1], sourceClub[c2], sourceClub[c3], sourceClub[c4])
        olo = [sourceClub[c1], sourceClub[c2], sourceClub[c3], sourceClub[c4]]
        x = olo
        print('第 %s 组牌'%(n), x)
        n = n - 1
    pass

def ContrastPoker(cd = [], cs = []):
    '''
    闲家 翻牌,庄家说 过.(过, 反)
    闲家 翻牌,庄家说 杀.(反, 认)

    闲家盖牌, 庄家说, (认. 翻)

    闲家翻一张, 庄家说, (认, 比)

    四张牌相同, 水一天下. 最大

    左一组(同), 右一组(同), 水一;

    左一组(同), 右一组(9, 8) [9 + (J, Q, K)>1 + 8, 2 + 7]

    规则, 共四张,分两组, 左一组(大), 右一组(小);

    :param cd: cd 庄家牌
    :param cs: cs 闲家牌
    :return:
    '''
    sktone = ['2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A']
    sktoneTwo = ['2', '3', '4', '5', '6', '7', '8', '9', 'A']
    sktoneThree = ['J', 'Q', 'K']
    sktoneColor = ["黑桃", "红桃", "梅花", "方片"]

    if cd[0][0] == cd[1][0]:

        pass
    else:
        ''' 此组 大于10， 等于10 ， 小于10； 小于10【9 + sktoneThree【i】, 1 + 8 , 2 + 7 ...牌面一致比花色】 '''

        pass

    xs = 1


    pass

def LockPlate(x = []):
    '''
    锁牌, 锁牌后,不可换牌;
    不可 换牌，  列表 格式转换为将 元组 ；  
    :return:
    '''
    pass


def movedThePoker(k = [], xsign =(1, 3)):
    klist = k
    mvsign = xsign
    print('\n移动前', klist, '\n被移动', klist[mvsign[0] - 1], '与', klist[mvsign[1] - 1])
    x1 = klist[mvsign[0] - 1]
    tmppoker = klist[mvsign[1] - 1]
    x2 = x1
    x1 = tmppoker

    klist[mvsign[0] - 1] = x1
    klist[mvsign[1] - 1] = x2
    print("\n移动后", klist)
    return klist

def waterTheSky(k = []):
    print('waterTheSky -->')
    # print('牌1', k[0][0])
    ssetlist = [k[0][0], k[1][0], k[2][0], k[3][0]]
    # print('构建 set', set(ssetlist))
    om = set(ssetlist)

    ssetlistlen = len(om)
    # print('ssetlistlen', ssetlistlen)
    omm = list(om)

    if ssetlistlen == 1:
        print("水一天下")
        return [k[0][0]]
        pass
    elif ssetlistlen == 2:
        print("水一")
        print('om', omm)

        return omm
    elif ssetlistlen == 3:
        print("可 报1")
        return k
    else:
        print(" 一般的 牌 ")
        return k

if __name__ == "__main__":
    speople = [[19, 20, 14, 3], [7, 41, 28, 17], [6, 11, 8, 34], [30, 16, 22, 44], [45, 36, 23, 12], [26, 4, 9, 29],
               [21, 25, 15, 2], [5, 33, 18, 35], [42, 38, 43, 31], [32, 39, 47, 27], [46, 37, 13, 24], [40, 10, 1, 0]]

    extractionPoker(s4=speople)
    print(" 华丽的分割线 ")
    v1 = [('2', '方片', 'blackCover'), ('Q', '红桃', 'blackCover'), ('8', '黑桃', 'blackCover'), ('5', '红桃', 'blackCover')]
    v2 = [('2', '梅花', 'blackCover'), ('3', '方片', 'blackCover'), ('3', '黑桃', 'blackCover'), ('9', '梅花', 'blackCover')]
    v3 = [('2', '梅花', 'blackCover'), ('3', '方片', 'blackCover'), ('3', '黑桃', 'blackCover'), ('2', '红桃', 'blackCover')]
    v4 = [('2', '梅花', 'blackCover'), ('2', '方片', 'blackCover'), ('2', '黑桃', 'blackCover'), ('2', '红桃', 'blackCover')]

    print("牌1 ", v1)
    print("牌2 ", v2)

    movedThePoker(k=v2, xsign=(1, 3))

    waterTheSky(k=v3)
