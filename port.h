/***********************************************************************************
  Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.

  (c) Copyright 1996 - 2002  Gary Henderson (gary.henderson@ntlworld.com),
                             Jerremy Koot (jkoot@snes9x.com)

  (c) Copyright 2002 - 2004  Matthew Kendora

  (c) Copyright 2002 - 2005  Peter Bortas (peter@bortas.org)

  (c) Copyright 2004 - 2005  Joel Yliluoma (http://iki.fi/bisqwit/)

  (c) Copyright 2001 - 2006  John Weidman (jweidman@slip.net)

  (c) Copyright 2002 - 2006  funkyass (funkyass@spam.shaw.ca),
                             Kris Bleakley (codeviolation@hotmail.com)

  (c) Copyright 2002 - 2010  Brad Jorsch (anomie@users.sourceforge.net),
                             Nach (n-a-c-h@users.sourceforge.net),

  (c) Copyright 2002 - 2011  zones (kasumitokoduck@yahoo.com)

  (c) Copyright 2006 - 2007  nitsuja

  (c) Copyright 2009 - 2011  BearOso,
                             OV2


  BS-X C emulator code
  (c) Copyright 2005 - 2006  Dreamer Nom,
                             zones

  C4 x86 assembler and some C emulation code
  (c) Copyright 2000 - 2003  _Demo_ (_demo_@zsnes.com),
                             Nach,
                             zsKnight (zsknight@zsnes.com)

  C4 C++ code
  (c) Copyright 2003 - 2006  Brad Jorsch,
                             Nach

  DSP-1 emulator code
  (c) Copyright 1998 - 2006  _Demo_,
                             Andreas Naive (andreasnaive@gmail.com),
                             Gary Henderson,
                             Ivar (ivar@snes9x.com),
                             John Weidman,
                             Kris Bleakley,
                             Matthew Kendora,
                             Nach,
                             neviksti (neviksti@hotmail.com)

  DSP-2 emulator code
  (c) Copyright 2003         John Weidman,
                             Kris Bleakley,
                             Lord Nightmare (lord_nightmare@users.sourceforge.net),
                             Matthew Kendora,
                             neviksti

  DSP-3 emulator code
  (c) Copyright 2003 - 2006  John Weidman,
                             Kris Bleakley,
                             Lancer,
                             z80 gaiden

  DSP-4 emulator code
  (c) Copyright 2004 - 2006  Dreamer Nom,
                             John Weidman,
                             Kris Bleakley,
                             Nach,
                             z80 gaiden

  OBC1 emulator code
  (c) Copyright 2001 - 2004  zsKnight,
                             pagefault (pagefault@zsnes.com),
                             Kris Bleakley
                             Ported from x86 assembler to C by sanmaiwashi

  SPC7110 and RTC C++ emulator code used in 1.39-1.51
  (c) Copyright 2002         Matthew Kendora with research by
                             zsKnight,
                             John Weidman,
                             Dark Force

  SPC7110 and RTC C++ emulator code used in 1.52+
  (c) Copyright 2009         byuu,
                             neviksti

  S-DD1 C emulator code
  (c) Copyright 2003         Brad Jorsch with research by
                             Andreas Naive,
                             John Weidman

  S-RTC C emulator code
  (c) Copyright 2001 - 2006  byuu,
                             John Weidman

  ST010 C++ emulator code
  (c) Copyright 2003         Feather,
                             John Weidman,
                             Kris Bleakley,
                             Matthew Kendora

  Super FX x86 assembler emulator code
  (c) Copyright 1998 - 2003  _Demo_,
                             pagefault,
                             zsKnight

  Super FX C emulator code
  (c) Copyright 1997 - 1999  Ivar,
                             Gary Henderson,
                             John Weidman

  Sound emulator code used in 1.5-1.51
  (c) Copyright 1998 - 2003  Brad Martin
  (c) Copyright 1998 - 2006  Charles Bilyue'

  Sound emulator code used in 1.52+
  (c) Copyright 2004 - 2007  Shay Green (gblargg@gmail.com)

  SH assembler code partly based on x86 assembler code
  (c) Copyright 2002 - 2004  Marcus Comstedt (marcus@mc.pp.se)

  2xSaI filter
  (c) Copyright 1999 - 2001  Derek Liauw Kie Fa

  HQ2x, HQ3x, HQ4x filters
  (c) Copyright 2003         Maxim Stepin (maxim@hiend3d.com)

  NTSC filter
  (c) Copyright 2006 - 2007  Shay Green

  GTK+ GUI code
  (c) Copyright 2004 - 2011  BearOso

  Win32 GUI code
  (c) Copyright 2003 - 2006  blip,
                             funkyass,
                             Matthew Kendora,
                             Nach,
                             nitsuja
  (c) Copyright 2009 - 2011  OV2

  Mac OS GUI code
  (c) Copyright 1998 - 2001  John Stiles
  (c) Copyright 2001 - 2011  zones


  Specific ports contains the works of other authors. See headers in
  individual files.


  Snes9x homepage: http://www.snes9x.com/

  Permission to use, copy, modify and/or distribute Snes9x in both binary
  and source form, for non-commercial purposes, is hereby granted without
  fee, providing that this license information and copyright notice appear
  with all copies and any derived work.

  This software is provided 'as-is', without any express or implied
  warranty. In no event shall the authors be held liable for any damages
  arising from the use of this software or it's derivatives.

  Snes9x is freeware for PERSONAL USE only. Commercial users should
  seek permission of the copyright holders first. Commercial use includes,
  but is not limited to, charging money for Snes9x or software derived from
  Snes9x, including Snes9x or derivatives in commercial game bundles, and/or
  using Snes9x as a promotion for your commercial product.

  The copyright holders request that bug fixes and improvements to the code
  should be forwarded to them so everyone can benefit from the modifications
  in future versions.

  Super NES and Super Nintendo Entertainment System are trademarks of
  Nintendo Co., Limited and its subsidiary companies.
 ***********************************************************************************/


#ifndef _PORT_H_
#define _PORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#ifndef __LIBRETRO__
#include <memory.h>
#endif
#include <time.h>
#include <string.h>
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#include <sys/types.h>

#ifdef __WIN32__
#define NOMINMAX
#include <windows.h>
#endif

#define GFX_MULTI_FORMAT

#ifdef __WIN32__
//#define RIGHTSHIFT_IS_SAR
#define RIGHTSHIFT_int8_IS_SAR
#define RIGHTSHIFT_int16_IS_SAR
#define RIGHTSHIFT_int32_IS_SAR
#ifndef __WIN32_LIBSNES__
#define SNES_JOY_READ_CALLBACKS
#endif //__WIN32_LIBSNES__
#endif

#ifdef __MACOSX__
#undef GFX_MULTI_FORMAT
#define PIXEL_FORMAT RGB555
#endif

#ifndef snes9x_types_defined
#define snes9x_types_defined
typedef unsigned char		bool8;
#ifdef HAVE_STDINT_H
#include <stdint.h>
typedef intptr_t			pint;
typedef int8_t				int8;
typedef uint8_t				uint8;
typedef int16_t				int16;
typedef uint16_t			uint16;
typedef int32_t				int32;
typedef uint32_t			uint32;
typedef int64_t				int64;
typedef uint64_t			uint64;
#else	// HAVE_STDINT_H
#ifdef __WIN32__
typedef intptr_t			pint;
typedef signed char			int8;
typedef unsigned char		uint8;
typedef signed short		int16;
typedef unsigned short		uint16;
typedef signed int     		int32;
typedef unsigned int		uint32;
typedef signed __int64		int64;
typedef unsigned __int64	uint64;
typedef int8                int8_t;
typedef uint8       		uint8_t;
typedef int16       		int16_t;
typedef uint16      		uint16_t;
typedef int32		    	int32_t;
typedef uint32      		uint32_t;
typedef int64               int64_t;
typedef uint64              uint64_t;
typedef int					socklen_t;
#else	// __WIN32__
typedef signed char			int8;
typedef unsigned char		uint8;
typedef signed short		int16;
typedef unsigned short		uint16;
typedef signed int			int32;
typedef unsigned int		uint32;
#ifdef __GNUC__
// long long is not part of ISO C++ 
__extension__
#endif
typedef long long			int64;
typedef unsigned long long	uint64;
#ifdef PTR_NOT_INT
typedef long				pint;
#else   // __PTR_NOT_INT
typedef int					pint;
#endif  // __PTR_NOT_INT
#endif	//  __WIN32__
#endif	// HAVE_STDINT_H
#endif	// snes9x_types_defined

#ifndef TRUE
#define TRUE	1
#endif
#ifndef FALSE
#define FALSE	0
#endif

#define START_EXTERN_C	extern "C" {
#define END_EXTERN_C	}

#ifndef __WIN32__
#ifndef PATH_MAX
#define PATH_MAX	1024
#endif
#define _MAX_DRIVE	1
#define _MAX_DIR	PATH_MAX
#define _MAX_FNAME	PATH_MAX
#define _MAX_EXT	PATH_MAX
#define _MAX_PATH	PATH_MAX
#else
#ifndef PATH_MAX
#define PATH_MAX	_MAX_PATH
#endif
#endif

#ifndef __WIN32__
void _splitpath (const char *, char *, char *, char *, char *);
void _makepath (char *, const char *, const char *, const char *, const char *);
#define S9xDisplayString	DisplayStringFromBottom
#else   // __WIN32__
#define snprintf _snprintf
#define strcasecmp	stricmp
#define strncasecmp	strnicmp
#ifndef __WIN32_LIBSNES__
void WinDisplayStringFromBottom(const char *string, int linesFromBottom, int pixelsFromLeft, bool allowWrap);
#define S9xDisplayString	WinDisplayStringFromBottom
void SetInfoDlgColor(unsigned char, unsigned char, unsigned char);
#define SET_UI_COLOR(r,g,b) SetInfoDlgColor(r,g,b)
#else   // __WIN32_LIBSNES__
#define S9xDisplayString	DisplayStringFromBottom
#endif  // __WIN32_LIBSNES__
#endif  // __WIN32__

#ifdef __DJGPP
#define SLASH_STR	"\\"
#define SLASH_CHAR	'\\'
#else
#define SLASH_STR	"/"
#define SLASH_CHAR	'/'
#endif

#ifndef SIG_PF
#define SIG_PF	void (*) (int)
#endif

#ifdef __linux
#define TITLE "Snes9x: Linux"
#define SYS_CONFIG_FILE "/etc/snes9x/snes9x.conf"
#endif

#ifndef TITLE
#define TITLE "Snes9x"
#endif

#if defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__) || defined(__x86_64__) || defined(__alpha__) || defined(__MIPSEL__) || defined(_M_IX86) || defined(_M_X64) || defined(_XBOX1)
#define LSB_FIRST
#define FAST_LSB_WORD_ACCESS
#else
#define MSB_FIRST
#endif

union WORD
{
    uint8 u8[2];
    int16 s16;
};

static inline int16 READ_WORD(uint8 *in)
{
    union WORD out;

#if defined(LSB_FIRST)
    out.u8[0] = in[0];
    out.u8[1] = in[1];
#else
    out.u8[0] = in[1];
    out.u8[1] = in[0];
#endif

    return (out.s16);
}

static inline uint32 READ_WORD(uint16 *in)
{
    uint32 out = *in;
    return out;
}

static inline void WRITE_WORD(uint8 *out, int16 in)
{
    union WORD tmp;

    tmp.s16 = in;
#if defined(LSB_FIRST)
    out[0] = tmp.u8[0];
    out[1] = tmp.u8[1];
#else
    out[0] = tmp.u8[1];
    out[1] = tmp.u8[0];
#endif
}

union DWORD
{
    uint8  u8[4];
    uint32 u32;
};

static inline uint32 READ_3WORD(uint8 *in)
{
    union DWORD out;

#if defined(LSB_FIRST)
    out.u8[0] = in[0];
    out.u8[1] = in[1];
    out.u8[2] = in[2];
    out.u8[3] = 0;
#else
    out.u8[0] = 0;
    out.u8[1] = in[2];
    out.u8[2] = in[1];
    out.u8[3] = in[0];
#endif

    return (out.u32);
}

static inline void WRITE_3WORD(uint8 *out, uint32 in)
{
    union DWORD tmp;

    tmp.u32 = in;
#if defined(LSB_FIRST)
    out[0] = tmp.u8[0];
    out[1] = tmp.u8[1];
    out[2] = tmp.u8[2];
#else
    out[0] = tmp.u8[2];
    out[1] = tmp.u8[1];
    out[2] = tmp.u8[0];
#endif
}

static inline uint32 READ_DWORD(uint8 *in)
{
    union DWORD out;

#if defined(LSB_FIRST)
    out.u8[0] = in[0];
    out.u8[1] = in[1];
    out.u8[2] = in[2];
    out.u8[3] = in[3];
#else
    out.u8[0] = in[3];
    out.u8[1] = in[2];
    out.u8[2] = in[1];
    out.u8[3] = in[0];
#endif

    return (out.u32);
}

static inline void WRITE_DWORD(uint8 *out, uint32 in)
{
    union DWORD tmp;

    tmp.u32 = in;
#if defined(LSB_FIRST)
    out[0] = tmp.u8[0];
    out[1] = tmp.u8[1];
    out[2] = tmp.u8[2];
    out[3] = tmp.u8[3];
#else
    out[0] = tmp.u8[3];
    out[1] = tmp.u8[2];
    out[2] = tmp.u8[1];
    out[3] = tmp.u8[0];
#endif
}

#define SWAP_WORD(s)		(s) = (((s) & 0xff) <<  8) | (((s) & 0xff00) >> 8)
#define SWAP_DWORD(s)		(s) = (((s) & 0xff) << 24) | (((s) & 0xff00) << 8) | (((s) & 0xff0000) >> 8) | (((s) & 0xff000000) >> 24)

#include "pixform.h"

#endif
