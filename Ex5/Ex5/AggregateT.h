#pragma once
#include <iostream>
template <typename T>
class AggregateT {
public:
    T m_object;
    AggregateT(T m_object) : m_object(m_object)
    {
        std::cout << "aggregateT created" << std::endl;
    }

    ~AggregateT() {
        std::cout << "aggregateT deleted" << std::endl;
    }
};

