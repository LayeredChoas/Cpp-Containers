/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_iter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:27:04 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:04:38 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../list/node.hpp"
namespace ft
{
	template<typename T, typename P, typename R>
		class deque_iter
		{     
			public:
				typedef T								value_type;
				typedef ptrdiff_t						difference_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef std::random_access_iterator_tag iterator_category;
				deque_iter (node<T> *n):current(n){};
				deque_iter (){}
				deque_iter& operator++(){ current = current->next; return (*this);}
				deque_iter operator++(int) {deque_iter tmp = *this; ++(*this); return tmp;}
				deque_iter& operator--(){ current = current->prev; return (*this);}
				deque_iter operator--(int) {deque_iter tmp = *this; --(*this); return tmp;}
				T & operator*(){ return (current->value);}
				node<T> *next_ptr(){return (current->next);}
				node<T> *prev_ptr(){return (current->prev);}
				node<T> *ptr() const {return (current);}
				deque_iter  operator+(int const &x){ 
					int i = 0;
					while (i < x)
					{
						i++;
						current++;
					}return (deque_iter(current));}
				deque_iter  operator-(int const &x){ 
					int i = 0;
					while (i < x)
					{
						i++;
						current--;
					}return (deque_iter(current));}

				deque_iter const operator+=(int const &x){ this->current = this->current + x; return(deque_iter(current));}
				deque_iter const operator-=(int const &x){ this->current = this->current - x; return(deque_iter(current));}
				bool operator!=(deque_iter &x){return (this->current != x.current);}
				deque_iter& operator=(deque_iter const &a){ current = a.current; return (*this);}
				node<T> *current;

				template <typename T1, typename P1, typename R1>
					friend bool operator== (const deque_iter& lhs, const deque_iter<T1, P1, R1>& rhs){return (lhs.current == rhs.current);};
				template <typename T1, typename P1, typename R1>
					friend bool operator!= (const deque_iter& lhs, const deque_iter<T1, P1, R1>& rhs){return (lhs.current != rhs.current);};
		};
	template <typename T, typename P, typename R>
		bool operator<  (const deque_iter<T, P, R>& lhs, const deque_iter<T, P, R>& rhs){return (lhs.current < rhs.current);};
	template <typename T, typename P, typename R>
		bool operator<= (const deque_iter<T, P, R>& lhs, const deque_iter<T, P, R>& rhs){return (!(lhs < rhs));};
	template <typename T, typename P, typename R>
		bool operator>  (const deque_iter<T, P, R>& lhs, const deque_iter<T, P, R>& rhs){
			return (rhs < lhs);}
	template <typename T, typename P, typename R>
		bool operator>= (const deque_iter<T, P, R>& lhs, const deque_iter<T, P, R>& rhs){return !(lhs < rhs);};
	template<typename T, typename P, typename R>
		class rev_deque_iter
		{     
			public:
				typedef T								value_type;
				typedef ptrdiff_t						difference_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef std::bidirectional_iterator_tag iterator_category;
				rev_deque_iter (node<T> *n){current = n;}
				rev_deque_iter (){}
				rev_deque_iter& operator++(){ current = current->prev; return (*this);}
				rev_deque_iter operator++(int) {rev_deque_iter tmp = *this; --(*this); return tmp;}
				rev_deque_iter& operator--(){ current = current->next; return (*this);}
				rev_deque_iter operator--(int) {rev_deque_iter tmp = *this; ++(*this); return tmp;}
				T & operator*(){ return (current->value);}
				node<T> *next_ptr(){return (current->next);}
				node<T> *prev_ptr(){return (current->prev);}
				node<T> *ptr(){return (current);}
				rev_deque_iter  operator+(int const &x){ 
					int i = 0;
					while (i < x)
					{
						i++;
						current++;
					}return (rev_deque_iter(current));}
				rev_deque_iter  operator-(int const &x){ 
					int i = 0;
					while (i < x)
					{
						i++;
						current--;
					}return (rev_deque_iter(current));}

				rev_deque_iter const operator+=(int const &x){ this->current = this->current + x; return(rev_deque_iter(current));}
				rev_deque_iter const operator-=(int const &x){ this->current = this->current - x; return(rev_deque_iter(current));}
				template <typename T1, typename P1, typename R1>
					friend bool operator== (const rev_deque_iter& lhs, const rev_deque_iter<T1, P1, R1>& rhs){return (lhs.current == rhs.current);};
				template <typename T1, typename P1, typename R1>
					friend bool operator!= (const rev_deque_iter& lhs, const rev_deque_iter<T1, P1, R1>& rhs){return (lhs.current != rhs.current);};
			private:
				node<T> *current;
		};
	template <typename T, typename P, typename R>
		bool operator<  (const rev_deque_iter<T, P, R>& lhs, const rev_deque_iter<T, P, R>& rhs){return (lhs.current < rhs.current);};
	template <typename T, typename P, typename R>
		bool operator<= (const rev_deque_iter<T, P, R>& lhs, const rev_deque_iter<T, P, R>& rhs){return (!(lhs < rhs));};
	template <typename T, typename P, typename R>
		bool operator>  (const rev_deque_iter<T, P, R>& lhs, const rev_deque_iter<T, P, R>& rhs){
			return (rhs < lhs);}
	template <typename T, typename P, typename R>
		bool operator>= (const rev_deque_iter<T, P, R>& lhs, const rev_deque_iter<T, P, R>& rhs){return !(lhs < rhs);};
} // namespace ft
