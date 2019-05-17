# -*- coding: UTF-8
import operator

l = [('5', '黑桃', 'cover'), ('A', '红桃', 'cover'), ('2', '梅花', 'cover'), ('8', '方片', 'cover')]

sortlist = ["3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2"]

print(l[0][0])

def sortTed(keyList= [], sourceList = [], element = str()):
    '''
    :param key: 排序规则. 需要排序的 list 跟 规则list 比较， 相同的 就记一个someList， 不相同的就 排序相加, 最后， 按照 someList = sourceList， 再排序一次
    :param sourceList: 需要排序的 list
    :param element: sort element , 根据它来排序
    :return: return the sorted list
    '''


    iolist = [] #''' list(sourceList[element]) '''
    pok1 = []
    pok11 = []
    for x in sourceList:
        iolist.append(x[0][0])
    someList = []
    print('取 需要排列的 list的 值list', iolist)

    i = 1
    x = len(iolist) -1
    while i >= 0:
        x1 = x - 1
        if keyList.index(iolist[x1]):
            xc = keyList.index(iolist[x1])
            # print('1', xc, iolist[x1])
            pok1.append(xc)
        else:
            pass
        # print('到这么')
        x = x - 1
        i = x
    pok12 = sorted(pok1)
    print('pok12', pok12)
    i = 1

    while i>= 0:
        for k in pok12:
            pok11.append(keyList[k])
            print('1', k)
        i = -1
    print('pok11', pok11)
    # i = 1
    x = len(iolist) -1
    i = x
    p = []
    while i>=0:
        print('---------------', x, 'i', i)
        for d in range(0, x+1):
            if pok11[d] == sourceList[d][0]:
                print('--------------d-', d, sourceList)
                print(sourceList[d])
                print('i de 值', i, '| d', d)
                p.append(sourceList[d])
                sourceList = list(set(sourceList) - set(list(sourceList[d])))
                print('d', d, '|x', x)
                if d == x:
                    i = -1
                    x = -2
                    continue
            else:
                pass
    pass


sortTed(keyList=sortlist, sourceList=l, element=l[0][0])