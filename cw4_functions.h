#ifndef CW4_FUNCTIONS_H
#define CW4_FUNCTIONS_H
#include <vector>
#include <string>

void StartRestore(std::string& text, std::string& restoredText, bool &error);
void StartModify(std::string& text, std::string& modifiedText, size_t sequences_size);
void SetSequenceSize(size_t& sequences_size);
void InputText(std::string& text);
void ShowRestored(const std::string& restoredText);
void ShowModified(const std::string& modifiedText);

bool IsTextRestored(const std::string& text);
void ReplaceText(std::string& text, size_t pos, size_t length, std::string input);
void FormatText(std::string& text, size_t sequences_size);
void RestoreText(std::string& text, bool &error);

#endif