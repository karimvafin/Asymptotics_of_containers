#include <iostream>
using namespace std;

template<typename T>
class subvector
{
private:
    T *mas;
    unsigned int top;
    unsigned int capacity;

public:
    subvector();

    ~subvector();
    bool resize(unsigned int new_capacity);
    bool push_back(T d);
    void set_top(int top);
    void clear();
    bool pop_back();
    void insert1(unsigned int k, T d);
    bool insert(unsigned int k, T d);
    bool erase(unsigned int k);
    void shrink_to_fit();
    void print();
    unsigned int get_top();
    unsigned int get_capacity();
    T& get_element(unsigned int k);
};

template<typename T>
subvector<T>::subvector()
{
    capacity = 0;
    top = 0;
    mas = nullptr;
}

template<typename T>
subvector<T>::~subvector()
{
    delete [] mas;
}

template<typename T>
unsigned int subvector<T>::get_top()
{
    if (mas == nullptr)
        cout << "NULL!!!!!!" << endl;
    return top;
}

template<typename T>
unsigned int subvector<T>::get_capacity()
{
    return capacity;
}

template<typename T>
bool subvector<T>::resize(unsigned int new_capacity)
{
    if (new_capacity > 0)
    {
        if (new_capacity >= this->capacity)
        {
            T *a = new T[new_capacity];
            for (int i = 0; i < this->top; i++)
                a[i] = (this->mas)[i];
            delete[] this->mas;
            this->mas = a;
            this->capacity = new_capacity;
            return true;
        }
        return true;
    }
    else
    {
        delete[] this->mas;
        this->mas = nullptr;
        return true;
    }
}

template<typename T>
bool subvector<T>::push_back(T d)
{
    if (this->capacity <= this->top)
        this->resize(this->capacity + 10000);
    mas[top] = d;
    top ++;
    return true;
}

template<typename T>
bool subvector<T>::erase(unsigned int k)
{
    if (mas == nullptr)
    {
        return false;
    }
    else
    {
        if (k == top - 1)
        {
            pop_back();
            return true;
        }
        else
        {
            if (k >= top)
                return false;
            T* new_mas = new T[capacity];
            for (unsigned int i = 0; i < k; i++)
                new_mas[i] = mas[i];
            for (unsigned int i = k; i < top; i++)
                new_mas[i] = mas[i+1];
            delete [] mas;
            mas = new_mas;
            top --;
            return true;
        }
    }
}

template<typename T>
bool subvector<T>::insert(unsigned int k, T d)
{
    if (mas == nullptr)
    {
        if (k == 0)
        {
            push_back(d);
            return true;
        }
        else
            return false;
    }
    else
    {
        if (k == top)
        {
            push_back(d);
            return true;
        }
        else
        {
            if (k > top)
                return false;
            if (top >= capacity)
                resize(capacity + 10000);
            T* new_mas = new T[capacity];
            for (unsigned int i = 0; i < k; i++)
                new_mas[i] = mas[i];
            new_mas[k] = d;
            for (unsigned int i = k + 1; i < top + 1; i++)
                new_mas[i] = mas[i-1];
            delete [] mas;
            mas = new_mas;
            top ++;
            return true;
        }
    }
}

template<typename T>
T& subvector<T>::get_element(unsigned int k)
{
    /*if (k >= top)
        return 0;
    else*/
    return mas[k];
}

template<typename T>
void subvector<T>::insert1(unsigned int place, T data)
{
    if ((place > top + 1) || (place <= 0)) return;
    if (this->top + 1 <= this->capacity)
    {
        for (int i = this->top; i > place; i--)
        {
            this->mas[i] = this->mas[i - 1];
        }
        this->mas[place - 1] = data;
        this->top++;
    }
    else
    {
        this->resize(2*this->capacity + 1);
        this->insert1(data, place);
    }
}


template<typename T>
void subvector<T>::clear()
{
    top = 0;
}

template<typename T>
bool subvector<T>::pop_back()
{
    if (top <= 0)
        return false;
    else
    {
        top --;
        return true;
    }
}

template<typename T>
void subvector<T>::set_top(int top)
{
    resize(top);
    this->top = top;
}

template<typename T>
void subvector<T>::shrink_to_fit()
{
    if (this->top == 0)
    {
        delete[] this->mas;
        this->mas = nullptr;
        this->capacity = 0;
        return;
    }
    if (this->top >= this->capacity)
        return;
    else
    {
        T *a = new T[this->top];
        for(int i = 0; i < this->top; i++)
            a[i] = (this->mas)[i];
        delete[] this->mas;
        this->mas = a;
        this->capacity = this->top;
    }
}

template<typename T>
void subvector<T>::print()
{
    for (int i = 0; i < this->top; i++)
        cout << this->mas[i] << " ";
    cout << endl;
}