/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:24:47 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:48:00 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.hpp"
#include <map>

	template<typename T1, typename T2>
void ft_print_pair(ft::pair<T1, T2> x)
{
	std::cout << "First: " << x.first << "\t\t" << "Second: " << x.second << std::endl;
}

void ft_print_map(ft::map<int, int> x)
{
	ft::map<int, int>::iterator it = x.begin(); 
	for (; it != x.end(); it++)
		std::cout << "First: " << it->first << "\t" << "Second: " << it->second << std::endl;

}
int main()
{
	ft::map<int, int> x;
	ft::pair<int, int> p(0, 2);
	ft::map<int, int>::iterator it;

	// begin:
	std::cout << "--------begin--------" << std::endl;
	std::cout << x.begin()->first << std::endl;

	// end:
	std::cout << "--------end--------" << std::endl;
	std::cout << x.end()->first << std::endl;

	// rbegin:
	std::cout << "--------rbegin--------" << std::endl;
	std::cout << x.rbegin()->first << std::endl;

	// rend:
	std::cout << "--------rend--------" << std::endl;
	std::cout << x.rend()->first << std::endl;

	// empty:
	std::cout << "--------empty--------" << std::endl;
	std::cout << x.empty() << std::endl;

	// size:
	std::cout << "--------size--------" << std::endl;
	std::cout << x.size() << std::endl;

	// max_size:
	std::cout << "--------max_size--------" << std::endl;
	std::cout << x.max_size() << std::endl;

	// operator[]:
	std::cout << "--------operator[]--------" << std::endl;
	std::cout << x[0] << std::endl;
    std::cout << x[5] << std::endl;

    std::cout << x.size() << std::endl;
	// insert:
	std::cout << "--------insert--------" << std::endl;
	x.insert(p);
	x.insert(ft::make_pair(3, 4));
	x.insert(ft::make_pair(10, 12));
	x.insert(ft::make_pair(-1, 4));
	ft_print_map(x);
	std::cout << "--------insert(pos)--------" << std::endl;
	x.insert(x.begin(), ft::make_pair(100, 4));
	ft_print_map(x);

	// erase:
	std::cout << "--------erase--------" << std::endl;
	x.erase(1);
	ft_print_map(x);
	std::cout << "--------erase(iter)--------" << std::endl;
	x.erase(x.begin());
	ft_print_map(x);

	// swap:
	std::cout << "--------swap--------" << std::endl;
	ft::map<int, int> y;

	y.swap(x);
	std::cout << "--------map y--------" << std::endl;
	ft_print_map(y);
	std::cout << "--------map x--------" << std::endl;
	ft_print_map(x);

	// key_comp:
	std::cout << "--------key_comp--------" << std::endl;
	ft::map<int,int>::key_compare mycomp = x.key_comp();
	std::cout << mycomp(1, 2) << std::endl;

	// value_comp:
	std::cout << "--------value_comp--------" << std::endl;
	it = y.begin();
	ft::pair<int, int> hi = *y.rbegin();
	it = y.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( y.value_comp()(*it++, hi) );

	// find:
	std::cout << "--------find--------" << std::endl;
	it = y.find(100);
	ft_print_pair(*it);
	it = y.find(-5555);
	ft_print_pair(*it);

	// count:
	std::cout << "--------count--------" << std::endl;
	std::cout << y.count(10) << std::endl;

	// lower_bound:
	std::cout << "--------lower_bound--------" << std::endl;
	it = y.lower_bound(10);
	ft_print_pair(*it);

	// upper_bound:
	std::cout << "--------upper_bound--------" << std::endl;
	it = y.upper_bound(1);
	ft_print_pair(*it);

	// equal_range:
	std::cout << "--------equal_range--------" << std::endl;
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> p2;
	p2 = y.equal_range(3);

	std::cout << "lower bound points to: ";
	std::cout << p2.first->first << " => " << p2.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << p2.second->first << " => " << p2.second->second << '\n';

    // Loop
    // iter++:
	std::cout << "--------iter++--------" << std::endl;
    it = y.begin();
    for (; it != y.end(); it++)
        std::cout << it->first  << std::endl;
    // iter--:
	std::cout << "--------iter(--)--------" << std::endl;
    it = y.end();
    for (; it != y.begin(); it--)
        std::cout << it->first  << std::endl;
    std::cout << it->first  << std::endl;

    //reverse_iter++
	std::cout << "--------reverse_iter++--------" << std::endl;
    ft::map<int, int>::reverse_iterator rit;
    rit = y.rbegin();
    for (; rit != y.rend(); rit++)
        std::cout << rit->first  << std::endl;
    //reverse_iter--
	std::cout << "--------reverse_iter(--)--------" << std::endl;
    rit = y.rend();
    for (; rit != y.rbegin(); rit--)
        std::cout << rit->first  << std::endl;
    std::cout << rit->first  << std::endl;

	std::cout << "\n----------------- relational operators (map)" << std::endl;

ft::map<char,int> foo,bar;
  foo['a']=100;
  foo['b']=200;
  bar['a']=10;
  bar['z']=1000;

  // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	return (0);
}
