#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef unsigned char uchar;

std::map<uchar, uchar> DecayBrackets(const std::string& InString)
{
	std::map<uchar, uchar> Decay;
	for (char Literal : InString)
	{
		const char Lower = std::tolower(Literal);
		const bool Contain = Decay.find(Lower) != Decay.end();
		Decay[Lower] = Contain ? ')' : '(';
	}
	return Decay;
}

std::string ConvertToBrackets(const char* Input)
{
	std::string OutString = Input;
	const auto BracketsMap = DecayBrackets(OutString);

	std::transform(OutString.begin(), OutString.end(), OutString.begin(),
	[&BracketsMap](char& c)
	{
		return BracketsMap.at(std::tolower(c));
	});
	return OutString;
}

int main(int argc, char* argv[])
{
	std::cout << ConvertToBrackets("din") << std::endl;
	std::cout << ConvertToBrackets("recede") << std::endl;
	std::cout << ConvertToBrackets("Success") << std::endl;
	std::cout << ConvertToBrackets("(( @") << std::endl;

	return 0;
}