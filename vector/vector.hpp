/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:43:32 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:39:05 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include "vec_iter.hpp"
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
			public:
				typedef T						value_type;
				typedef T&						reference;
				typedef const T&				const_reference;
				typedef value_type*				pointer;
				typedef const value_type*		const_pointer;
				typedef size_t					size_type;
				typedef Alloc					allocator_type;
				typedef	ptrdiff_t				difference_type;
				typedef vec_iter<T>				iterator;
				typedef vec_rev_iter<T>			reverse_iterator;
			private:
				Alloc alloc;
				T *_data;
				size_type _size;
				size_type _cap;
				T null;
			public:
				// --->  Member functions
				explicit vector (const allocator_type& alloc = allocator_type()):alloc(alloc),_size(0), _cap(0),null(0){_data = new T[1];};
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):alloc(alloc),_cap(0)
			{
				_data = new T[n];
				for (size_t i = 0; i < n; i++)
					_data[i] = val;
				_size = n;
				Set_cap();
				null = 0;
			};
				template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):alloc(alloc){
						InputIterator p1(first);
						InputIterator p2(last);
						int count = 0;
						while (p1 != p2)
						{
							p1++;
							count++;
						}
						_data = new value_type[count];
						_size = count;
						count = 0;
						Set_cap();
						this->assign(first, last);
					};
				vector (const vector& x){
					_data = new T[x.size()];
					for (size_t i = 0; i < x.size(); i++)
						_data[i] = x[i];
					_size = x.size();
					_cap = x._cap;
					alloc = x.alloc;
				};
				~vector(void){delete _data;};


				// --->  Iterators

				iterator begin() const {return (iterator(_data));};
				iterator end()const{return (iterator((_data + _size)));};
				reverse_iterator rbegin()const{return (reverse_iterator((_data + _size - 1)));};
				reverse_iterator rend()const{return (reverse_iterator(_data - 1));};

				// ---> Capacity:
				size_type max_size() const{return (alloc.max_size());};
				size_type size() const{return this->_size;};
				void resize (size_type n, value_type val = value_type()){
					if (n <= _size)
					{
						value_type *ret = new T[n];
						for (size_t i = 0; i < n; i++)
							ret[i] = _data[i];
						_size = n;
						delete _data;
						_data = ret;
						Set_cap();
						return ;
					}
					else
					{
						value_type *ret = new T[n];
						for (size_t i = 0; i < _size; i++)
							ret[i] = _data[i];
						for (size_t i = _size; i < n; i++)
							ret[i] = val;
						delete _data;
						_size = n;
						_data = ret;
						Set_cap();
						return ;
					}
				};
				size_type Set_cap()
				{
					size_type ret = 1;
					if (_size < _cap)
						return _cap;
					for (size_t i = 0; i < _size; i++)
					{
						ret *= 2;
						if (ret > _size)
							break ;
					}
					if (ret > _cap)
						_cap = ret;
					reserve(_cap);
					return (_cap);
				}
				size_type capacity() const{ return (_cap); }; 
				bool empty() const{return (_size == 0);};
				void reserve (size_type n){
					if (n > _cap)
					{
						_cap = n;
						T *ret = new T[n];
						for (size_t i = 0; i < _size; i++)
							ret[i] = _data[i];
						delete _data;
						_data = ret;
					}
				}
				// ---> Element access:
				reference operator[] (size_type n) {
					if (n >= _size)
						return (null);
					return (_data[n]);
				}
				const_reference operator[] (size_type n) const{
					if (n >= _size)
						return (null);
					return (_data[n]);
				}
				reference at (size_type n) {
					if (n < 0 || n > _size)
						throw(std::out_of_range("vector"));
					return(this->operator[](n));}
				const_reference at (size_type n) const {
					if (n < 0 || n > _size)
						throw(std::out_of_range("vector"));
					return (this->operator[](n));}
				reference front(){return (_data[0]);};
				const_reference front() const {return _data[0];};
				reference back(){return _data[_size - 1];};
				const_reference back() const {return _data[_size - 1];};


				// ---> Modifiers:
				template <class InputIterator>
					void assign (InputIterator first, InputIterator last){
						InputIterator start = first;
						size_t count = 0;
						while (start != last)
						{
							count++;
							start++;
						}
						if (count == 0)
							return ;
						value_type *ret = new value_type[count];
						for (size_t i = 0; i < count; i++)
						{
							ret[i] = *first;
							first++;
						}
						delete _data;
						_data = ret;
						_size = count;
						Set_cap();
					};

				void assign (size_type n, const value_type& val){
					if (n == 0)
					{
						delete _data;
						_data = NULL;
						_size = 0;
						Set_cap();
						return ;
					}
					else if (n > 0)
					{
						value_type *ret = new value_type[n];
						for (size_t i = 0; i < n; i++)
							ret[i] = val;
						_size = n;
						delete _data;
						_data = ret;
						Set_cap();
					}
				};
				void assign (int n, const value_type& val){
					if (n == 0)
					{
						delete _data;
						_data = NULL;
						_size = 0;
						Set_cap();
						return ;
					}
					else if (n > 0)
					{
						value_type *ret = new value_type[n];
						for (int i = 0; i < n; i++)
							ret[i] = val;
						_size = n;
						delete _data;
						_data = ret;
						Set_cap();
					}
				};
				void push_back (const value_type& val)
				{
					T *ret;
					T *_new = new T[_size + 1];

					ret = _data;
					for (size_t i = 0; i < _size; i++)
						_new[i] = _data[i];
					_new[_size] = val;
					delete ret;
					_data = _new;
					_size++;
					Set_cap();

				};
				void pop_back(){
					if (_size == 0)
						return ;
					if (_size == 1)
					{
						_size = 0;
						return ;
					}
					T *_new = new T[_size - 1];
					for (size_t i = 0; i < _size - 1; i++)
						_new[i] = _data[i];
					delete _data;
					_data = _new;
					_size--;
					Set_cap();
				};
				iterator insert (iterator position, const value_type& val){

					value_type *ret = new value_type[this->size() + 1];
					iterator lop = this->begin();
					int count = 0;
					int place = 0;
					while (std::addressof(*lop) != std::addressof(*position))
					{
						ret[count] = *lop;
						lop++;
						count++;
					}
					place = count;
					ret[count] = val;
					count++;
					while (std::addressof(*lop) != std::addressof(*this->end()))
					{
						ret[count] = *lop;
						lop++;
						count++;
					}
					_size++;
					Set_cap();
					delete this->_data;
					this->_data = ret;
					return(iterator(this->_data + place));
				};
				void insert (iterator position, size_type n, const value_type& val){
					size_type i = 0;
					value_type *ret = new value_type[this->size() + n];
					iterator lop = this->begin();
					int count = 0;

					while (std::addressof(*lop) != std::addressof(*position))
					{
						ret[count] = *lop;
						lop++;
						count++;
					}
					i = count;
					while ((count - i) < n)
					{
						ret[count] = val;
						count++;
					}
					while (std::addressof(*lop) != std::addressof(*this->end()))
					{
						ret[count] = *lop;
						lop++;
						count++;
					}
					this->_size += n;
					Set_cap();
					delete this->_data;
					this->_data = ret;
				};
				void insert (iterator position, int n, const value_type& val){
					int i = 0;
					value_type *ret = new value_type[this->size() + n];
					iterator lop = this->begin();
					int count = 0;

					while (std::addressof(*lop) != std::addressof(*position))
					{
						ret[count] = *lop;
						lop++;
						count++;
					}
					i = count;
					while ((count - i) < n)
					{
						ret[count] = val;
						count++;
					}
					while (std::addressof(*lop) != std::addressof(*this->end()))
					{
						ret[count] = *lop;
						lop++;
						count++;
					}
					this->_size += n;
					Set_cap();
					delete this->_data;
					this->_data = ret;
				};
				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last){
						int n = 0;
						iterator p1(first);
						iterator p2(last);
						while (std::addressof(*first) != std::addressof(*last))
						{
							first++;
							n++;
						}
						if (n == 0)
						{
							this->insert(position, *first);
							return ;
						}
						value_type *ret = new value_type[this->size() + n];
						iterator lop = this->begin();
						int count = 0;
						int i;
						while (std::addressof(*lop) != std::addressof(*position))
						{
							ret[count] = *lop;
							lop++;
							count++;
						}
						i = count;
						while (std::addressof(*p1) != std::addressof(*p2))
						{
							ret[count] = *p1;
							p1++;
							count++;
						}
						while (std::addressof(*lop) != std::addressof(*this->end()))
						{
							ret[count] = *lop;
							lop++;
							count++;
						}
						this->_size += n;
						Set_cap();
						delete this->_data;
						this->_data = ret;
					};

				iterator erase (iterator position)
				{
					size_type pos = 0;

					for (size_t i = 0; i < this->size(); i++)
					{
						if (std::addressof(this->at(i)) == std::addressof(*position))
						{
							pos = i;
							break ;
						}
					}
					for (size_t i = pos; i < this->size() - 1; i++)
						this->at(i) = this->at(i + 1);
					_size--;
					Set_cap();
					return (position);
				};
				iterator erase (iterator first, iterator last)
				{
					iterator pos(first);

					while (std::addressof(*last) != std::addressof(*this->end()))
					{
						*first = *last;
						first++;
						last++;
					}
					while (std::addressof(*first) != std::addressof(*last))
					{
						first++;
						_size--;
					}
					Set_cap();
					return (pos);
				}
				void swap (vector& x)
				{
					T *d = _data;
					size_type s = _size;
					size_type c = _cap;

					_data = x._data;
					_size = x._size;
					_cap =x. _cap;

					x._data = d;
					x._size = s;
					x._cap = c;
				};
				void clear()
				{
					delete[] _data;
					_data = new T[0];
					_size = 0;
					Set_cap();
				}
		};
	template <class R, class L>
		bool equal(R start, R end, L start1)
		{
			while (start != end)
			{
				if (*start != *start1)
					return false;
				start++;
				start1++;
			}
			return true;
		}
	template <class R, class L>
		bool less_then(R start, R end, L start1, L end1)
		{
			while (start != end)
			{
				if (start1 == end1 || *start > *start1)
					return false;
				else if (*start < *start1)
					return true;
				start++;
				start1++;
			}
			return (*start != *end1);
		}
	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return (lhs.size() == rhs.size() && equal(rhs.begin(), rhs.end(), lhs.begin()));
		};

	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){return (!(lhs == rhs));};
	template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){return (less_then(lhs.begin(), lhs.end(), rhs.begin(),rhs.end()));};
	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){return (!(rhs < lhs));};
	template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
			return (rhs < lhs);};
	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){return !(lhs < rhs);};
	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
			x.swap(y);
		};
} // namespace ft


#endif
