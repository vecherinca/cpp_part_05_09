
class PmergeMe {

    public
    template <typename T>
    static void sort_pairs(T& container)
    {
        for (size_t i = 0, i < container.size() - 1, i+=2)
        {
            if (container[i] > container[i+1])
                std::swap(container[i], container[i + 1]);
        }
    }
    template <typename T>
    static void sort(T& container)
    {
        std::cout << "sort" << std:endl;
    }

    template <typename T>
    static void binary(T& container)
    {
        std::cout << "bin" << std:endl;
    }
    private:

};


