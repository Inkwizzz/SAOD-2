#include <chrono>
#include <iostream>

using namespace std;

long fibonacci(unsigned n) {
    return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

template <typename T>
class Timer {
public:
    static void reset();
    static T elapsed_nanoseconds();
    static T elapsed_microseconds();
    static T elapsed_milliseconds();
    static T elapsed_seconds();
    static T elapsed_minutes();
private:
    typedef std::chrono::high_resolution_clock clock_;
    static std::chrono::time_point<std::chrono::high_resolution_clock> beg_;
};

template <typename T>
void Timer<T>::reset() {
    beg_ = clock_::now();
}

template <typename T>
T Timer<T>::elapsed_nanoseconds() {
    return std::chrono::duration_cast<std::chrono::duration<T, std::nano>>(clock_::now() - beg_).count();
}

template <typename T>
T Timer<T>::elapsed_microseconds() {
    return std::chrono::duration_cast<std::chrono::duration<T, std::micro>>(clock_::now() - beg_).count();
}

template <typename T>
T Timer<T>::elapsed_milliseconds() {
    return std::chrono::duration_cast<std::chrono::duration<T, std::milli>>(clock_::now() - beg_).count();
}

template <typename T>
T Timer<T>::elapsed_seconds() {
    return std::chrono::duration_cast<std::chrono::duration<T, std::ratio<1>>>(clock_::now() - beg_).count();
}

template <typename T>
T Timer<T>::elapsed_minutes() {
    return std::chrono::duration_cast<std::chrono::duration<T, std::ratio<60>>>(clock_::now() - beg_).count();
}

template<typename T>
std::chrono::time_point<std::chrono::high_resolution_clock> Timer<T>::beg_ = std::chrono::high_resolution_clock::now();

int main() {
    Timer<double>::reset();
    std::cout << "f(42) = " << fibonacci(42) << '\n';
    std::cout << "Elapsed time in minutes: " << Timer<double>::elapsed_minutes() << std::endl;
    std::cout << "Elapsed time in seconds: " << Timer<double>::elapsed_seconds() << std::endl;
    std::cout << "Elapsed time in milliseconds: " << Timer<double>::elapsed_milliseconds() << std::endl;
    std::cout << "Elapsed time in microseconds: " << Timer<double>::elapsed_microseconds() << std::endl;
    std::cout << "Elapsed time in nanoseconds: " << Timer<double>::elapsed_nanoseconds() << std::endl;
    
    return 0;
}

