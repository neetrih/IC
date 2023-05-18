#include "vector.h" 

template <typename T>//Ԫ������ 
void Vector :: copyFrom ( T const* A, Rank lo, Rank hi ) //����������[lo��hi��Ϊ������������ 
{
	_elem = new T[_capacity = 2 * ( hi - lo ) ]; _size=0; //����ռ䣬��ģ����
	while ( lo < hi ) //A[lo,hi)��Ԫ����һ
	    _elem[_size++] = A[lo++]; //������_elem[0,hi-lo) 
}

template <typename T >
void Vector<T> :: expand() //�ռ䲻��ʱ����
{
	if ( _size < _capacity ) return ; //��δ��Ա����������
	if ( _capacity < DEFAULT_CAPACITY ) _capacity =  DEFAULT_CAPACITY; //������Ĭ������
	T* oldElem = _elem; _elem = new T[_capacity *= 2]; //�����ӱ�
	for ( int i = 0; i < _size; i++ )
	    _elem[i] = oldElem[i]; //����ԭ���� 
	delete [] oldElem;  //�ͷ�ԭ�ռ� 
 } 

template <typename T >
void Vector<T> :: shrink() //���� 
{
	if ( _capacity < DEFAULT_CAPACITY ) return ; //����������DEFAULT_CAPACITY����
	if ( _size << 2 > _capacity ) return ; //��25%Ϊ��
	T* oldElem = _elem; _elem = new T[_capacity >> 1]; //��������
	for ( int i = 0; i < _size; i++ )
	    _elem[i] = oldElem[i]; //����ԭ���� 
	delete [] oldElem;  //�ͷ�ԭ�ռ� 
 } 

template <typename T >
void swap ( T &a, T &b) //���� 
{
	T temp = a;
	a = b;
	b = temp;
}

 template <typename T >
 bool Vector<T> :: bubble ( Rank lo, Rank hi) //ɨ�轻��
 {
 	bool sorted = true; //�����־
	 while ( ++lo < hi)
	 {
	 	if ( _elem[lo-1] > _elem[lo])
	 	{
	 		sorted = false;
	 		swap ( _elem[lo-1], _elem[lo] ); //����ʹ�ֲ����� 
		 }
	  } 
	return sorted; //���������־ 
  } 

 template <typename T>
 void Vector<T> :: bubbleSort ( Rank lo, Rank hi ) //0<=lo<hi<=_size  �������� 
 {
 	while ( !bubble ( lo, hi--) ) //����ɨ�������� 
}

template <typename T >
Rank Vector<T> :: max (Rank lo, Rank hi ) //ѡȡ��� 
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
void Vector<T> :: selectionSort (Rank lo, Rank hi ) //ѡ������ 
{
	while ( lo < hi)
	{
		swap(_elem[max( lo, hi ) ],_elem[hi--] );
	}
}
 
template <typename T >
void Vector<T> :: merge ( Rank lo, Rank mi, Rank hi ) //�鲢
{
	T* A = _elem + lo;
	int lb = mi - lo; T* B = new T[lb];
	for ( Rank i=0; i <lb; B[i] = A[i++] ); //������ǰ���� 
	int lc = hi - mi; T* C = _elem + mi;
	for ( Rank i=0, j = 0, k = 0; ( j < lb ) || ( k < lc ); ){
		if ( ( j < lb ) && (!( k < lc ) || ( B[j] <= C[k] ) ) ) A[i++] = B[j++];
		if ( ( k < lc ) && (!( j < lb ) || ( C[k] < B[j]  ) ) ) A[i++] = C[k++];
	}
	delete [] B;
 } 
 
template <typename T >
void Vector<T> :: mergeSort ( Rank lo, Rank hi ) //�鲢����
{
	if ( hi -lo < 2) return ;
	int mi = ( lo + hi ) / 2;
	mergeSort ( lo, mi );
	mergeSort ( mi, hi ); //�ֱ����� 
	merge ( lo, mi, hi ); //�鲢 
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
int Vector<T> :: disordered() const //������������Ԫ�ض��� 
{
	int n = 0; //����
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
Vector T& operator[] ( Rank r ) const //�����±������
{
	return _elem[r];
 } 

template <typename T>
Vector T& operator = ( Vector<T> const& V ) //���ظ�ֵ������
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
void Vector<T> :: traverse ( void ( *visit ) ( T& ) ) //ָ�� 
{
	for ( int i = 0; i < _size; i++)  
	    visit ( _elem[i]); 
}
 
template <typename T> template <typename VST> //Ԫ�����ͣ�������
void Vector<T> :: increase ( VST& visit ) //�������� 
{
	for ( int i = 0; i < _size; i++)  
	    visit ( _elem[i]); 
}
 
