/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:43:00 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:44:29 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque/deque.hpp"
#include <deque>

void ft_print_deque(ft::deque<int> x)
{
	ft::deque<int>::iterator it = x.begin();
	while (it != x.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

int main()
{
	ft::deque<int> first;                                // empty deque of ints
	ft::deque<int> second (4,100);                       // four ints with value 100
	ft::deque<int> third (second.begin(),second.end());  // iterating through second
	ft::deque<int> fourth (third);                       // a copy of third
	ft::deque<int>::reverse_iterator rit;

	// Iterator
    // begin:
    std::cout << "--------begin--------" << std::endl;
    std::cout << *second.begin() << std::endl;

    // end:
    std::cout << "--------end--------" << std::endl;
    std::cout << *second.end() << std::endl;

    // rbegin:
    std::cout << "--------rbegin--------" << std::endl;
    std::cout << *second.rbegin() << std::endl;

    // rend:
    std::cout << "--------rend--------" << std::endl;
    std::cout << *second.rend() << std::endl;
	
	// size:
    std::cout << "\n--------size--------" << std::endl;
    std::cout << second.size() << std::endl;
    
    // max_size:
    std::cout << "\n--------max_size--------" << std::endl;
    std::cout << second.max_size() << std::endl;

    // resize:
    std::cout << "\n--------resize--------" << std::endl;
    second.resize(10, 50);
	ft_print_deque(second);
	std::cout << "size: " << second.size() << std::endl;

    // empty:
    std::cout << "\n--------empty--------" << std::endl;
    std::cout << second.empty() << std::endl;

	// Element access:
    // operator[]:
    std::cout << "\n--------operator[]--------" << std::endl;
	std::cout << second[0] << std::endl;
	std::cout << second[8] << std::endl;

    // at:
    std::cout << "\n--------at--------" << std::endl;
	std::cout << second.at(0) << std::endl;
	std::cout << second.at(8) << std::endl;

    // front and back:
    std::cout << "\n--------front and back--------" << std::endl;
	std::cout << "front: " << second.front() << std::endl;
	std::cout << "back: " << second.back() << std::endl;

    // assign:
    std::cout << "\n--------assign--------" << std::endl;
	std::cout << "\n--------assign(iter)--------" << std::endl;
	first.assign(second.begin(), second.end());
	ft_print_deque(first);
	std::cout << "\n--------assign(n, val)--------" << std::endl;
	first.assign(5, -3);
	ft_print_deque(first);

    // push_back:
    std::cout << "\n--------push_back--------" << std::endl;
	first.push_back(1);
	std::cout <<first.back() << std::endl;

    // push_front:
    std::cout << "\n--------push_front--------" << std::endl;
	first.push_front(-1);
	std::cout <<first.front() << std::endl;

    // pop_back and pop_front:
    std::cout << "\n--------pop_back and pop_front--------" << std::endl;
	first.pop_back();
	first.pop_front();
	ft_print_deque(first);

    // insert:
    std::cout << "\n--------insert--------" << std::endl;
	std::cout << "\n--------insert(pos, val)--------" << std::endl;
	first.insert(first.begin(), 2021);
	ft_print_deque(first);
	std::cout << "\n--------insert(pos, n, val)--------" << std::endl;
	first.insert(first.end(), 5, -6);
	ft_print_deque(first);
	std::cout << "\n--------insert(pos, iter, iter)--------" << std::endl;
	first.insert(first.begin(),second.begin(), second.end());
	ft_print_deque(first);

	// erase:
    std::cout << "\n--------erase--------" << std::endl;
	std::cout << "\n--------erase(pos)--------" << std::endl;
	first.erase(first.begin());
	ft_print_deque(first);
	std::cout << "\n--------erase(iter, iter)--------" << std::endl;
	first.erase(first.begin(), first.end());
	ft_print_deque(first);

	// swap:
	std::cout << "\n--------swap--------" << std::endl;
	first.swap(second);
	std::cout << "\n--------deque first--------" << std::endl;
	ft_print_deque(first);
	std::cout << "\n--------deque second--------" << std::endl;
	ft_print_deque(second);

	// clear:
	std::cout << "\n--------clear--------" << std::endl;
	first.clear();
	std::cout << "\n--------deque first--------" << std::endl;
	ft_print_deque(first);

  ft::deque<std::string> mydeque(5, "hats");
  ft::deque<std::string> otherdeque(5, "hats");

  if (mydeque == otherdeque)
    std::cout << "\tmydeque == otherdeque" << std::endl;
  else
    std::cout << "NOT\tmydeque == otherdeque" << std::endl;

  if (mydeque != otherdeque)
    std::cout << "\tmydeque != otherdeque" << std::endl;
  else
    std::cout << "NOT\tmydeque != otherdeque" << std::endl;

  if (mydeque < otherdeque)
    std::cout << "\tmydeque < otherdeque" << std::endl;
  else
    std::cout << "NOT\tmydeque < otherdeque" << std::endl;

  if (mydeque > otherdeque)
    std::cout << "\tmydeque > otherdeque" << std::endl;
  else
    std::cout << "NOT\tmydeque > otherdeque" << std::endl;

  if (mydeque >= otherdeque)
    std::cout << "\tmydeque >= otherdeque" << std::endl;
  else
    std::cout << "NOT\tmydeque >= otherdeque" << std::endl;
  if (mydeque <= otherdeque)
    std::cout << "\tmydeque <= otherdeque" << std::endl;
  else
    std::cout << "NOT\tmydeque <= otherdeque" << std::endl;
	return (0);
}
