/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:32:09 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:44:46 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list/list.hpp"
#include "deque_iter.hpp"
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
		class deque{
			public:
				typedef  T																	value_type;
				typedef  Alloc																allocator_type;
				typedef value_type&															reference;
				typedef const value_type&													const_reference;
				typedef value_type*															pointer;
				typedef const value_type*						    							const_pointer;
				typedef ptrdiff_t															difference_type;
				typedef size_t																size_type;
				typedef deque_iter<value_type, value_type*, value_type&>						iterator;
				typedef list_iter<value_type, value_type*, value_type&>                         list_iterator;
				typedef deque_iter<value_type, const value_type*, const value_type&>			const_iterator;
				typedef rev_deque_iter<value_type, value_type*, value_type&>					reverse_iterator;
				typedef rev_deque_iter<value_type, const value_type*, const value_type&>		const_reverse_iterator;
				explicit deque (const allocator_type& alloc = allocator_type()):_alloc(alloc){
					_data = new ft::list<T, Alloc>();
				};
				explicit deque (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()):_alloc(alloc){
					_data = new ft::list<T, Alloc>(n, val);
				};
				template <class InputIterator>
					deque (InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type()):_alloc(alloc){
						_data = new ft::list<T, Alloc>(first, last);
					};
				deque (const deque& x){
					_data = new ft::list<T, Alloc>(*x._data);
				};
				deque& operator= (const deque& x){
					_data->clear();
					delete _data;
					ft::list<T, Alloc> *ret = new ft::list<T, Alloc>(*x._data);
					_data = ret;
					return (*this);
				};
				~deque(){delete _data;};

				// Iterators:
				iterator begin() const {return iterator(_data->begin().ptr());}
				iterator end() const {return iterator(_data->end().ptr());}
				const_iterator cbegin() const {return iterator(_data->cbegin().ptr());}
				const_iterator cend() const {return iterator(_data->cend().ptr());}
				reverse_iterator rbegin() {return reverse_iterator(_data->crbegin().ptr());}
				reverse_iterator rend() {return reverse_iterator(_data->crend().ptr());}
				const_reverse_iterator crbegin(){return const_reverse_iterator(_data->crbegin().ptr());}
				const_reverse_iterator crend() {return const_reverse_iterator(_data->crend().ptr());}
				//Capacity
				size_type size() const {return (_data->size());}
				size_type max_size() {return (4611686018427387903);}
				void resize (size_type n, value_type val = value_type()){
					if (n > _data->size())
					{
						for (size_type i = _data->size(); i < n; i++)
							_data->push_back(val);
					}
					if (n < _data->size())
					{
						while (_data->size() > n)
							_data->pop_back();
					}
				};
				bool empty() {return (_data->empty());}

				// ---> Element access:
				reference operator[] (size_type n) {
					size_type i = 0;
					iterator it = this->begin();
					while (it != this->end())
					{
						if (i == n)
							break;
						i++;
						it++;
					}
					return (*it);
				}
				const_reference operator[] (size_type n) const{
					size_type i = 0;
					iterator it = this->begin();
					while (it != this->end())
					{
						if (i == n)
							break ;
						i++;
						it++;
					}
					return (*it);
				}
				reference at (size_type n) {
					if (n < 0 || n > _data->size())
						throw(std::out_of_range("deque"));
					return(this->operator[](n));}
				const_reference at (size_type n) const {
					if (n < 0 || n >  _data->size())
						throw(std::out_of_range("deque"));
					return (this->operator[](n));}
				reference front(){return _data->front();};
				const_reference front() const{return _data->front();};
				reference back(){return _data->back();};
				const_reference back() const{return _data->back();};

				/// Modifiers:
				template <class InputIterator>
					void assign (InputIterator first, InputIterator last){
						ft::list<T, Alloc> *ret = new  ft::list<T, Alloc>();
						_data->clear();
						delete _data;
						ret->assign(first, last);
						_data = ret;
					};
				void assign (size_type n, const value_type& val){
					ft::list<T, Alloc> *ret = new  ft::list<T, Alloc>();
					_data->clear();
					delete _data;
					ret->assign(n, val);
					_data = ret;
				};
				void push_back (const value_type& val){_data->push_back(val);};
				void push_front (const value_type& val){_data->push_front(val);};
				void pop_back(){_data->pop_back();};
				void pop_front(){_data->pop_front();};
				iterator insert (iterator position, const value_type& val){
					return(iterator(_data->insert(list_iterator(position.ptr()), val).ptr()));
				};
				void insert (iterator position, size_type n, const value_type& val){
					for (size_type i = 0; i < n; i++)
						this->insert(position, val);
				};
				void insert (iterator position, int n, const value_type& val){
					for (int i = 0; i < n; i++)
						this->insert(position, val);
				};
				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last){
						while (first != last)
						{
							this->insert(position, (value_type)*first);
							first++;
						}
					};
				iterator erase (iterator position){
					_data->erase(list_iterator(position.ptr()));
					return (position++);
				};
				iterator erase (iterator first, iterator last){
					while (first != last)
					{
						this->erase(first);
						first++;
					}
					return (first);
				};
				void swap (deque& x){
					_data->swap(*x._data);
				};
				void clear(){_data->clear();};
			private:
				ft::list<T, Alloc> *_data;
				Alloc _alloc;
				template <class T1, class Alloc1>
					friend bool operator== (const deque<T1,Alloc1>& lhs, const deque<T1,Alloc1>& rhs){return (*lhs._data == *rhs._data);};

				template <class T1, class Alloc1>
					friend bool operator!= (const deque<T1,Alloc1>& lhs, const deque<T1,Alloc1>& rhs){return (*lhs._data != *rhs._data);};

				template <class T1, class Alloc1>
					friend bool operator<  (const deque<T1,Alloc1>& lhs, const deque<T1,Alloc1>& rhs){return (*lhs._data < *rhs._data);};

				template <class T1, class Alloc1>
					friend bool operator<= (const deque<T1,Alloc1>& lhs, const deque<T1,Alloc1>& rhs){return (*lhs._data <= *rhs._data);};

				template <class T1, class Alloc1>
					friend bool operator>  (const deque<T1,Alloc1>& lhs, const deque<T1,Alloc1>& rhs){return (*lhs._data > *rhs._data);};

				template <class T1, class Alloc1>
					friend bool operator>= (const deque<T1,Alloc1>& lhs, const deque<T1,Alloc1>& rhs){return (*lhs._data >= *rhs._data);};
		};
	template <class T1, class Alloc1>
		void swap (deque<T1,Alloc1>& x, deque<T1,Alloc1>& y){
			x.swap(y);
		};
} // namespace ft
