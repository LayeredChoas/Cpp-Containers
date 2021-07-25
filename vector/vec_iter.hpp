/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:43:02 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:07:14 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once

#ifndef VEC_ITER_HPP
#define VEC_ITER_HPP
#include <iostream>
namespace ft
{
	template<typename T>
		class vec_iter
		{     
			public:
				T *tab;
				typedef T                   			value_type;
				typedef T&								reference;
				typedef ptrdiff_t						difference_type;
				typedef value_type*						pointer;
				typedef const value_type*				const_pointer;
				typedef std::random_access_iterator_tag	iterator_category;

				vec_iter(){}; 
				vec_iter(T const *a):tab(const_cast<T*>(a)){};
				vec_iter& operator=(vec_iter const &a){ tab = a.tab; return (*this);}

				T & operator*(){ return (*tab);}

				vec_iter  operator+(int const &x){ return (vec_iter(tab + x));}
				vec_iter  operator-(int const &x){ return (vec_iter(tab - x));}

				vec_iter const operator+=(int const &x){ this->tab = this->tab + x; return(vec_iter(tab));}
				vec_iter const operator-=(int const &x){ this->tab = this->tab - x; return(vec_iter(tab));}
				reference operator[] (size_t n) {
					return (*(tab + n));
				}
				vec_iter(vec_iter const &it): tab(it.tab){};
				vec_iter& operator++(){ tab++; return (*this);}
				vec_iter operator++(int) {vec_iter tmp = *this; ++(*this); return tmp;}
				vec_iter& operator--(){ tab--; return (*this);}
				vec_iter operator--(int) {vec_iter tmp = *this; --(*this); return tmp;}
				~vec_iter(){};
				bool eq(const vec_iter<T>& lhs, const vec_iter<T>& rhs) {return (lhs.tab == rhs.tab);};
		};
	template <class T>
		bool operator== (const vec_iter<T>& lhs, const vec_iter<T>& rhs){return (lhs.tab == rhs.tab);};
	template <class T>
		bool operator!= (const vec_iter<T>& lhs, const vec_iter<T>& rhs){return (!(lhs == rhs));};
	template <class T>
		bool operator<  (const vec_iter<T>& lhs, const vec_iter<T>& rhs){return (lhs.tab < rhs.tab);};
	template <class T>
		bool operator<= (const vec_iter<T>& lhs, const vec_iter<T>& rhs){return (!(lhs < rhs));};
	template <class T>
		bool operator>  (const vec_iter<T>& lhs, const vec_iter<T>& rhs){
			return (rhs < lhs);}
	template <class T>
		bool operator>= (const vec_iter<T>& lhs, const vec_iter<T>& rhs){return !(lhs < rhs);};
	template<typename T>
		class vec_rev_iter
		{     
			public:
				T *tab;
				typedef T                   			value_type;
				typedef T&								reference;
				typedef ptrdiff_t						difference_type;
				typedef vec_rev_iter<T>         			iterator;
				typedef vec_rev_iter<const T>   			const_iterator;
				typedef value_type*						pointer;
				typedef const value_type*				const_pointer;
				typedef std::random_access_iterator_tag	iterator_category;

				vec_rev_iter(){}; 
				vec_rev_iter(T *a):tab(a){};
				iterator& operator=(iterator const &a){ tab = a.tab; return (*this);}

				bool &operator==(iterator &x){
					return ((x.tab == this->tab));
				}
				bool &operator!=(iterator &x){
					return ((x.tab != this->tab));
				}

				T & operator*(){ return (*tab);}

				iterator  operator+(int const &x){ return (iterator(tab - x));}
				iterator  operator-(int const &x){ return (iterator(tab + x));}

				iterator const operator+=(int const &x){ this->tab = this->tab - x; return(iterator(tab));}
				iterator const operator-=(int const &x){ this->tab = this->tab + x; return(iterator(tab));}

				bool &operator>(iterator &x){
					return ((this->tab > x.tab));
				}
				bool &operator>=(iterator &x){
					return ((this->tab >= x.tab));
				}
				bool &operator<=(iterator &x){
					return ((this->tab <= x.tab));
				}
				bool &operator<(iterator &x){
					return ((this->tab < x.tab));
				}
				reference operator[] (size_t n) {
					return (*(tab - n));
				}
				vec_rev_iter(vec_rev_iter const &it): tab(it.tab){};
				iterator& operator++(){ tab--; return (*this);}
				iterator operator++(int) {iterator tmp = *this; ++(*this); return tmp;}
				iterator& operator--(){ tab++; return (*this);}
				iterator operator--(int) {iterator tmp = *this; --(*this); return tmp;}
				virtual ~vec_rev_iter(){};
		};
	template <class T>
		bool operator== (const vec_rev_iter<T>& lhs, const vec_rev_iter<T>& rhs){return (lhs.tab == rhs.tab);};
	template <class T>
		bool operator!= (const vec_rev_iter<T>& lhs, const vec_rev_iter<T>& rhs){return (!(lhs == rhs));};
	template <class T>
		bool operator<  (const vec_rev_iter<T>& lhs, const vec_rev_iter<T>& rhs){return (lhs.tab < rhs.tab);};
	template <class T>
		bool operator<= (const vec_rev_iter<T>& lhs, const vec_rev_iter<T>& rhs){return (!(lhs < rhs));};
	template <class T>
		bool operator>  (const vec_rev_iter<T>& lhs, const vec_rev_iter<T>& rhs){
			return (rhs < lhs);}
	template <class T>
		bool operator>= (const vec_rev_iter<T>& lhs, const vec_rev_iter<T>& rhs){return !(lhs < rhs);};
} // namespace ft
#endif
