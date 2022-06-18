# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/2483
#!/usr/bin/env python
# -*- coding : utf-8 -*-
mensagem = "Feliz n*tal!"
repeticoes = int(input())
print(mensagem.replace("a", "a" * repeticoes).replace("*", "a"))
