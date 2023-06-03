# Считываем данные из конфига
with open("./scripts/cfg.txt", "r") as f:
    line = f.readline()
    i = 0
    while (len(line) != 0):
        line = line.strip()
        if (i == 0):
            options = list(line.split())
        elif (i == 1):
            sort_types = list(line.split())
        elif (i == 3):
            tests = int(line)
        elif (i == 4):
            sizes = list(line.split())
        line = f.readline()
        i += 1

# Обрабатываем данные
def analyze(time):
    # time.sort()
    avg = sum(time) // len(time)
    minimum = min(time)
    low_quartile = time[len(time)//4]
    median = time[len(time)//2]
    high_quartile = time[len(time)//4*3]
    maximum = max(time)
    return str(avg), str(minimum), str(low_quartile), str(median), str(high_quartile), str(maximum)


# Считываем и обрабатываем данные из датасета
for opt in options:
    for sort_type in sort_types:
        for size in sizes:
            time = [0]*tests
            with open(f"./dataset/{opt}_s{sort_type}_n{size}.txt", "r") as fin:
                for i in range(tests):
                    time[i] = int(fin.readline().strip())
            time.sort()
            data = list(analyze(time))
            with open(f"./graph/{opt}_s{sort_type}.txt", 'a') as fout:
                for t in time:
                    fout.write(str(str(t) + " " + " ".join(data) + " " + str(size) + "\n"))               
