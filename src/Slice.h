#ifndef SLICE_H
#define SLICE_H

//#include <atomic>
#include <stddef.h>

class Slice {
public:
    unsigned char* address;
    size_t len;


    Slice(unsigned char* address, size_t size);
    // 拷贝构造
    Slice(const Slice &slice);
    Slice& operator=(const Slice& slice); 
    // 移动构造
    Slice(Slice &&slice);
    Slice& operator=(Slice&& slice); 
    ~Slice(); 
    /*   */
    unsigned char at(size_t index);
    bool set(size_t index, unsigned char ch);
    Slice slice(size_t pso, size_t size);
    Slice slice(size_t pso);
};


#if 0
enum Vtable {
    Vtable_Static,
    Vtable_Share
};


class Buff{
public:
    unsigned char* address = nullptr;
    std::atomic<int> *use = nullptr;
    size_t size = 0;
    size_t read_index = 0;
    size_t write_index = 0;
    Vtable vtable = Vtable_Static;

public:
    Buff(Slice* slice );
    Buff(unsigned char* address, size_t size);
    Buff(size_t _size);
    Buff(const Buff &buff);
    Buff(Buff &&buff);
    ~Buff(); 

    /* 剩余空间大小 */
    size_t remaining( );
    /* 返回从当前位置开始的切片 */
    Slice* check();
    
    /* 返回原始数据 */
    unsigned char* data( );
    /* 读取有效门数据 */
    int read(Slice (&slice)[2]);
    /* 读标记前进 */
    void take(size_t len);
    void take(const Slice *ch);
    /* 返回u8 并前进前进 */
    unsigned char get_u8(); 
    /*   */
    unsigned char at(size_t index);
    /* 填写数据 */
    void put(unsigned char ch);
    /* 填写数据 */
    void put(const Slice *ch); 


    Buff& operator=(const Buff& ptr);   
};

class BuffMut : public Buff{

public:  
    using Buff::Buff;
    /*  */
    void put(unsigned char ch);
    /*  */
    void put(const Slice *ch); 
    /* 读取有效门数据 */
    Slice read();
};

#endif

#endif
