#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include "windows.h"

class threadSafeQ
{
    std::queue<int> rawQ;
    std::mutex m;
public:
    int retrieveAndDelete()
    {
        int front_value = 0;
        m.lock();
        if (!rawQ.empty())
        {
            front_value = rawQ.front();
            rawQ.pop();
        }
        m.unlock();
        return front_value;
    }

    void push(int val, int val2, int val3)
    {
        m.lock();
        rawQ.push(val);
        m.unlock();
        m.lock();
        rawQ.push(val2);
        m.unlock();
        m.lock();
        rawQ.push(val3);
        m.unlock();

    }

    void Print()
    {
        m.lock();
        while (!rawQ.empty())
        {
            std::cout << rawQ.front() << " ";
            rawQ.pop();
        }
        m.unlock();
    }

};




int main()
{
    threadSafeQ q;
    std::thread pushThread(&threadSafeQ::push, &q, 5, 6, 10);
    std::thread popThread(&threadSafeQ::retrieveAndDelete, &q);

    if (pushThread.joinable())
    {
        pushThread.join();
    }
    if (popThread.joinable())
    {
        popThread.join();
    }
    q.Print();




    return 0;
}