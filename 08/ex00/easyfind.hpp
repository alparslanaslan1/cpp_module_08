#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm> // std::find



template <typename T>

typename T::const_iterator easyfind(const T& container, typename T::value_type value){
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw std::runtime_error("value not found in container");

    return (it);
}

#endif


