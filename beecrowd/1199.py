# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1199
#!/usr/bin/env python
# encoding : utf-8
while True:
    entrada = input()
    if "-" in entrada:
        break
    elif "x" in entrada:
        print(int(entrada, 16))
    else:
        print("0x" + hex(int(entrada))[2:].upper())
