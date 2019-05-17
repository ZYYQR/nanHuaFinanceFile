# -*- coding: UTF-8

s = ''
for i in range(1, 256):
    s = s + str("式")
    if i >254 or i < 3:
        print(i)
    else:
        continue

print(s)