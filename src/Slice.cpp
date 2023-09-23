#include "Slice.h"
#include <iostream>

Slice::Slice(unsigned char *address, size_t size)
{
    //printf("Slice 构造\n");
    this->address = address;
    this->len     = size;
}
// 拷贝构造
Slice::Slice(const Slice &slice)
{
    //printf("Slice1 拷贝构造\n");
    this->address = slice.address;
    this->len     = slice.len;
}
// 移动构造
Slice::Slice(Slice &&slice)
{
    //printf("Slice1 移动构造\n");
    this->address = slice.address;
    this->len     = slice.len;
}

Slice& Slice::operator= (const Slice &slice)
{
    //printf("Slice1 赋值运算符\n");
    this->address = slice.address;
    this->len     = slice.len;

    return *this;
}

// 移动赋值运算符
// 和复制赋值运算符的区别在于，其参数是右值引用
Slice& Slice::operator= (Slice &&slice)
{
    //printf("Slice1 移动赋值运算符\n");
    this->address = slice.address;
    this->len     = slice.len;

    return *this;
}
Slice::~Slice()
{
}
/*   */
unsigned char Slice::at(size_t index)
{
    return *(this->address + index);
}

/*   */
bool Slice::set(size_t index, unsigned char ch)
{
    if( index <= this->len )
    {
        *( this->address + index) = ch;
        return true;
    }

    return false;
}

Slice Slice::slice(size_t pso, size_t size)
{
    return Slice(this->address + pso, size);
}

Slice Slice::slice(size_t pso )
{
    return Slice(this->address + pso, this->len - pso);
}