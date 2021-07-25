/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:19:01 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/01 16:08:34 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list/list.hpp"
#include <list>
#include <cmath>

void print_list(ft::list<int> a)
{
    ft::list<int>::iterator it = a.begin();
    while (it != a.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
}

void print_list(ft::list<std::string> a)
{
    ft::list<std::string>::iterator it = a.begin();
    while (it != a.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
}

struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};
int main()
{
    ft::list<int> x;

    ft::list<int> x1;
    ft::list<int> y(5, 10);
    ft::list<int> z(y.begin(), y.end());
    ft::list<int> z1(z);

    std::cout << "Begin" << std::endl;
    std::cout << *x.begin() << std::endl;
    std::cout << *y.begin() << std::endl;
    std::cout << *z.begin() << std::endl;
    std::cout << *z1.begin() << std::endl;

    // end
    std::cout << "\nEnd" << std::endl;
    std::cout << *x.end() << std::endl;
    std::cout << *y.end() << std::endl;
    std::cout << *z.end() << std::endl;
    std::cout << *z1.end() << std::endl;

    // rbegin
    std::cout << "\nrBegin" << std::endl;
    std::cout << *x.rbegin() << std::endl;
    std::cout << *y.rbegin() << std::endl;
    std::cout << *z.rbegin() << std::endl;
    std::cout << *z1.rbegin() << std::endl;

    // rend
    std::cout << "\nrend" << std::endl;
    std::cout << *x.rend() << std::endl;
    std::cout << *y.rend() << std::endl;
    std::cout << *z.rend() << std::endl;
    std::cout << *z1.rend() << std::endl;

    // empty
    std::cout << "\nempty" << std::endl;
    std::cout << x.empty() << std::endl;
    std::cout << y.empty() << std::endl;
    std::cout << z.empty() << std::endl;
    std::cout << z1.empty() << std::endl;

    // size
    std::cout << "\nsize" << std::endl;
    std::cout << x.size() << std::endl;
    std::cout << y.size() << std::endl;
    std::cout << z.size() << std::endl;
    std::cout << z1.size() << std::endl;

    // max_size
    std::cout << "\nmax_size" << std::endl;
    std::cout << x.max_size() << std::endl;

    // front
    std::cout << "\nfront" << std::endl;
    std::cout << x.front() << std::endl;
    std::cout << y.front() << std::endl;
    std::cout << z.front() << std::endl;
    std::cout << z1.front() << std::endl;

    // back
    std::cout << "\nback" << std::endl;
    std::cout << x.back() << std::endl;
    std::cout << y.back() << std::endl;
    std::cout << z.back() << std::endl;
    std::cout << z1.back() << std::endl;

    // assign
    std::cout << "\nassign" << std::endl;
    x.assign(6, -5);
    y.assign(x.begin(), x.end());
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    // pusH_front
    std::cout << "\npush_front, push_back, front and back" << std::endl;
    y.push_front(-1);
    y.push_back(-22222);
    std::cout << "front: " << y.front() << "  back:" << y.back() << std::endl;


    std::cout << "\npop" << std::endl;
    y.pop_front();
    y.pop_back();
    std::cout << "front: " << y.front() << "  back:" << y.back() << std::endl;


    // insert
    std::cout << "\ninsert" << std::endl;
    x.insert(x.begin(), 555);
    y.insert(y.begin(), x.begin(), x.end());
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    // clear
    std::cout << "\nclear" << std::endl;
    x.clear();
    std::cout << "-----list x------" << std::endl;
    print_list(x);

    // erase
    std::cout << "\nerase" << std::endl;
    x.push_back(1);
    x.push_back(2);
    x.push_front(3);
    x.push_front(4);
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    x.erase(++x.begin());
    std::cout << "-----list x------" << std::endl;
    print_list(x);

    // swap
    std::cout << "\nswap" << std::endl;
    x.swap(y);
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    // resize
    std::cout << "\nresize" << std::endl;
    y.resize(10, 50);
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    // splice
    std::cout << "\nsplice" << std::endl;
    x.clear();
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);

    y.splice(y.begin(), x);
    std::cout << "-----list y------" << std::endl;
    print_list(y);
    std::cout << "-----list x------" << std::endl;
    print_list(x);

    // remove
    std::cout << "\nremove" << std::endl;
    y.remove(50);
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    // remove_if
    std::cout << "\nremove if" << std::endl;
    y.remove_if(is_odd());
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    // unique
    std::cout << "\nunique" << std::endl;
    y.clear();
    
    print_list(y);
    y.push_back(1);
    y.push_back(1);
    y.push_back(2);
    y.push_back(2);
    y.push_back(0);
    y.push_back(1);
    y.unique(same_integral_part);
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    // sort
    std::cout << "\nsort" << std::endl;
    y.clear();
    print_list(y);
    y.push_back(1);
    y.push_back(1);
    y.push_back(2);
    y.push_back(2);
    y.push_back(0);
    y.push_back(1);
    y.sort();
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    // merge
    std::cout << "\nmerge" << std::endl;
    y.clear();

    x.clear();

    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    y.assign(5, 10);
    x.merge(y);
    std::cout << "-----list x------" << std::endl;
    print_list(x);
    std::cout << "-----list y------" << std::endl;
    print_list(y);

    // reverse
    std::cout << "\nreverse" << std::endl;
    x.reverse();
    std::cout << "-----list x------" << std::endl;
    print_list(x);

  ft::list<std::string> myList(5, "hats");
  ft::list<std::string> otherList(5, "hats");

  if (myList == otherList)
    std::cout << "\tmylist == otherlist" << std::endl;
  else
    std::cout << "NOT\tmylist == otherlist" << std::endl;

  if (myList != otherList)
    std::cout << "\tmylist != otherlist" << std::endl;
  else
    std::cout << "NOT\tmylist != otherlist" << std::endl;

  if (myList < otherList)
    std::cout << "\tmylist < otherlist" << std::endl;
  else
    std::cout << "NOT\tmylist < otherlist" << std::endl;

  if (myList > otherList)
    std::cout << "\tmylist > otherlist" << std::endl;
  else
    std::cout << "NOT\tmylist > otherlist" << std::endl;

  if (myList >= otherList)
    std::cout << "\tmylist >= otherlist" << std::endl;
  else
    std::cout << "NOT\tmylist >= otherlist" << std::endl;
  if (myList <= otherList)
    std::cout << "\tmylist <= otherlist" << std::endl;
  else
    std::cout << "NOT\tmylist <= otherlist" << std::endl;
    return (0);
}