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
{"À", "A"}, 
{"Á", "A"}, 
{"Â", "A"}, 
{"Ã", "A"}, 
{"Ä", "A"}, 
{"Å", "A"}, 
{"Æ", "AE"},
{"Ç", "C"}, 
{"È", "E"}, 
{"É", "E"}, 
{"Ê", "E"}, 
{"Ë", "E"}, 
{"Ì", "I"}, 
{"Í", "I"},
{"Î", "I"}, 
{"Ï", "I"}, 
{"Ð", "D"}, 
{"Ñ", "N"}, 
{"Ò", "O"}, 
{"Ó", "O"}, 
{"Ô", "O"},
{"Õ", "O"}, 
{"Ö", "O"}, 
{"Ő", "O"}, 
{"Ø", "O"}, 
{"Ù", "U"}, 
{"Ú", "U"}, 
{"Û", "U"},
{"Ü", "U"}, 
{"Ű", "U"}, 
{"Ý", "Y"}, 
{"Þ", "TH"}, 
{"ß", "ss"}, 
{"à", "a"}, 
{"á", "a"},
{"â", "a"}, 
{"ã", "a"}, 
{"ä", "a"}, 
{"å", "a"}, 
{"æ", "ae"}, 
{"ç", "c"}, 
{"è", "e"},
{"é", "e"}, 
{"ê", "e"}, 
{"ë", "e"}, 
{"ì", "i"}, 
{"í", "i"}, 
{"î", "i"}, 
{"ï", "i"},
{"ð", "d"}, 
{"ñ", "n"}, 
{"ò", "o"}, 
{"ó", "o"}, 
{"ô", "o"}, 
{"õ", "o"}, 
{"ö", "o"},
{"ő", "o"}, 
{"ø", "o"}, 
{"ù", "u"}, 
{"ú", "u"}, 
{"û", "u"}, 
{"ü", "u"}, 
{"ű", "u"},
{"ý", "y"}, 
{"þ", "th"}, 
{"ÿ", "y"}, 
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
{"ş", "s"}, 
{"Ş", "S"}, 
{"ı", "i"}, 
{"İ", "I"}, 
{"ç", "c"}, 
{"Ç", "C"}, 
{"ü", "u"}, 
{"Ü", "U"},
{"ö", "o"}, 
{"Ö", "O"}, 
{"ğ", "g"}, 
{"Ğ", "G"},
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
{"č", "c"}, 
{"ď", "d"}, 
{"ě", "e"}, 
{"ň", "n"}, 
{"ř", "r"}, 
{"š", "s"}, 
{"ť", "t"}, 
{"ů", "u"},
{"ž", "z"}, 
{"Č", "C"}, 
{"Ď", "D"}, 
{"Ě", "E"}, 
{"Ň", "N"}, 
{"Ř", "R"}, 
{"Š", "S"}, 
{"Ť", "T"},
{"Ů", "U"}, 
{"Ž", "Z"},
{"ą", "a"}, 
{"ć", "c"}, 
{"ę", "e"}, 
{"ł", "l"}, 
{"ń", "n"}, 
{"ó", "o"}, 
{"ś", "s"}, 
{"ź", "z"},
{"ż", "z"}, 
{"Ą", "A"}, 
{"Ć", "C"}, 
{"Ę", "e"}, 
{"Ł", "L"}, 
{"Ń", "N"}, 
{"Ś", "S"},
{"Ź", "Z"}, 
{"Ż", "Z"},
{"ā", "a"}, 
{"č", "c"}, 
{"ē", "e"}, 
{"ģ", "g"}, 
{"ī", "i"}, 
{"ķ", "k"}, 
{"ļ", "l"}, 
{"ņ", "n"},
{"š", "s"}, 
{"ū", "u"}, 
{"ž", "z"}, 
{"Ā", "A"}, 
{"Č", "C"}, 
{"Ē", "E"}, 
{"Ģ", "G"}, 
{"Ī", "i"},
{"Ķ", "k"}, 
{"Ļ", "L"}, 
{"Ņ", "N"}, 
{"Š", "S"}, 
{"Ū", "u"}, 
{"Ž", "Z"},
{"€", "euro"}, 
{"₢", "cruzeiro"}, 
{"₣", "french-franc"},  // no space
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
{"©", "(c)"}, 
{"œ", "oe"}, 
{"Œ", "OE"}, 
{"∑", "sum"}, 
{"®", "(r)"}, 
{"†", "+"},
{"“", "\\\""}, // more '\\' for output
{"∂", "d"}, 
{"ƒ", "f"}, 
{"™", "tm"},
{"℠", "sm"}, 
{"…", "..."}, 
{"˚", "o"}, 
{"º", "o"}, 
{"ª", "a"}, 
{"•", "*"},
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
   char   *walk;
   char           *sep;

   n = sizeof( map) / sizeof( map[ 0]);
   for( i = 0; i < n; i++)
   {
      fprintf( stderr, "Converting %i \"%s\" (%ld, %ld)\n", i, map[ i].ascii,
                                                            (long) strcspn( map[ i].ascii, " \t\r\n{}[]()/&%$!.;,_#'+~*"),
                                                            (long) strlen( map[ i].ascii));
      // don't do ascii escapes
      assert( map[ i].utf8[ 1] || map[ i].utf8[ 0] > 127);
      // just a sanity check in case table gets edited
      assert( strcspn( map[ i].ascii, " \t\r\n&<>|$") == strlen( map[ i].ascii));

      walk          = (char *) map[ i].utf8;
      map[ i].utf32 = mulle_utf8_next_utf32character( &walk);

      // can only do one UTF32
      assert( ! *walk);
   }

   qsort( &map, n, sizeof( map[ 0]), compare_utf32);

   sep="   ";
   for( i = 0; i < n; i++)
   {
      printf( "%s{ 0x%06lx, \"%s\" }", sep, (unsigned long) map[ i].utf32, map[ i].ascii);
      sep=",\n   ";
   }
   return( 0);
}