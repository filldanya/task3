#include <iostream>

class bad_element : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad element Arguments!";
    }
};
class bad_range : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad range Arguments!";
    }
};

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
            throw bad_range();
        }
        _arr[_index] = number;
        ++_index;
    }
    int get_element(int index)
    {
        if (index < 0 || index >(_index - 1))
        {
            throw bad_element();
        }
        return _arr[index];
    }
    int get_size()
    {
        return _size;
    }
    void erase()
    {
        delete[] _arr;

        _arr = nullptr;
        _size = 0;
        _index = 0;
    }
    void reallocate(int newLength, int newIndex)
    {
        erase();
        if (newLength <= 0)
            return;
        _arr = new int[newLength];
        _size = newLength;
        _index = newIndex;
    }
    Smart_array& operator=(const Smart_array& arr)
    {
        if (this == &arr)
        {
            return *this;
        }
        reallocate(arr._size, arr._index);
        if (arr._size > _size)
        {
            delete[] _arr;
            _arr = new int[arr._size];
        }
        for (int i = 0; i < arr._size; i++)
        {
            _arr[i] = arr._arr[i];
        }
        return *this;
    }
    Smart_array(const Smart_array& c)
    {
        reallocate(c._size, c._index);
        _arr = new int[c._size];
        for (int i = 0; i < _size; i++)
        {
            _arr[i] = c._arr[i];
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

        Smart_array new_array = arr;

        std::cout << new_array.get_element(0) << std::endl;
        std::cout << new_array.get_element(1) << std::endl;
        std::cout << new_array.get_element(2) << std::endl;
    }
    catch (bad_element& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (bad_range& ex) {
        std::cout << ex.what() << std::endl;

    }
}