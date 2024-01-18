#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Movie
{
public:
    string title;
    int duration; 

    Movie(const string &t, int d) : title(t), duration(d) {}
};

class Theater
{
public:
    string name;
    unordered_map<int, vector<Movie>> showtimes; 

    Theater(const string &n) : name(n) {}

    void addMovie(int date, const Movie &movie)
    {
        showtimes[date].push_back(movie);
    }

    void displayMovies(int date)
    {
        auto it = showtimes.find(date);
        if (it != showtimes.end())
        {
            cout << "Movies playing at " << name << " on " << date << ":\n";
            for (const auto &movie : it->second)
            {
                cout << "- " << movie.title << " (" << movie.duration << " mins)\n";
            }
        }
        else
        {
            cout << "No movies found for the selected date.\n";
        }
    }
};

class BookingSystem
{
public:
    unordered_map<string, Theater> theaters;
    void addTheater(const string &theaterName)
    {
        theaters.emplace(theaterName, Theater(theaterName));
    }

    void bookTicket(const string &theaterName, int date, const string &movieTitle)
    {
        auto it = theaters.find(theaterName);
        if (it != theaters.end())
        {
            auto theater = it->second;
            auto showtimeIt = theater.showtimes.find(date);
            if (showtimeIt != theater.showtimes.end())
            {
                auto movies = showtimeIt->second;
                for (const auto &movie : movies)
                {
                    if (movie.title == movieTitle)
                    {
                        cout << "Ticket booked for " << movie.title << " at " << theater.name << " on " << date << ". Enjoy the show!\n";
                        return;
                    }
                }
                cout << "Movie not found for the selected date.\n";
            }
            else
            {
                cout << "No showtimes found for the selected date.\n";
            }
        }
        else
        {
            cout << "Theater not found.\n";
        }
    }
};

int main()
{
    BookingSystem bookingSystem;

    bookingSystem.addTheater("Cineplex");
    bookingSystem.addTheater("Star Movies");

    Movie movie1("Avengers: Endgame", 180);
    Movie movie2("Inception", 150);

    bookingSystem.theaters["Cineplex"].addMovie(20240101, movie1);
    bookingSystem.theaters["Cineplex"].addMovie(20240101, movie2);

    bookingSystem.theaters["Star Movies"].addMovie(20240101, movie1);

    bookingSystem.bookTicket("Cineplex", 20240101, "Avengers: Endgame");
    bookingSystem.bookTicket("Cineplex", 20240101, "Inception");
    bookingSystem.bookTicket("Star Movies", 20240101, "Inception");

    return 0;
}
