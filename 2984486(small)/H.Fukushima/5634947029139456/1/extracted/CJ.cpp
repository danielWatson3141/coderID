#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>

#undef min
#undef max

#include <stdio.h>

#include <exception>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <memory>
#include <limits>
#include <numeric>

#include <algorithm>

#include <cassert>

using namespace std;

#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

using namespace boost;

#define foreach BOOST_FOREACH


// NOTE :
//
// - platform
//   - windwos
//
// - development tool
//   - Visual Studio 2005
//
// - require libraries
//   - boost( http://www.boost.org/ )( used version 1.38 )

























// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// begin utility



// -------------------------------------------------------------------------

template<typename T> inline T (min)( const T& a , const T& b )                           { return a < b ? a : b ;                            }
template<typename T> inline T (min)( const T& a , const T& b , const T& c )              { return (min)( (min)( a , b ) , c ) ;              }
template<typename T> inline T (min)( const T& a , const T& b , const T& c , const T& d ) { return (min)( (min)( a , b ) , (min)( c , d ) ) ; }
template<typename T> inline T (max)( const T& a , const T& b )                           { return a > b ? a : b ;                            }
template<typename T> inline T (max)( const T& a , const T& b , const T& c )              { return (max)( (max)( a , b ) , c ) ;              }
template<typename T> inline T (max)( const T& a , const T& b , const T& c , const T& d ) { return (max)( (max)( a , b ) , (max)( c , d ) ) ; }

template<typename T> inline T pow2( const T& v ) { return v * v ;             }
template<typename T> inline T pow3( const T& v ) { return v * v * v ;         }
template<typename T> inline T pow4( const T& v ) { return pow2( v * v ) ;     }
template<typename T> inline T pow5( const T& v ) { return pow2( v * v ) * v ; }
template<typename T> inline T pow6( const T& v ) { return pow3( v * v ) ;     }
template<typename T> inline T pow7( const T& v ) { return pow3( v * v ) * v ; }
template<typename T> inline T pow8( const T& v ) { return pow4( v * v ) ;     }

template<typename T> inline T clamp( const T& i_min , const T& i_value , const T& i_max ) 
{
#ifdef _DEBUG
	assert( i_min <= i_max );
#endif

	return (min)( (max)( i_min , i_value ) , i_max );
}

template<typename T> inline T get_pair( const T& value , const T& pair_value_a , const T& pair_value_b )
{
#ifdef _DEBUG
	assert( value == pair_value_a || value == pair_value_b );
#endif

	if( value == pair_value_a )
		return pair_value_b;
	else
		pair_value_a;
}

template<typename T> inline T gcd( T a , T b )
{
	if( b > a ) (swap)( a , b );
	while( ( a = a % b ) != 0 ) (swap)( b , a );
	return b;
}

template<typename T> inline T lcm( const T& a , const T& b )
{
	return a * b / gcd( a , b );
}

template<typename DstContainerType , typename AddContainerType>
void insert_to_end( DstContainerType& dst_container , AddContainerType& add_container )
{
	DstContainerType::iterator dst_end   = dst_container.end();
	AddContainerType::iterator add_begin = add_container.begin();
	AddContainerType::iterator add_end   = add_container.end();

	dst_container.insert( dst_end , add_begin , add_end );
}

template<typename From> struct auto_cast_t
{
public:
	auto_cast_t(const From& val) : m_val(val) {}

	template<typename To>
	operator To() const
	{
		return static_cast<To>( m_val );
	}

private:
	const From& m_val;
};

template<typename From> auto_cast_t<From> auto_cast(const From& i_value)
{
	return auto_cast_t<From>(i_value);
}

template<typename STREAM, typename STR_STREAM> class StreamToStrHelper_T
{
public:
	STREAM& os() { return ss; }
private:
	STR_STREAM ss;
};

typedef StreamToStrHelper_T<ostream, ostringstream> StreamToStrHelper;
#define STREAM_TO_STR(STREAM)\
	((ostringstream&)(StreamToStrHelper().os()<<STREAM)).str()

inline size_t GetStreamSize( istream& stream )
{
	stream.seekg( 0 , ios::end );
	fstream::pos_type pos_end = stream.tellg();

	stream.seekg( 0 , ios::beg );
	fstream::pos_type pos_beg = stream.tellg();

	size_t stream_size = pos_end - pos_beg;
	return stream_size;
}

inline void LoadBufferFromStream(vector<char>& o_buffer, istream& stream)
{
	size_t filesize = GetStreamSize(stream);
	o_buffer.resize( filesize );
	stream.read( &o_buffer[0] , filesize );
}

inline bool LoadBufferFromFile(vector<char>& o_buffer, const char* filename)
{
	ifstream ifs( filename , ios::binary );
	if( !ifs.is_open() )
		return false;

	LoadBufferFromStream( o_buffer , ifs );
	return true;
}

template<typename SrcContainerType>
class container_cast_t
{
public:
	container_cast_t(SrcContainerType& t)
		: m_SrcContainer(&t)
	{}
	
	template<typename DstContainerType>
	operator DstContainerType(void) const
	{
		return DstContainerType( m_SrcContainer->begin() , m_SrcContainer->end() );
	}

private:
	SrcContainerType* m_SrcContainer;
};

template<typename SrcContainerType>
container_cast_t<SrcContainerType> container_cast(SrcContainerType& container)
{
	return container_cast_t<SrcContainerType>( container );
}

template<typename DST,typename SRC>
void container_cast( DST& dst_container , SRC& src_container )
{
	dst_container = DST( src_container.begin() , src_container.end() );
}

#define post_while(GUARD,EQUATION)\
	for(bool GUARD=false;!GUARD;GUARD=!(EQUATION))

#define for_permutation(CONTAINER)\
	sort((CONTAINER).begin(), (CONTAINER).end());\
	post_while(FORPERMUTATION_END, next_permutation( (CONTAINER).begin() , (CONTAINER).end() ))


// -------------------------------------------------------------------------

template<typename T> class container_holder
{
public:
	container_holder(void) {}

	container_holder<T>& operator()(const T& val)
	{
		return push_back(val);
	}

	container_holder<T>& push_back(const T& val)
	{
		m_vec.push_back(val);
		return *this;
	}

	void clear(void)
	{
		m_vec.clear();
	}

	template<typename DstContainer>
	operator DstContainer() const
	{
		return DstContainer( m_vec.begin() , m_vec.end() );
	}

private:
	std::vector<T> m_vec;
};

template<typename T>
container_holder<T> list_of(const T& t)
{
	container_holder<T> _holder;
	return _holder(t);
}

template<typename T,typename U>
std::pair<T,U> pair_of( const T& t , const U& u )
{
	return std::pair<T,U>( t , u );
}



// -------------------------------------------------------------------------
class String
{
public:
	static void Split(const string& str , vector<string>& o_sList, const char splitter)
	{
		o_sList.clear();

		size_t next_head = 0;
		for(size_t i=0;i<str.size();++i)
		{
			if( str.c_str()[i] == splitter )
			{
				if( next_head != i )
					o_sList.push_back( str.substr( next_head , i - next_head ) );
				next_head = i + 1;
			}
		}

		if( next_head < str.size() ) o_sList.push_back( str.substr( next_head ) );
	}

	static void ToMultiByte(const wstring &src, string &dst)
	{
		if( src.empty() )
			return;

		vector< char > mbs( src.length() * MB_CUR_MAX + 1 );

		wcstombs(&mbs[0], src.c_str(), src.length() * MB_CUR_MAX + 1);
		dst = &mbs[0];
	}
	static string ToMultiByte(const wstring &src)
	{
		string dst;
		ToMultiByte( src , dst );
		return dst;
	}

	static void ToUnicode(const string &src, wstring &dst)
	{
		if( src.empty() )
			return;

		vector< wchar_t > wcs( src.length() + 1 );
		mbstowcs(&wcs[0], src.c_str(), src.length() + 1);
		dst = &wcs[0];
	}
	static wstring ToUnicode(const string &src)
	{
		wstring dst;
		ToUnicode( src , dst );
		return dst;
	}

	static void Trim(string& s)
	{
		TrimStr(s, " \t");
	}
	static void TrimStr(string& s, const string& pattern)
	{
		typedef string::size_type size_type;

		size_type top = s.find_first_not_of( pattern );
		if( top == string::npos )
		{
			s.clear();
			return;
		}

		size_type end = s.find_last_not_of( pattern );

		if( top == 0 && (end+1) == s.size() )
			return;

		s = s.substr( top , end );
	}
};



// -------------------------------------------------------------------------

class invalid_product_exception : std::exception
{};

template<typename T>
class matrix
{
public:
	matrix(void)
		: m_size_x( 0 )
		, m_size_y( 0 )
	{}
	matrix(size_t num_x, size_t num_y)
		: m_size_x( num_x )
		, m_size_y( num_y )
	{
		buf.resize( m_size_x * m_size_y );
	}
	matrix(size_t num_x, size_t num_y, const T& initial_value)
		: m_size_x( num_x )
		, m_size_y( num_y )
	{
		buf.resize( m_size_x * m_size_y );
		fill( buf.begin() , buf.end() , initial_value );
	}
	matrix(const matrix<T>& m)
	{
		buf = m.buf;
		m_size_x = m.size_x();
		m_size_y = m.size_y();
	}

	T* v(void)
	{
		if( buf.empty() ) return NULL    ;
		else              return &buf[0] ;
	}
	const T* v(void) const
	{
		if( buf.empty() ) return NULL    ;
		else              return &buf[0] ;
	}

	T& at(size_t idx_v) { return buf[idx_v]; }
	const T& at(size_t idx_v) const { return buf[idx_v]; }
	T& operator()(size_t idx_v) { return at(idx_v); }
	const T& operator()(size_t idx_v) const { return at(idx_v); }
	T& operator[](size_t idx_v) { return at( idx_v ); }
	const T& operator[](size_t idx_v) const { return at( idx_v ); }

	T& at(size_t idx_x, size_t idx_y)
	{
		assert( idx_x < m_size_x && idx_y < m_size_y );  // Matrix subscript out of range
		return buf[ idx_x + m_size_x * idx_y ];
	}
	const T& at(size_t idx_x, size_t idx_y) const
	{
		assert( idx_x < m_size_x && idx_y < m_size_y );  // Matrix subscript out of range
		return buf[ idx_x + m_size_x * idx_y ];
	}
	T& operator()(size_t idx_x, size_t idx_y){ return at( idx_x , idx_y ); }
	const T& operator()(size_t idx_x, size_t idx_y) const{ return at( idx_x , idx_y ); }

	void resize(size_t num_x, size_t num_y)
	{
		m_size_x = num_x;
		m_size_y = num_y;
		buf.resize( m_size_x * m_size_y );
	}
	void resize(size_t num_x, size_t num_y, const T& initial_value)
	{
		resize( num_x , num_y );
		fill( buf.begin() , buf.end() , initial_value );
	}

	void clear(void)
	{
		m_size_x = 0;  m_size_y = 0;
		buf.clear();
	}

	size_t size(void) const { return buf.size(); }
	size_t size_x(void) const { return m_size_x; }
	size_t size_y(void) const { return m_size_y; }

	bool empty(void) const { return buf.empty(); }

	void set(const matrix<T>& m)
	{
		buf = m.buf;
		m_size_x = m.size_x();   m_size_y = m.size_y();
	}
	matrix<T>& operator=(const matrix<T>& m)
	{
		set( m );
		return (*this);
	}

	bool equals(const matrix<T>& m)
	{
		if( m_size_x != m.m_size_x || m_size_y != m.m_size_y ) return false;
		for(size_t i=0;i<m.size();i++) { if( at(i) != m(i) ) return false; }
		return true;
	}
	bool operator==(const matrix<T>& m) { return equals( m );  }
	bool operator!=(const matrix<T>& m) { return !equals( m ); }

	typedef typename vector<T>::iterator               iterator;
	typedef typename vector<T>::const_iterator         const_iterator;
	typedef typename vector<T>::reverse_iterator       reverse_iterator;
	typedef typename vector<T>::const_reverse_iterator const_reverse_iterator;
	iterator               begin  (void)       { return buf.begin();  }
	iterator               end    (void)       { return buf.end();    }
	reverse_iterator       rbegin (void)       { return buf.rbegin(); }
	reverse_iterator       rend   (void)       { return buf.rend();   }
	const_iterator         begin  (void) const { return buf.begin();  }
	const_iterator         end    (void) const { return buf.end();    }
	const_reverse_iterator rbegin (void) const { return buf.rbegin(); }
	const_reverse_iterator rend   (void) const { return buf.rend();   }

protected:
	size_t m_size_x;
	size_t m_size_y;
	vector<T> buf;
};

template<typename T> inline vector<T> operator*(const matrix<T>& _m, const vector<T>& _v)
{
	assert( _m.size_x() == _v.size() );
	if( _m.size_x() != _v.size() )
		throw invalid_product_exception();

	vector<T> ret( _m.size_y() );
	for( size_t i = 0 ; i < _m.size_y() ; ++i )
	{
		T& val = ret[i];

		for( size_t j = 0 ; j < _m.size_x() ; ++j )
		{
			val += _m( j , i ) * _v[j];
		}
	}

	return ret;
}

template<typename T> inline vector<T> operator*(const vector<T>& _v, const matrix<T>& _m)
{
	assert( _m.size_y() == _v.size() );
	if( _m.size_y() != _v.size() )
		throw invalid_product_exception();

	vector<T> ret( _m.size_x() );
	for( size_t i = 0 ; i < _m.size_x() ; ++i )
	{
		T& val = ret[i];

		for( size_t j = 0 ; j < _m.size_y() ; ++j )
		{
			val += _v[j] * _m( i , j );
		}
	}

	return ret;
}

template<typename T> inline matrix<T> operator*(const matrix<T>& _m0, const matrix<T>& _m1)
{
	assert( _m0.size_x() == _m1.size_y() );
	if( _m0.size_x() != _m1.size_y() )
		throw invalid_product_exception();

	matrix<T> m( _m1.size_x() , _m0.size_y() );
	for( size_t i = 0 ; i < _m1.size_x() ; ++i )
	{
		for( size_t j = 0 ; j < _m0.size_y() ; ++j )
		{
			T& val = m( i , j );

			for( size_t k = 1 ; k < _m0.size_x() ; ++k )
			{
				val += _m0( k , j ) * _m1( i , k );
			}
		}
	}

	return m;
}

template<typename T> inline vector<T> dot(const matrix<T>& _m, const vector<T>& _v)
{
	return _m * _v;
}

template<typename T> inline vector<T> dot(const vector<T>& _v, const matrix<T>& _m)
{
	return _v * _m;
}

template<typename T> inline matrix<T> dot(const matrix<T>& _m0, const matrix<T>& _m1)
{
	return _m0 * _m1;
}



// -------------------------------------------------------------------------
class TextReader
{
public:
	static bool LoadAsLineAry(const char* filename, vector<string>& ary)
	{
		ary.clear();

		ifstream ifs(filename);
		if( !ifs.is_open() )
			return false;

		return LoadAsLineAry( ifs , ary );
	}
	static bool LoadAsLineAry(ifstream& is, vector<string>& ary)
	{
		ary.clear();

		while( !is.eof() )
		{
			ary.push_back( string() );
			getline( is , ary.back() );
		}

		return true;
	}

	static bool LoadAsString(const char* filename, string& str)
	{
		str.clear();

		ifstream ifs(filename);
		if( !ifs.is_open() )
			return false;

		return LoadAsString( ifs , str );
	}
	static bool LoadAsString(ifstream& is, string& str)
	{
		str.clear();

		is.seekg( 0 , ios::end );
		fstream::pos_type pos_end = is.tellg();

		is.seekg( 0 , ios::beg );
		fstream::pos_type pos_beg = is.tellg();

		size_t stream_size = pos_end - pos_beg;
		if( stream_size == 0 )
			return true;

		str.resize( stream_size );
		is.read( &str.at(0) , (streamsize)stream_size );

		return true;
	}

	static bool LoadCsv(const char* filename, vector<vector< string > >& ary, const char separator=',')
	{
		ary.clear();

		ifstream ifs(filename);
		if( !ifs.is_open() )
			return false;

		return LoadCsv( ifs , ary , separator );
	}
	static bool LoadCsv(ifstream& is, vector<vector< string > >& ary, const char separator=',')
	{
		ary.clear();

		while( !is.eof() )
		{
			ary.resize( ary.size()+1 );
			vector<string>& line = ary.back();

			string s;
			getline( is , s );

			string::iterator iter = s.begin();
			while( iter != s.end() )
			{
				string::iterator next = find( iter , s.end() , separator );

				line.push_back( string( iter , next ) );
				String::Trim( line.back() );

				if( next == s.end() )
					break;

				iter = next;
				++iter;
			}
		}

		return true;
	}
};



// -------------------------------------------------------------------------

class DebugStreambuf : public streambuf 
{
public:
	virtual int_type overflow( int_type i_char = EOF )
	{
		if( m_buf.empty() )
			m_buf.push_back( (i_char) );
		else
			m_buf.back() = (i_char);

		m_buf.push_back( ('\0') );

		return i_char;
	}

	virtual int sync(void)
	{
		if( !m_buf.empty() )
		{
			OutputDebugString( &m_buf[0] );
			m_buf.clear();
		}
		return 0;
	}

private:
	vector<TCHAR> m_buf;
};

class DebugStream : public ostream
{
public:
	DebugStream(void) : ostream( &m_buf )
	{}

private:
	DebugStreambuf m_buf;
};

static DebugStream dout;



// -------------------------------------------------------------------------


// end utility
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------





// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------






// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
// output

enum OUT_MODE
{
	OUT_DOUT = 0x001,
	OUT_COUT = 0x010,
	OUT_FOUT = 0x100,
};

const int OUTMODE_D = OUT_DOUT;
const int OUTMODE_F = OUT_FOUT;
const int OUTMODE_C = OUT_COUT;
const int OUTMODE_DF = ( OUT_DOUT | OUT_FOUT );
const int OUTMODE_CF = ( OUT_COUT | OUT_FOUT );
const int OUTMODE_DCF = ( OUT_DOUT | OUT_COUT | OUT_FOUT );

int g_OUTMODE = OUTMODE_DCF;

#define OUT_M(STREAM)\
	if(g_OUTMODE&OUT_DOUT) { dout STREAM; }\
	if(g_OUTMODE&OUT_COUT) { cout STREAM; }\
	if(g_OUTMODE&OUT_FOUT) { fout STREAM; }

#define OUT_S(STREAM)\
	{\
		ostringstream OUTS_STREAM;\
		OUTS_STREAM STREAM;\
		OUT_M( << OUTS_STREAM.str().c_str() );\
		if(g_OUTMODE&OUT_DOUT) dout.flush();\
	}

//#define OUTANS OUT_M
#define OUTANS OUT_S

#define FillLen(FILL_CHAR,WIDTH) setfill(FILL_CHAR) << setw(WIDTH)
#define FillSpace(WIDTH) setfill(' ') << setw(WIDTH)
#define StrPrec(PREC) setprecision(PREC)


// end output
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------



#define CaseHead(NUM) "Case #" << (NUM) << ": "


typedef long long ll;




void flip(char& c)
{
	c = (c == '0') ? '1' : '0';
}

void flip(string& s, int i)
{
	flip(s[i]);
}

vector<bool> getflip(string& a, string& b)
{
	vector<bool> c(a.size());
	for (size_t i = 0; i < a.size(); ++i)
	{
		c[i] = (a[i] != b[i]);
	}

	return c;
}

int flipcnt(vector<bool>& b)
{
	int i = 0;
	for (auto x : b)
	{
		if (x) i++;
	}

	return i;
}

void flip(string& s, vector<bool>& p)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		if(p[i])
			flip(s, i);
	}
}

bool match(vector<string> a, vector<string> b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (size_t i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
			return false;
	}

	return true;
}

void solve(istream& in, ostream& fout, int caseIdx)
{
	vector<string> req, pat;

	int N, L;
	in >> N >> L;

	req.resize(N);
	for (int i = 0; i < N; ++i)
	{
		in >> req[i];
	}
	pat.resize(N);
	for (int i = 0; i < N; ++i)
	{
		in >> pat[i];
	}

	int minflip = -1;
	for (size_t i = 0; i < req.size(); ++i)
	{
		for (size_t j = 0; j < pat.size(); ++j)
		{
			string& a = req[i];
			string& b = pat[j];

			vector<bool> c = getflip(a, b);

			vector<string> p2 = pat;
			for (string& s : p2)
			{
				flip(s, c);
			}

			if (match(req, p2))
			{
				if (minflip == -1)
				{
					minflip = flipcnt(c);
				}
				else
				{
					minflip = (std::min)(minflip, flipcnt(c));
				}
			}
		}
	}

	if (minflip == -1)
	{
		OUTANS( << CaseHead(caseIdx+1) << "NOT POSSIBLE" << endl );
	}
	else
	{
		OUTANS( << CaseHead(caseIdx+1) << minflip << endl );
	}
}


void proc(istream& in, ostream& fout)
{
	int cnt = 0;
	in >> cnt;

	for( int i = 0 ; i < cnt ; ++i )
	{
		solve(in, fout, i);
		cout << i << "/" << cnt << endl;
	}
}






// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void proc_file(const char* f_in, const char* f_out)
{
	ifstream ifs(f_in);
	assert( ifs.is_open() );

	ofstream ofs(f_out);
	assert( ofs.is_open() );

	proc( ifs , ofs );
}

int main(int argc, char* argv[])
{
	g_OUTMODE = OUTMODE_D;
	//g_OUTMODE = OUTMODE_F;
	//g_OUTMODE = OUTMODE_C;
	g_OUTMODE = OUTMODE_DF;
	//g_OUTMODE = OUTMODE_CF;
	//g_OUTMODE = OUTMODE_DCF;

	string infile;
	infile += "../CJ/";
	//infile += "A-small-attempt0.in";
	infile += "A-large.in";

	proc_file( infile.c_str() , "../CJ/out.txt" );

	return 0;
}
