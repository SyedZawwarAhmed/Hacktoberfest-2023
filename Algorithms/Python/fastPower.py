# returns base raised to power modulo mod -> int
def fast_power(base, power):
    result = 1
    while power > 0:
        if power % 2 == 1:
            result = (result * base) % mod
        power = power // 2
        base = (base * base) % mod
    return result
