#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;

struct Base
{
	Base() { cout <<"Base constructor" <<endl; }
	~Base() { cout <<"Base destructor" <<endl; }
};


struct Derived : public Base
{
	Derived() { cout <<"Derived constructor" <<endl; }
	~Derived() { cout <<"Derived destructor" <<endl; }
};


void 
thr(shared_ptr<Base> p)
{
	shared_ptr<Base>lp = p;
	{
		static mutex io_mutex;
		lock_guard<mutex> lk(io_mutex);
		cout <<"local shared pointer in a thread" <<endl
		     <<"lp.get(): " <<lp.get()
		     <<"lp.use_count(): "<<lp.use_count() <<endl;
	}
}


int
main (int argc, char *argv[])
{
	shared_ptr<Base> p = make_shared<Derived>();

	cout <<"Create a shared derived" <<endl;
	cout <<"get: " <<p.get() <<endl
	     <<"Use count: "<<p.use_count() <<endl;

	thread t1(thr, p), t2(thr, p), t3(thr, p);
	cout <<"Shared owndership between 3 threads and released" <<endl
	     <<"Owndership from main: " <<endl;
	cout <<"get: " <<p.get()
	     <<"Use count: "<<p.use_count() <<endl;
	t1.join(); t2.join(); t3.join();
	
	return 0;
}
