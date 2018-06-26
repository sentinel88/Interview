#include <iostream>
#include <string>

using namespace std;

class Singleton
{
	private:
		Singleton();
		int m_value;
	public:
		//static Singleton *getInstance();
		static Singleton &getInstance();
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		int getValue() const;
		void setValue(int);
};

Singleton::Singleton() : m_value(0)
{
}

//Singleton*
Singleton&
Singleton::getInstance()
{
	//static Singleton *ptr = new Singleton();
	static Singleton instance;
	//return ptr;
	return instance;
}

int 
Singleton::getValue() const
{
	return m_value;
}


void 
Singleton::setValue(int inVal)
{
	m_value = inVal;
}


int
main (int argc, char *argv[])
{
/*	Singleton *obj1 = Singleton::getInstance();
	obj1->setValue(5);
	cout <<obj1->getValue() <<endl;
	Singleton *obj2 = Singleton::getInstance();	
	obj2->setValue(10);
	cout <<obj2->getValue() <<endl;*/
	//Singleton obj = Singleton::getInstance();
	(Singleton::getInstance()).setValue(10);
	cout <<(Singleton::getInstance()).getValue() <<endl;

	return 0;
}
