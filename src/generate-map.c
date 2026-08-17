//
//  generate-map.c
//  mulle-slug
//
//  Copyright (c) 2023 Nat! - Mulle kybernetiK.
//  All rights reserved.
//
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//  Neither the name of Mulle kybernetiK nor the names of its contributors
//  may be used to endorse or promote products derived from this software
//  without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
#include "include.h"

#include <assert.h>
#include <stdio.h>

static struct map_entry
{
   char            *utf8;
   char            *ascii;
   mulle_utf32_t   utf32;
} map[] =
{
{"Æ", "AE"},
{"Ð", "D"}, 
{"Ø", "O"}, 
{"Þ", "TH"}, 
{"ß", "ss"}, 
{"æ", "ae"}, 
{"ð", "d"}, 
{"ø", "o"}, 
{"þ", "th"}, 
{"ẞ", "SS"},
{"α", "a"}, 
{"β", "b"}, 
{"γ", "g"}, 
{"δ", "d"}, 
{"ε", "e"}, 
{"ζ", "z"}, 
{"η", "h"}, 
{"θ", "8"},
{"ι", "i"}, 
{"κ", "k"}, 
{"λ", "l"}, 
{"μ", "m"}, 
{"ν", "n"}, 
{"ξ", "3"}, 
{"ο", "o"}, 
{"π", "p"},
{"ρ", "r"}, 
{"σ", "s"}, 
{"τ", "t"}, 
{"υ", "y"}, 
{"φ", "f"}, 
{"χ", "x"}, 
{"ψ", "ps"}, 
{"ω", "w"},
{"ά", "a"}, 
{"έ", "e"}, 
{"ί", "i"}, 
{"ό", "o"}, 
{"ύ", "y"}, 
{"ή", "h"}, 
{"ώ", "w"}, 
{"ς", "s"},
{"ϊ", "i"}, 
{"ΰ", "y"}, 
{"ϋ", "y"}, 
{"ΐ", "i"},
{"Α", "A"}, 
{"Β", "B"}, 
{"Γ", "G"}, 
{"Δ", "D"}, 
{"Ε", "E"}, 
{"Ζ", "Z"}, 
{"Η", "H"}, 
{"Θ", "8"},
{"Ι", "I"}, 
{"Κ", "K"}, 
{"Λ", "L"}, 
{"Μ", "M"}, 
{"Ν", "N"}, 
{"Ξ", "3"}, 
{"Ο", "O"}, 
{"Π", "P"},
{"Ρ", "R"}, 
{"Σ", "S"}, 
{"Τ", "T"}, 
{"Υ", "Y"}, 
{"Φ", "F"}, 
{"Χ", "X"}, 
{"Ψ", "PS"}, 
{"Ω", "W"},
{"Ά", "A"}, 
{"Έ", "E"}, 
{"Ί", "I"}, 
{"Ό", "O"}, 
{"Ύ", "Y"}, 
{"Ή", "H"}, 
{"Ώ", "W"}, 
{"Ϊ", "I"},
{"Ϋ", "Y"},
{"ı", "i"}, 
{"а", "a"}, 
{"б", "b"}, 
{"в", "v"}, 
{"г", "g"}, 
{"д", "d"}, 
{"е", "e"}, 
{"ё", "yo"}, 
{"ж", "zh"},
{"з", "z"}, 
{"и", "i"}, 
{"й", "j"}, 
{"к", "k"}, 
{"л", "l"}, 
{"м", "m"}, 
{"н", "n"}, 
{"о", "o"},
{"п", "p"}, 
{"р", "r"}, 
{"с", "s"}, 
{"т", "t"}, 
{"у", "u"}, 
{"ф", "f"}, 
{"х", "h"}, 
{"ц", "c"},
{"ч", "ch"}, 
{"ш", "sh"}, 
{"щ", "sh"}, 
{"ъ", "u"}, 
{"ы", "y"}, 
{"ь", ""}, 
{"э", "e"}, 
{"ю", "yu"},
{"я", "ya"},
{"А", "A"}, 
{"Б", "B"}, 
{"В", "V"}, 
{"Г", "G"}, 
{"Д", "D"}, 
{"Е", "E"}, 
{"Ё", "Yo"}, 
{"Ж", "Zh"},
{"З", "Z"}, 
{"И", "I"}, 
{"Й", "J"}, 
{"К", "K"}, 
{"Л", "L"}, 
{"М", "M"}, 
{"Н", "N"}, 
{"О", "O"},
{"П", "P"}, 
{"Р", "R"}, 
{"С", "S"}, 
{"Т", "T"}, 
{"У", "U"}, 
{"Ф", "F"}, 
{"Х", "H"}, 
{"Ц", "C"},
{"Ч", "Ch"}, 
{"Ш", "Sh"}, 
{"Щ", "Sh"}, 
{"Ъ", "U"}, 
{"Ы", "Y"}, 
{"Ь", ""}, 
{"Э", "E"}, 
{"Ю", "Yu"},
{"Я", "Ya"},
{"Є", "Ye"}, 
{"І", "I"}, 
{"Ї", "Yi"}, 
{"Ґ", "G"}, 
{"є", "ye"}, 
{"і", "i"}, 
{"ї", "yi"}, 
{"ґ", "g"},
{"ł", "l"}, 
{"Ł", "L"}, 
{"€", "euro"}, 
{"₢", "cruzeiro"}, 
{"₣", "franc"},  // no space
{"£", "pound"},
{"₤", "lira"}, 
{"₥", "mill"}, 
{"₦", "naira"}, 
{"₧", "peseta"}, 
{"₨", "rupee"},
{"₩", "won"}, 
{"₪", "new-shequel"},   // no space
{"₫", "dong"}, 
{"₭", "kip"}, 
{"₮", "tugrik"},
{"₯", "drachma"}, 
{"₰", "penny"}, 
{"₱", "peso"}, 
{"₲", "guarani"}, 
{"₳", "austral"},
{"₴", "hryvnia"}, 
{"₵", "cedi"}, 
{"¢", "cent"}, 
{"¥", "yen"}, 
{"元", "yuan"},
{"円", "yen"}, 
{"﷼", "rial"}, 
{"₠", "ecu"}, 
{"¤", "currency"}, 
{"฿", "baht"}, 
{"©", "c"}, 
{"œ", "oe"}, 
{"Œ", "OE"}, 
{"∑", "sum"}, 
{"®", "r"}, 
{"†", "cross"},
{"∂", "d"}, 
{"ƒ", "f"}, 
{"™", "tm"},
{"℠", "sm"}, 
{"…", ""}, 
{"˚", "o"}, 
{"•", ""},
{"∆", "delta"}, 
{"∞", "infinity"}, 
{"♥", "love"}, 
// {"$", "dollar"},
// {"&", "and"},
// {"|", "or"},
// {"<", "less"},
// {">", "greater"},
};


static int  compare_utf32( const void *_a, const void *_b)
{
   struct map_entry *a = (struct map_entry *) _a;
   struct map_entry *b = (struct map_entry *) _b;

   if( ! (a->utf32 - b->utf32))
      return( 0);
   return( a->utf32 > b->utf32 ? +1 : -1);
}


int  main( void)
{
   int            i;
   int            n;
   int            j;
   char           *walk;
   char           *sep;

   n = sizeof( map) / sizeof( map[ 0]);
   for( i = 0; i < n; i++)
   {
      fprintf( stderr, "Converting %i \"%s\" (%ld, %ld)\n", i, map[ i].ascii,
                                                            (long) strcspn( map[ i].ascii, " \t\r\n{}[]()/&%$!.;,_#'+~*\""),
                                                            (long) strlen( map[ i].ascii));
      // don't do ascii escapes
      assert( map[ i].utf8[ 1] || map[ i].utf8[ 0] > 127);
      // just a sanity check in case table gets edited (no slug-unsafe chars)
      assert( strcspn( map[ i].ascii, " \t\r\n&<>|$\"()[]{}*+.!#;,") == strlen( map[ i].ascii));

      walk          = (char *) map[ i].utf8;
      map[ i].utf32 = mulle_utf8_next_utf32character( &walk);

      // can only do one UTF32
      assert( ! *walk);
   }

   qsort( &map, n, sizeof( map[ 0]), compare_utf32);

   // detect and skip duplicates (keep first occurrence after sort)
   j   = 0;
   sep = "   ";
   for( i = 0; i < n; i++)
   {
      if( i > 0 && map[ i].utf32 == map[ i - 1].utf32)
      {
         fprintf( stderr, "Skipping duplicate 0x%06lx \"%s\"\n",
                          (unsigned long) map[ i].utf32, map[ i].ascii);
         continue;
      }
      printf( "%s{ 0x%06lx, \"%s\" }", sep, (unsigned long) map[ i].utf32, map[ i].ascii);
      sep = ",\n   ";
      j++;
   }
   fprintf( stderr, "Emitted %d entries (%d duplicates skipped)\n", j, n - j);
   return( 0);
}
