/* *
 * balisyin 20190203
 * c++11 thread
 * compile:g++ thread.cpp -std=c++11 -pthread
 * */
#include<thread>
#include<iostream>
#include<array>
#include<mutex>
#include<chrono>
#include<atomic>
#include<cstdarg>

using namespace std;
const int N = 10000000;
//atomic_int num{0};
int num = 0;
mutex mt;
void show(){
    cout << "balis thread" << endl;

    return;
}

void num_plus(){
    for(int i = 0; i < N; ++i){
        mt.lock();
        ++num;
        mt.unlock();
    }
}

void show_va(const char* fun, ...){
    va_list ap;
    va_start(ap, fun);
    vprintf(fun, ap);
    va_end(ap);
    return;
}

int main(){
    thread th(show);
    th.join();
    //th.detach();
    cout << th.joinable() << endl;
    auto n = thread::hardware_concurrency();
    cout << "cup core num is " << n << endl;

    array<int, 3> arr = {1,2,3};
    for(auto& it : arr){
        cout << it;
    }
    cout << endl;

    auto begin = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
    thread th1(num_plus);
    th1.join();
    thread th2(num_plus);
    th2.join();

    auto end = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
    cout << "count " << num << " cost " << end - begin << " ms" << endl;

    ///lambda
    auto fun = [](const string str) { cout << str << endl; };
    fun("balis love lambda 1");
    fun("balis love lambda 2");
    thread th3([]() {
        auto begin = chrono::system_clock::now().time_since_epoch() / chrono::seconds(1);
        this_thread::sleep_for(chrono::seconds(1));
        this_thread::yield(); //let other thread use cpu
        auto end = chrono::system_clock::now().time_since_epoch() / chrono::seconds(1);

        cout << "this thread id is: 0x" << hex << this_thread::get_id() << endl;
        cout << "sleep " << end - begin << " s" << endl;

    });
    th3.join();

    thread th4(show_va, "alice wanna be %s%c%dpp%2.1f\n", "algo", 'r', 24, 0.9);
    th4.detach();
    this_thread::sleep_for(chrono::seconds(1));
    this_thread::yield();
    cout << "main thread id is: 0x" << hex << this_thread::get_id() << endl;
   return 0;
}
