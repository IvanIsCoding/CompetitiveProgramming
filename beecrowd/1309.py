# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1309
#!/usr/bin/env python
# encoding : utf-8
def metodo(texto):
    if texto in [str(i) for i in range(10)]:
        return "0%s" % texto
    else:
        return texto


while True:
    try:
        entrada1 = [k for k in input()]
        entrada2 = input()
        tamanho = len(entrada1)
        if tamanho <= 3:
            print("$%s.%s" % ("".join(entrada1), metodo(entrada2)))
        else:
            if tamanho % 3 == 1:
                entrada1.insert(0, "*")
                entrada1.insert(0, "*")
            elif tamanho % 3 == 2:
                entrada1.insert(0, "*")
            count = 0
            for i in range(3, tamanho, 3):
                entrada1.insert(i + count, ",")
                count += 1
            print("$%s.%s" % ("".join(entrada1).replace("*", ""), metodo(entrada2)))
    except EOFError:
        break
