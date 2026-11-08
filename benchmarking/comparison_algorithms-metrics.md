# Algorithmic Efficiency Comparison

Compiled with: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long

## Run 1
```
Naive algorithm result: 625025000
Naive algorithm time: 2.247366 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000123 seconds
```

## Run 2
```
```

## Run 3
```
```

## Run 4
```
```

## Averages and relative difference

- Naive average time: 0.000000 seconds
- Single-pass average time: 0.000000 seconds
- Single-pass time is too small to measure (0.000000 s), so the naive algorithm is orders of magnitude slower

## Analysis

The naive version uses nested loops, so it does about n(n+1)/2 checks (O(n^2)). The single-pass version checks each element once (O(n)). Less work means less CPU time, which is a proxy for lower energy use.
