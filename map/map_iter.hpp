/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:18:11 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:05:00 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "node.hpp"
namespace ft
{
	template<typename T, typename p, typename r>
		class map_iter
		{
			private:
				node<T> *current;
			public:
				typedef T                   			value_type;
				typedef T&								reference;
				typedef ptrdiff_t						difference_type;
				typedef value_type*						pointer;
				typedef const value_type*				const_pointer;
				typedef std::bidirectional_iterator_tag iterator_category;

				map_iter(node<value_type> *n){current = n;};
				map_iter(){};
				map_iter& operator++(){ current = current->next; return (*this);}
				map_iter operator++(int) {map_iter tmp = *this; ++(*this); return tmp;}
				map_iter& operator--(){ current = current->prev; return (*this);}
				map_iter operator--(int) {map_iter tmp = *this; --(*this); return tmp;}
				map_iter& operator=(map_iter const &a){ current = a.ptr(); return (*this);}
				T &operator*(){return (current->_value);};
				node<value_type> *next_ptr(){return (current->next);}
				node<value_type> *prev_ptr(){return (current->prev);}
				node<value_type> *ptr() const {return (current);}
				value_type* operator->(){return (&current->_value);};
				template<typename X, typename Y, typename Z>
					friend bool operator==(map_iter const &h, map_iter<X, Y, Z> const &x){return (h.current == x.current);}
				template<typename X, typename Y, typename Z>
					friend bool operator!=(map_iter const &h, map_iter<X, Y, Z> const &x){return !(h.current == x.current);}
		};
	template<typename T, typename p, typename r>
		class map_rev_iter
		{
			private:
				node<T> *current;
			public:
				typedef T                   			value_type;
				typedef T&								reference;
				typedef ptrdiff_t						difference_type;
				typedef value_type*						pointer;
				typedef const value_type*				const_pointer;
				typedef std::bidirectional_iterator_tag iterator_category;

				map_rev_iter(node<value_type> *n){current = n;};
				map_rev_iter(){};
				map_rev_iter& operator++(){ current = current->prev; return (*this);}
				map_rev_iter operator++(int) {map_rev_iter tmp = *this; ++(*this); return tmp;}
				map_rev_iter& operator--(){ current = current->next; return (*this);}
				map_rev_iter operator--(int) {map_rev_iter tmp = *this; --(*this); return tmp;}
				map_rev_iter& operator=(map_rev_iter const &a){ current = a.ptr(); return (*this);}
				node<value_type> *next_ptr(){return (current->next);}
				node<value_type> *prev_ptr(){return (current->prev);}
				T &operator*(){return (current->_value);};
				node<value_type> *ptr() const {return (current);}
				value_type* operator->(){return (&current->_value);};
				template<typename X, typename Y, typename Z>
					friend bool operator==(map_rev_iter const &h, map_rev_iter<X, Y, Z> const &x){return (h.current == x.current);}
				template<typename X, typename Y, typename Z>
					friend bool operator!=(map_rev_iter const &h, map_rev_iter<X, Y, Z> const &x){return !(h.current == x.current);}
		};
}
