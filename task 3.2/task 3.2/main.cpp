#include <iostream>
class Smart_array
{
private:
    int* _arr;
    int _size = 0;
    int index = 0;
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
        if (index > _size)
        {
            throw "out of range!";
        }
        _arr[index] = number;
        ++index;
    }
    int get_element(int index)
    {
        if (index < 0 && index > _size)
        {
            throw "invalid index!";
        }
        return _arr[index];
    }
    int get_size()
    {
        return _size;
    }
    Smart_array& operator = (Smart_array& arr)
    {
        for (int i = 0; i < arr.get_size(); i++)
        {
            _arr[i] = arr.get_element(i);
        }
        return arr;
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


