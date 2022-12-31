using namespace std;



#include<iostream>
#include<cstdio> //snprintf()
#include<cstdlib> //RAND_MAX
#include<cstring>
#include<string>

using std::cin;
using std::cout;
using std::string;

const long ASIZE = 500000L;

//
class MyString
{
public:
	static size_t DCtor;    //default ctor
	static size_t Ctor;		// ctor
	static size_t CCtor;	// copy ctor
	static size_t CAsgn;	//copy asgn
	static size_t MCtor;	//move ctor
	static size_t MAsgn;    //move asgn
	static size_t Dtor;		//dtor
	
private:
	char* _data;
	size_t _len;
	void _init_data(const char* s)
	{
		_data = new char[_len + 1];
		memcpy(_data, s, _len);
		_data[_len] = '\0';
	}
	
public:
	//default ctor
	MyString() : _data(NULL), _len(0) {DCtor++; }
	
	//ctor
	MyString(const char* p) : _len(strlen(p))	
	{
		++Ctor;
		_init_data(p);
	}
	
	//copy ctor
	MyString(const MyString& str): _len(str._len)
	{
		++CCtor;
		_init_data(str._data);
	}
	
	//move ctor
	MyString(MyString&& str) noexcept : _data(str._data), _len(str._len)
	{
		++MCtor;
		str._len = 0;
		str._data = NULL; 
	}
	

	//copy asgn
	MyString& operator=(const MyString& str)
	{
		++CAsgn;
		if(this != &str)
		{
			if(_data) 
				delete _data;
			
			_len = str._len;
			_init_data(str._data); 
		}
		else
		{
		}
		return *this;
	}
	
	//move asgn
	MyString& operator=(MyString&& str) noexcept
	{
		++MAsgn;
		if(this != &str)
		{
			if(_data)
				delete _data;
				
			_len = str._len;
			_data = str._data;   //move
			
			str._len = 0;
			str._data = NULL; 	
		}
		return *this;
	}
	
	//dtor
	virtual ~MyString()
	{
		++Dtor;
		if(_data)
			delete _data;
	}
	
	//
	bool operator< (const MyString& rhs) const
	{
		return std::string(this->_data) < std::string(rhs._data);
	}
	
	bool operator==(const MyString& rhs) const
	{
		return std::string(this->_data) == std::string(rhs._data);
	}
	
	char* get() const {return _data;}
};
size_t MyString::DCtor=0;  	
size_t MyString::Ctor=0;  	 
size_t MyString::CCtor=0;
size_t MyString::CAsgn=0;
size_t MyString::MCtor=0;
size_t MyString::MAsgn=0;
size_t MyString::Dtor=0;


//-----------------
//以下 MyStrNoMove 是為了測試 containers with no-moveable elements 效果.  
class MyStrNoMove { 
public: 
    static size_t DCtor;  	//累計 default-ctor 的呼叫次數 
    static size_t Ctor;  	//累計 ctor      的呼叫次數 
    static size_t CCtor;  	//累計 copy-ctor 的呼叫次數 
    static size_t CAsgn;  	//累計 copy-asgn 的呼叫次數 
    static size_t MCtor;  	//累計 move-ctor 的呼叫次數 
    static size_t MAsgn;  	//累計 move-asgn 的呼叫次數 		    
    static size_t Dtor;	    //累計 dtor 的呼叫次數 
private:     
  	char* _data; 
  	size_t _len; 
  	void _init_data(const char *s) { 
    		_data = new char[_len+1]; 
    		memcpy(_data, s, _len); 
    		_data[_len] = '\0'; 
  	} 
public: 
	//default ctor
  	MyStrNoMove() : _data(NULL), _len(0) { 	++DCtor; _init_data("jjhou"); }

	//ctor
  	MyStrNoMove(const char* p) : _len(strlen(p)) { 
    	++Ctor;  _init_data(p); 
  	} 

	// copy ctor
  	MyStrNoMove(const MyStrNoMove& str) : _len(str._len) { 
		++CCtor;  	 
    	_init_data(str._data); 	//COPY
  	} 

 	//copy assignment
  	MyStrNoMove& operator=(const MyStrNoMove& str) { 
    	++CAsgn;

		if (this != &str) { 
    		if (_data) delete _data;  
      		_len = str._len; 
      		_init_data(str._data); 	//COPY! 
    	} 
    	else {
		    // Self Assignment, Nothing to do.   
		}
    	return *this; 
  	} 

 	//dtor
  	virtual ~MyStrNoMove() { 	   
  	    ++Dtor;		  	    
    	if (_data) {
    		delete _data; 	
		}
  	}   	
  	
  	bool 											
  	operator<(const MyStrNoMove& rhs) const		//為了讓 set 比較大小 
  	{
	   return string(this->_data) < string(rhs._data);  //借用事實：string 已能比較大小. 
	}  	
	
  	bool 											
  	operator==(const MyStrNoMove& rhs) const	//為了讓 set 判斷相等. 
  	{
	   return string(this->_data) == string(rhs._data);  //借用事實：string 已能判斷相等. 
	} 
		
	char* get() const { return _data; }	
}; 
size_t MyStrNoMove::DCtor=0;  	
size_t MyStrNoMove::Ctor=0;  
size_t MyStrNoMove::CCtor=0;
size_t MyStrNoMove::CAsgn=0;
size_t MyStrNoMove::MCtor=0;
size_t MyStrNoMove::MAsgn=0;
size_t MyStrNoMove::Dtor=0;



namespace std
{
	template<>
	struct hash<MyString>
	{
		size_t operator() (const MyString& s) const noexcept
		{
			return hash<string>()(string(s.get()));
			
		}
	};
}


//----------------------------------------------------
#include <iostream>
#include <cstdio>  //snprintf()
#include <cstdlib> //RAND_MAX
#include <string> 
#include <algorithm> 
#include <list> 
#include <forward_list> 
using std::cin;
using std::cout;
using std::string;
using std::max;
using std::min;

namespace jj00
{
	
bool strLonger(const string& s1, const string& s2) {
          return s1.size() < s2.size();
}		
	
void test_misc()
{
	cout << "\ntest_misc().......... \n";
     
    //以下這些是標準庫的眾多容器的 max_size() 計算方式.  
    cout << size_t(-1) << endl;					         	//4294967295
	cout << size_t(-1)/sizeof(long) << endl;		     	//1073741823
	cout << size_t(-1)/sizeof(string) << endl;	         	//1073741823
	cout << size_t(-1)/sizeof(_List_node<string>) << endl; 	//357913941
	cout << size_t(-1)/sizeof(_Fwd_list_node<string>) << endl; //536870911
	cout << "RAND_MAX= " << RAND_MAX << endl;	//32767
	
	cout << min( {2,5,8,9,45,0,81} ) << endl;  //0
	cout << max( {2,5,8,9,45,0,81} ) << endl;  //81
	vector<int> v {2,5,8,9,45,0,81};               
         
	cout << "max of     zoo and hello : " 
	     << max(string("zoo"), string("hello")) << endl;              //zoo
	cout << "longest of zoo and hello : " 
	     << max(string("zoo"), string("hello"), strLonger) << endl;   //hello    
		 
	cout << hash<MyString>()(MyString("Ace")) << endl;		//1765813650
	cout << hash<MyString>()(MyString("Stacy")) << endl;	//2790324277
	cout << "MyString(zoo) < MyString(hello) ==> " << (MyString("zoo") < MyString("hello")) << endl;	//0
	cout << "MyString(zoo) == MyString(hello) ==> " << (MyString("zoo") == MyString("hello")) << endl;	//0	  
	cout << "MyStrNoMove(zoo) < MyStrNoMove(hello) ==> " << (MyStrNoMove("zoo") < MyStrNoMove("hello")) << endl;	 //0
	cout << "MyStrNoMove(zoo) == MyStrNoMove(hello) ==> " << (MyStrNoMove("zoo") == MyStrNoMove("hello")) << endl;	 //0
	//以上建構了 6 個 MyString objects 和 4 個 MyStrNoMove objects，都是暫時生命.    
}
}   

//--------------------------------------------------
#include<typeinfo>
template <typename T>
void output_static_data(const T& myStr)
{
	cout << typeid(myStr).name() << "----" << endl;
	cout << " CCtor = " << T::CCtor
		 << " MCtor = " << T::MCtor
		 << " CAsgn = " << T::CAsgn
		 << " MAsgn = " << T::MAsgn
		 << " Ctor = "  << T::Ctor
		 << " DCtor = " << T::DCtor
		 << " Dtor = "  << T::Dtor
		 << endl;
}


//
#include<ctime>
template <typename M, typename NM>
void test_moveable(M c1, NM c2, long& value)
{
char buf[10];
	
	//test move
	cout << "\n test, with moveable elements" << endl;
	typedef typename iterator_traits<typename M::iterator>::value_type valueType;
	
clock_t timeStart = clock();
	for(long i = 0; i < value; i++)
	{
		snprintf(buf, 10, "%d", rand());
		auto ite = c1.end();
		c1.insert(ite, valueType(buf));
	}
	cout << "construction milli-seconds : " << (clock() - timeStart) << endl;
	cout << "size() = " << c1.size() << endl;
	output_static_data(*(c1.begin()));
	
 	timeStart = clock();
M c11(c1);
	cout << "copy, milli-seconds : " << (clock() - timeStart) << endl;
	
	timeStart = clock();
M c12(std::move(c1));
	cout << "move copy, milli-seconds : " << (clock() - timeStart) << endl;
	
	timeStart = clock();
	c11.swap(c12);
	cout << "swap, milli-seconds :" << (clock() - timeStart) << endl;
	
	//test non-moveable
	cout << "\n teest, with non-moveable elements " << endl;
	typedef typename iterator_traits<typename NM::iterator>::value_type V2type;
	timeStart = clock();
	for(long i = 0; i < value; i++)
	{
		snprintf(buf, 10, "%d", rand());
		auto ite = c2.end();
		c2.insert(ite, V2type(buf));
	}
	
	cout << "construction milli-seconds : " << (clock() - timeStart) << endl;
	cout << "size() = " << c2.size() << endl;
	output_static_data(*(c2.begin()));
	
	timeStart = clock();
NM c21(c2);
	cout << "copy, milli-secondes : " << (clock() - timeStart) << endl;
	
	timeStart = clock();
NM c22(std::move(c2));
	cout << "move copy, milli-seconds : " << (clock() - timeStart) << endl;
	
	timeStart = clock();
	c21.swap(c22);
	cout << "swap, milli-seconds : " << (clock() - timeStart) << endl;
	 
}


//---------------------
long get_a_target_long()
{
	long target = 0;
	cout << "target (0~)" << RAND_MAX << "):" ;
	cin >> target;
	return target;
}


string get_a_target_string()
{
	long target = 0;
	char buf[10];
	
	cout << "target (0~)" << RAND_MAX << "):" ;
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}


int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);	
}

int compareStrings(const void* a, const void* b)
{
	if(*(string*)a > *(string*)b)
		return 1;
	else if(*(string*)a < *(string*)b)
		return -1;
	else
		return 0;
}

//------------------------------------------------
#include<array>
#include<iostream>
#include<ctime>
#include<cstdlib>   //qsort , bsearch, NULL

namespace jj01
{
void test_array()
{
	cout << "\n test array() ............\n";
	
array<long, ASIZE> c;

clock_t timeStart = clock();
	for(long i = 0; i < ASIZE; i++)
		c[i] = rand();
		
	cout << "milli-seconds : " << (clock() - timeStart) << endl;
	cout << "array.size() : " << c.size() << endl;
	cout << "array.front() : " << c.front() << endl;
	cout << "array.back() : " << c.back() << endl;
	cout << "arrray.data() : " << c.data() << endl;
	
long target = get_a_target_long();

	timeStart = clock();
	::qsort(c.data(), ASIZE, sizeof(long), compareLongs);
long* pItem = (long*)::bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
	cout << "qsort + bsearch milli-secondes : " << (clock() - timeStart) << endl;
	if(pItem != NULL)
		cout << "found , " << *pItem << endl;
	else
		cout << "not found !" << endl;  	
}
	
}


//---------------------------------------------------
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <algorithm> 	//sort()
namespace jj02
{
void test_vector(long& value)
{
	cout << "\ntest_vector().......... \n";
     
vector<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push_back(string(buf));     		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			     //曾經最高 i=58389486 then std::bad_alloc
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "vector.max_size()= " << c.max_size() << endl;	//1073747823
	cout << "vector.size()= " << c.size() << endl;		
	cout << "vector.front()= " << c.front() << endl;	
	cout << "vector.back()= " << c.back() << endl;	
	cout << "vector.data()= " << c.data() << endl;
	cout << "vector.capacity()= " << c.capacity() << endl << endl;		

																				
string target = get_a_target_string();
    {
	timeStart = clock();
auto pItem = find(c.begin(), c.end(), target);
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;  
	 
  	if (pItem != c.end())
    	cout << "found, " << *pItem << endl << endl;
  	else
    	cout << "not found! " << endl << endl;
    }

	{
	timeStart = clock();
    sort(c.begin(), c.end());
	cout << "sort(), milli-seconds : " << (clock()-timeStart) << endl; 
	
	timeStart = clock();	    
string* pItem = (string*)::bsearch(&target, (c.data()), 
                                   c.size(), sizeof(string), compareStrings); 
	cout << "bsearch(), milli-seconds : " << (clock()-timeStart) << endl; 
	   
  	if (pItem != NULL)
    	cout << "found, " << *pItem << endl << endl;
  	else
    	cout << "not found! " << endl << endl;	
	}
	
	c.clear();
	test_moveable(vector<MyString>(),vector<MyStrNoMove>(), value);	
}	
}




namespace qy01
{
class circle{
	int a;
	int b;
	//static const int c;
	//static const double d = 3.14159;
}; 

circle::c = 1; 	
	
}





//-----------------------------------------------------
int main()
{
	cout << __cplusplus << endl;
	
	//jj00::test_misc();
	//jj01::test_array();	
	//long value = 500000;
	//jj02::test_vector(value);
	//qy01::
	
	return 0;
}
