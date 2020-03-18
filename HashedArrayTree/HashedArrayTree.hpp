

template<typename T>
class HashedArrayTree
{
private:
	T** top;
	
	size_t nowPower;
	size_t nowSize;
	
	size_t leafIndex(size_t index);
	size_t topIndex(size_t index);
	
public:
	HashedArrayTree();
	
	void resize(size_t size);
	T& operator[](const size_t& index);
	
	~HashedArrayTree();
}

template<typename T>
HashedArrayTree<T>::HashedArrayTree()
{
	nowPower = 1;
	nowSize = std::pow(2, power);
	
	top = new T*[nowSize];
	
	for (size_t i = 0; i < nowSize; ++i)
		top[i] = nullptr;
}

template<typename T>
size_t HashedArrayTree<T>::leafIndex(size_t index)
{
	return index & ((1 << power) - 1);
}

template<typename T>
size_t HashedArrayTree<T>::topIndex(size_t index)
{
	return index >> power;
}

template<typename T>
T& HashedArrayTree<T>::operator[](size_t index)
{
	size_t tid = topIndex(index);
	size_t lid = leafIndex(index);
	
	if (top[tid] == nullptr)
		top[tid] = new T[nowSize];
		
	return top[tid][lid];
}

template<typename T>
void HashedArrayTree<T>::resize(size_t size)
{
	size_t newSize 	= nowSize;
	
	while (size > newSize) {
		newSize *= 2;
		++nowPower;
	}
	
	T** tmpTop = new T*[newSize];
	
	size_t tid = 0;
	while (top[tid++] != nullptr) {
		tmpTop[tid] = new T*[newSize];
		for (size_t i = 0; i < nowSize; ++i)
			
	}
}
