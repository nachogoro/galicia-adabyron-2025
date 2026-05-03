import sys
from fractions import Fraction


def main():
    data = sys.stdin.buffer.read().split()
    i = 0
    C = int(data[i]); i += 1
    out = []
    for _ in range(C):
        N = int(data[i]); i += 1
        T = int(data[i]); i += 1
        t = list(map(int, data[i:i+N])); i += N
        p = list(map(int, data[i:i+N])); i += N

        # Densidad popularidad / tiempo de mayor a menor.
        # Fraction permite ordenar exactamente sin riesgo de ties por redondeo.
        order = sorted(range(N), key=lambda j: Fraction(p[j], t[j]), reverse=True)

        remaining = T
        total = Fraction(0)
        for j in order:
            if remaining == 0:
                break
            take = min(t[j], remaining)
            total += Fraction(p[j] * take, t[j])
            remaining -= take

        # Convertir el racional exacto a 4 decimales redondeando.
        scaled = round(total * 10000)
        out.append(f"{scaled // 10000}.{scaled % 10000:04d}")

    sys.stdout.write("\n".join(out) + "\n")


main()
