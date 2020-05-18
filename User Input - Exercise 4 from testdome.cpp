#include <iostream>
#include <string>

class TextInput
{
public:

    virtual ~TextInput() {}

    virtual void add(char c) { data += c; }

    std::string getValue() { return data; }

private:

    std::string data;
};

class NumericInput : public TextInput
{
    void add(char c)
    {
        if (('0' <= 'c') && (c <= '9'))
            TextInput::add(c);
    }
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('8');
    input->add('y');
    input->add('9');
    std::cout << input->getValue();

}
#endif