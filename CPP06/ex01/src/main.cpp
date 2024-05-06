#include "../headers/Serializer.hpp"
int main() {
    Data myData;
    myData.str = "Hello, World!";
    myData.i = 100;
	
    uintptr_t serializedData = Serializer::serialize(&myData);
    std::cout << "Serialized Data Pointer: " << serializedData << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized Data String: " << deserializedData->str << std::endl;
    std::cout << "Deserialized Data Integer: " << deserializedData->i << std::endl;

    return 0;
}