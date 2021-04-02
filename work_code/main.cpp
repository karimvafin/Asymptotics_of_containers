#include "subvectorTemplate.cpp"
#include "subforwardlistTemplate.cpp"
#include <string>
#include <fstream>
#include <vector>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <ctime>

template<typename T>
void write_to_file(T data, string filename)
{
    std::ofstream out; // поток для записи

    out.open(filename, std::ios::app);
    if (out.is_open())
        out << data << endl;
    out.close();
    // cout << "Recording: " << data << endl;
}

template<typename T>
void write_to_file2(T data)
{
    std::ofstream out; // поток для записи

    out.open("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test2.txt", std::ios::app);
    if (out.is_open())
        out << data << endl;
    out.close();
    // cout << "Recording: " << data << endl;
}

void clean_file(string filename)
{
    std::ofstream out; // поток для записи
    out.open(filename);
    if (out.is_open())
        out << "" << endl;
    out.close();
}

void test1()
{
    subvector<int> vec;
    clean_file("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test1.txt");
    clean_file("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test2.txt");
    for (int i = 0; i < 100000; i++)
    {
        vec.push_back(i);
        //write_to_file(to_string(i) + " " + to_string(vec.get_capacity()));
        write_to_file2(to_string(i) + " " + to_string(vec.get_top()));
    }
}

void test2()
{
    vector<int> vec;
    clean_file("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test1.txt");
    clean_file("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test2.txt");
    for (int i = 0; i < 100000; i++)
    {
        vec.push_back(i);
        //write_to_file(to_string(i) + " " + to_string(vec.capacity()));
        write_to_file2(to_string(i) + " " + to_string(vec.size()));
    }
}

double test3_1(int size)
{
    vector<int> vec(size);
    double n = 0;
    double k = 0;
    int num;
    int start1 = clock();
    for (int i = 0; i < 10000; i++)
    {
        auto it = vec.begin();
        num = rand()%(size + 1);
        vec.insert(it + num, 2);
        vec.pop_back();
        n += 1.0;
    }
    int end1 = clock();
    vec.resize(size);
    int start2 = clock();
    for (int i = 0; i < 10000; i++)
    {
        auto it = vec.begin();
        num = rand()%(size + 1);
        vec.pop_back();
        k += 1.0;
    }
    int end2 = clock();
    double time = (end1 - start1) - (end2 - start2);
    time = time / n;
    //cout << time << endl;
    return time;
}

double test3_2(int size)
{
    //cout << "test2" << endl;
    subvector<int> vec;
    vec.set_top(size);
    double n = 0;
    double k = 0;
    int num;
    int start1 = clock();
    for (int i = 0; i < 1000; i++)
    {
        num = rand()%(size + 1);
        vec.insert(num, 2);
        vec.pop_back();
        n += 1.0;
    }
    int end1 = clock();
    vec.resize(size);
    int start2 = clock();
    for (int i = 0; i < 1000; i++)
    {
        num = rand()%(size + 1);
        vec.pop_back();
        k += 1.0;
    }
    int end2 = clock();
    double time = (end1 - start1) - (end2 - start2);
    time = time / n;
    return time;
}

double test_5_2(int size)
{
    subvector<int> vec;
    vec.set_top(size);
    double n = 0;
    double k = 0;
    int num;
    int start1 = clock();
    for (int i = 0; i < 100000; i++)
    {
        num = rand()%(size);
        int& elem = vec.get_element(num);
        n += 1.0;
    }
    int end1 = clock();
    int start2 = clock();
    for (int i = 0; i < 100000; i++)
    {
        num = rand()%(size + 1);
        k += 1;
    }
    int end2 = clock();
    double time = (end1 - start1) - (end2 - start2);
    time = time / n;
    return time;
}

double test_5_1(int size)
{
    vector<int> vec;
    vec.resize(size);
    double n = 0;
    double k = 0;
    int num;
    int elem;
    int start1 = clock();
    for (int i = 0; i < 100000; i++)
    {
        num = rand()%(size);
        elem = vec[num];
        n += 1.0;
    }
    int end1 = clock();
    int start2 = clock();
    for (int i = 0; i < 100000; i++)
    {
        num = rand()%(size + 1);
        k += 1;
    }
    int end2 = clock();
    double time = (end1 - start1) - (end2 - start2);
    time = time / n;
    return time;
}


double test_6_1(int size)
{
    forward_list<int> list;
    list.resize(size, 10);
    double n = 0;
    double k = 0;
    int start1 = clock();
    for (int i = 0; i < 100; i++)
    {
        list.push_front(10);
        list.pop_front();
        n ++;
    }
    int end1 = clock();
    list.resize(100);
    int start2 = clock();
    for (int i = 0; i < 100; i++)
    {
        list.pop_front();
        k ++;
    }
    int end2 = clock();
    double time = (end1 - start1) - (end2 - start2);
    time = time / n;
    return time;
}

double test_6_2(int size)
{
    subclass<int> list;
    for (int i = 0; i < size; i++)
        list.push_back(10);
    double n = 0;
    double k = 0;
    int start1 = clock();
    for (int i = 0; i < 100; i++)
    {
        list.push_forward(10);
        list.pop_forward();
        n ++;
    }
    int end1 = clock();
    int start2 = clock();
    for (int i = 0; i < 100; i++)
    {
        list.pop_forward();
        k ++;
    }
    int end2 = clock();
    double time = (end1 - start1) - (end2 - start2);
    time = time / n;
    return time;
}

double test_7_1(int size)
{
    forward_list<int> list;
    list.resize(size, 10);
    double n = 0;
    double k = 0;
    int start1 = clock();
    for (int i = 0; i < 100; i++)
    {
        list.push_front(10);
        list.pop_front();
        n ++;
    }
    int end1 = clock();
    list.resize(100);
    int start2 = clock();
    for (int i = 0; i < 100; i++)
    {
        list.push_front(2);
        k ++;
    }
    int end2 = clock();
    double time = (end1 - start1) - (end2 - start2);
    time = time / n;
    return time;
}

double test_7_2(int size)
{
    subclass<int> list;
    for (int i = 0; i < size; i++)
        list.push_back(10);
    double n = 0;
    double k = 0;
    int start1 = clock();
    for (int i = 0; i < 100; i++)
    {
        list.push_forward(10);
        list.pop_forward();
        n ++;
    }
    int end1 = clock();
    int start2 = clock();
    for (int i = 0; i < 100; i++)
    {
        list.push_forward(2);
        k ++;
    }
    int end2 = clock();
    double time = (end1 - start1) - (end2 - start2);
    time = time / n;
    return time;
}

double test_8_vector(int size)
{
    vector<int> vec;
    vec.resize(size);
    int start = clock();
    for (auto i = vec.begin(); i != vec.end(); i++)
        *i ++;
    int end = clock();
    double time = (end - start);
    return time;
}

double test_8_forward_list(int size)
{
    forward_list<int> l;
    l.resize(size);
    int start = clock();
    for (auto i = l.begin(); i != l.end(); i++)
        *i ++;
    int end = clock();
    double time = (end - start);
    return time;
}

double test_8_list(int size)
{
    list<int> l;
    l.resize(size);
    int start = clock();
    for (auto i = l.begin(); i != l.end(); i++)
        *i ++;
    int end = clock();
    double time = (end - start);
    return time;
}

double test_8_map(int size)
{
    int num;
    map<int, int> l;
    for (int i = 0; i < size; i ++)
    {
        num = rand()%(size);
        l[num] = i;
    }
    int start = clock();
    for (auto i = l.begin(); i != l.end(); i++)
        i->second ++;
    int end = clock();
    double time = (end - start);
    return time;
}

double test_8_set(int size)
{
    int num;
    int value;
    set<int> l;
    for (int i = 0; i < size; i ++)
    {
        num = rand()%(size);
        l.insert(num);
    }
    int start = clock();
    for (auto i = l.begin(); i != l.end(); i++)
        value = *i ;
    int end = clock();
    double time = (end - start);
    return time;
}

int main()
{
    srand(time(NULL));
    clean_file("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test1.txt");
    clean_file("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test2.txt");
    /*clean_file("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test3.txt");
    clean_file("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test4.txt");
    clean_file("/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test5.txt");*/
    string data1 = "";
    string data2 = "";
    for (int j = 1000; j < 50000000; j += 1000)
    {
        cout << j << endl;
        //double time1 = test_5_1(j);
        double time2 = test_5_2(j);
        //double time3 = test_8_list(j);
        //double time4 = test_8_map(j);
        //double time5 = test_8_set(j);
        //data1 += to_string(j) + " " + to_string(time1) + "\n";
        data2 += to_string(j) + " " + to_string(time2) + "\n";
        /* write_to_file(to_string(j) + " " + to_string(time3), "/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test3.txt");
        write_to_file(to_string(j) + " " + to_string(time4), "/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test4.txt");
        write_to_file(to_string(j) + " " + to_string(time5), "/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test5.txt");
        write_to_file2(to_string(j) + " " + to_string(time2));*/
    }
    write_to_file(data1, "/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test1.txt");
    write_to_file(data2, "/Users/karimvafin/Documents/Repositories/MIPT/Subcontainers_asymptotics/work_code/test2.txt");
    //cout << data1 << endl;
    return 0;
}
