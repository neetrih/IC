#include "vector.h" 

template <typename T>//元素类型 
void Vector :: copyFrom ( T const* A, Rank lo, Rank hi ) //以数组区间[lo，hi）为蓝本复制向量 
{
	_elem = new T[_capacity = 2 * ( hi - lo ) ]; _size=0; //分配空间，规模清零
	while ( lo < hi ) //A[lo,hi)内元素逐一
	    _elem[_size++] = A[lo++]; //复制至_elem[0,hi-lo) 
}

template <typename T >
void Vector<T> :: expand() //空间不足时扩容
{
	if ( _size < _capacity ) return ; //尚未满员，不需扩容
	if ( _capacity < DEFAULT_CAPACITY ) _capacity =  DEFAULT_CAPACITY; //不低于默认容量
	T* oldElem = _elem; _elem = new T[_capacity *= 2]; //容量加倍
	for ( int i = 0; i < _size; i++ )
	    _elem[i] = oldElem[i]; //复制原向量 
	delete [] oldElem;  //释放原空间 
 } 

template <typename T >
void Vector<T> :: shrink() //缩容 
{
	if ( _capacity < DEFAULT_CAPACITY ) return ; //不致收缩到DEFAULT_CAPACITY以下
	if ( _size << 2 > _capacity ) return ; //以25%为界
	T* oldElem = _elem; _elem = new T[_capacity >> 1]; //容量减半
	for ( int i = 0; i < _size; i++ )
	    _elem[i] = oldElem[i]; //复制原向量 
	delete [] oldElem;  //释放原空间 
 } 

template <typename T >
void swap ( T &a, T &b) //交换 
{
	T temp = a;
	a = b;
	b = temp;
}

 template <typename T >
 bool Vector<T> :: bubble ( Rank lo, Rank hi) //扫描交换
 {
 	bool sorted = true; //有序标志
	 while ( ++lo < hi)
	 {
	 	if ( _elem[lo-1] > _elem[lo])
	 	{
	 		sorted = false;
	 		swap ( _elem[lo-1], _elem[lo] ); //交换使局部有序 
		 }
	  } 
	return sorted; //返回有序标志 
  } 

 template <typename T>
 void Vector<T> :: bubbleSort ( Rank lo, Rank hi ) //0<=lo<hi<=_size  起泡排序 
 {
 	while ( !bubble ( lo, hi--) ) //逐趟扫描至有序 
}

template <typename T >
Rank Vector<T> :: max (Rank lo, Rank hi ) //选取最大 
{
	Rank max = lo;
	for ( ;lo < hi;lo++)
	{
		if (_elem[lo]>_elem[max])
		    max = lo;
	}
	return max;
}
  
template <typename T >
void Vector<T> :: selectionSort (Rank lo, Rank hi ) //选择排序 
{
	while ( lo < hi)
	{
		swap(_elem[max( lo, hi ) ],_elem[hi--] );
	}
}
 
template <typename T >
void Vector<T> :: merge ( Rank lo, Rank mi, Rank hi ) //归并
{
	T* A = _elem + lo;
	int lb = mi - lo; T* B = new T[lb];
	for ( Rank i=0; i <lb; B[i] = A[i++] ); //复制子前向量 
	int lc = hi - mi; T* C = _elem + mi;
	for ( Rank i=0, j = 0, k = 0; ( j < lb ) || ( k < lc ); ){
		if ( ( j < lb ) && (!( k < lc ) || ( B[j] <= C[k] ) ) ) A[i++] = B[j++];
		if ( ( k < lc ) && (!( j < lb ) || ( C[k] < B[j]  ) ) ) A[i++] = C[k++];
	}
	delete [] B;
 } 
 
template <typename T >
void Vector<T> :: mergeSort ( Rank lo, Rank hi ) //归并排序
{
	if ( hi -lo < 2) return ;
	int mi = ( lo + hi ) / 2;
	mergeSort ( lo, mi );
	mergeSort ( mi, hi ); //分别排序 
	merge ( lo, mi, hi ); //归并 
 } 

template <typename T >
void Vector<T> :: sort ( Rank lo, Rank hi )
{
	switch ( rand() % 3 ){
		case 1: bubbleSort ( lo, hi ); break;
		case 2: selectionSort ( lo, hi ); break;
		default: mergeSort ( lo, hi ); break;
	}
}

template <typename T >
int Vector<T> :: disordered() const //返回逆序相邻元素对数 
{
	int n = 0; //计数
	for ( int i=1; i < _elem; i++){
		if ( _elem[i -1] > _elem[i] ) n++;
	return n;
	} 
}
 
template <typename T>
static Rank binSearch ( T *A, T const& e, Rank lo, Rank hi )
{
	while( lo < hi){
		Rank mi = ( lo + hi ) >> 1;
		( e < A[mi] ) ? hi = mi : lo = mi + 1;
	}
	return  --lo;
}

template <typename T>
Rank Vector<T> :: find ( T const& e, Rank lo, Rank hi ) const
{
    return binSearch( _elem, e, lo, hi );
 } 
 
template <typename T>
Rank Vector<T> :: rearch ( T const& e, Rank lo, Rank hi ) const
{
	while ( ( lo < hi-- ) && ( e != _elem[hi] ) );
	if ( hi < lo)
	    return -1;
	else return hi;
}

template <typename T>
Vector T& operator[] ( Rank r ) const //重载下标操作符
{
	return _elem[r];
 } 

template <typename T>
Vector T& operator = ( Vector<T> const& V ) //重载赋值操作符
{
	if ( _elem ) delete [] _elem;
	copyForm ( V._elem, , V.size() );
	return *this;
}

template <typename T>
int Vector<T> :: remove ( Rank lo, Rank hi)
{
	if ( lo == hi ) return ;
	while  ( hi <= _size ) _elem[lo++];
	_size = lo;
	shrink();
	return hi - lo; 
}

template <typename T>
T Vector<T> :: remove ( Rank r )
{
	T e = _elem[r];
	remove ( r, r+1 );
	return e;
}

template <typename T>
Rank insert ( Rank r, T const& e)
{
	expand();
	for ( int i = _size; i >r; i--) _elem[i] = _elem[i-1];
	_elem = e; _size++;
	return r;
}

template <typename T>
Rank insert ( T const& e)
{
	return insert ( _size, e );
}

template <typename T>
void Vector<T> :: sort() { sort ( 0, _size ) }

template <typename T>
void Vector<T> :: unsort ( Rank lo, Rank hi )
{
	T* V = _elem + lo;
	for ( Rank i = hi - lo; i > 0; i-- )
	{
		swap ( V[i - 1],V[rand()%i]);
	}
}

template <typename T>
void Vector<T> :: unsort () 
{
	unsort ( 0, _size );
}

template <typename T>
int  Vector<T> :: deduplicate()
{
	Rank i = 0, j = 0;
	while ( ++j < _size )
	{
		if (_elem[i] != _elem[j] )
		    _elem[++i] = _elem[j];
	}
	_size = ++i; shrink();
	return j-i;
}

template <typename T>
int  Vector<T> :: uniquify()
{
	Rank i = 0, j = 0;
	while ( ++j < _size )
	{
		if (_elem[i] != _elem[j] )
		    _elem[++i] = _elem[j];
	}
	_size = ++i; shrink();
	return j-i;
}
 
template <typename T> 
void Vector<T> :: traverse ( void ( *visit ) ( T& ) ) //指针 
{
	for ( int i = 0; i < _size; i++)  
	    visit ( _elem[i]); 
}
 
template <typename T> template <typename VST> //元素类型，操作器
void Vector<T> :: increase ( VST& visit ) //函数对象 
{
	for ( int i = 0; i < _size; i++)  
	    visit ( _elem[i]); 
}
 
