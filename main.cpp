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
		const bool Contain = Decay.find(Literal) != Decay.end();
		Decay[Literal] = Contain ? ')' : '(';
	}
	return Decay;
}

std::string ConvertToBrackets(const char* Input)
{
	std::string OutString = Input;
	std::transform(OutString.begin(), OutString.end(), OutString.begin(),
	[](char& c)
	{
		return std::tolower(c);
	});

	const auto BracketsMap = DecayBrackets(OutString);

	for (auto& Literal : OutString)
	{
		Literal = BracketsMap.at(Literal);
	}
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