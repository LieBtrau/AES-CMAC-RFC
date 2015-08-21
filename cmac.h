/**
 * File: cmac.h
 * Created on: 21 авг. 2015 г.
 * Description:
 * 
 *
 * Author: Roman Savrulin <romeo.deepmind@gmail.com>
 * Copyright: 2015 Roman Savrulin
 * Copying permission statement:
 * 
 *  This file is part of AES-CMAC.
 *
 *  AES-CMAC is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */
#ifndef CMAC_H_
#define CMAC_H_

#define BLOCK_SIZE 16
#define LAST_INDEX (BLOCK_SIZE - 1)

void AES_CMAC(const unsigned char *key, const unsigned char *input, int length,
		unsigned char *mac);

int AES_CMAC_CHECK(const unsigned char *key, const unsigned char *input, int length,
		const unsigned char *mac);

#ifdef CMAC_DEBUG_ON
void print_hex(const char *str, const unsigned char *buf, int len);
void print128(const unsigned char *bytes);
void print96(const unsigned char *bytes);
#endif


#endif /* CMAC_H_ */