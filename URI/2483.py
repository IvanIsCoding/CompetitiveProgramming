# Ivan Carvalho
# Solution to https://www.urionlinejudge.com.br/judge/problems/view/2483
#!/usr/bin/env python2.7
# -*- coding : utf-8 -*-
mensagem = "Feliz n*tal!"
repeticoes = int(raw_input())
print mensagem.replace("a","a"*repeticoes).replace("*","a")
