#pragma once

template<class T>
class SmartPtr
{
public:
    SmartPtr(T* p = nullptr) : ptr(p)
    {
    }

    ~SmartPtr()
    {
        delete ptr;
    }

    SmartPtr(SmartPtr& p)
    {
        ptr = p.ptr;
        p.ptr = nullptr;
    }

    SmartPtr& operator=(SmartPtr& p)
    {
        if (&p == this)
            return *this;

        delete ptr;
        ptr = p.ptr;
        p.ptr = nullptr;

        return *this;
    }

    T* operator->() const { return ptr; }
    T& operator* () const { return *ptr; }
    const T* Get() const { return ptr; }

private:
    T* ptr{nullptr};
};
