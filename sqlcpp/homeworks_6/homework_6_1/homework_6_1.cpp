// homework_6_1.cpp : SQLCPP-5 Задание 1

#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

class Book;
class Stock;
class Shop;
class Sale;

class Publisher {
public:
	std::string name = "";
	Wt::Dbo::collection < Wt::Dbo::ptr <Book> > books;
	
	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}
};

class Book {
public:
	std::string title = "";
	Wt::Dbo::ptr <Publisher> publisher;
	Wt::Dbo::collection < Wt::Dbo::ptr <Stock> > stocks;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, publisher, "publisher");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
	}
};

class Stock {
public:
	int count = 0;
	Wt::Dbo::ptr <Book> book;
	Wt::Dbo::ptr <Shop> shop;
	Wt::Dbo::collection < Wt::Dbo::ptr <Sale> > sales;
	
	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, book, "book");
		Wt::Dbo::belongsTo(a, shop, "shop");
		Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
	}
};

class Sale {
public:
	std::string dateSale = "";
	float price = 0.00;
	int count = 0;
	Wt::Dbo::ptr <Stock> stock;
	
	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, dateSale, "date_sale");
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, stock, "stock");
	}
};

class Shop {
public:
	std::string name = "";
	Wt::Dbo::collection < Wt::Dbo::ptr<Stock> > stocks;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
	}
};

//_____________________________________________________________________________

int main(int argc, char** argv) {
	setlocale(LC_ALL, "ru_RU.UTF-8");

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

	}
	catch (Wt::Dbo::Exception& e) {
		std::cout << "Error happened: " << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error happened" << std::endl;
	}
	return 0;
}