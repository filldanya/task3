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
    Smart_array(const Smart_array&) = delete;
    Smart_array& operator=(const Smart_array&) = delete;
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
};

int main()
{
    try {
        Smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        std::cout << arr.get_element(5) << std::endl;
    }
    catch (bad_element& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (bad_range& ex) {
        std::cout << ex.what() << std::endl;

    }
}