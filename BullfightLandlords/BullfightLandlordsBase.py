# -*- coding: UTF-8

import random


class startPoker():
    sourceKey = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]
    sourceColor = ["黑桃", "红桃", "梅花", "方片"]
    playCards = []
    biddingCards = []
    sourceClub = []

    def __init__(self, playCards, biddingCards, sourceClub):
        self.playCards = playCards
        self.biddingCards = biddingCards
        self.sourceClub = sourceClub

    def AAA(self):
        '''

        :return:  numx1, numx2, numx3 返回三组牌。
        '''
        gaiPai = ['cover']

        for x in self.sourceKey:
            for y in self.sourceColor:
                for i in gaiPai:
                    x = x
                    y = y
                    club = (x, y, i)
                    # print(club)
                    self.sourceClub.append(club)
        wang1 = [("大王", 'x', 'cover'), ("小王", 'x', 'cover')]

        # print(wang1)
        self.sourceClub = self.sourceClub + wang1
        print('all The poker\n', self.sourceClub, 'len', len(self.sourceClub))
        numx1 = random.sample(self.sourceClub, 17)
        self.sourceClub = set(self.sourceClub) - set(numx1)
        numx2 = random.sample(self.sourceClub, 17)
        self.sourceClub = set(self.sourceClub) - set(numx2)
        numx3 = random.sample(self.sourceClub, 17)
        self.sourceClub = set(self.sourceClub) - set(numx3)

        bottomCard = list(self.sourceClub)
        # print('=========开始分牌================================')
        # print('a的牌\n', len(numx1))
        # print(len(numx2))
        # print(len(numx3))
        # print(bottomCard)
        return numx1, numx2, numx3, bottomCard

    def ProhibitionOfPlayingCards(self):
        '''本轮已经说话, 禁止 出牌'''
        print()

    soutToBid = []
    speakToBid = []

    def toBidS(self, soutToBid, speakToBid):

        if len(soutToBid) == len(speakToBid):
            print(speakToBid)
        else:
            print('重新出牌')

        pass

    def toWho(self):
        '''记录 到 谁出牌'''
        '''记录， 本次是 谁出牌'''
        pass

    def Note(self):
        '''
        https://www.jb51.net/article/129909.htm
        Python实现比较扑克牌大小程序代码示例
        '''
        pass

    def card_ranks(self, hand):
        sourceKey = ["2","3","4","5","6","7","8","9","J","Q","K", "A"]
        sourceKey = set(sourceKey)
        for i in range(0, len(hand)):
            print('hand[i][0]', hand[i][0])
            ranks = [sourceKey .INDEX(r) for r in hand[i][0]]
            ranks.sorted(reverse=True)
            print('排序后的牌', ranks)
        return ranks

if __name__ == "__main__":
    A1 = startPoker(sourceClub=[], playCards=[], biddingCards=[])

    a,b,c,d=A1.AAA()
    xx = [("6", 2), ("6", 3)]
    xxx = [('A', '黑桃'), ('A', '红桃'), ('A', '梅花'), ('A', '方片'), ('2', '黑桃'), ('2', '红桃'), ('2', '梅花'), ('2', '方片'), ('3', '黑桃')]
    A1.card_ranks(hand=a)
