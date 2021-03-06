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
#include "define.h"
#include "gc.h"
#include "lock.h"
#include "lang.gc.h"
lock gcing=lock_init;
PUBLIC void gc(){
	lock_with_or_doNothing_m(gcing,{
		
		gc_lang();
		
	})}
lock gc_step_ing=lock_init;
PUBLIC void gc_step(){
	lock_with_or_doNothing_m(gc_step_ing,{
		
		gc_step_lang();
		
	})}
