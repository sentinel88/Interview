#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class A
{
	public:
		A() { cout <<"Constructing A" <<endl; }
		virtual ~A() { cout <<"Destroying A" <<endl; }
		virtual void display() { cout <<"It is A's value"<<endl; }
};


class B : public A
{
	public:
		B() { cout <<"Constructing B" <<endl; }
		virtual ~B() { cout <<"Destroying B" <<endl; }
		void display() override { cout <<"It is B's value" <<endl; }
};


unique_ptr<B> 
pass_through (unique_ptr<B> p)
{
	p->display();
	return p; // While returning from the function, looks like the move semantics is getting used
}


int 
main (int argc, char *argv[])
{
	cout <<"Checking for emptyness of the unique pointer" <<endl;
	{
		unique_ptr<B> p;
		if (!p)
			cout <<"The unique pointer is empty" <<endl;
	}
	cout <<"Unique ownership semantics demo" <<endl;
	{
		unique_ptr<B> p(new B());
		//p.reset();
		auto q = pass_through(std::move(p));
	}
	cout <<"Runtime polymorphism demo" <<endl;
	{
		unique_ptr<B> p(new B()); 	
		p->display();
		vector<unique_ptr<A>> v;
		v.push_back(unique_ptr<B>(new B()));
		v.push_back(move(p));
		v.emplace_back(new B());
		for (auto &p : v)
			p->display();
	}
	cout <<"Array form of unique pointer demo" <<endl;
	{
		unique_ptr<B[]> p(new B[3]);  // Unique pointer has partial specialization where we can pass array type as a template 
					      // parameter
	}

	return 0;
}
