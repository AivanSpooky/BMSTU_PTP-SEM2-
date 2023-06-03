# Считываем данные из конфига
with open("./cfg.txt", "r") as f:
    line = f.readline()
    i = 0
    while (len(line) != 0):
        line = line.strip()
        if (i == 0):
            options = list(line.split())
        elif (i == 1):
            tests = int(line)
        line = f.readline()
        i += 1

# Игорь Владимирович!
'''
Если вы это читаете, то хочу сказать, что данная функция возвращает
только значение rse. Величины, которые зависят от rse считаются вручную.
'''
# Обрабатываем данные
def analyze(time):
    global tests
    # time.sort()
    avg = sum(time) / tests
    s_sq = 1 / (tests - 1) * sum([(i - avg)**2 for i in time])
    stdErr = (s_sq**0.5) / (tests**0.5)
    try:
        rse = (stdErr / avg * 100)
    except Exception:
        rse = -1 
    return str(avg), str(rse)

# Считываем и обрабатываем данные из датасета
for opt in options:
    time = [0]*tests
    for test in range(tests):
        with open(f"./dataset/t_{opt}_{test+1}.txt", "r") as fin:
            time[test] = float(fin.readline().strip())
    data = list(analyze(time))
    with open(f"./graph/t_{opt}.txt", 'w') as fout:
        fout.write(str(" ".join(data)) + "\n")
