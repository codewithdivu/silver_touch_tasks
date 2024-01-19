#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
public:
    string title;

    Movie(const string& t) : title(t) {}
};

class Customer {
public:
    string name;

    Customer(const string& n) : name(n) {}
};

class Ticket {
public:
    Movie* movie;
    Customer* customer;

    Ticket(Movie* m, Customer* c) : movie(m), customer(c) {}
};

class Cinema {
private:
    vector<Movie> movies;
    vector<Customer> customers;
    vector<Ticket> bookings;

public:
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    Ticket bookTicket(Movie* movie, Customer* customer) {
        bookings.emplace_back(movie, customer);
        cout << customer->name << " booked a ticket for " << movie->title << "." << endl;
        return bookings.back();
    }

    void cancelBooking(const Ticket& ticket) {
        // Implement cancellation logic
        cout << ticket.customer->name << "'s booking for " << ticket.movie->title << " canceled." << endl;
    }
};

int main() {
    Cinema cinema;

    Movie movie1("The Avengers");
    Movie movie2("Inception");

    Customer customer1("Alice");
    Customer customer2("Bob");

    cinema.addMovie(movie1);
    cinema.addMovie(movie2);

    cinema.addCustomer(customer1);
    cinema.addCustomer(customer2);

    Ticket ticket1 = cinema.bookTicket(&movie1, &customer1);
    Ticket ticket2 = cinema.bookTicket(&movie2, &customer2);

    cinema.cancelBooking(ticket1);

    return 0;
}
