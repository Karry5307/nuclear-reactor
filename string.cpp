#include<cstring>
#include "basic.cpp"
namespace Random{
	typedef std::string Str;
	// Make an analysis of a given charset.
	// Charsets begins with a '[' and ends with a ']'.
	// You can use '-' just like regular expressions.
	inline Str analyzeCharSet(Str charSet)
	{
		int length=charSet.length();
		if(charSet[0]!='['||charSet[length-1]!=']')
		{
			puts("[Error] Not a valid charset");
			return "";
		}
		Str res;
		for(register int i=1;i<length-1;i++)
		{
			if(charSet[i+1]=='-')
			{
				if(charSet[i+2]<charSet[i])
				{
					puts("[Error] Not a valid charset");
					return "";
				}
				for(register int j=charSet[i];j<=charSet[i+2];j++)
				{
					res+=(char)(j);
				}
				i+=2;
			}
			else
			{
				res+=charSet[i];
			}
		}
		return res;
	}
	// Generates a char which matches the given charset.
	inline char randChar(Str charSet)
	{
		RandEngine rd;
		if(!charSet.length())
		{
			puts("[Error] Charset is empty");
			return 0;
		}
		Str str=analyzeCharSet(charSet);
		if(str=="")
		{
			return 0;
		}
		return str[rd.get()%str.length()];
	}
	// Generates a string which has a specific length and every letter matches the charset.
	inline Str randString(int length,Str charSet)
	{
		RandEngine rd;
		if(!charSet.length())
		{
			puts("[Error] Charset is empty");
			return 0;
		}
		Str str=analyzeCharSet(charSet),res="";
		for(register int i=0;i<length;i++)
		{
			res+=str[rd.get()%str.length()];
		}
		return res;
	}
}
