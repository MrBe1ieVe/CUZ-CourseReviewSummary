# !/usr/bin/env python3
# conding=utf-8

def tiny_map(idx, val):
    return list(map(lambda i: [int(i), 0], val.split("\n")))


def tiny_reduce_max(val):
    num_max = val[0][0]

    for [k, v] in val:
        if num_max < k:
            num_max = k

    return num_max


def tiny_reduce_aver(val):
    num_sum = 0

    for [k, v] in val:
        num_sum += k

    return num_sum / len(val)


def tiny_reduce_freq(val):
    res_dict = dict()

    for [k, v] in val:
        tmp = res_dict.get(k)
        if tmp == None:
            res_dict[k] = 1
        else:
            res_dict[k] = tmp + 1

    return res_dict


if __name__ == "__main__":
    # input a large file
    raw_data = """158
22
87
517
35
25
19
514
34
14
311
38
19
929
799
299
999
99
14
85
11
54
14
82
17
587"""

    # process raw data
    number_list = tiny_map(0, raw_data)

    print("最大值为：", tiny_reduce_max(number_list))

    print("所有整数平均值：", tiny_reduce_aver(number_list))

    print("各个整数出现次数：", tiny_reduce_freq(number_list))
