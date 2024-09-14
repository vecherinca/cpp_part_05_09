#ifndef EASYFIND_HPP
#define EASYFIND_HPP

        #include <limits.h>
        #include <algorithm>
        #include <iostream>
        #include <iterator>
        #include <stdexcept>
        #include <vector>

        class Span
        {
            private: 
                unsigned int max_length;
                std::vector<int> vector;
                unsigned int current_len;
            public:
                Span();
                Span(unsigned int max_length);
                Span(const Span &cls);
                Span &operator=(const Span &cls);
                ~Span();
                void addNumber(int number);
                void addRange(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end);
                unsigned int shortestSpan( void ) const;
                unsigned int longestSpan( void ) const;
                void checkDist() const;
                class SpanIsFull: public std::exception
                {
                    public:
                        virtual const char *what() const throw();
                };
                class SpanTooShort: public std::exception
                {
                    public:
                        virtual const char *what() const throw();
                };
            };
        #endif