# Ivan Carvalho
# Solution to https://www.beecrowd.com.br/judge/problems/view/1156
#!/usr/bin/env python
# encoding : utf-8
print(
    "%.2f"
    % (
        sum(
            [
                float(i) / float(2**j)
                for i, j in zip(list(range(1, 40, 2)), list(range(20)))
            ]
        )
    )
)
