from multiprocessing import Process, Manager

# 定义一个函数，它接收一个字典和一个列表，并修改它们
def modify_shared_objects(shared_dict, shared_list):
    shared_dict[1] = '一'
    shared_dict['二'] = 2
    shared_dict[0.25] = None
    shared_list.reverse()

if __name__ == '__main__':
    __spec__ = None
    # 使用Manager创建共享的数据结构
    with Manager() as manager: # 类似上下文管理器，自动对共享数据结构加/解锁
        shared_dict = manager.dict()
        shared_list = manager.list(range(10))

        # 创建并启动一个进程
        p = Process(target=modify_shared_objects, args=(shared_dict, shared_list))
        p.start()
        p.join()

        # 打印修改后的共享字典和列表
        print(shared_dict)
        print(shared_list)
