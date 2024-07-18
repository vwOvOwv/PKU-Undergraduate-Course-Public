print("%%开头的magic的作用区域延续到整个cell")

a = [3, 'aa', 34.4] * 4 # 复制对象
print(a)
a[1] = 'bb'
print(a)

b = [{'k1': 1.5}] * 4 # 复制引用，指向同一个对象
print(b)
b[0]['k1'] = 10
print(b)
