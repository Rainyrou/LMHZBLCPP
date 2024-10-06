#pragma once

#include <iostream>
#include <vector>
#include <string>

class Buffer
{
  public:
    Buffer();
    friend Buffer &operator<<(Buffer &curr, const std::string &str);
    void goToLine(int);
    int getCurrLine() const;
    void disp();
    void clear();

  private:
    int line;
    std::vector<std::string> buf;
    int size;

} writeBuf;

Buffer::Buffer()
{
    buf.emplace_back("");
    line = 0;
    size = 1;
}

Buffer &operator<<(Buffer &curr, const std::string &str)
{
    if (str == "\n")
    {
        if (curr.line == curr.size - 1)
        {
            curr.buf.emplace_back("");
            ++curr.line;
            ++curr.size;
        }
        else
        {
            ++curr.line;
        }
    }
    else
        curr.buf[curr.line] += str;
    
    return curr;
}

void Buffer::goToLine(int n)
{
    if (n > size)
        return;
    else
        line = n;
}

int Buffer::getCurrLine() const
{
    return line;
}
void Buffer::disp()
{
    goToLine(0);
    for (const auto& str : buf)
        std::cout << str << std::endl;
}

void Buffer::clear()
{
    std::vector<std::string> t(size, "");
    buf = t;
}