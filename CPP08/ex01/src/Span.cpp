#include "../headers/Span.hpp"

Span::Span() : max_length(0) {
    current_len = 0;
    std::cout << "Default constructor called: Span with max_length set to 0" << std::endl;
}

Span::Span(unsigned int max_length) : max_length(max_length) {

    current_len = 0;
    std::cout << "Parameterized constructor called: Span with max_length set to " << max_length << std::endl;
}

Span::Span(const Span &cls) : max_length(cls.max_length), vector(cls.vector), current_len(cls.current_len) {
    std::cout << "Copy constructor called: copying Span with max_length " << cls.max_length << std::endl;
}

Span& Span::operator=(const Span &cls) {
    if (this != &cls) { // Protect against self-assignment
        std::cout << "Assignment operator called: Assigning Span with new max_length " << cls.max_length << std::endl;
        max_length = cls.max_length;
        vector = cls.vector;
        current_len = cls.current_len;
    } else {
        std::cout << "Assignment operator called: Self-assignment detected" << std::endl;
    }
    return *this;
}

Span::~Span() {
    std::cout << "Destructor called: Cleaning up Span with max_length " << max_length << std::endl;
}

const char *Span::SpanIsFull::what(void) const throw()
{
    return ("Span is Full");
}

const char *Span::SpanTooShort::what(void) const throw()
{
    return ("Span is too short");
}

void Span::checkDist() const {
    if (this ->vector.size() < 2) {
        throw std::logic_error("Not enough elements to determine span.");
    }
}

void Span::addNumber(int number)
{
    if (this -> current_len + 1 > this -> max_length)
        throw SpanIsFull();
    this -> current_len++;
    this -> vector.push_back(number);
    std::sort(this -> vector.begin(), this ->vector.end());
}

void Span::addRange(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end)
{
    for (std::vector<int>::iterator i = begin; i != end; i++)
    {
        addNumber(*i);
    }
    std::cout << "Range insertion is done." << std::endl;
}

unsigned int Span::shortestSpan() const {
    checkDist();
    std::vector<int> sorted_vec(this ->vector);
    std::sort(sorted_vec.begin(), sorted_vec.end());

    unsigned int min_dist = UINT_MAX;
    for (size_t i = 1; i < sorted_vec.size(); i++) {
        unsigned int dist = static_cast<unsigned int>(sorted_vec[i] - sorted_vec[i - 1]);
        if (dist < min_dist) {
            min_dist = dist;
        }
    }
    return min_dist;
}

unsigned int Span::longestSpan() const {
    checkDist();
    int max = *std::max_element(this ->vector.begin(), this ->vector.end());
    int min = *std::min_element(this ->vector.begin(), this ->vector.end());
    return static_cast< int>(max - min);
}