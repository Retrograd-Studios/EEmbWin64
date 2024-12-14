
#include <stdio.h>

#include <string>
#include <iostream>


#include "win_forms.h"


void* exported_sym[] = {
    EEmbCreateWindow
};


extern "C" {
    void __entryPoint__(void);
} 

void foo() 
{
    std::cerr << "Print from EEmbWramework 2\n";
}





#include <exception>
#include <stdlib.h>
#include <stdexcept>




extern "C" void* EEmb_MemAlloc(uint32_t size)
{
    return malloc(size);
}



extern "C" void EEmb_MemFree(void* ptr)
{
    free(ptr);
}



extern "C" uint32_t MemGetFreeHeapSize()
{
    return 0xFFFFFFFF;
}

extern "C" uint32_t MemGetMinimumEverFreeHeapSize()
{
    return 0;
}


extern "C" uint32_t uxTaskGetStackHighWaterMark(void * p)
{
    return 0;
}


extern "C" void EEmb_Panic(const char* where, const char* message)
{
    std::cerr << where << "\n" << message << "\n";
    const auto err = std::string(where) + "\n" + message;
    throw std::runtime_error(err);
}

extern "C" uint32_t EEmb_GetStringSize(const char *str)
{
    uint32_t size = 0;
    while (*str != '\0')
    {
        ++size;
        ++str;
    }
    ++size;
    return size;
}

extern "C" uint32_t EEmb_IntToString(char *buf, int32_t val)
{
    const uint32_t result = sprintf(buf, "%d", val)+1;
    return result;
}

extern "C" uint32_t EEmb_FpToString(char *buf, float val)
{
    return sprintf(buf, "%f", val)+1;
}



extern "C" void Print(const char* str)
{
    std::cerr << str;
}

extern "C" void Println(const char* str)
{
    std::cerr << str << "\n";
}




int main(int argc, char** argv)
{
    std::cerr << "Print from EEmbWramework\n";
    __entryPoint__();
    return 0;
}
