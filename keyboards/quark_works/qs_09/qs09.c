/* Copyright 2021 Quark Works
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "qs09.h"

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 8,    5,    4},
  { 7,    6,    3},
  { 0,    1,    2}
}, {
    // LED Index to Physical Position
    {  45,  5}, {  25,  5}, {   5,  5},  
    {   5, 25}, {   5, 45}, {  25, 45},
    {  25, 25}, {  45, 25}, {  45, 45},
        

    { 45,45 },{ 45,25 },{ 5,25 },{ 5,45 }


}, {
    // LED Index to Flag
    4, 4, 4,
    4, 4, 4,
    4, 4, 4,
    2, 2, 2, 2
} };
