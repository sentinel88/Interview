/* We can have a map inside the singleton factory class to store a collection of interface name and their interface create function pointers */

// Abstract Interface Class
class Interface
{
	public:
		virtual int getValue() const = 0;
		virtual void print() = 0;
		virtual void free() = 0;
};

class IA : public Interface
{
	public:
		virtual void print() { std::cout <<"IA Interface" <<endl; }
		virtual int getValue() { return 4; }
		virtual void free() { delete this; }
		static IA * Create() { return new IA(); }
};

class IB : public Interface
{
	public:
		virtual void print() { std::cout <<"IB Interface" <<endl; }
		virtual int getValue() { return 4; }
		virtual void free() { delete this; }
		static IB * Create() { return new IB(); }
};

// Singleton Factory Class
class Factory
{
	public:
		static Factory& getInstance();
		Interace *createInterface(const std::string&);
	private:
		Factory();
		Factory(const Factory&);
		Factory& operator=(const Factory&);
};
