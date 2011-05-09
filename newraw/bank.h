/* Raw - Another World Interpreter
 * Copyright (C) 2004 Gregory Montoir
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef __BANK_H__
#define __BANK_H__

#include "intern.h"

struct MemEntry;

struct UnpackCtx {
	int size, datasize;
	uint32 crc;
	uint32 chk;
	uint8 *dst;
	const uint8 *src;
};

struct Bank {
	UnpackCtx _unpCtx;
	const char *_dataDir;
	uint8 *_oBuf;

	Bank(const char *dataDir);

	bool read(const MemEntry *me, uint8 *buf);
	void dec_unk1(UnpackCtx *uc, uint8 num_chunks, uint8 add_count);
	void dec_unk2(UnpackCtx *uc, uint8 num_chunks);
	bool unpack(uint8 *dst, uint8 *src, int len);
	uint16 get_code(UnpackCtx *uc, uint8 num_chunks);
	int next_chunk(UnpackCtx *uc);
	int rcr(UnpackCtx *uc, int CF);
};

#endif
