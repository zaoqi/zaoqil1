/*
    語: The Language
    Copyright (C) 2018  Zaoqi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef List_null


#include "eq.h"
#include "bool.h"
#include "memory.h"
#include "c.h"
struct List;
typedef struct List List;
struct List{
	void* head;
	List* tail;};
#ifdef NULL
#define List_null NULL
#else
extern List List_null_v;
#define List_null (&List_null_v)
#endif
extern void remove_List(List* xs);
inline List* List_cons(void* head, List* tail){
	List* r=memory_new_type(List);
	r->head=head;r->tail=tail;
	return r;}
inline bool List_null_p(List* xs){return eq_p(xs, List_null);}
inline bool List_cons_p(List* xs){return !List_null_p(xs);}
inline void* assert_List_head(List* xs){
	assert(List_cons_p(xs));
	return xs->head;}
inline List* assert_List_tail(List* xs){
	assert(List_cons_p(xs));
	return xs->tail;}

inline void List_push(List** l, void* x){
	List* r=memory_new_type(List);
	r->head=x;r->tail=*l;
	*l=r;}
#define List_push_m(xs, x) List_push(&xs, x)
inline void* assert_List_pop(List** l){
	assert(List_cons_p(*l));
	List* nl=(*l)->tail;void* r=(*l)->head;
	memory_delete(*l);
	*l=nl;
	return r;}
#define assert_List_pop_m(xs) assert_List_pop(&xs)


#endif
