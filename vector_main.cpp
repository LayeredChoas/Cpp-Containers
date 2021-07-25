/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:28:37 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:51:54 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <vector>


template<typename T>
void ft_print_vector(ft::vector<T> x)
{
    size_t i;

    i = 0;
    while (i < x.size())
    {
        std::cout << x[i] << std::endl;
        i++;
    }
}

int main()
{
    ft::vector<int> x;
    ft::vector<int> ret(5, 10);
    ft::vector<int>::iterator it;
    ft::vector<int>::reverse_iterator rit;

    // Iterator
    // begin:
    std::cout << "--------begin--------" << std::endl;
    std::cout << *ret.begin() << std::endl;

    // end:
    std::cout << "--------end--------" << std::endl;
    std::cout << *ret.end() << std::endl;

    // rbegin:
    std::cout << "--------rbegin--------" << std::endl;
    std::cout << *ret.rbegin() << std::endl;

    // rend:
    std::cout << "--------rend--------" << std::endl;
    std::cout << *ret.rend() << std::endl;

    // loop:
    std::cout << "----------------loop----------------" << std::endl;
    ret.clear();
    ret.push_back(1);
    ret.push_back(2);
    ret.push_back(3);
    std::cout << "--------iterator++--------" << std::endl;
    it = ret.begin();
    for (; it != ret.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "--------reverse_iterator++--------" << std::endl;
    rit = ret.rbegin();
    for (; rit != ret.rend(); rit++)
        std::cout << *rit << std::endl;
    std::cout << "--------iterator(--)--------" << std::endl;
    it = ret.end();
    it--;
    for (; it != ret.begin(); it--)
        std::cout << *it << std::endl;
    std::cout << *it << std::endl;
    std::cout << "--------reverse_iterator(--)--------" << std::endl;
    rit = ret.rend();
    rit--;
    for (; rit != ret.rbegin(); rit--)
        std::cout << *rit << std::endl;
    std::cout << *rit << std::endl;


    // size:
    std::cout << "\n--------size--------" << std::endl;
    std::cout << x.size() << std::endl;
    
    // max_size:
    std::cout << "\n--------max_size--------" << std::endl;
    std::cout << x.max_size() << std::endl;

    // resize
    std::cout << "\n--------resize--------" << std::endl;
    x.resize(3, 1);
    ::ft_print_vector(x);

    // capacity
    std::cout << "\n--------capacity--------" << std::endl;
    std::cout << x.capacity() << std::endl;

    // empty
    std::cout << "\n--------empty--------" << std::endl;
    std::cout << x.empty() << std::endl;

    // reserve
    std::cout << "\n--------reserve--------" << std::endl;
    x.reserve(10);
    std::cout << x.capacity() << std::endl;

    // operator
    std::cout << "\n--------operator[]--------" << std::endl;
    std::cout << x[0] << std::endl;

    // at
    std::cout << "\n--------at()--------" << std::endl;
    std::cout << x.at(1) << std::endl;

    // front and back
    x.push_back(203);
    std::cout << "\n--------front and back--------" << std::endl;
    std::cout << x.front() << std::endl;
    std::cout << x.back() << std::endl;

    // assign
    ft::vector<int> y;
    std::cout << "\n--------assign(iter, iter)--------" << std::endl;
    y.assign(x.begin(), x.end());
    ft_print_vector(y);
    std::cout << "\n--------assign(num, value)--------" << std::endl;
    y.assign(5, 10);
    ft_print_vector(y);

    // push_back
    x.push_back(33);
    std::cout << "\n--------push_back--------" << std::endl;
    std::cout << x.back() << std::endl;

    // pop_back
    std::cout << "\n--------pop_back--------" << std::endl;
    x.pop_back();
    std::cout << x.back() << std::endl;

    // insert
    std::cout << "\n--------insert--------" << std::endl;
    x.insert(x.begin(), 2021);
    ft_print_vector(x);
    std::cout << "\n--------insert(3)--------" << std::endl;
    x.insert(x.end(), 5, 0);
    ft_print_vector(x);
    std::cout << "\n--------insert(iter)--------" << std::endl;
    y.clear();
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    x.insert(x.begin(), y.begin(), y.end());
    ft_print_vector(x);

    // erase
    std::cout << "\n--------erase--------" << std::endl;
    x.erase(x.begin());
    ft_print_vector(x);
    std::cout << "\n--------erase(iter)--------" << std::endl;
    ft::vector<int>::iterator it1 = x.begin();
    it1++;
    it1++;
    it1++;
    x.erase(x.begin(), it1);
    ft_print_vector(x);

    // swap
    std::cout << "\n--------swap--------" << std::endl;
    x.swap(y);
    ft_print_vector(x);

    // clear
    std::cout << "\n--------clear--------" << std::endl;
    x.clear();
    y.clear();
    std::cout << x.size() << std::endl;

    // relational operators
    if (x == y)
        std::cout << "vectors are equal" << std::endl;
    x.push_back(1);
    y.push_back(2);
    if (x != y)
        std::cout << "vectors are not equal" << std::endl;
    if (x > y)
         std::cout << "x is greater than y" << std::endl;
    if (x >= y)
         std::cout << "x is greater or equal to y" << std::endl;
    if (x < y)
         std::cout << "y is greater than x" << std::endl;
    if (x <= y)
         std::cout << "y is greater or equal to x" << std::endl;
         
    // swap
    std::cout << "\n--------swap--------" << std::endl;
    ft::swap(x, y);
    std::cout << "vector x:" << std::endl;
    ft_print_vector(x);
    std::cout << "vector y:" << std::endl;
    ft_print_vector(y);
    return (0);
}