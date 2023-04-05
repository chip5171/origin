// homework_6_2.cpp : SQLCPP-5 Задание 2

#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>

class Book;
class Stock;
class Shop;
class Sale;

class Publisher {
public:
	std::string name_ = "";
	Wt::Dbo::collection < Wt::Dbo::ptr <Book>> books;

	Publisher() {};
	Publisher(const std::string& name) { this->name_ = name; }

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name_, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}
};

class Book {
public:
	std::string title_ = "";
	Wt::Dbo::ptr <Publisher> publisher_;
	Wt::Dbo::collection < Wt::Dbo::ptr <Stock> > stocks;

	Book() {};
	Book(const std::string& title) { this->title_ = title; }

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, title_, "title");
		Wt::Dbo::belongsTo(a, publisher_, "publisher");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
	}
};

class Stock {
public:
	int count_ = 0;
	Wt::Dbo::ptr <Book> book_;
	Wt::Dbo::ptr <Shop> shop_;
	Wt::Dbo::collection < Wt::Dbo::ptr <Sale> > sales;

	Stock() {};
	Stock(const int& count) { this->count_ = count; }

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, count_, "count");
		Wt::Dbo::belongsTo(a, book_, "book");
		Wt::Dbo::belongsTo(a, shop_, "shop");
		Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
	}
};

class Sale {
public:
	std::string dataSale = "";
	float price_ = 0.00;
	int count_ = 0;
	Wt::Dbo::ptr <Stock> stock_;

	Sale() {};
	Sale(const std::string& data, float const price, const int count) {
		this->dataSale = data;
		this->price_ = price;
		this->count_ = count;
	}

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, dataSale, "data_sale");
		Wt::Dbo::field(a, price_, "price");
		Wt::Dbo::field(a, count_, "count");
		Wt::Dbo::belongsTo(a, stock_, "stock");
	}
};

class Shop {
public:
	std::string name_ = "";
	Wt::Dbo::collection < Wt::Dbo::ptr<Stock> > stocks;

	Shop() {};
	Shop(const std::string& name) { this->name_ = name; }

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name_, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
	}
};

void addRecords(Wt::Dbo::Session& s) {
	Wt::Dbo::Transaction tx(s);
	
	Wt::Dbo::ptr<Publisher> p1 = s.add(std::make_unique<Publisher>("publisher1"));
	Wt::Dbo::ptr<Publisher> p2 = s.add(std::make_unique<Publisher>("publisher2"));
	
	Wt::Dbo::ptr<Book> b1 = s.add(std::make_unique<Book>("book1"));
	Wt::Dbo::ptr<Book> b2 = s.add(std::make_unique<Book>("book2"));
	Wt::Dbo::ptr<Book> b3 = s.add(std::make_unique<Book>("book3"));
	Wt::Dbo::ptr<Book> b4 = s.add(std::make_unique<Book>("book4"));
	Wt::Dbo::ptr<Book> b5 = s.add(std::make_unique<Book>("book5"));

	Wt::Dbo::ptr<Stock> st1 = s.add(std::make_unique<Stock>(20));
	Wt::Dbo::ptr<Stock> st2 = s.add(std::make_unique<Stock>(30));
	Wt::Dbo::ptr<Stock> st3 = s.add(std::make_unique<Stock>(10));
	Wt::Dbo::ptr<Stock> st4 = s.add(std::make_unique<Stock>(5));
	Wt::Dbo::ptr<Stock> st5 = s.add(std::make_unique<Stock>(3));
	Wt::Dbo::ptr<Stock> st6 = s.add(std::make_unique<Stock>(15));

	Wt::Dbo::ptr<Shop> sh1 = s.add(std::make_unique<Shop>("shop1"));
	Wt::Dbo::ptr<Shop> sh2 = s.add(std::make_unique<Shop>("shop2"));

	Wt::Dbo::ptr<Sale> sale1 = s.add(std::make_unique<Sale>("20.03", 150.55, 2));
	Wt::Dbo::ptr<Sale> sale2 = s.add(std::make_unique<Sale>("20.04", 300.00, 5));
	Wt::Dbo::ptr<Sale> sale3 = s.add(std::make_unique<Sale>("20.05", 499.99, 10));

	p1.modify()->books.insert(b1);
	p1.modify()->books.insert(b3);
	p2.modify()->books.insert(b2);
	p2.modify()->books.insert(b4);
	p2.modify()->books.insert(b5);
	
	b1.modify()->stocks.insert(st2);
	b1.modify()->stocks.insert(st2);
	b2.modify()->stocks.insert(st1);
	b2.modify()->stocks.insert(st3);
	b3.modify()->stocks.insert(st4);
	b4.modify()->stocks.insert(st5);
	b5.modify()->stocks.insert(st6);

	sh1.modify()->stocks.insert(st1);
	sh1.modify()->stocks.insert(st2);
	sh1.modify()->stocks.insert(st4);
	sh2.modify()->stocks.insert(st6);
	sh2.modify()->stocks.insert(st3);
	sh2.modify()->stocks.insert(st5);

	st1.modify()->sales.insert(sale1);
	st2.modify()->sales.insert(sale3);
	st3.modify()->sales.insert(sale2);
	st3.modify()->sales.insert(sale3);

	tx.commit();
}

//_____________________________________________________________________________

int main(int argc, char** argv) {
	SetConsoleOutputCP(CP_UTF8);

	try {
		std::string connectionString =
			"host=localhost "
			"port=5432 "
			"dbname=my_dbase2 "
			"user=postgres "
			"password=admin ";

		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session session;
		session.setConnection(std::move(postgres));
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Stock>("stock");
		session.mapClass<Sale>("sale");
		session.mapClass<Shop>("shop");

		session.createTables();
		addRecords(session);
		
		Wt::Dbo::Transaction tx(session);
	    std::string value;
		std::cout << "Enter the publisher's name: " << std::endl;
		std::cin >> value;
		
		Wt::Dbo::ptr<Publisher>pb = session.find<Publisher>().where("name = ?").bind(value);
		for (const auto& b : pb->books) {
			std::string x = b->title_;
			Wt::Dbo::ptr<Book>bks = session.find<Book>().where("title = ?").bind(x);
			std::cout << "The book '"<< bks->title_ << "' is sold in: ";
			for (const auto& i : bks->stocks) {
				Wt::Dbo::ptr <Shop> xs = i->shop_;
				std::cout << xs->name_ << " ";
			}
			std::cout << std::endl;
		}
	}
	catch (Wt::Dbo::Exception& e) {
		std::cout << "Error happened: " << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error happened" << std::endl;
	}
	return 0;
}

