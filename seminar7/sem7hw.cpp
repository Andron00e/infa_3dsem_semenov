#include <bits/stdc++.h>
template <typename T> class Vector
{
	T* arr;
	int capacity;
	int Size;
public:
	Vector()
	{
		arr = new T[1];
		capacity = 1;
		Size = 0;
	}
	void PushBack(T data) //добавление в конец
	{

		if (Size == capacity){ //если нет места, увеличиваем
			T* temp = new T[2 * capacity];

			for (int i = 0; i < capacity; i++){
				temp[i] = arr[i];
			}
			delete[] arr;
			capacity *= 2;
			arr = temp;
		}
		arr[Size] = data;
		Size++;
	}

	void PushBack(int data, int id){
		if (id == capacity)
			PushBack(data);
		else
			arr[id] = data;
	}

	T Get(int id){

		if (id < Size)
			return arr[id];
	}

	void PopBack() { Size--; }

	int size() { return Size; }

	int Getcapacity() { return capacity; }

	void print(){
		for (int i = 0; i < Size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

 	/*Vector(const std::initializer_list<T> &list): capacity(2*list.size()), Size(list.size()) {
 	arr_ new T [capacity_];
 	int count = 0;
 	for (auto &element : list) {
        arr_[count] = element;
        ++count;
 	}
 	}
    */
    void Clear() { Size = 0; return capacity; }

    void Swap (Vector<T>& other) {
        Vector<T> temp = other;
        other = *this;
        *this = temp;
    }

    void Reserve (int n) {
        if (n > capacity) {
            Vector<T> temp = this;
            delete[] arr;
            capacity = n;
            arr = new T[capacity];
            for (int i = 0; i < Size; ++i){
                arr[i] = temp.arr[i];
            }
        }
    }

    //Vector operator+(Vector<T>)         //!!!!!!!!!!
};

/*template <class T>
class ShallowCopyVector : public Vector<T>
{
public:
using Vector<T>::Vector
private:
    int Size;
    int capacity;
    T* arr;
};

template <class T>
class DeepCopyVector : public Vector<T>
{
public:
using Vector<T>::Vector
private:
    int Size;
    int capacity;
    T* arr;
};

template <class T>
class COWVector : public Vector<T>
{
public:
using Vector<T>::Vector
private:
    int Size;
    int capacity;
    T* arr;
};
*/
int main()
{
	Vector<int> v;
	Vector<char> u; //заполним вектор не интами
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	u.PushBack(1);
	u.PushBack(2);
	u.PushBack(3);
	u.PushBack(4);

	std::cout << "Vector size : " << v.size() << std::endl;
	std::cout << "Vector capacity : " << v.Getcapacity() << std::endl;
	std::cout << "Vector elements : ";
	v.print();
	v.PushBack(100, 1);
    std::cout << std::endl;
	std::cout << "After updating first id" << std::endl;
	std::cout << "Vector elements of type int : " << std::endl;
	v.print();
	std::cout << "Vector elements of type char : " << std::endl;
	u.print();
	std::cout << "Element at first id of type int: " << v.Get(1)
		<< std::endl;
	std::cout << "Element at first id of type char: "
		<< u.Get(1) << std::endl;
	v.PopBack();
	u.PopBack();
    std::cout << std::endl;
	std::cout << "After deleting last element" << std::endl;
	std::cout << "Vector size of type int: " << v.size() << std::endl;
	std::cout << "Vector size of type char: " << u.size() << std::endl;
	std::cout << "Vector capacity of type int : " << v.Getcapacity() << std::endl;
	std::cout << "Vector capacity of type char : " << u.Getcapacity() << std::endl;
	std::cout << "Vector elements of type int: ";
	v.print();
	std::cout << "Vector elements of type char: ";
	u.print();

	return 0;
}
