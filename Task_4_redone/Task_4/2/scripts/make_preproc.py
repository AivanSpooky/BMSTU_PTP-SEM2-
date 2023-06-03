from math import log
# Считываем данные из конфига
with open("./scripts/cfg.txt", "r") as f:
    line = f.readline()
    i = 0
    while (len(line) != 0):
        line = line.strip()
        if (i == 0):
            options = list(line.split())
        elif (i == 1):
            tests = int(line)
        elif (i == 2):
            sort_types = list(line.split())
        elif (i == 4):
            arr_types = list(line.split())
        elif (i == 5):
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
    # Табличные данные
    
    return str(avg), str(minimum), str(low_quartile), str(median), str(high_quartile), str(maximum)

def extra(time):
    avg = sum(time) // len(time)
    s_sq = 1 / (tests - 1) * sum([(i - avg)**2 for i in time])
    stdErr = (s_sq**0.5) / (tests**0.5)
    try:
        rse = round((stdErr / avg * 100), 6) # t_i округлено до 6 знаков
    except ZeroDivisionError:
        rse = -1
    return rse

# Считываем и обрабатываем данные из датасета
for opt in options:
    for sort_type in sort_types:
        for arr_type in arr_types:
            entered = False
            tmp_extr = ""
            tmp_size = 0
            for size in sizes:
                with open(f"./dataset/{opt}_s{sort_type}_a{arr_type}_n{size}.txt", "r") as fin:
                    tests = sum(1 for line in fin)
                time = [0]*tests
                with open(f"./dataset/{opt}_s{sort_type}_a{arr_type}_n{size}.txt", "r") as fin:
                    for i in range(tests): 
                        time[i] = int(fin.readline().strip())
                time.sort()
                data = list(analyze(time))
                extr = extra(time)
                if (extr > 5):
                    print(f"For ./dataset/{opt}_s{sort_type}_a{arr_type}_n{size}.txt - rse > 5%")
                if (entered):
                    try:
                        f.write(str(str(tmp_extr) + " " + str(round((log(extr)-log(tmp_extr)) / (log(size)-log(tmp_size)), 6)) + "\n"))
                    except Exception:
                        f.write(str(str(tmp_extr) + " " + "-2" + "\n"))
                    f.close()
                with open(f"./graph/{opt}_s{sort_type}_a{arr_type}.txt", 'a') as fout:
                    for ind, t in enumerate(time):
                        fout.write(str(str(t) + " " + " ".join(data) + " " + str(size) + "\n"))
                f = open(f"./graph/{opt}_s{sort_type}_a{arr_type}_e.bu", 'a')
                entered = True
                tmp_extr = extr
                tmp_size = size
f.close()
