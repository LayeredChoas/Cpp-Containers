/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multimap_iter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:56:03 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:08:00 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#include "../map/node.hpp"
namespace ft
{
	template<typename T, typename p, typename r>
		class multimap_iter
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

				multimap_iter(node<value_type> *n){current = n;};
				multimap_iter(){};
				multimap_iter& operator++(){ current = current->next; return (*this);}
				multimap_iter operator++(int) {multimap_iter tmp = *this; ++(*this); return tmp;}
				multimap_iter& operator--(){ current = current->prev; return (*this);}
				multimap_iter operator--(int) {multimap_iter tmp = *this; --(*this); return tmp;}
				multimap_iter& operator=(multimap_iter const &a){ current = a.ptr(); return (*this);}
				T &operator*(){return (current->_value);};
				node<value_type> *next_ptr(){return (current->next);}
				node<value_type> *prev_ptr(){return (current->prev);}
				node<value_type> *ptr() const {return (current);}
				value_type* operator->(){return (&current->_value);};
				template<typename X, typename Y, typename Z>
					friend bool operator==(multimap_iter const &h, multimap_iter<X, Y, Z> const &x){return (h.current == x.current);}
				template<typename X, typename Y, typename Z>
					friend bool operator!=(multimap_iter const &h, multimap_iter<X, Y, Z> const &x){return !(h.current == x.current);}
		};
	template<typename T, typename p, typename r>
		class multimap_rev_iter
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

				multimap_rev_iter(node<value_type> *n){current = n;};
				multimap_rev_iter(){};
				multimap_rev_iter& operator++(){ current = current->prev; return (*this);}
				multimap_rev_iter operator++(int) {multimap_rev_iter tmp = *this; ++(*this); return tmp;}
				multimap_rev_iter& operator--(){ current = current->next; return (*this);}
				multimap_rev_iter operator--(int) {multimap_rev_iter tmp = *this; --(*this); return tmp;}
				multimap_rev_iter& operator=(multimap_rev_iter const &a){ current = a.ptr(); return (*this);}
				node<value_type> *next_ptr(){return (current->next);}
				node<value_type> *prev_ptr(){return (current->prev);}
				T &operator*(){return (current->_value);};
				node<value_type> *ptr() const {return (current);}
				value_type* operator->(){return (&current->_value);};
				template<typename X, typename Y, typename Z>
					friend bool operator==(multimap_rev_iter const &h, multimap_rev_iter<X, Y, Z> const &x){return (h.current == x.current);}
				template<typename X, typename Y, typename Z>
					friend bool operator!=(multimap_rev_iter const &h, multimap_rev_iter<X, Y, Z> const &x){return !(h.current == x.current);}
		};
}
