/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
/* GPL v3 fraret <fraretblauet@gmail.com>
 * 2015-2016
 *
 * FITXER DE CONFIGURACUIO DE cotxe_teledirigit.ino
 */


#ifndef CODIS_H
#define CODIS_H

#define LT_MOTOR 12 //Pin del motor esquerre
#define RT_MOTOR 13 //Pin del motor dret
#define LT_POWER 255 //Potencia del motor esquerre (de 0 a 255)
#define RT_POWER 255 //Potencia del motor esquerre (de 0 a 255)

#define CODE_LT 0x4EBA0422 //Codi per anar cap a l'esquerra
#define CODE_RT 0x5EA08104 //Codi per anar cap a la dreta
#define CODE_FW 0x9986485A //Codi per anar endavant
#define CODE_REPEAT 0xFFFFFFF //Codi de repetici del comandament (si en te)

#define CICLES 20000 //Quants cicles ha de passar sense senyal per tal de que el cotxe s'aturi?

#define RECV_PIN 11 //Pin del receptor de IR


#endif
