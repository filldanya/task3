#include <iostream>
class Smart_array
{
private:
    int* _arr;
    int _size = 0;
    int _index = 0;
public:
    Smart_array(int size) : _size(size)
    {
        _arr = new int[size];
    }
    ~Smart_array()
    {
        delete[] _arr;
    }
    void add_element(int number)
    {
        if (_index > _size)
        {
            throw "out of range!";
        }
        _arr[_index] = number;
        ++_index;
    }
    int get_element(int index)
    {
        if (index < 0 && index > _index)
        {
            throw "invalid index!";
        }
        return _arr[index];
    }
    int get_size()
    {
        return _size;
    }
    Smart_array& operator=(const Smart_array& arr)
    {
        if (this == &arr)
        {
            return  *this;
        }
        if (arr._size > _size)
        {
            delete[] _arr;
            _arr = new int[arr._size];
        }
        for (int i = 0; i < arr._size; i++)
        {
            _arr[i] = arr._index;
        }
        return *this;
    }
    Smart_array(const Smart_array& c)
    {
        _arr = new int[c._size];
        for (int i = 0; i < c._size; i++)
        {
            _arr[i] = c._index;
        }
    }
};

int main()
{
    try {
        Smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        Smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}