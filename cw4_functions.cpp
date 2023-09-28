#include "input.h"
#include <iostream>
#include <regex>


bool IsTextRestored(const std::string& text)
{
	std::regex pattern(".*((\\{)\\s*(.+)\\s*,\\s*(\\d+)\\s*(\\})).*");
	bool isTextRestored = true;

	if (std::regex_search(text, pattern))
		isTextRestored = false;

	return isTextRestored;
}

void ReplaceText(std::string& text, size_t pos, size_t end_pos, std::string input)
{
	std::string temp1{}, temp2{};

	for (size_t i = 0; i < pos; i++)
		temp1 += text[i];

	for (size_t i = end_pos + 1; i < text.size(); i++)
		temp2 += text[i];

	text = temp1 + input + temp2;
}


void FormatText(std::string& text, size_t sequence_size)
{

	std::string repeatedSymbol{};
	std::string signature{};

	size_t startIndex = 0;
	size_t endIndex = 0;
	size_t lenOfSequence = 1;

	for (size_t j = 0; j < text.size()-1; j++)
	{
		if (text[j] == text[j + 1] && (text[j] != ' ' && text[j] != '\n' && text[j] != '\t'))
		{
			lenOfSequence++;

			if (lenOfSequence >= sequence_size)
			{
				repeatedSymbol = text[j];
				endIndex = j + 1;
			}
		}
		else
		{
			if (lenOfSequence >= sequence_size)
			{
				signature = '{' + repeatedSymbol + ", " + std::to_string(lenOfSequence) + '}';
				ReplaceText(text, startIndex, endIndex, signature);
				j = startIndex + signature.size() - 1;
			}

			lenOfSequence = 1;
			startIndex = j + 1;
			endIndex = j + 1;
		}
	}
}


void RestoreText(std::string &text, bool &error)
{
	std::regex pattern(".*((\\{)\\s*(.+)\\s*,\\s*(\\d+)\\s*(\\})).*");
	std::smatch matches{};

	while (std::regex_search(text, matches, pattern))
	{
		std::string temp{};
		size_t symbol(0), length(0), begin_bracket(0), end_bracket(0);
		begin_bracket = static_cast<size_t>(matches.position(2));
		symbol = static_cast<size_t>(matches.position(3));
		length = static_cast<size_t>(std::stoi(matches[4].str()));
		end_bracket = static_cast<size_t>(matches.position(5));

		if ((length > text.size()) || (begin_bracket + length > text.size()))
		{
			std::cout << "Специальная сигнатура " << matches[1] << " содержит недопустимую длину! Перезапустите программу." << std::endl;
			error = true;
			break;
		}

		for (size_t k = 0; k < length; k++)
			temp += text[symbol];

		length = static_cast<size_t>(matches.position(4));
		ReplaceText(text, begin_bracket, end_bracket, temp);
	}
}


void StartModify(std::string& text, std::string& modifiedText, size_t sequence_size)
{
	std::vector<std::string> sequences{};
	FormatText(text, sequence_size);
	modifiedText = text;
}


void StartRestore(std::string& text, std::string& restoredText, bool &error)
{
	if (!IsTextRestored(text))
		RestoreText(text, error);
	restoredText = text;
}


void SetSequenceSize(size_t& sequence_size)
{
	std::cout << "Введите минимальную длину подстроки: " << std::endl;
	sequence_size = GetSequenceSize();
}


void InputText(std::string& text)
{
	std::cout << "Введите текст. Введите q чтобы завершить ввод." << std::endl;
	std::string input{};
	while (input != "q")
	{
		GetLine(std::cin, input, CW4_INPUT, MANUAL_INPUT);
		if (input != "q")
			text += (input + '\n');
	}
}


void ShowRestored(const std::string& restoredText)
{
	std::cout
		<< "Восстановленный(исходный) текст: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< restoredText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}


void ShowModified(const std::string& modifiedText)
{
	std::cout
		<< "Изменённый текст: " << std::endl
		<< "----------------------------------------------------------------------------" << std::endl
		<< modifiedText << std::endl
		<< "----------------------------------------------------------------------------" << std::endl;
}
