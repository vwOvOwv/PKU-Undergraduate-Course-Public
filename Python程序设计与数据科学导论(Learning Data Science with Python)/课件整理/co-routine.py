import asyncio
import datetime
import time

# 定义四个函数，它们将被作为事件循环中的回调函数

def function_1(end_time, loop):
    print('function_1 called')
    if (loop.time() + 1.0) < end_time:
        loop.call_later(1, function_2, end_time, loop) # 睡眠1s后再调用function_2
    else:
        loop.stop()

def function_2(end_time, loop):
    print('function_2 called')
    if (loop.time() + 1.0) < end_time:
        loop.call_later(1, function_3, end_time, loop)
    else:
        loop.stop()

def function_3(end_time, loop):
    print('function_3 called')
    if (loop.time() + 1.0) < end_time:
        loop.call_later(1, function_1, end_time, loop)
    else:
        loop.stop()

def function_4(end_time, loop):
    print('function_4 called')
    if (loop.time() + 1.0) < end_time:
        loop.call_later(1, function_1, end_time, loop) # 睡眠1s后再调用function_1
    else:
        loop.stop()

# 获取当前事件循环
loop = asyncio.get_event_loop()

# 定义结束时间为当前时间加上9秒
end_time = loop.time() + 9.0

# 在事件循环中注册function_4函数作为初始调用
loop.call_soon(function_4, end_time, loop) # 尽快执行

# 运行事件循环，直到stop()被调用
loop.run_forever()

# 关闭事件循环
loop.close()
