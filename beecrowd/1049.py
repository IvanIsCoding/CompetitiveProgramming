# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1049
# -*- coding: utf-8 -*-
dicio = {
    "vertebrado": {
        "ave": {"carnivoro": "aguia", "onivoro": "pomba"},
        "mamifero": {"onivoro": "homem", "herbivoro": "vaca"},
    },
    "invertebrado": {
        "inseto": {"hematofago": "pulga", "herbivoro": "lagarta"},
        "anelideo": {"hematofago": "sanguessuga", "onivoro": "minhoca"},
    },
}
array = []
for i in range(3):
    array.append(input())
a, b, c = array
print(dicio[a][b][c])
