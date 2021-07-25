/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:43:02 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:10:02 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once

#ifndef LIST_ITR_HPP
#define LIST_ITR_HPP
#include <iostream>
#include "node.hpp"
namespace ft
{
	template<typename T, typename P, typename R>
		class list_iter
		{     
			public:
				typedef T								value_type;
				typedef ptrdiff_t						difference_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef std::bidirectional_iterator_tag iterator_category;
				list_iter (node<T> *n):current(n){};
				list_iter (){}
				list_iter& operator++(){ current = current->next; return (*this);}
				list_iter operator++(int) {list_iter tmp = *this; ++(*this); return tmp;}
				list_iter& operator--(){ current = current->prev; return (*this);}
				list_iter operator--(int) {list_iter tmp = *this; --(*this); return tmp;}
				T & operator*(){ return (current->value);}
				node<T> *next_ptr(){return (current->next);}
				node<T> *prev_ptr(){return (current->prev);}
				node<T> *ptr() const {return (current);}
				list_iter& operator=(list_iter const &a){ current = a.current; return (*this);}
				node<T> *current;

				template <typename T1, typename P1, typename R1>
					friend bool operator== (const list_iter& lhs, const list_iter<T1, P1, R1>& rhs){return (lhs.current == rhs.current);};
				template <typename T1, typename P1, typename R1>
					friend bool operator!= (const list_iter& lhs, const list_iter<T1, P1, R1>& rhs){return (lhs.current != rhs.current);};
		};
	template <typename T, typename P, typename R>
		bool operator<  (const list_iter<T, P, R>& lhs, const list_iter<T, P, R>& rhs){return (lhs.current < rhs.current);};
	template <typename T, typename P, typename R>
		bool operator<= (const list_iter<T, P, R>& lhs, const list_iter<T, P, R>& rhs){return (!(lhs < rhs));};
	template <typename T, typename P, typename R>
		bool operator>  (const list_iter<T, P, R>& lhs, const list_iter<T, P, R>& rhs){
			return (rhs < lhs);}
	template <typename T, typename P, typename R>
		bool operator>= (const list_iter<T, P, R>& lhs, const list_iter<T, P, R>& rhs){return !(lhs < rhs);};
	template<typename T, typename P, typename R>
		class rev_list_iter
		{     
			public:
				typedef T								value_type;
				typedef ptrdiff_t						difference_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef std::bidirectional_iterator_tag iterator_category;
				rev_list_iter (node<T> *n){current = n;}
				rev_list_iter& operator++(){ current = current->prev; return (*this);}
				rev_list_iter operator++(int) {rev_list_iter tmp = *this; --(*this); return tmp;}
				rev_list_iter& operator--(){ current = current->next; return (*this);}
				rev_list_iter operator--(int) {rev_list_iter tmp = *this; ++(*this); return tmp;}
				T & operator*(){ return (current->value);}
				node<T> *next_ptr(){return (current->next);}
				node<T> *prev_ptr(){return (current->prev);}
				node<T> *ptr(){return (current);}
				node<T> *current;
				template <typename T1, typename P1, typename R1>
					friend bool operator== (const rev_list_iter& lhs, const rev_list_iter<T1, P1, R1>& rhs){return (lhs.current == rhs.current);};
				template <typename T1, typename P1, typename R1>
					friend bool operator!= (const rev_list_iter& lhs, const rev_list_iter<T1, P1, R1>& rhs){return (lhs.current != rhs.current);};
		};
	template <typename T, typename P, typename R>
		bool operator<  (const rev_list_iter<T, P, R>& lhs, const rev_list_iter<T, P, R>& rhs){return (lhs.current < rhs.current);};
	template <typename T, typename P, typename R>
		bool operator<= (const rev_list_iter<T, P, R>& lhs, const rev_list_iter<T, P, R>& rhs){return (!(lhs < rhs));};
	template <typename T, typename P, typename R>
		bool operator>  (const rev_list_iter<T, P, R>& lhs, const rev_list_iter<T, P, R>& rhs){
			return (rhs < lhs);}
	template <typename T, typename P, typename R>
		bool operator>= (const rev_list_iter<T, P, R>& lhs, const rev_list_iter<T, P, R>& rhs){return !(lhs < rhs);};
} // namespace ft
#endif
