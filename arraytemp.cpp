#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class Animal {					// The Animal class is considered "abstract" or
public:						// a pure virtual method due to the "= 0"
    virtual string speak() const = 0;		// meaning there is no implementation
};

class Cat : public Animal {			// Both classes, Cat and Dog are both subclasses
public: 					// of Animal, where there are implementations
        virtual string speak() const;		// of the function "speak()" which is inheritted
};						// from the Animal parent class

class Dog : public Animal {
public: 
        virtual string speak() const;
};

template <class T>				// The line with template <class T> in it 
class Array {
public:
	Array(int size);
	~Array();
	T & operator[](int i) const;
	int size() const;
	void fill(T k);
	T * begin() {
		return data;
	};
	T * end() {
		return (data + len);
	};
private:
	int len;
	T * data;
};

string Cat::speak() const {
	return "Meow";
};

string Dog::speak() const {
	return "Woof";
};

template <class T>
Array<T>::Array(int size) {
	len = size;
	data = new T[len];
};

template <class T>
Array<T>::~Array() {
	delete [] data;
};

template <class T>
T & Array<T>::operator[](int i) const {
	return data[i];
};

template <class T>
int Array<T>::size() const {
	return len;
};

template <class T>
void Array<T>::fill(T k) {
	for(int i = 0; i < len; i++) {
		data[i] = k;
	}
};

int main(int argc, char * args[]) {
	Array<Animal*> s(2);

	assert(s.size() == 2);

	s[0] = new Cat();
	s[1] = new Dog();
	assert(s[0] -> speak() == "Meow");
	assert(s[1] -> speak() == "Woof");

	s.fill(new Cat());
	assert(s[0] -> speak() == "Meow");
	assert(s[1] -> speak() == "Meow");

	s.fill(new Dog());
	assert(s[0] -> speak() == "Woof");
	assert(s[1] -> speak() == "Woof");

	cout << "All tests passed." << endl;
}
